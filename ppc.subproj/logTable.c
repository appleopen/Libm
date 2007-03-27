/*
 * Copyright (c) 2002 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*******************************************************************************
*                                                                              *
*     File logTable.c,                                                         *
*     This file contains the uint32_t array logTable[] used in the        *
*     approximation for log, log2, log10, log1p and Power functions.           *
*                                                                              *
*     Copyright � 1997-2001 Apple Computer, Inc.  All rights reserved.         *
*                                                                              *
*     Written by A. Sazegari, started on April 1997.                           *
*                                                                              *
*     A MathLib v4 file.                                                       *
*                                                                              *
*      Change History (most recent first):                                     *
*                                                                              *
*     November 06 2001: commented out warning about Intel architectures.       *
*     October  08 2001: changed compiler errors to warnings.                   *
*                       made logTable a const private_extern.                  *
*     Sept     10 2001: added macros to detect PowerPC and correct compiler.   *
*     Sept     09 2001: added more comments.                                   *
*     Sept     06 2001: added #ifdef __ppc__.                                  *
*     April    28 1997: port of the ibm/taligent logTable entries.             *
*                                                                              *
*     W A R N I N G:                                                           *
*     These routines require a 64-bit double precision IEEE-754 model.         *
*     They are written for PowerPC only and are expecting the compiler         *
*     to generate the correct sequence of multiply-add fused instructions.     *
*                                                                              *
*     These routines are not intended for 32-bit Intel architectures.          *
*                                                                              *
*     A version of gcc higher than 932 is required.                            *
*                                                                              *
*     GCC compiler options:                                                    *
*           optimization level 3 (-O3)                                         *
*           -fschedule-insns -finline-functions -funroll-all-loops             *
*                                                                              *
*******************************************************************************/
#include "stdint.h"

