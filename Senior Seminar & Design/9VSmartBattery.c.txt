////////////////////////////////////////////////////////////////////////////////
///
/// @file       patches/beacon/beacon.c
///
/// @project    T9304
///
/// @brief      Example Bluetooth Low Energy beacon application.
///
/// @classification  Confidential
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (C) 2016 EM Microelectronic
/// @cond
///
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
/// 1. Redistributions of source code must retain the above copyright notice,
/// this list of conditions and the following disclaimer.
/// 2. Redistributions in binary form must reproduce the above copyright notice,
/// this list of conditions and the following disclaimer in the documentation
/// and/or other materials provided with the distribution.
///
////////////////////////////////////////////////////////////////////////////////
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
/// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
/// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
/// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
/// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
/// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
/// POSSIBILITY OF SUCH DAMAGE.
/// @endcond
////////////////////////////////////////////////////////////////////////////////

// EM Includes
#include <types.h>
#include <macros.h>
#include <em_qpn.h>
#include <bsp.h>
#include <platform.h>
#include <pml.h>
#include <spi_slave.h>

// Standard Includes
#include <string.h>

// Stack Includes
#include <BleBase.h>
#include <BleGap.h>
#include <BleEngine.h>
#include <BleHostStackTask.h> // To access AO_BleHostStackTask

//////////////////////////////TX POWER//////////////////////////////////
#include <BleHci.h>
////////////////////////////////////////////////////////////////

// SPI slave configuration data structure.
extern SPIS_Configuration_t gSPIS_Config;

typedef struct
{
    // Root structure for all state machines.
    QActive super;

    // Handler for the Bluetooth Low Energy stack.
    BleHandler handler;
} Beacon_t;

typedef enum
{
    BEACON_BLE_INIT_SIG = EM_USER_SIG,
    BEACON_SIG_COUNT
} BeaconSignals_t;

_Static_assert(255 >= (int)BEACON_SIG_COUNT, "Too many QP-nano signals!");

// This variable represents the task.
static Beacon_t gBeaconTask;

// This variable stores all signals being sent to the task.
static SECTION_NONPERSISTENT QEvt gBeaconEventQueue[5];

static QMutex Beacon_StackMutexLock(void)
{
    // For some reason this does not work.
    return QK_mutexLock(0xFF /*AO_BleHostStackTask.super.prio*/);
}

static void Beacon_StackMutexUnlock(QMutex mutex)
{
    QK_mutexUnlock(mutex);
}

/**
 * @bried Called during a stack event.
 */
void Beacon_CoreCallback(BleEvent event, BleStatus status, void* pParam);

/**
 * @bried Called during a GAP event.
 */
void Beacon_GapCallback(BleGapEvent event, BleStatus status, void *parms);

/**
 * @brief Constructor for the task.
 *
 * This will initialize the state machine variable @ref gBeaconTask.
 *
 * @param me Pointer to the task to construct.
 */
void Beacon_Constructor(Beacon_t *me);

/**
 * @brief Initialization state.
 *
 * The first state of a QP-nano task is special. It must always make a
 * transition to another state. This implementation will initialize the
 * Bluetooth Low Energy stack.
 *
 * @param me Pointer to the task.
 * @returns Next action for the state machine to take (stay or transition).
 */
QState Beacon_Init(Beacon_t *me);

/**
 * @brief Waiting for Bluetooth Low Energy stack initialization.
 *
 * @param me Pointer to the task.
 * @returns Next action for the state machine to take (stay or transition).
 */
QState Beacon_WaitForStack(Beacon_t *me);

/**
 * @brief Main state of the beacon application.
 *
 * @param me Pointer to the task.
 * @returns Next action for the state machine to take (stay or transition).
 */
QState Beacon_Run(Beacon_t *me);

/**
 * @brief Where programs go to die.
 *
 * @param me Pointer to the task.
 * @returns Next action for the state machine to take (stay or transition).
 */
QState Beacon_Error(Beacon_t *me);

////////////////////////////////////////////////////////////////////////////////

void Beacon_CoreCallback(BleEvent event, BleStatus status, void *pParam)
{
    switch(event)
    {
        case BLEEVENT_INITIALIZATION_RSP:
        	BLEGAP_SetTXPowerLevelADData(-6.9);
            // Notify the task.
            QACTIVE_POST(&gBeaconTask.super, (int)BEACON_BLE_INIT_SIG,
                (QParam)status);
            break;

        default:
            break;
    }
}


void Beacon_GapCallback(BleGapEvent event, BleStatus status, void *parms)
{
    QMutex mutex;

    switch(event)
    {
        case BLEGAP_EVENT_CONNECTED:
            // Handle connected event.
            break;

        case BLEGAP_EVENT_DISCONNECTED:
            mutex = Beacon_StackMutexLock();
            BLEGAP_SetTXPowerLevelADData(-6.9);
            (void)BLEGAP_SetModeWithIntervals(BLEMODE_DISCOVERABLE, 0x0C80);
            Beacon_StackMutexUnlock(mutex);
            break;

        default:
            break;
    }
}


void Beacon_Constructor(Beacon_t *me)
{
    // Tell QP-nano what the initial state is.
    QActive_ctor(&me->super, Q_STATE_CAST(Beacon_Init));
}


