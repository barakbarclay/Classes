////////////////////////////////////////////////////////////////////////////////
///
/// @file       projects/findmeplus/findmeplus.c
///
/// @project    EM9304 SOC SDK Example
///
/// @brief      Example Bluetooth Low Energy example application demonstrating
///             the FindMe and data exchange profiles, and the following
///             features of the EM9304:
///
///               o Data transfer using the data exchange profile
///               o Generating a random Bluetooth local device address
///               o Using the sleep timer as time source
///               o Create a time stamp from the sleep timer
///               o Using the timer peripheral to create a PWM signal to drive
///                 a buzzer
///               o Battery profile
///               o Bluetooth connecting, pairing, and bonding
///               o Multiple connections
///               o Analyzing a firmware exception
///               o Setting the radio transmit power
///
///             To create a new application based on this example, follow these
///             steps:
///             1. Create a new application folder under the SDK "projects"
///                folder.
///             2. Copy the example application files to the new application
///                folder.  Only the source files (*.h and *.c) and the
///                CMakelists.txt file need be copied to the new application
///                folder.
///             3. Modify the application specific CMakelists.txt file as
///                instructed in the comment sections of the file.
///             4. Add the application folder to the projects CMakelists.txt
///                located in the [SOC SDK path]/sw/projects folder.
///             5. In the Metaware IDE, press F5 to refresh the files.
///             6. In the Metaware IDE, select Project->Build All.
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (C) 2015-present EM Microelectronic-US Inc.
/// @cond
///
/// All rights reserved.
///
/// IMPORTANT - PLEASE CAREFULLY READ THE FOLLOWING SOURCE CODE LICENSE
/// AGREEMENT, WHICH IS LEGALLY BINDING.  THE SOURCE CODE MAY BE USED ONLY IF
/// YOU ACCEPT THE TERMS AND CONDITIONS OF THIS SOURCE CODE LICENSE AGREEMENT
/// (hereafter, the Agreement).
///
/// By Using this source code, you: (i) warrant and represent that you have
/// obtained all authorizations and other applicable consents required
/// empowering you toenter into and (ii) agree to be bound by the terms of this
/// Agreement on your own behalf and/or on behalf of your company.  If you do
/// not agree to this Agreement, then you are not permitted to Use this source
/// code, in whole or in part.
///
/// License Grant.  Pursuant to the terms in the accompanying software license
/// agreement and Terms of Use located at:
/// https://forums.emdeveloper.com/emassets/emus_sourcelicense.html and
/// https://forums.emdeveloper.com/emassets/emus_termsofuse.html  (the terms of
/// each are incorporated herein by this reference) and subject to the
/// restrictions, disclaimer and limitation of liability set forth below,
/// EM Microelectronic US Inc. (EM), grants strictly to you, without the right
/// to sublicense, a non-exclusive, non-transferable, revocable, limited
/// worldwide license to use the source code to modify or create derivative
/// works of the software program for the sole purpose of developing object
/// and executable versions that execute solely and exclusively on devices
/// manufactured by or for EM or your products that use or incorporate devices
/// manufactured by or for EM.
///
/// Restriction.  Without limiting any of the foregoing, the name
/// "EM Microelectronic-US Inc." or that of any of the EM Parties (as such term
/// is defined below) must not be Used (as such term is defined below) to
/// endorse or promote products derived from the source code without prior
/// written permission from an authorized representative of EM Microelectronic
/// US Inc. Unless authorized officers of the parties to this Agreement have
/// duly executed a special written contract specifically governing such Use,
/// in no event shall the source code be Used in or with: (i) life-critical
/// medical equipment, products or services, (ii) military, armament, nuclear or
/// aerospace applications or environments; or (iii) automotive applications
/// unless specifically designated by EM as automotive-grade.  In addition, you
/// understand and agree that you remain solely responsible for using your
/// independent analysis, evaluation, and judgment in designing and developing
/// your applications, products and services.
///
/// DISCLAIMER.  THE SOURCE CODE IS PROVIDED "AS IS" WITH ALL FAULTS, WITHOUT
/// ANY SUPPORT. EM MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS, IMPLIED OR
/// STATUTORY, INCLUDING ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
/// A PARTICULAR PURPOSE OR USE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS OF
/// RESPONSES, RESULTS, LACK OF NEGLIGENCE AND LACK OF SECURITY.  EM DISCLAIMS
/// ANY WARRANTY OF TITLE, QUIET ENJOYMENT, QUIET POSSESSION, AND NON-
/// INFRINGEMENT OF ANY THIRD PARTY INTELLECTUAL PROPERTY RIGHTS WITH REGARD TO
/// THE SOURCE CODE OR YOUR USE OF THE SOURCE CODE.  THE ENTIRE RISK AS TO THE
/// QUALITY AND PERFORMANCE OF THE SOURCE CODE IS WITH YOU. SHOULD THE SOURCE
/// CODE PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR
/// OR CORRECTION.  NOTHING CONTAINED IN THIS AGREEMENT WILL BE CONSTRUED AS A
/// WARRANTY OR REPRESENTATION BY ANY EM PARTIES TO MAINTAIN PRODUCTION OF ANY
/// EM DEVICE OR OTHER HARDWARE OR SOFTWARE WITH WHICH THE SOURCE CODE MAY BE
/// USED.  NO ORAL OR WRITTEN INFORMATION OR ADVICE GIVEN BY EM OR AN EM
/// AUTHORIZED REPRESENTATIVE WILL CREATE A WARRANTY
///
/// LIMITATION OF LIABILITY.  IN NO EVENT SHALL EM MICROELECTRONIC US INC., ITS
/// PARENT AND ITS AND THEIR RESPECTIVE AFFILIATES, SUBSIDIARIES, LICENSORS,
/// THIRD PARTY PROVIDERS, REPRESENTATIVES, AGENTS AND ASSIGNS (COLLECTIVLEY,
/// EM PARTIES) BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
/// PUNITIVE, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
/// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
/// EQUIPMENT, SYSTEMS, SOFTWARE, TECHNOLOGY, SERVICES, GOODS, CONTENT,
/// MATERIALS OR PROFITS; BUSINESS INTERRUPTION OR OTHER ECONOMIC LOSS OR ANY
/// CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF)
/// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
/// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
/// OUT OF THE USE OF THIS SOURCE CODE, INCLUDING ANY PORTION(S) THEREOF, EVEN
/// IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  NOTWITHSTANDING ANYTHING ELSE
/// TO THE CONTRARY, IN NO EVENT WILL THE EM PARTIES AGGREGATE LIABILITY UNDER
/// THIS AGREEMENT OR ARISING OUT OF YOUR USE OF THE SOURCE CODE EXCEED ONE
/// HUNDRED U.S. DOLLARS (U.S. $100).
///
/// Because some jurisdictions do not allow the exclusion or limitation of
/// incidental or consequential damages or limitation on how long an implied
/// warranty lasts, the above limitations or exclusions may not apply to you.
///
/// Please refer to the accompanying software license agreement and Terms of Use
/// located at, respectively:
/// https://forums.emdeveloper.com/emassets/emus_sourcelicense.html and
/// https://forums.emdeveloper.com/emassets/emus_termsofuse.html  to better
/// understand all of your rights and obligations hereunder.  Except as
/// otherwise provided in this Agreement, all capitalized terms defined in said
/// software license agreement and Terms of Use shall have the meanings
/// ascribed to such terms therein.
/// @endcond
////////////////////////////////////////////////////////////////////////////////

