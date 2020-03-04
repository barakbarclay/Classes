////////////////////////////////////////////////////////////////////////////////
///
/// @file       projects/findme/findme.h
///
/// @project    EM9304 SOC SDK Example
///
/// @brief      Jump table header file, which idenfies which functions are
///             placed in the jump table, so they can be patched in the future
///             if necessary.  The index defines index into the jump table for
///             the specific function.  Only the entry function is patchable
///             in this application, which allows the entire application to
///             be replaced with a new and improved version.
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

#ifndef FINDME_JLI_H
#define FINDME_JLI_H

//
// JLI table indexes start at 1023 and decrement by 1.
//

#define JLI_INDEX_FindMe_EntryPatchable       1023
#pragma jli_call_fixed(FindMe_EntryPatchable, JLI_INDEX_FindMe_EntryPatchable)


/* Template for a JLI entry.
#define JLI_INDEX_        1023
#pragma jli_call_fixed(,  JLI_INDEX_)
*/

#endif /* FINDME_JLI_H */
