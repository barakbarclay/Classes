////////////////////////////////////////////////////////////////////////////////
///
/// @file       projects/findmeplus/findme.h
///
/// @project    EM9304 SOC SDK Example
///
/// @brief      Example Bluetooth Low Energy example application demonstrating
///             the FindMe and data exchange profiles, and the following
///             features of the EM9304:
///
///               o Data transfer using the data exhange profile
///               o Generating a random Bluetooth local device address
///               o Using the sleep timer as time source
///               o Create a time stamp from the sleep timer
///               o Using the timer peripheral to create a PWM signal to drive
///               o a buzzer
///               o Battery profile
///               o Bluetooth connecting, pairing, and bonding
///               o Multiple connections
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

#ifndef FINDME_MELODY_H
#define FINDME_MELODY_H

/******************************************************************************\
 *  INCLUDE FILES
\******************************************************************************/

#include <em_qpn.h>
#include <BleBase.h>
#include <BleGap.h>
#include <BleEngine.h>

#include <timer.h>
#include <timer_hal.h>
#include <t9304_periph.h>
#include <t9304_uni_tim.h>

/******************************************************************************\
 *  CONSTANTS
\******************************************************************************/

#define GPIO_FINDME_ALERT_BUZZER ( 6 )

// Maximum number of connection to support.
#define FINDME_CONNECTIONS_MAX   ( 4 )

// Uncomment the following line to disable the SPI slave peripheral.
//#ifdef EXAMPLE_DISABLE_SPI_SLAVE

// Enable the watchdog timer.  When enabled, the watchdog functionality will
// default to a timeout of 30 seconds and the watchdog timer will automatically
// be reset prior to the EM9304 entering sleep mode.  If the code enters an
// infinite loop, the sleep mode will not be entered and the watchdog timer will
// reset the EM9304.
//
// When exposed to extremely low temperatures (-40C), the EM9304 may enter a
// state where the CPU fails to operate properly, but remains in an active state.
// Enabling the watchdog timer with the default settings will ensure the EM9304
// is reset when in this abnormal state once the temperatures rises within the
// operational temperature range.
//
// Note that since sleep mode must be disabled, the watchdog timer must also
// be disabled to use the debugger.  Otherwise, the watchdog timer will reset
// the EM9304 causing the debugging session to enter an error condition.
//
//#define EXAMPLE_ENABLE_WATCHDOG


/******************************************************************************\
 *  MACROS
\******************************************************************************/


/******************************************************************************\
 *  TYPE DEFINITION
\******************************************************************************/

typedef struct
{
    // Root structure for all state machines.
    QActive super;

    // Handler for the Bluetooth Low Energy stack.
    BleHandler handler;
} MyTask_t;

/******************************************************************************\
 *  GLOBAL VARIABLES
\******************************************************************************/

extern MyTask_t gMyTask;

/******************************************************************************\
 *  FUNCTION PROTOTYPES
\******************************************************************************/

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
 * @brief Patchable portion of the application entry function.
 *
 * @brief Entry function content that can be updated with future patches because this
 *        function can be called through the JLI table.  This function is intended to
 *        be called by the actual entry function since the entry function is called
 *        through a function pointer.  Functions called via a function pointer do not
 *        use the JLI table.
 */
void FindMe_EntryPatchable( void );


/**
 * @brief The percent of the battery life remaining.
 *
 * @returns The percent of the battery remaining based on the course battery
 *          measurement.  This may need to be adjusted based on the specific
 *          application.
 */
uint8_t GetBatteryPercent(void);

#endif  // FINDME_MELODY_H