/******************************************************************************\
 *  INCLUDE FILES
\******************************************************************************/

// EM Includes
#include <aux_registers.h>
#include <types.h>
#include <macros.h>

#include <em_qpn.h>
#include <bsp.h>
#include <rtc.h>
#include <gpio.h>
#include <memory_map.h>
#include <memory_manager.h>
#include <platform.h>
#include <pml.h>
#include <pml_volt_monitor.h>
#include <radio.h>
#include <t9304_periph.h>
#include <t9304_uni_tim.h>
#include <sleep_timer.h>
#include <vendor.h>

// Standard Includes
#include <printf.h>
#include <string.h>

// Stack Includes
#include <BleCommonTypes.h>
#include <BleBase.h>
#include <BleGap.h>
#include <BleEngine.h>
#include <BleSystem.h>        // for SYSTEM_CreateTimer()

#include <AciCoreCallback.h>  // Enable vendor specific ACI commands

#include <BleFindMe_Target.h>
#include <BleLinkLayerHci.h> // for BLELINKLAYERHCI_SendEvent
#include <BleAlpwDataExchange_Server.h>

#include <BleSm.h>

// Application Specific Includes
#include <findme.h>

//////////////////////////////TX POWER//////////////////////////////////
#include <BleHci.h>
////////////////////////////////////////////////////////////////

/******************************************************************************\
 *  CONSTANTS
\******************************************************************************/

// Uncomment to enable pairing.
//#define FINDME_REQUEST_PAIRING
//#define FINDME_LED_DRIVER
//#define FINDME_BUZZER_DRIVER

// Define the advertising and connection intervals.  The values
// represent the number of 0.625 ms slots. The possible value
// is: Range: 0x0020 to 0x4000.
#define FINDME_ADVERTISING_PERIOD (320u)   // 200 ms
#define FINDME_CONNECTION_INTERVAL (320u)  // 200 ms

#define TIMER_SLEEP_TICKS_SHIFTED_TO_SECOND ( 15 )
#define TIMER_TIME_STAMP_SIZE ( 15 )

// Sleep Timer channel used for RTC function
// System has 4 Sleep Timer channels. Channel 0 is used by generic Sleep mode
// controller thus channels 1-3 are available. Here we choose channel 1.
#define RTC_SLEEP_TIMER_CHANNEL         1

// Use LF XTAL as a clock source for RTC
#define RTC_USE_LF_XTAL                 0

// Use RTC low frequency calibration clock
// If macro has value 1 LF clock calibration is enabled. Otherwise RTC clock
// calibration is disabled.
#define RTC_USE_LF_CLOCK_CALIBRATION    1

// Use Short Alarm feature in example
// If macro has value 1 Short Alarm feature is enabled and used in example.
#define RTC_USE_SHORT_ALARM             1

// Use Alarm feature in example
// If macro has value 1 Alarm feature is enabled and used in example.
#define RTC_USE_ALARM                   1

// Use debug HCI events
// If macro has value 1 debug HCI events are send over current transport layer
#define USE_HCI_DEBUG_EVENT             0

/******************************************************************************\
 *  MACROS
\******************************************************************************/


/******************************************************************************\
 *  TYPE DEFINITION
\******************************************************************************/