QState Beacon_Init(Beacon_t *me)
{
    QState status;
    QMutex mutex;

    // Protect calls to the stack.
    mutex = Beacon_StackMutexLock();

    if(BLESTATUS_PENDING == BLEMGMT_Init())
    {
        // Register a stack callback.
        me->handler.callback = Beacon_CoreCallback;

        // Check if the callback was registered properly.
        if(BLESTATUS_SUCCESS != BLEMGMT_RegisterHandler(&me->handler))
        {
            // There was an error.
            status = Q_TRAN(Beacon_Error);
        }
        else
        {
            // Now wait for the stack to finish initialization.
            status = Q_TRAN(Beacon_WaitForStack);
        }
    }
    else
    {
        // The call to BLEMGMT_Init() failed.
        status = Q_TRAN(Beacon_Error);
    }

    // We are doing calling the stack.
    Beacon_StackMutexUnlock(mutex);

    // GPIO initialization.
    // Unused pins must be properly set avoid significant current draw due to
    // floating pins.
    GPIO->RegGPIOInputEn.r32 = 0x000;		// Inputs disabled
	GPIO->RegGPIOOutputEn.r32 = 0x000;		// Outputs disabled
	GPIO->RegGPIOPuEn.r32 = 0x000;			// Pull-up disabled
	GPIO->RegGPIOPdEn.r32 = 0xFFF;			// Pull-down enabled
	GPIO_SetOutputPinFunction(0,  GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(1,  GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(2,  GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(3,  GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(4,  GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(5,  GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(6,  GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(7,  GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(8,  GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(9,  GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(10, GPIO_PIN_FUNC_OUT_GPIO);
	GPIO_SetOutputPinFunction(11, GPIO_PIN_FUNC_OUT_GPIO);

	PML->RegPmlPadWake.r16[0] &= ~0x001;	// Disable wakeup on GPIO00

    return status;
}

#define EXAMPLE_LOCAL_DEVICE_NAME ("9V Smart Battery")

QState Beacon_WaitForStack(Beacon_t *me)
{
    QState status;
    QMutex mutex;

    switch( Q_SIG(me) )
    {
        case BEACON_BLE_INIT_SIG:
        {
            if(BLESTATUS_SUCCESS == Q_PAR(me))
            {
                // Register a GAP device.
                mutex = Beacon_StackMutexLock();
                (void)BLEGAP_RegisterDevice(BLEGAPROLE_PERIPHERAL,
                    Beacon_GapCallback);
                Beacon_StackMutexUnlock(mutex);

                // Set the name of the peripheral.
                mutex = Beacon_StackMutexLock();
                (void)BLEGAP_SetLocalBluetoothDeviceName((U8*) EXAMPLE_LOCAL_DEVICE_NAME,
                                    sizeof(EXAMPLE_LOCAL_DEVICE_NAME));
                Beacon_StackMutexUnlock(mutex);

                // Start advertising.
                mutex = Beacon_StackMutexLock();
                BLEGAP_SetTXPowerLevelADData(-6.9);
                (void)BLEGAP_SetModeWithIntervals(BLEMODE_DISCOVERABLE, 0x0C80);
                Beacon_StackMutexUnlock(mutex);

                status = Q_TRAN(Beacon_Run);
            }
            else
            {
                status = Q_TRAN(Beacon_Error);
            }

            break;
        }
        default:
            // Let the super class handle this.
            status = Q_SUPER(QHsm_top);
            break;
    }

    return status;
}


QState Beacon_Run(Beacon_t *me)
{
    QState status;

    switch( Q_SIG(me) )
    {
        default:
            // Let the super class handle this.
            status = Q_SUPER(QHsm_top);
            break;
    }

    return status;
}


QState Beacon_Error(Beacon_t *me)
{
    QState status;

    switch( Q_SIG(me) )
    {
        default:
            // Let the super class handle this.
            status = Q_SUPER(QHsm_top);
            break;
    }

    return status;
}


void Beacon_EntryFunction(void)
{
    // Add the task to QP-nano. This must always happen here.
    (void)QF_addTask(&gBeaconTask.super, &gBeaconEventQueue[0],
        Q_DIM(gBeaconEventQueue));

	// Disable the SPI slave port.
	gSPIS_Config.spisEnabled = false;

	// Initialize the transport with the SPI slave disabled.  The compiler
	// will issue a warning about the buffers being deprecated.  This can
	// be ignored because the buffers are not being used in this instant.
	SPIS_InitBuffers(gSPIS_Config.pRxBuffer, gSPIS_Config.rxBufferSize,
		gSPIS_Config.pTxBuffer, gSPIS_Config.txBufferSize);

    // Setup the task during a reset.
    if(!PML_DidBootFromSleep())
    {
        // Construct our new QP-nano task.
        Beacon_Constructor(&gBeaconTask);

        // Override some configuration settings so a configuration patch
        // does not need to be loaded.
        Platform_Configuration_t *pPlatform_Config =
            (Platform_Configuration_t*)MODIFY_CONST(&gPlatform_Config);

        pPlatform_Config->blePacketPayloadLengthMax = 251;
        pPlatform_Config->bleIsStackRequested = 1;
    }
}

ENTRY_FUNCTION(Beacon_EntryFunction);
