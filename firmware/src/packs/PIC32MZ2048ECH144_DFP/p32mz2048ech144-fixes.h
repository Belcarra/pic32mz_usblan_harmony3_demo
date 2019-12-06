/*-------------------------------------------------------------------------
 * PIC32MZ2048ECH144 processor header
 * Build date : Oct 15 2019
 *
 * Copyright (c) 2019, Microchip Technology Inc. and its subsidiaries ("Microchip")
 * All rights reserved.
 * 
 * This software is developed by Microchip Technology Inc. and its
 * subsidiaries ("Microchip").
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * 1.      Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 * 2.      Redistributions in binary form must reproduce the above 
 *         copyright notice, this list of conditions and the following 
 *         disclaimer in the documentation and/or other materials provided 
 *         with the distribution.
 * 3.      Microchip's name may not be used to endorse or promote products
 *         derived from this software without specific prior written 
 *         permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */


#pragma once
#ifndef __32MZ2048ECH144_FIXES_H
#define __32MZ2048ECH144_FIXES_H


#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


#define USBCRCON USBCRCON
extern volatile uint32_t   USBCRCON __attribute__((section("sfrs"), address(0xBF884000)));
typedef struct {
  uint32_t USBWKUPEN:1;
  uint32_t USBRIE:1;
  uint32_t USBIE:1;
  uint32_t SENDMONEN:1;
  uint32_t BSVALMONEN:1;
  uint32_t ASVALMONEN:1;
  uint32_t VBUSMONEN:1;
  uint32_t PHYIDEN:1;
  uint32_t USBIDVAL:1;
  uint32_t USBIDOVEN:1;
  uint32_t :14;
  uint32_t USBWKUP:1;
  uint32_t USBRF:1;
  uint32_t USBIF:1;
} __USBCRCONbits_t;
extern volatile __USBCRCONbits_t USBCRCONbits __asm__ ("USBCRCON") __attribute__((section("sfrs"), address(0xBF884000)));

#define _USBCRCON_USBWKUPEN_POSITION             0x00000000
#define _USBCRCON_USBWKUPEN_MASK                 0x00000001
#define _USBCRCON_USBWKUPEN_LENGTH               0x00000001

#define _USBCRCON_USBRIE_POSITION                0x00000001
#define _USBCRCON_USBRIE_MASK                    0x00000002
#define _USBCRCON_USBRIE_LENGTH                  0x00000001

#define _USBCRCON_USBIE_POSITION                 0x00000002
#define _USBCRCON_USBIE_MASK                     0x00000004
#define _USBCRCON_USBIE_LENGTH                   0x00000001

#define _USBCRCON_SENDMONEN_POSITION             0x00000003
#define _USBCRCON_SENDMONEN_MASK                 0x00000008
#define _USBCRCON_SENDMONEN_LENGTH               0x00000001

#define _USBCRCON_BSVALMONEN_POSITION            0x00000004
#define _USBCRCON_BSVALMONEN_MASK                0x00000010
#define _USBCRCON_BSVALMONEN_LENGTH              0x00000001

#define _USBCRCON_ASVALMONEN_POSITION            0x00000005
#define _USBCRCON_ASVALMONEN_MASK                0x00000020
#define _USBCRCON_ASVALMONEN_LENGTH              0x00000001

#define _USBCRCON_VBUSMONEN_POSITION             0x00000006
#define _USBCRCON_VBUSMONEN_MASK                 0x00000040
#define _USBCRCON_VBUSMONEN_LENGTH               0x00000001

#define _USBCRCON_PHYIDEN_POSITION               0x00000007
#define _USBCRCON_PHYIDEN_MASK                   0x00000080
#define _USBCRCON_PHYIDEN_LENGTH                 0x00000001

#define _USBCRCON_USBIDVAL_POSITION              0x00000008
#define _USBCRCON_USBIDVAL_MASK                  0x00000100
#define _USBCRCON_USBIDVAL_LENGTH                0x00000001