__private_extern__
const uint32_t logTable[] __attribute__ ((aligned(8))) = 
      { 
/*i = 0*/                                                                       
      0x3FE81000, 0x0029D0FA, 0x3FF54725, 0xE69688D3, 0xBFD23EC5, 0x98AF81D4, 
      0x3FE83000, 0x0029AA1F, 0x3FF52AFF, 0x56838EB8, 0xBFD1E9E1, 0x671A5B74, 
      0x3FE85000, 0x00313D0A, 0x3FF50F22, 0xE0E71E79, 0xBFD1956D, 0x3B1A2597, 
      0x3FE87000, 0x001372E5, 0x3FF4F38F, 0x62CC9FF7, 0xBFD14167, 0xEF038828, 
      0x3FE89000, 0x001CDE1B, 0x3FF4D843, 0xBEC3ACBD, 0xBFD0EDD0, 0x606C48DC, 
      0x3FE8B000, 0x00297513, 0x3FF4BD3E, 0xDD83BC26, 0xBFD09AA5, 0x727B4D71, 
      0x3FE8D000, 0x0014C18E, 0x3FF4A27F, 0xAD64BE64, 0xBFD047E6, 0x0CA8FA3A, 
      0x3FE8F000, 0x0015D3E2, 0x3FF48805, 0x21EF4FEF, 0xBFCFEB22, 0x3379FE23, 
      0x3FE91000, 0x0026073F, 0x3FF46DCE, 0x343A6103, 0xBFCF474B, 0x128BBA00, 
      0x3FE93000, 0x00255A5B, 0x3FF453D9, 0xE2A95180, 0xBFCEA444, 0x9E46D828, 
      0x3FE95000, 0x00285F27, 0x3FF43A27, 0x308BAB81, 0xBFCE020C, 0xC5573403, 
      0x3FE97000, 0x00196E3C, 0x3FF420B5, 0x264A3A02, 0xBFCD60A1, 0x7F103DF7, 
      0x3FE99000, 0x00149CB4, 0x3FF40782, 0xD0FE3EDF, 0xBFCCC000, 0xC974061A, 
      0x3FE9B000, 0x001BAF93, 0x3FF3EE8F, 0x42903385, 0xBFCC2028, 0xAA8E048C, 
      0x3FE9D000, 0x0027FC5C, 0x3FF3D5D9, 0x918BBBBF, 0xBFCB8117, 0x2FF1DB60, 
      0x3FE9F000, 0x0024313F, 0x3FF3BD60, 0xD9079E01, 0xBFCAE2CA, 0x6EB49066, 
      0x3FEA1000, 0x001ACE5A, 0x3FF3A524, 0x38669383, 0xBFCA4540, 0x82630427, 
      0x3FEA3000, 0x00122129, 0x3FF38D22, 0xD3587F83, 0xBFC9A877, 0x8D930D07, 
      0x3FEA5000, 0x001F0679, 0x3FF3755B, 0xD1B2545E, 0xBFC90C6D, 0xB965CFD5, 
      0x3FEA7000, 0x002067B1, 0x3FF35DCE, 0x5F876E13, 0xBFC87121, 0x36B40519, 
      0x3FEA9000, 0x001B2FDA, 0x3FF34679, 0xACCC58CD, 0xBFC7D690, 0x3C2C5884, 
      0x3FEAB000, 0x0028C3FD, 0x3FF32F5C, 0xED4CCFCB, 0xBFC73CB9, 0x068C4BA9, 
      0x3FEAD000, 0x002551E6, 0x3FF31877, 0x58CF5787, 0xBFC6A399, 0xDA09AA3A, 
      0x3FEAF000, 0x002A6E2C, 0x3FF301C8, 0x2AA61215, 0xBFC60B30, 0xFFE6F63E, 
      0x3FEB1000, 0x0012C8E5, 0x3FF2EB4E, 0xA1F1AF6F, 0xBFC5737C, 0xC8A8B3CB, 
      0x3FEB3000, 0x002900DB, 0x3FF2D50A, 0x0110E9AF, 0xBFC4DC7B, 0x88BAB61A, 
      0x3FEB5000, 0x0021C9F4, 0x3FF2BEF9, 0x8E430627, 0xBFC4462B, 0x9D2B59DD, 
      0x3FEB7000, 0x0013B33D, 0x3FF2A91C, 0x92E65B0D, 0xBFC3B08B, 0x66FC0B35, 
      0x3FEB9000, 0x001AF6AA, 0x3FF29372, 0x5BA5D88A, 0xBFC31B99, 0x4CBD179C, 
      0x3FEBB000, 0x00260E7B, 0x3FF27DFA, 0x3888636F, 0xBFC28753, 0xBB61BBEA, 
      0x3FEBD000, 0x001C0820, 0x3FF268B3, 0x7CC3734D, 0xBFC1F3B9, 0x25715AF4, 
      0x3FEBF000, 0x001EBC63, 0x3FF2539D, 0x7E7D4E24, 0xBFC160C8, 0x01BE5574, 
      0x3FEC1000, 0x001902A9, 0x3FF23EB7, 0x97071DA2, 0xBFC0CE7E, 0xCD5AAE6F, 
      0x3FEC3000, 0x0024932F, 0x3FF22A01, 0x22888083, 0xBFC03CDC, 0x09ABD5A6, 
      0x3FEC5000, 0x0013D8A9, 0x3FF21579, 0x803BA8C2, 0xBFBF57BC, 0x7CDC92D1, 
      0x3FEC7000, 0x001C5240, 0x3FF20120, 0x11EF31C8, 0xBFBE3707, 0xED31544C, 
      0x3FEC9000, 0x0018D480, 0x3FF1ECF4, 0x3C702302, 0xBFBD1797, 0x87430759, 
      0x3FECB000, 0x00150CCE, 0x3FF1D8F5, 0x6721322C, 0xBFBBF968, 0x75E3F1BC, 
      0x3FECD000, 0x0017661A, 0x3FF1C522, 0xFC0E71F6, 0xBFBADC77, 0xED8B044D, 
      0x3FECF000, 0x0012279F, 0x3FF1B17C, 0x67E7A12F, 0xBFB9C0C3, 0x2CAC8965, 
      0x3FED1000, 0x001E5763, 0x3FF19E01, 0x19CDAD28, 0xBFB8A647, 0x79869857, 
      0x3FED3000, 0x001CD50E, 0x3FF18AB0, 0x837ED7D3, 0xBFB78D02, 0x2540A07F, 
      0x3FED5000, 0x0020A798, 0x3FF1778A, 0x19086124, 0xBFB674F0, 0x88192A2B, 
      0x3FED7000, 0x001D78AD, 0x3FF1648D, 0x50EAC854, 0xBFB55E10, 0x040DB811, 
      0x3FED9000, 0x001E48FB, 0x3FF151B9, 0xA3EC17B0, 0xBFB4485E, 0x02D59DD1, 
      0x3FEDB000, 0x001AF138, 0x3FF13F0E, 0x8D24A05A, 0xBFB333D7, 0xF72FEB7D, 
      0x3FEDD000, 0x0010AD74, 0x3FF12C8B, 0x89E4252E, 0xBFB2207B, 0x5BE91ED0, 
      0x3FEDF000, 0x001AB6D1, 0x3FF11A30, 0x1998055D, 0xBFB10E45, 0xB2E67875, 
      0x3FEE1000, 0x0013E0C6, 0x3FF107FB, 0xBDF5CD94, 0xBFAFFA69, 0x10590729, 
      0x3FEE3000, 0x001883FD, 0x3FF0F5ED, 0xFAA55F81, 0xBFADDA8A, 0xDAC82163, 
      0x3FEE5000, 0x0015539A, 0x3FF0E406, 0x55767DDE, 0xBFABBCEB, 0xFB00BB84, 
      0x3FEE7000, 0x0017E427, 0x3FF0D244, 0x56286A1F, 0xBFA9A187, 0xB3E1FC83, 
      0x3FEE9000, 0x00155A73, 0x3FF0C0A7, 0x867F8D0E, 0xBFA78859, 0x58CFBEBB, 
      0x3FEEB000, 0x0018539F, 0x3FF0AF2F, 0x7221B2D9, 0xBFA5715C, 0x4A6DEF53, 
      0x3FEED000, 0x0017674A, 0x3FF09DDB, 0xA6A2E461, 0xBFA35C8B, 0xF91C4D5E, 
      0x3FEEF000, 0x00161C41, 0x3FF08CAB, 0xB3699206, 0xBFA149E3, 0xE2927035, 
      0x3FEF1000, 0x0013FD64, 0x3FF07B9F, 0x29AE4F68, 0xBF9E72BF, 0x2580D378, 
      0x3FEF3000, 0x00101055, 0x3FF06AB5, 0x9C709E49, 0xBF9A55F5, 0x46B6554E, 
      0x3FEF5000, 0x00113323, 0x3FF059EE, 0xA0697A38, 0xBF963D61, 0x763691D7, 
      0x3FEF7000, 0x00124587, 0x3FF04949, 0xCC0CED91, 0xBF9228FB, 0x1D970718, 
      0x3FEF9000, 0x00117D16, 0x3FF038C6, 0xB7794AF4, 0xBF8C3173, 0x805895C6, 
      0x3FEFB000, 0x00118ED5, 0x3FF02864, 0xFC6E35F2, 0xBF841929, 0xF4F968B6, 

/* Log for table entries 61 < i < 66 are computed directly from a polynomial.    
0x3FEFD000, 0x001016E4, 0x3FF01824, 0x3649566C, 0xBF781212, 0x0C40D5F4, 
0x3FEFF000, 0x000FD3BE, 0x3FF00804, 0x01F90EB1, 0xBF600401, 0x45F9DCC8, 
0x3FF00800, 0x000FDC91, 0x3FEFF007, 0xFBE26580, 0x3F5FF802, 0xE8FDAB99, 
0x3FF01800, 0x000F8871, 0x3FEFD047, 0x948259EB, 0x3F77EE11, 0xFB4975A9, 
*/
      0x3ff00000, 0x00000000, 0x3ff00000, 0x00000000, 0x00000000, 0x00000000, 
/* i = 64 */
      0x3ff00000, 0x00000000, 0x3ff00000, 0x00000000, 0x00000000, 0x00000000, 
      0x3ff00000, 0x00000000, 0x3ff00000, 0x00000000, 0x00000000, 0x00000000, 
      0x3ff00000, 0x00000000, 0x3ff00000, 0x00000000, 0x00000000, 0x00000000, 
      0x3FF02800, 0x000FEE6B, 0x3FEFB0C6, 0x10B6A965, 0x3F83E729, 0x650924A1, 
      0x3FF03800, 0x000FBD7E, 0x3FEF9182, 0xB66298A0, 0x3F8BCF71, 0x3437CACB, 
      0x3FF04800, 0x000FEF7B, 0x3FEF727C, 0xCE408B87, 0x3F91D7F7, 0xEF892C84, 
      0x3FF05800, 0x000FC95F, 0x3FEF53B3, 0xA3DBDDFD, 0x3F95C45A, 0x5595EB46, 
      0x3FF06800, 0x001006D2, 0x3FEF3526, 0x857D10A0, 0x3F99ACE7, 0x59051396, 
      0x3FF07800, 0x000FF34A, 0x3FEF16D4, 0xC42202C9, 0x3F9D91A6, 0x70340104, 
      0x3FF08800, 0x001039F4, 0x3FEEF8BD, 0xB36B8528, 0x3FA0B94F, 0x7E0FF039, 
      0x3FF09800, 0x000FA856, 0x3FEEDAE0, 0xA996B668, 0x3FA2A7EC, 0x23F8059E, 
      0x3FF0A800, 0x00110424, 0x3FEEBD3C, 0xFF65A3C3, 0x3FA494AC, 0xC558A171, 
      0x3FF0B800, 0x00128EDA, 0x3FEE9FD2, 0x1022E94D, 0x3FA67F94, 0xF2CD1118, 
      0x3FF0C800, 0x0010AE4D, 0x3FEE829F, 0x3990A123, 0x3FA868A8, 0x3280E6B8, 
      0x3FF0D800, 0x00126017, 0x3FEE65A3, 0xDBC62432, 0x3FAA4FEA, 0x01D26093, 
      0x3FF0E800, 0x0011E997, 0x3FEE48DF, 0x594F1D47, 0x3FAC355D, 0xD2B09832, 
      0x3FF0F800, 0x00130FB2, 0x3FEE2C51, 0x16F80938, 0x3FAE1907, 0x0E6683AE, 
      0x3FF10800, 0x0012E9EF, 0x3FEE0FF8, 0x7BE07E5A, 0x3FAFFAE9, 0x13D42B16, 
      0x3FF11800, 0x0015A503, 0x3FEDF3D4, 0xF157F7A3, 0x3FB0ED83, 0x9C994E7B, 
      0x3FF12800, 0x00121A8C, 0x3FEDD7E5, 0xE2F75B7D, 0x3FB1DCB2, 0x64E93C79, 
      0x3FF13800, 0x00118740, 0x3FEDBC2A, 0xBE5F2CCE, 0x3FB2CB02, 0x84FA785F, 
      0x3FF14800, 0x001585B8, 0x3FEDA0A2, 0xF35B553B, 0x3FB3B875, 0x99F08A7D, 
      0x3FF15800, 0x00139574, 0x3FED854D, 0xF3E082F4, 0x3FB4A50D, 0x3BC2C0A0, 
      0x3FF16800, 0x00152EF2, 0x3FED6A2B, 0x33CBA813, 0x3FB590CA, 0xFF27A95F, 
      0x3FF17800, 0x0014EE12, 0x3FED4F3A, 0x29144BE4, 0x3FB67BB0, 0x73A17A1D, 
      0x3FF18800, 0x00107FFE, 0x3FED347A, 0x4BA4A088, 0x3FB765BF, 0x2497AEE7, 
      0x3FF19800, 0x000F4AF1, 0x3FED19EB, 0x1545BD10, 0x3FB84EF8, 0x99C6ACFF, 
      0x3FF1A800, 0x00138814, 0x3FECFF8C, 0x01AFE4BC, 0x3FB9375E, 0x56748F93, 
      0x3FF1B800, 0x000FC180, 0x3FECE55C, 0x8E92C720, 0x3FBA1EF1, 0xD8E9C0B9, 
      0x3FF1C800, 0x00148E3C, 0x3FECCB5C, 0x3B4224BD, 0x3FBB05B4, 0x9D16355F, 
      0x3FF1D800, 0x00163EB8, 0x3FECB18A, 0x890D1905, 0x3FBBEBA8, 0x19538C28, 
      0x3FF1E800, 0x00102DE2, 0x3FEC97E6, 0xFAFC0E63, 0x3FBCD0CD, 0xC0736312, 
      0x3FF1F800, 0x001323F9, 0x3FEC7E71, 0x15B27475, 0x3FBDB527, 0x02988ADA, 
      0x3FF20800, 0x0015CF55, 0x3FEC6528, 0x5FB30FC7, 0x3FBE98B5, 0x4A9CBA2C, 
      0x3FF21800, 0x00128384, 0x3FEC4C0C, 0x6128765D, 0x3FBF7B79, 0xFFC96F0F, 
      0x3FF22800, 0x001793DE, 0x3FEC331C, 0xA3C477C6, 0x3FC02EBB, 0x436575A3, 
      0x3FF23800, 0x001339E9, 0x3FEC1A58, 0xB30A4D48, 0x3FC09F56, 0x1F6E2DC5, 
      0x3FF24800, 0x0019428D, 0x3FEC01C0, 0x1BDB0D5E, 0x3FC10F8E, 0x42D6169A, 
      0x3FF25800, 0x001858A4, 0x3FEBE952, 0x6CE25E8A, 0x3FC17F64, 0x59A68885, 
      0x3FF26800, 0x0014654C, 0x3FEBD10F, 0x36357EF9, 0x3FC1EED9, 0x0EBB987E, 
      0x3FF27800, 0x000F4324, 0x3FEBB8F6, 0x0970ABC4, 0x3FC25DED, 0x0B2631C0, 
      0x3FF28800, 0x001AA24D, 0x3FEBA106, 0x7995CED9, 0x3FC2CCA0, 0xF6ADEA08, 
      0x3FF29800, 0x0015B655, 0x3FEB8940, 0x1B691894, 0x3FC33AF5, 0x760C860E, 
      0x3FF2A800, 0x00167689, 0x3FEB71A2, 0x84CD6000, 0x3FC3A8EB, 0x2DCBC1B8, 
      0x3FF2B800, 0x00101231, 0x3FEB5A2D, 0x4D438C5F, 0x3FC41682, 0xBFE060DA, 
      0x3FF2C800, 0x0010014D, 0x3FEB42E0, 0x0D8A34BE, 0x3FC483BC, 0xCD53F83B, 
      0x3FF2D800, 0x001C2A51, 0x3FEB2BBA, 0x5FC9CD94, 0x3FC4F099, 0xF561823C, 
      0x3FF2E800, 0x000F4F6C, 0x3FEB14BB, 0xDFC172C9, 0x3FC55D1A, 0xD48AD4E4, 
      0x3FF2F800, 0x000F446F, 0x3FEAFDE4, 0x2A16FAF7, 0x3FC5C940, 0x07C0789A, 
      0x3FF30800, 0x0019810A, 0x3FEAE732, 0xDCF81C66, 0x3FC6350A, 0x29563039, 
      0x3FF31800, 0x00157748, 0x3FEAD0A7, 0x97F9510F, 0x3FC6A079, 0xD18791E4, 
      0x3FF32800, 0x0016FD06, 0x3FEABA41, 0xFBB2D2AB, 0x3FC70B8F, 0x983B458D, 
      0x3FF33800, 0x000F5A9B, 0x3FEAA401, 0xAA2AD21D, 0x3FC7764C, 0x12F563A0, 
      0x3FF34800, 0x001A54E7, 0x3FEA8DE6, 0x4664A80B, 0x3FC7E0AF, 0xD6DF906E, 
      0x3FF35800, 0x00179919, 0x3FEA77EF, 0x74EA0CAD, 0x3FC84ABB, 0x762277EB, 
      0x3FF36800, 0x0018FD92, 0x3FEA621C, 0xDB2D9639, 0x3FC8B46F, 0x82C83789, 
      0x3FF37800, 0x00173505, 0x3FEA4C6E, 0x1FEDCD09, 0x3FC91DCC, 0x8CCC9FED, 
      0x3FF38800, 0x0017D81C, 0x3FEA36E2, 0xEAFC4261, 0x3FC986D3, 0x231DC4AE, 
      0x3FF39800, 0x0011AFE9, 0x3FEA217A, 0xE55E68A2, 0x3FC9EF83, 0xD2EA25A9, 
      0x3FF3A800, 0x001AF16A, 0x3FEA0C35, 0xB90B19C2, 0x3FCA57DF, 0x28D3C13C, 
      0x3FF3B800, 0x0015ECE8, 0x3FE9F713, 0x115521E2, 0x3FCABFE5, 0xAED46543, 
      0x3FF3C800, 0x00149878, 0x3FE9E212, 0x9A626C31, 0x3FCB2797, 0xEECB7700, 
      0x3FF3D800, 0x0018E359, 0x3FE9CD34, 0x017C76FD, 0x3FCB8EF6, 0x70E295EE, 
      0x3FF3E800, 0x00165C98, 0x3FE9B876, 0xF5094927, 0x3FCBF601, 0xBB9E0ED4, 
      0x3FF3F800, 0x0019A694, 0x3FE9A3DB, 0x24540C0C, 0x3FCC5CBA, 0x54DF5003, 
      0x3FF40800, 0x0011A6DE, 0x3FE98F60, 0x3FCFEA82, 0x3FCCC320, 0xC08830A4, 
      0x3FF41800, 0x001C2B2B, 0x3FE97B05, 0xF8B1ADF4, 0x3FCD2935, 0x826A240D, 
      0x3FF42800, 0x00170224, 0x3FE966CC, 0x01796DCF, 0x3FCD8EF9, 0x1B853A0B, 
      0x3FF43800, 0x001B0A46, 0x3FE952B2, 0x0D5210C5, 0x3FCDF46C, 0x0D1D5C6B, 
      0x3FF44800, 0x001CD556, 0x3FE93EB7, 0xD0868376, 0x3FCE598E, 0xD65E77A0, 
      0x3FF45800, 0x001AAB04, 0x3FE92ADD, 0x0043ADB1, 0x3FCEBE61, 0xF58545A9, 
      0x3FF46800, 0x001431E6, 0x3FE91721, 0x529F6D41, 0x3FCF22E5, 0xE7ADBD02, 
      0x3FF47800, 0x001D0793, 0x3FE90384, 0x7E7E5509, 0x3FCF871B, 0x294AD923, 
      0x3FF48800, 0x0018C61E, 0x3FE8F006, 0x3BE377C3, 0x3FCFEB02, 0x34807B16, 
      0x3FF49800, 0x00106DA6, 0x3FE8DCA6, 0x43840EBD, 0x3FD0274D, 0xC19F313E, 
      0x3FF4A800, 0x001D9735, 0x3FE8C964, 0x4EDE6DC9, 0x3FD058F3, 0xC75F9A4F, 
      0x3FF4B800, 0x0022EDAD, 0x3FE8B640, 0x188C9713, 0x3FD08A73, 0x66E83C6D, 
      0x3FF4C800, 0x002112B4, 0x3FE8A339, 0x5BDA5458, 0x3FD0BBCC, 0xDB72FFA3, 
      0x3FF4D800, 0x0014C53D, 0x3FE8904F, 0xD4EAFA18, 0x3FD0ED00, 0x5FA54409, 
      0x3FF4E800, 0x00176810, 0x3FE87D83, 0x40900349, 0x3FD11E0E, 0x2DF54421, 
      0x3FF4F800, 0x001EF369, 0x3FE86AD3, 0x5C919004, 0x3FD14EF6, 0x7FE6DFE0, 
      0x3FF50800, 0x001E9A4A, 0x3FE8583F, 0xE7845383, 0x3FD17FB9, 0x8E7229D1, 
      0x3FF51800, 0x0020F514, 0x3FE845C8, 0xA0A8649C, 0x3FD1B057, 0x92547A01, 
      0x3FF52800, 0x00179EC3, 0x3FE8336D, 0x481E752D, 0x3FD1E0D0, 0xC37E8ADE, 
      0x3FF53800, 0x001AE1B8, 0x3FE8212D, 0x9E9BAE52, 0x3FD21125, 0x59D72AB0, 
      0x3FF54800, 0x00189D61, 0x3FE80F09, 0x65C3D800, 0x3FD24155, 0x8C471A6B, 
      0x3FF55800, 0x001658C1, 0x3FE7FD00, 0x5FDAE3EE, 0x3FD27161, 0x91828720, 
      0x3FF56800, 0x0012606E, 0x3FE7EB12, 0x4FE57CBE, 0x3FD2A149, 0x9FAD1D00, 
      0x3FF57800, 0x001F1A3E, 0x3FE7D93E, 0xF987BE65, 0x3FD2D10D, 0xECAD3D92, 
      0x3FF58800, 0x00246380, 0x3FE7C786, 0x21486476, 0x3FD300AE, 0xAD725EA9, 
      0x3FF59800, 0x001CA034, 0x3FE7B5E7, 0x8C49C89F, 0x3FD3302C, 0x16AD3D03, 
      0x3FF5A800, 0x0020E567, 0x3FE7A463, 0x003AA7E6, 0x3FD35F86, 0x5CF460BC, 
      0x3FF5B800, 0x0020D78E, 0x3FE792F8, 0x43A2E3FB, 0x3FD38EBD, 0xB3EF9A32, 
      0x3FF5C800, 0x0014B679, 0x3FE781A7, 0x1DA9BD0C, 0x3FD3BDD2, 0x4EEE27B5, 
      0x3FF5D800, 0x00225A72, 0x3FE7706F, 0x55EBFC07, 0x3FD3ECC4, 0x61540628, 
      0x3FF5E800, 0x00227775, 0x3FE75F50, 0xB4FDEB84, 0x3FD41B94, 0x1D32BE05, 
      0x3FF5F800, 0x001CDF34, 0x3FE74E4B, 0x03E2D3D7, 0x3FD44A41, 0xB4B7E0C0, 
      0x3FF60800, 0x001E7ECB, 0x3FE73D5E, 0x0C386EF3, 0x3FD478CD, 0x59B24A4E, 
      0x3FF61800, 0x002475F2, 0x3FE72C89, 0x984ABAD0, 0x3FD4A737, 0x3D5697AB, 
      0x3FF62800, 0x00245A04, 0x3FE71BCD, 0x7308AA05, 0x3FD4D57F, 0x9058E3A0, 
      0x3FF63800, 0x0011963C, 0x3FE70B29, 0x67FC299A, 0x3FD503A6, 0x82FDC529, 
      0x3FF64800, 0x0017EA9A, 0x3FE6FA9D, 0x430B992D, 0x3FD531AC, 0x45C399DF, 
      0x3FF65800, 0x00173920, 0x3FE6EA28, 0xD100E36B, 0x3FD55F91, 0x07E6C3B7, 
      0x3FF66800, 0x001F7C70, 0x3FE6D9CB, 0xDF06CE96, 0x3FD58D54, 0xF8C7F258, 
      0x3FF67800, 0x0023F0E2, 0x3FE6C986, 0x3AF640DF, 0x3FD5BAF8, 0x47107AE6, 
      0x3FF68800, 0x0014180E, 0x3FE6B957, 0xB33A33F4, 0x3FD5E87B, 0x20FBA8F9, 
      0x3FF69800, 0x0026E61D, 0x3FE6A940, 0x16823C47, 0x3FD615DD, 0xB52CF101, 
      0x3FF6A800, 0x00125275, 0x3FE6993F, 0x348A80A0, 0x3FD64320, 0x3078097B, 
      0x3FF6B800, 0x0024D032, 0x3FE68954, 0xDCFF0C27, 0x3FD67042, 0xC0FFF2AE, 
      0x3FF6C800, 0x001556E1, 0x3FE67980, 0xE0A9FB6E, 0x3FD69D45, 0x92DC2931, 
      0x3FF6D800, 0x0025CACA, 0x3FE669C3, 0x105096D6, 0x3FD6CA28, 0xD34D2AD0, 
      0x3FF6E800, 0x0022DD44, 0x3FE65A1B, 0x3DAF2E0B, 0x3FD6F6EC, 0xADEC8BBD, 
      0x3FF6F800, 0x001AF9E0, 0x3FE64A89, 0x3AC2A43A, 0x3FD72391, 0x4EB02B5F, 
      0x3FF70800, 0x0020EB4D, 0x3FE63B0C, 0xDA03A7C0, 0x3FD75016, 0xE13E3472, 
      0x3FF71800, 0x0026F0E2, 0x3FE62BA5, 0xEE888406, 0x3FD77C7D, 0x9087A3F8, 
      0x3FF72800, 0x0020EF86, 0x3FE61C54, 0x4BE1EEF6, 0x3FD7A8C5, 0x8728FC96, 
      0x3FF73800, 0x0024ECCA, 0x3FE60D17, 0xC5FA9029, 0x3FD7D4EE, 0xEFC4B408, 
      0x3FF74800, 0x00264C21, 0x3FE5FDF0, 0x31572F41, 0x3FD800F9, 0xF445DC47, 
      0x3FF75800, 0x002497A9, 0x3FE5EEDD, 0x62E83E23, 0x3FD82CE6, 0xBE62A04D, 
      0x3FF76800, 0x0023953F, 0x3FE5DFDF, 0x300FF698, 0x3FD858B5, 0x778717C9, 
      0x3FF77800, 0x002188CC, 0x3FE5D0F5, 0x6EA9F206, 0x3FD88466, 0x48BB7925, 
      0x3FF78800, 0x00282D26, 0x3FE5C21F, 0xF4F9C9CD, 0x3FD8AFF9, 0x5AD35CEB, 
      0x3FF79800, 0x00276630, 0x3FE5B35E, 0x99CC2A2D, 0x3FD8DB6E, 0xD60906CB, 
      0x3FF7A800, 0x0016A8F6, 0x3FE5A4B1, 0x345621D0, 0x3FD906C6, 0xE2599557, 
      0x3FF7B800, 0x0017E9CA, 0x3FE59617, 0x9C140F66, 0x3FD93201, 0xA7E3D98F, 
      0x3FF7C800, 0x0020B50D, 0x3FE58791, 0xA917E08A, 0x3FD95D1F, 0x4DFDCF8F, 
      0x3FF7D800, 0x00224349, 0x3FE5791F, 0x33E27C5A, 0x3FD9881F, 0xFBA29E4F, 
      0x3FF7E800, 0x002434FC, 0x3FE56AC0, 0x154A503D, 0x3FD9B303, 0xD7BB2458, 
      0x3FF7F800, 0x0011F2F3, 0x3FE55C74, 0x26A79378, 0x3FD9DDCB, 0x0896D46E, 
/*i = 192*/                                                                     
      0x3FF80800, 0x000F4240, 0x3FE54E3B, 0x41874733, 0x3FDA0875, 0xB4CEC036  
      };