typedef enum
{
    FINDME_BLE_INIT_SIG = EM_USER_SIG,

    FINDME_BLE_MODECHANGE_OK_SIG,
    FINDME_BLE_MODECHANGE_ERR_SIG,
    FINDME_BLE_START_ADVERTISING_SIG,
    FINDME_BLE_CONNECTED_SIG,
    FINDME_BLE_DISCONNECTED_SIG,
	FINDME_BLE_BONDED_SIG,

    FINDME_BLE_DATA_EXCHANGE_TX_SIG,
    FINDME_SIG_COUNT,

	FINDME_RTC_SIG
} FindMeSignals_t;

_Static_assert(255 >= (int)FINDME_SIG_COUNT, "Too many QP-nano signals!");

/******************************************************************************\
 *  GLOBAL VARIABLES
\******************************************************************************/

MyTask_t gMyTask;

// Number of connections.
static uint8_t gConnectionCount;
static U8      gDisconnectReason;
static bool    gDataExchangeTxPending;
static U8      gDataExchangeRxData;
static U8      gDataExchangeRxDataAllCharacters[9];
static int 	   gDataExchangeRxDataSize;
static U16     gDataExchangeConnectionHandle;

static bool snoozing;

// RTC alarm
static time_t  gRtcAlarm;

uint32_t  gResetReason;
uint32_t  gResetAddress;
uint32_t *gPersistentAllocation;

// Local Bluetooth address
static BD_ADDR       *gpLocalAddr;
static BleAddressType gLocalAddrType;

extern const Config_ModuleConfiguration_t gPML_Config;

/******************************************************************************\
 *  FUNCTION PROTOTYPES
\******************************************************************************/

/**
 * @brief Called during a stack event.
 */
void FindMe_CoreCallback(BleEvent event, BleStatus status, void* pParam);

/**
 * @bried Called during a GAP event.
 */
void FindMe_GapCallback(BleGapEvent event, BleStatus status, void *parms);


/**
 * @bried Callback for the data exchange service
 */
void FindMe_DataExchangeCallback(BleAlpwDataExchangeEvent event, BleStatus status, void* parms);


/**
 * @bried Callback for the data exchange service
 */
void FindMe_DataExchangeTx( void );

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
QState FindMe_Init(MyTask_t *me);

/**
 * @brief Waiting for Bluetooth Low Energy stack initialization.
 *
 * @param me Pointer to the task.
 * @returns Next action for the state machine to take (stay or transition).
 */
QState FindMe_WaitForStack(MyTask_t *me);

/**
 * @brief Waiting for random address to be generated and set.
 *
 * @param me Pointer to the task.
 * @returns Next action for the state machine to take (stay or transition).
 */
QState FindMe_WaitForRandomAddress(MyTask_t *me);

/**
 * @brief Main state of the findme application.
 *
 * @param me Pointer to the task.
 * @returns Next action for the state machine to take (stay or transition).
 */
QState FindMe_Run(MyTask_t *me);

/**
 * @brief Where programs go to die.
 *
 * @param me Pointer to the task.
 * @returns Next action for the state machine to take (stay or transition).
 */
QState FindMe_Error(MyTask_t *me);

////////////////////////////////////////////////////////////////////////////////

/**
* RTC callback
*
* This callback is called in an interrupt context.
* If the user wishes to post a QP-nano event from the RTC callback, special care must be taken.
* The QACTIVE_POST_ISR macro must be used and all post must be wrapped by QK_ISR_ENTRY and
* QK_ISR_EXIT as shown here.
*/
void RTC_Callback(RTC_CallbackReason_t reason)
{
	/* In this RTC callback we redirect event from RTC interrupt service routine to QPnano to notify RtcTask_Run(). */
	QK_ISR_ENTRY();
	QACTIVE_POST_ISR(&gMyTask.super, (int )FINDME_RTC_SIG, (QParam )reason);
	QK_ISR_EXIT();
}

void FindMe_CoreCallback(BleEvent event, BleStatus status, void *pParam)
{
    switch(event)
    {
        case BLEEVENT_INITIALIZATION_RSP:
        	BLEGAP_SetTXPowerLevelADData(-6.9);
            // Notify the task.
            ( void ) QACTIVE_POST(&gMyTask.super, ( int )FINDME_BLE_INIT_SIG,
                (QParam) status);
        break;

        case BLEEVENT_GENERATE_RANDOM_ADDRESS_RSP:
        {
            if (status == BLESTATUS_SUCCESS)
            {
                // The address has been set.
                ( void ) BLEGAP_GetLocalBdAddr( &gpLocalAddr, &gLocalAddrType );
            }
            ( void ) QACTIVE_POST(&gMyTask.super, ( int )FINDME_BLE_START_ADVERTISING_SIG,
                (QParam) status);
        }
        break;

        case BLEEVENT_PAIRING_REQUEST:
        {
            BlePairingInfo *pInfo = ((BlePairingInfo *) pParam);
            ( void ) BLESMP_ConfirmPairing(pInfo->connHandle, 1, 1);
        }
        break;

        case BLEEVENT_PAIRING_COMPLETE:
        {
            BleLinkSecurityProperties securityProperties;
            BlePairingInfo *pInfo = ((BlePairingInfo *) pParam);

            // retrieve the link security state ( Authenticated and/or encrypted and/or bonded)
            ( void ) BLESMP_GetLinkSecurityProperties(pInfo->connHandle, &securityProperties);

            if(status == BLESTATUS_SUCCESS)
            {
                ( void ) QACTIVE_POST(&(gMyTask.super), ( int ) FINDME_BLE_BONDED_SIG, (const QParam) 0);
            }
            else
            {
                // The pairing has failed.
                if ( 0x00 != (securityProperties & CONNSTATE_BONDED))
                {
                    // We were bonded and the pairing has failed reason 0x08
                    // it means that the link encryption attempt has failed
                    // either the remote device is trying to spoof us by imitating
                    // the original remote device, or the original remote device
                    // has lost bonding information.  We should unbond.

                    BD_ADDR pairingAddr;

                    if (BLESTATUS_SUCCESS == BLEGAP_GetBDAddr(pInfo->connHandle, &pairingAddr ))
                    {
                        ( void ) BLESMP_UnBond(&pairingAddr);
                    }
                }
                ( void ) QACTIVE_POST(&gMyTask.super, ( int )FINDME_BLE_DISCONNECTED_SIG,
                    ( QParam ) status);
            }
        }
        break;

#ifndef EXAMPLE_DISABLE_SPI_SLAVE

#endif

        default:
            break;
    }
}


