/*******************************************************************************
  Device Header File

  Company:
    Microchip Technology Inc.

  File Name:
    device.h

  Summary:
    This file includes the selected device from within the project.
    The device will provide access to respective device packs.

  Description:
    None

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include <xc.h>
/* XXX
 *  The most current dev packs included in mplabs v5.30 are not up to date with all of the
 *  USBHS configuration registers.
 *
 *  Specifically:
 * 
 *      - USBCRCON register definition is missing
 *      - AD1.\* registered renamed to ADC.\*
 *
 *  The *p32mz2048ech144-fixes.h* file has enough of the required changes to get this
 *  project compiling.
 *
 *  At some point if Microchip updates the dev packs to have the current definitions
 *  then compilation will fail with a compiler warning that numerous names are being
 *  redefined. 
 *
 *  It may be possible to remove this include in device.h:
 *
 */
#include "../src/packs/PIC32MZ2048ECH144_DFP/p32mz2048ech144-fixes.h"
#include <sys/attribs.h>
#include "toolchain_specifics.h"