#define _USBCRCON_USBIDOVEN_POSITION             0x00000009
#define _USBCRCON_USBIDOVEN_MASK                 0x00000200
#define _USBCRCON_USBIDOVEN_LENGTH               0x00000001

#define _USBCRCON_USBWKUP_POSITION               0x00000018
#define _USBCRCON_USBWKUP_MASK                   0x01000000
#define _USBCRCON_USBWKUP_LENGTH                 0x00000001

#define _USBCRCON_USBRF_POSITION                 0x00000019
#define _USBCRCON_USBRF_MASK                     0x02000000
#define _USBCRCON_USBRF_LENGTH                   0x00000001

#define _USBCRCON_USBIF_POSITION                 0x0000001A
#define _USBCRCON_USBIF_MASK                     0x04000000
#define _USBCRCON_USBIF_LENGTH                   0x00000001



#define _ADC_VECTOR                             44
#define _ADC_DC1_VECTOR                         46
#define _ADC_DC2_VECTOR                         47
#define _ADC_DC3_VECTOR                         48
#define _ADC_DC4_VECTOR                         49
#define _ADC_DC5_VECTOR                         50
#define _ADC_DC6_VECTOR                         51
#define _ADC_DF1_VECTOR                         52
#define _ADC_DF2_VECTOR                         53
#define _ADC_DF3_VECTOR                         54
#define _ADC_DF4_VECTOR                         55
#define _ADC_DF5_VECTOR                         56
#define _ADC_DF6_VECTOR                         57
#define _ADC_DATA0_VECTOR                       59
#define _ADC_DATA1_VECTOR                       60
#define _ADC_DATA2_VECTOR                       61
#define _ADC_DATA3_VECTOR                       62
#define _ADC_DATA4_VECTOR                       63
#define _ADC_DATA5_VECTOR                       64
#define _ADC_DATA6_VECTOR                       65
#define _ADC_DATA7_VECTOR                       66
#define _ADC_DATA8_VECTOR                       67
#define _ADC_DATA9_VECTOR                       68
#define _ADC_DATA10_VECTOR                      69
#define _ADC_DATA11_VECTOR                      70
#define _ADC_DATA12_VECTOR                      71
#define _ADC_DATA13_VECTOR                      72
#define _ADC_DATA14_VECTOR                      73
#define _ADC_DATA15_VECTOR                      74
#define _ADC_DATA16_VECTOR                      75
#define _ADC_DATA17_VECTOR                      76
#define _ADC_DATA18_VECTOR                      77
#define _ADC_DATA19_VECTOR                      78
#define _ADC_DATA20_VECTOR                      79
#define _ADC_DATA21_VECTOR                      80
#define _ADC_DATA22_VECTOR                      81
#define _ADC_DATA23_VECTOR                      82
#define _ADC_DATA24_VECTOR                      83
#define _ADC_DATA25_VECTOR                      84
#define _ADC_DATA26_VECTOR                      85
#define _ADC_DATA27_VECTOR                      86
#define _ADC_DATA28_VECTOR                      87
#define _ADC_DATA29_VECTOR                      88
#define _ADC_DATA30_VECTOR                      89
#define _ADC_DATA31_VECTOR                      90
#define _ADC_DATA32_VECTOR                      91
#define _ADC_DATA33_VECTOR                      92
#define _ADC_DATA34_VECTOR                      93
#define _ADC_DATA35_VECTOR                      94
#define _ADC_DATA36_VECTOR                      95
#define _ADC_DATA37_VECTOR                      96
#define _ADC_DATA38_VECTOR                      97
#define _ADC_DATA39_VECTOR                      98
#define _ADC_DATA40_VECTOR                      99
#define _ADC_DATA41_VECTOR                      100
#define _ADC_DATA42_VECTOR                      101
#define _ADC_DATA43_VECTOR                      102
#define _ADC_DATA44_VECTOR                      103



#endif