void FindMe_GapCallback(BleGapEvent event, BleStatus status, void *parms)
{
    BleGapConnectionInformation *pConnectionInfo;

    switch(event)
    {
        case BLEGAP_EVENT_CONNECTED:
            // Handle connected event.
            pConnectionInfo = ((BleGapConnectionInformation *) parms );

            // The connection count has not been updated yet, so the index into the array
            // is the current connection count instead of count - 1.
            ( void ) QACTIVE_POST(&(gMyTask.super), ( int )FINDME_BLE_CONNECTED_SIG, ( const QParam )( pConnectionInfo->connHandle ));
            break;

        case BLEGAP_EVENT_DISCONNECTED:
            {
                BleGapConnectionInformation *connInfo = (BleGapConnectionInformation *) parms;

                gDisconnectReason = ( U8 ) connInfo->disconnectionReason;

                ( void ) QACTIVE_POST(&(gMyTask.super), ( int )FINDME_BLE_DISCONNECTED_SIG, (const QParam) 0);
            }
            break;

        case BLEGAP_EVENT_MODECHANGE:
            {
                if (status == BLESTATUS_SUCCESS)
                {
                    // Initialization is successful
                    ( void ) QACTIVE_POST(&(gMyTask.super), ( int )FINDME_BLE_MODECHANGE_OK_SIG, (const QParam) 0);
                }
                else
                {
                    // Initialization failed
                    ( void ) QACTIVE_POST(&(gMyTask.super), ( int )FINDME_BLE_MODECHANGE_ERR_SIG, (const QParam) 0);
                }
            }
            break;

        default:
            break;
    }
}

void FindMe_DataExchangeCallback( BleAlpwDataExchangeEvent event,
                                  BleStatus status,
                                  void* parms )
{
    BleAlpwDataExchangeServerRxData *pRxData;

    switch(event)
    {
        case BLEALPWDATAEXCHANGE_EVENT_RXDATA:
            if ( NULL != parms )
            {
                pRxData = ( BleAlpwDataExchangeServerRxData * ) parms;
                if ( NULL != pRxData->rxData )
                {
                    gDataExchangeRxData = ( U8 )( pRxData->rxData[ 0 ]);
                    gDataExchangeRxDataSize = sizeof(pRxData->rxData) / sizeof(U8);
                    for (int i = 0; i < gDataExchangeRxDataSize; i++)
                    {
                    	gDataExchangeRxDataAllCharacters[i] = pRxData->rxData[ i ];
                    }
                    gDataExchangeConnectionHandle = pRxData->connHandle;
                }
                else
                {
                    gDataExchangeRxData = 0u;
                    gDataExchangeConnectionHandle = 0u;
                }
            }
            ( void ) QACTIVE_POST(&gMyTask.super, ( int )FINDME_BLE_DATA_EXCHANGE_TX_SIG,
                (const QParam) 0);

            break;

        case BLEALPWDATAEXCHANGE_EVENT_TXCOMPLETE:
            gDataExchangeTxPending = false;
            break;

        default:
            break;
    }
}


