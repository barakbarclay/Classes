////////////////////////////////////////////////////////////////////////////////
///
/// @file       projects/findmeplus/findme_entry.c
///
/// @project    EM9304 SOC SDK Example
///
/// @brief      This file contains the entry function for the application.
///             The entry function is called early the boot process prior to
///             the start of the scheduler and before the link layer and BLE
///             stack are started.  Care must be taken not to call these
///             functions that are not yet initialized.
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

//
// Include Files
//
#include <types.h>
#include <macros.h>

// Standard Includes
#include <string.h>

// EM9304 Includes -- the order is important.
#include <em_qpn.h>
#include <bsp.h>
#include <rtc.h>
#include <platform.h>
#include <pml.h>
#include <watchdog.h>

// Application Includes
#include "findme.h"
#include "findme_jli.h"

//
// Variable Declarations
//

// This variable stores all signals being sent to the task.
static SECTION_NONPERSISTENT QEvt gEventQueue[5];

extern const Config_ModuleConfiguration_t gPML_Config;


//
//  Function Prototypes
//

/**
 * @brief Constructor for the task.
 *
 * This will initialize the state machine variable @ref gMyTask.
 *
 * @param me Pointer to the task to construct.
 */
void FindMe_Constructor(MyTask_t *me);

//
// Function Implementation
//

void FindMe_Constructor(MyTask_t *me)
{
    // Tell QP-nano what the initial state is.
    QActive_ctor(&me->super, Q_STATE_CAST(FindMe_Init));
}

/**
 * @brief Entry function content that can be updated with future patches because this
 *        function can be called through the JLI table.  This function is intended to
 *        be called by the actual entry function since the entry function is called
 *        through a function pointer.  Functions called via a function pointer do not
 *        use the JLI table.
 */
void FindMe_EntryPatchable( void )
{
    // Add the task and the task's event queue to QP-nano. This must always
    // occur during boot and resume from sleep because the event queue is not
    // in retention memory.
    ( void ) QF_addTask(&gMyTask.super, &gEventQueue[0],
        Q_DIM(gEventQueue));

#if (1 == RTC_USE_LF_XTAL)
    gPML_Config.lfClkSourceType      = PML_LF_CLK_XTAL_EN;
    gPML_Config.lfClkFreqRatioHf     = 46875;
    gPML_Config.lfClkFreqRatioLf     = 64;
    gPML_Config.lfClkSourceAccuracy  = PML_SCA_100_PPM;
    gPML_Config.rcCalibSkip          = true;
#endif

    // Override configuration settings in lieu of adding a configuration
    // patch to the OTP.  The configuration settings must be updated
    // during the boot and resume from sleep process.  Configuration
    // settings are stored in nonpersistent memory to minimize
    // persistent memory use.  The configuration settings are re-applied
    // during the resume from sleep process.
    Platform_Configuration_t *pPlatform_Config =
        ( Platform_Configuration_t * ) MODIFY_CONST( &gPlatform_Config );

    pPlatform_Config->bleNumberOfConnectionsMax = FINDME_CONNECTIONS_MAX;
    pPlatform_Config->bleNumberOfBondsMax       = FINDME_CONNECTIONS_MAX;
    pPlatform_Config->blePacketPayloadLengthMax = 251;
    pPlatform_Config->bleIsStackRequested       = 1;

    // Disable sleep mode when the JTAG debugger is needed.  If sleep mode
    // is entered, the JTAG controller in the EM9304 is powered down, the
    // debugger will disconnect with a error.  Sleep mode is enabled by default.
    PML_Configuration_t *pPML_Config = (PML_Configuration_t*) MODIFY_CONST (&gPML_Config);
    pPML_Config->sleepModeForbiden = true;

#ifdef EXAMPLE_DISABLE_SPI_SLAVE

    // Disable the SPI slave peripheral.  The following code must be included
    // to disable the SPI slave peripheral.  Because the SPI slave serves as the
    // HCI/ACI transport mechanism by default, it requires additional code to
    // disable the peripheral and transport.
    gSPIS_Config.spisEnabled = false;

    // Set buffer size to zero to ensure data is not added to the SPI buffer.
    gSPIS_Config.rxBufferSize = 0u;
    gSPIS_Config.txBufferSize = 0u;

    // Initialize the transport with the SPI slave disabled.  Disable the
    // compiler warning about the buffers being deprecated.  This is an
    // appropriate action in this instance.
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    SPIS_InitBuffers(gSPIS_Config.pRxBuffer, gSPIS_Config.rxBufferSize,
                     gSPIS_Config.pTxBuffer, gSPIS_Config.txBufferSize);
    #pragma GCC diagnostic pop

#endif    // EXAMPLE_DISABLE_SPI_SLAVE

#ifdef EXAMPLE_ENABLE_WATCHDOG
    Watchdog_SetLimitAndEnable(3000u);  // 30 seconds in 10 ms increments
#endif    // EXAMPLE_ENABLE_WATCHDOG

    // Setup the task after the power on reset.
    if(!PML_DidBootFromSleep())
    {
        // Construct our new QP-nano task.  The task constructor is only called
        // during boot since the retention data is retained during sleep mode.
        FindMe_Constructor(&gMyTask);
    }
}

// Add the function to the JLI table at the specified index.
JLI_SET(JLI_INDEX_FindMe_EntryPatchable, FindMe_EntryPatchable);