//
//  Create the time value.
//
U8 FindMe_GetTimeStamp( U32 timeToConvert, U8 *pTimeString )
{
    const char *decimalDigit = "0123456789";

    U8       digitPlace = 0u;
    U8       digitPlaceNext = 0u;
    uint32_t value;
    uint32_t days;
    uint32_t hours;
    uint32_t minutes;
    uint32_t seconds;
    uint32_t tenths;

    if ( 0u == timeToConvert )
    {
        // Retrieve the running time from the sleep timer.  The sleep timer continuously runs
        // and is relatively slow, so it provides a convenient time for the timer display.
        value = SleepTimer_GetCurrentValue();
    }
    else
    {
        value = ( uint32_t ) timeToConvert;
    }

    // Convert the sleep time to seconds.
    seconds = value >> TIMER_SLEEP_TICKS_SHIFTED_TO_SECOND;
    tenths  = (( value - ( seconds << TIMER_SLEEP_TICKS_SHIFTED_TO_SECOND )) * 10u ) >>
              TIMER_SLEEP_TICKS_SHIFTED_TO_SECOND;

    // Round up if necessary.
    if ( 10 <= tenths )
    {
        seconds++;
        tenths = 0u;
    }

    days     = seconds / (60u * 60u * 24u);
    seconds -= days * (60u * 60u * 24u);
    hours    = seconds / (60u * 60u);
    seconds -= hours * (60u * 60u);
    minutes  = seconds / 60u;
    seconds -= minutes * 60u;

    digitPlace = (( 100u <= days ) ? 2u : ( 10u <= days ? 1u : 0u ));
    digitPlaceNext = digitPlace + 1u;

    // Add the number of days.
    do
    {
        value = days;
        days /= 10u;
        pTimeString[ digitPlace ] = ( U8 ) decimalDigit[ value - ( days * 10u )];
        digitPlace--;
    } while ( 0u < days );

    digitPlace = digitPlaceNext;
    pTimeString[ digitPlace++ ] = ( U8 ) ' ';

    // Add the hours.
    if ( 10u <= hours )
    {
        value = hours / 10u;
    }
    else
    {
        value = 0u;
    }
    pTimeString[ digitPlace++ ] = ( U8 ) decimalDigit[ value ];
    pTimeString[ digitPlace++ ] = ( U8 ) decimalDigit[ hours - ( value * 10u )];
    pTimeString[ digitPlace++ ] = ( U8 ) ':';

    // Add the minutes.
    if ( 10u <= minutes )
    {
        value = minutes / 10u;
    }
    else
    {
        value = 0u;
    }
    pTimeString[ digitPlace++ ] = ( U8 ) decimalDigit[ value ];
    pTimeString[ digitPlace++ ] = ( U8 ) decimalDigit[ minutes - ( value * 10u )];
    pTimeString[ digitPlace++ ] = ( U8 ) ':';

    // Add the seconds.
    if ( 10u <= seconds )
    {
        value = seconds / 10u;
    }
    else
    {
        value = 0u;
    }
    pTimeString[ digitPlace++ ] = ( U8 ) decimalDigit[ value ];
    pTimeString[ digitPlace++ ] = ( U8 ) decimalDigit[ seconds - ( value * 10u )];

    pTimeString[ digitPlace++ ] = ( U8 )( '.' );
    pTimeString[ digitPlace++ ] = ( U8 )( decimalDigit[ tenths ]);
    pTimeString[ digitPlace++ ] = ( U8 )( '\0' );

    return digitPlace;
}

int FindMe_StringToDecimal(U8 a[]) {
  int c, offset, n;

  offset = 0;

  n = 0;

  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }

  return n;
}

//
//  Respond to the command request.
//
void FindMe_DataExchangeTx( void )
{
    if ( 0u != gDataExchangeConnectionHandle &&
         0u != gDataExchangeRxData && ! gDataExchangeTxPending )
    {
        U8 responseMessage[ TIMER_TIME_STAMP_SIZE ];
        U8 sizeOfString;

        if (( U8 )('d') == gDataExchangeRxData)
        {
        	sizeOfString = FindMe_GetTimeStamp( 0, &responseMessage[ 0 ]);
            BLEGAP_Disconnect(gDataExchangeConnectionHandle);
                        (void) BLEGAP_SetMode(BLEMODE_NOTDISCOVERABLE | BLEMODE_NOTCONNECTABLE);
                        snoozing = true;
                                                // First RTC time is read into structure
                                                time_t seconds = RTC_GetTime(NULL);
                                                // RTC time can be read also in struct format:
                                                RTC_TimeDate_t rtcTimeDate;
                                                RTC_GetTimeAndDate(&rtcTimeDate);
                                                // Finally, we configure alarm again to occur in 15 seconds from
                                                // previous alarm
                                                //
                                                // set time to be added to current Alarm time
                                                gRtcAlarm = seconds + 86400;
                                                RTC_SetAlarmTime(gRtcAlarm, 0, true);

        }
        else if (( U8 )('w') == gDataExchangeRxData)
        {
        	sizeOfString = FindMe_GetTimeStamp( 0, &responseMessage[ 0 ]);
            BLEGAP_Disconnect(gDataExchangeConnectionHandle);
                                    (void) BLEGAP_SetMode(BLEMODE_NOTDISCOVERABLE | BLEMODE_NOTCONNECTABLE);
                                    snoozing = true;
                                                            // First RTC time is read into structure
                                                            time_t seconds = RTC_GetTime(NULL);
                                                            // RTC time can be read also in struct format:
                                                            RTC_TimeDate_t rtcTimeDate;
                                                            RTC_GetTimeAndDate(&rtcTimeDate);
                                                            // Finally, we configure alarm again to occur in 15 seconds from
                                                            // previous alarm
                                                            //
                                                            // set time to be added to current Alarm time
                                                            gRtcAlarm = seconds + 604800;
                                                            RTC_SetAlarmTime(gRtcAlarm, 0, true);
        }
        else if (( U8 )('s') == gDataExchangeRxData)
        {
        	sizeOfString = FindMe_GetTimeStamp( 0, &responseMessage[ 0 ]);
            BLEGAP_Disconnect(gDataExchangeConnectionHandle);
            (void) BLEGAP_SetMode(BLEMODE_NOTDISCOVERABLE | BLEMODE_NOTCONNECTABLE);
            snoozing = true;
                                    // First RTC time is read into structure
                                    time_t seconds = RTC_GetTime(NULL);
                                    // RTC time can be read also in struct format:
                                    RTC_TimeDate_t rtcTimeDate;
                                    RTC_GetTimeAndDate(&rtcTimeDate);
                                    // Finally, we configure alarm again to occur in 15 seconds from
                                    // previous alarm
                                    //
                                    // set time to be added to current Alarm time
                                    gRtcAlarm = seconds + 30;
                                    RTC_SetAlarmTime(gRtcAlarm, 0, true);
        }
        else if ((( U8 )('0') <= gDataExchangeRxData) && (( U8 )('9') >= gDataExchangeRxData))
        {
        	BLEGAP_Disconnect(gDataExchangeConnectionHandle);
        	            (void) BLEGAP_SetMode(BLEMODE_NOTDISCOVERABLE | BLEMODE_NOTCONNECTABLE);
        	            snoozing = true;
        	                                    // First RTC time is read into structure
        	                                    time_t seconds = RTC_GetTime(NULL);
        	                                    // RTC time can be read also in struct format:
        	                                    RTC_TimeDate_t rtcTimeDate;
        	                                    RTC_GetTimeAndDate(&rtcTimeDate);
        	                                    // Finally, we configure alarm again to occur in 15 seconds from
        	                                    // previous alarm
        	                                    //
        	                                    // set time to be added to current Alarm time
        	                                    int i;
        	                                    i = FindMe_StringToDecimal(gDataExchangeRxDataAllCharacters);
        	                                    gRtcAlarm = seconds + i;
        	                                    RTC_SetAlarmTime(gRtcAlarm, 0, true);
        	sizeOfString = FindMe_GetTimeStamp( 0, &responseMessage[ 0 ]);
        }
        else
        {
            //
            // Report the time stamp.
            //
            sizeOfString = FindMe_GetTimeStamp( 0, &responseMessage[ 0 ]);
        }

        if ( BLESTATUS_SUCCESS == BLEALPWDATAEXCHANGE_SERVER_SendData( gDataExchangeConnectionHandle,
                &responseMessage[ 0 ], sizeOfString ))
        {
            gDataExchangeTxPending = true;
        }
    }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Task State Functions
//
///////////////////////////////////////////////////////////////////////////////

//
// Perform initializations that will only be executed at boot time.
// Initializations that should be executed when resuming from sleep should
// be placed in the entry funciton.
//
QState FindMe_Init(MyTask_t *me)
{
    QState status;

    uint8_t portNumberStart;
    uint8_t portNumberEnd;

    	// RTC init
    	// This will initialize RTC module and assign callback RTC module will
    	// use to post event(s) later
    	RTC_Init(RTC_SLEEP_TIMER_CHANNEL, RTC_Callback);

    	// RTC enable
        // After RTC initialization we can enable RTC.
        RTC_Enable(true);

        // RTC start time is non-zero as it waits for low-frequency oscillator to
        // start. Start-up time can be up to ~1sec in case of LF XTAL.
        // If LF RC oscillator is used it performs also initial clock calibration.
        //
        // We do not want to block execution here thus we let RTC to post event
        // later signalizing it is ready to use - see event RTC_READY in
        // RtcTask_Run().

    // Unused pins must be properly set to avoid significant current draw due
    // to floating pins.
    //
    // For all unsed GPIO, disable the input, output, and pullup function, and
    // enable the pulldown.  If an external pull is applied to the pin, then the
    // internal pullup and pulldown should both be disabled.  In this example,
    // GPIO7 is not used, and GPIO6 may not be used.  Perform the default
    // initialization, which will be overwritten if the GPIO is used.

#ifdef EXAMPLE_DISABLE_SPI_SLAVE
    // Since the SPI slave peripheral is disabled, ensure the wakeup feature is
    // disabled.
    PML->RegPmlPadWake.r16[0] = 0u; // Disable the wakeup on GPIO0

    portNumberStart =  0u;
    portNumberEnd   = 11u;
#else
    portNumberStart = 6u;
    portNumberEnd   = 7u;
#endif

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

    // Set the Bluetooth stack core callback.
    me->handler.callback = FindMe_CoreCallback;

    // Initialize the Bluetooth stack and register the callback.
    BleStatus bleStatus = BLEMGMT_InitWithHandler(&me->handler);

    if (BLESTATUS_SUCCESS == bleStatus || BLESTATUS_PENDING == bleStatus )
    {
        // Now wait for the stack to finish initialization.
        status = Q_TRAN(FindMe_WaitForStack);
    }
    else
    {
        // There was an error.
        status = Q_TRAN(FindMe_Error);
    }

    // Application specific initialization.
    gConnectionCount       = 0u;
    gpLocalAddr            = NULL;
    gDataExchangeTxPending = false;
    gDataExchangeRxData    = 0u;
    gDataExchangeConnectionHandle = 0u;

    snoozing = false;

    return status;
}


#define EXAMPLE_LOCAL_DEVICE_NAME ("9V Smart Battery")

//
//  Wait for the BLE stack to be initialized.  Execution of this function is
//  scheduled by the task scheduler since this is one of the task's states.
//
QState FindMe_WaitForStack(MyTask_t *me)
{
    QState state;
    U32    status = Q_PAR( me );

    switch( Q_SIG( me ))
    {
        case FINDME_BLE_INIT_SIG:
        {
            if (BLESTATUS_SUCCESS == status)
            {
                // Register a GAP device.
                status = BLEGAP_RegisterDevice(BLEGAPROLE_PERIPHERAL, FindMe_GapCallback);

                if (BLESTATUS_SUCCESS == status)
                {
                    // Set the name of the peripheral.
                    (void)BLEGAP_SetLocalBluetoothDeviceName((U8*) EXAMPLE_LOCAL_DEVICE_NAME,
                        sizeof(EXAMPLE_LOCAL_DEVICE_NAME));
                }

                if (BLESTATUS_SUCCESS == status)
                {
                    status = BLEALPWDATAEXCHANGE_SERVER_Register(FindMe_DataExchangeCallback);
                    ( void ) status; //lint !e438 last assigned value not used
                }

                BLEGAP_SetTXPowerLevelADData(-6.9);

                state = Q_TRAN(FindMe_WaitForRandomAddress);
            }
            else
            {
                state = Q_TRAN(FindMe_Error);
            }
            break;
        }

        default:
            // Let the super class handle this.
            state = Q_SUPER(QHsm_top);
            break;
    }

    return state;
}


//
//  This state is executes after the WaitForStack state and prior to the Run state.
//  Initiate the process of generating a static random address.
//
QState FindMe_WaitForRandomAddress(MyTask_t *me)
{
    BleStatus bleStatus;
    QState status;
    bool   startAdvertising = false;

    switch( Q_SIG(me) )
    {
        case Q_ENTRY_SIG:
            // Get the default address.  This will be set later to the random address upon
            // success.
            ( void ) BLEGAP_GetLocalBdAddr( &gpLocalAddr, &gLocalAddrType );

            bleStatus = BLESMP_GenerateAndSetRandomAddress( BLESM_RANDOMADDRESS_PRIVATE_RESOLVABLE );

            startAdvertising = ( BLESTATUS_PENDING != bleStatus );
            status = Q_HANDLED();
            break;

        case FINDME_BLE_START_ADVERTISING_SIG:
            startAdvertising = true;
            status = Q_HANDLED();
            break;

        default:
            // Let the super class handle this.
            status = Q_SUPER(QHsm_top);
            break;
    }

    if ( startAdvertising )
    {
        (void)BLEGAP_SetModeWithIntervals(BLEMODE_DISCOVERABLE | BLEMODE_CONNECTABLE, 0x0C80);
        status = Q_TRAN(FindMe_Run);
    }

    return status;
}


//
//  This is the primary operational state of the task.  Once in this state, the task
//  remains in this state until sleep is entered.  Process the various signals that
//  will occur while in this state.
//
QState FindMe_Run(MyTask_t *me)
{
    QState eventState;

    switch( Q_SIG(me) )
    {
        case FINDME_BLE_START_ADVERTISING_SIG:
        	(void)BLEGAP_SetModeWithIntervals(BLEMODE_DISCOVERABLE | BLEMODE_CONNECTABLE, 0x0C80);
            eventState = Q_HANDLED();
            break;

        case FINDME_BLE_MODECHANGE_OK_SIG:
            eventState = Q_HANDLED();
            break;

        case FINDME_BLE_MODECHANGE_ERR_SIG:
            eventState = Q_HANDLED();
            break;

        case FINDME_BLE_CONNECTED_SIG:
        case FINDME_BLE_BONDED_SIG:
        	eventState = Q_HANDLED();
            break;

        case FINDME_BLE_DISCONNECTED_SIG:
        	if (snoozing == false)
        	{
        		(void)BLEGAP_SetModeWithIntervals(BLEMODE_DISCOVERABLE | BLEMODE_CONNECTABLE, 0x0C80);
        	}
        	eventState = Q_HANDLED();
        	break;

        case FINDME_BLE_DATA_EXCHANGE_TX_SIG:
            FindMe_DataExchangeTx();
            eventState = Q_HANDLED();
            break;

 /////////////////////////////////////////////////
        case FINDME_RTC_SIG:
                {
                    // RTC short alarm event
                    // This event is post when RTC short alarm period expires. It
                    // could be one shot event or periodic event according to
                    // configuration of Short Alarm.
                    if ((int)RTC_SHORT_ALARM == Q_PAR(me))
                    {
                        // To demonstrate Short alarm function each time Short alarm
                        // event is generated this part of code does:
                        // - toggle LED
                        // - send current time over HCI.



                        // send debug HCI event with current RTC time
        #if (1 == USE_HCI_DEBUG_EVENT)
                        // First RTC time is read in raw format:
                        uint8_t subseconds;
                        time_t seconds = RTC_GetTime(&subseconds);

                        // RTC time can be read also in struct format:
                        RTC_TimeDate_t rtcTimeDate;
                        RTC_GetTimeAndDate(&rtcTimeDate);

                        // Then HCI event packet is composed and RTC time and date is
                        // added.
                        uint8_t eventData[] = {
                            0x7F,  // for debugging purposes
                            // time in raw format
                            subseconds,
                            seconds & 0xFF,
                            (seconds>>8) & 0xFF,
                            (seconds>>16) & 0xFF,
                            (seconds>>24) & 0xFF,
                            // time in decoded format
                            rtcTimeDate.time.subSeconds,
                            rtcTimeDate.time.seconds,
                            rtcTimeDate.time.minutes,
                            rtcTimeDate.time.hours,
                            rtcTimeDate.date.date,
                            rtcTimeDate.date.month,
                            rtcTimeDate.date.year,
                            rtcTimeDate.date.weekDay,
                        };
                        // Finally, HCI event packet is sent over active transport layer
                        (void)Vendor_SendEvent(HCI_EVENT_VENDOR, sizeof(eventData), eventData);
        #endif
                    }


                    // RTC alarm event
                    // This event is post when time and date in RTC alarm matches
                    // current RTC date and time.
                    // It is one-shot event thus if new event is needed Alarm
                    // has to be configured again.
                    else if ((int)RTC_ALARM == Q_PAR(me))
                    {
                    	(void)BLEGAP_SetModeWithIntervals(BLEMODE_DISCOVERABLE | BLEMODE_CONNECTABLE, 0x0C80);
                    	snoozing = false;
                    }


                    // RTC End of day event
                    // This event is post when there is wrap around hour counter
                    // at the end of day (hour counter 23->0).
                    //
                    else if ((int)RTC_END_OF_DAY == Q_PAR(me))
                    {
                        // place code here
                    }


                    // RTC ready
                    // This event is post when RTC is fully started including
                    // low-frequency oscillator and initial calibration in case
                    // of LF RC oscillator is used.
                    // If LF XTAL oscilaltor is used initial calibration is not
                    // performed.
                    else if ((int)RTC_READY == Q_PAR(me))
                    {
                        // If calibration of LF XTAL is required it can be enabled now
                        // since LF XTAL clock is available.
                        //
                        // Calibration of LF XTAL clock is configured and enabled here.
                        // In case of LF RC clock calibration is already enabled and
                        // parameters are updated here.
                        // calibration period: 1min
                        // calibration length: 100*100us = 10ms
        #if (1 == RTC_USE_LF_CLOCK_CALIBRATION)
                        RTC_SetCalibration(true, 1, 100);
        #endif

                        // set RTC time and date:
                        // date: 1.1.2017
                        // time: 0:0:0.00
                        RTC_TimeDate_t  rtcTimeDate;
                        rtcTimeDate.date.year       = 17;
                        rtcTimeDate.date.month      = 1;
                        rtcTimeDate.date.date       = 1;
                        rtcTimeDate.time.hours      = 0;
                        rtcTimeDate.time.minutes    = 0;
                        rtcTimeDate.time.seconds    = 0;
                        rtcTimeDate.time.subSeconds = 0;
                        RTC_SetTimeAndDate( &rtcTimeDate );

                        // alternative vay to set time is to use RTC_SetTime():
                        // for simplicity leap years are NOT assumed
                        //RTC_SetTime((2017 - 2000) * 365 * 24 * 3600, 0);


                        // set short alarm in period mode:
                        // period: 10000ms (10s)
                        // mode: periodic
        #if (1 == RTC_USE_SHORT_ALARM)
                        RTC_SetShortAlarm(10000, RTC_SHORT_ALARM_PERIODIC);
        #endif

                        // set alarm
                        // 5s later based on current time
        #if (1 == RTC_USE_ALARM)
                        gRtcAlarm = RTC_GetTime(NULL) + 5;
                        RTC_SetAlarmTime(gRtcAlarm, 0, true);
                        // alternative vay to set alarm is to use RTC_SetAlarm():
                        // RTC_TimeDate_t  gRtcAlarm;
                        // gRtcAlarm.date.year       = 17;
                        // gRtcAlarm.date.month      = 1;
                        // gRtcAlarm.date.date       = 1;
                        // gRtcAlarm.time.hours      = 0;
                        // gRtcAlarm.time.minutes    = 0;
                        // gRtcAlarm.time.seconds    = 5;
                        // gRtcAlarm.time.subSeconds = 0;
                        // RTC_SetAlarm(&gRtcAlarm, true);
        #endif
                    }


                    // RTC calibration done
                    // This event is post when RTC calibration is enabled and
                    // calibration just finished.
                    // It might be useful to know when calibration finished since
                    // RTC clock is updated based on latest calirbation results.
                    else if ((int)RTC_CALIBRATION_DONE == Q_PAR(me))
                    {
                        // place code here
                    }

                    eventState = Q_HANDLED();
                    break;
                }
        ///////////////////////////////////////

        default:
            // Let the super class handle this.
            eventState = Q_SUPER(QHsm_top);
            break;
    }

    return eventState;
}


QState FindMe_Error(MyTask_t *me)
{
    QState eventState;

    switch( Q_SIG(me) )
    {
        default:
            // Let the super class handle this.
            eventState = Q_SUPER(QHsm_top);
            break;
    }

    return eventState;
}


extern void NO_RETURN ROM_ResetCPU();

/**
 * @brief Override the reset function.
 *
 * Overrride the reset function to capture the reason and correspond address of
 * the exception that triggered the reset.
 */
void NO_RETURN ResetCPU(void)
{
    // An unexpected reset occurred.  Store the reset reason and other debug
    // information.
    gResetReason  = ( uint32_t ) ReadAUX(( ARC_AUX_Register * ) ECR );
    gResetAddress = ( uint32_t ) ReadAUX(( ARC_AUX_Register * ) EFA );

    gPersistentAllocation[ 0 ] = gResetReason;
    gPersistentAllocation[ 1 ] = gResetAddress;

    ROM_ResetCPU();
}
JLI_OVERRIDE(ResetCPU);



/**
 * @brief Entry function for the application.
 *
 * The application entry function is called early in the boot process to
 * allow for early initialization, creation of the application's task, and
 * to set configuration options.  The entry function is also called when the
 * EM9304 resumes from sleep.  The entry function is called prior to the
 * initialization of the peripheral drivers, QP-nano, the link layer, and
 * the Bluetooth stack.  Therefore, care must be taken to not call initialized
 * functions in the entry function.
 *
 * Note that the wrapper and entry function are located in separate source
 * files to ensure that the compiler doesn't perform an optimization that
 * breaks the separation.
 */
void FindMe_Entry(void)
{
    // This entry function is only a wrapper, so the entry functionality can
    // be updated or patched in the future.  A future patch would not include
    // this wrapper since this wrapper will be called, which will in turn call
    // the patchable entry function.  The future patch would include a new
    // patchable entry function.
    ( void ) FindMe_EntryPatchable();
}

// Define the entry function for the application.
ENTRY_FUNCTION(FindMe_Entry);
