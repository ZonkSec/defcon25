/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_GAMMA_CORRECTION_H
#define	XC_GAMMA_CORRECTION_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

//const unsigned int gamma_table_1024[1024] = {
//    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   
//    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   
//    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   
//    0,   0,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   
//    1,   1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   3,   
//    3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   4,   4,   4,   4,   4,   4,   4,   4,   4,   
//    4,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   6,   6,   6,   6,   6,   6,   6,   6,   7,   
//    7,   7,   7,   7,   7,   7,   7,   8,   8,   8,   8,   8,   8,   8,   9,   9,   9,   9,   9,   9,   
//    10,  10,  10,  10,  10,  10,  10,  11,  11,  11,  11,  11,  12,  12,  12,  12,  12,  12,  13,  13,  
//    13,  13,  13,  14,  14,  14,  14,  14,  14,  15,  15,  15,  15,  15,  16,  16,  16,  16,  17,  17,  
//    17,  17,  17,  18,  18,  18,  18,  19,  19,  19,  19,  19,  20,  20,  20,  20,  21,  21,  21,  21,  
//    22,  22,  22,  22,  23,  23,  23,  23,  24,  24,  24,  25,  25,  25,  25,  26,  26,  26,  26,  27,  
//    27,  27,  28,  28,  28,  28,  29,  29,  29,  30,  30,  30,  31,  31,  31,  32,  32,  32,  32,  33,  
//    33,  33,  34,  34,  34,  35,  35,  35,  36,  36,  36,  37,  37,  37,  38,  38,  38,  39,  39,  40,  
//    40,  40,  41,  41,  41,  42,  42,  42,  43,  43,  44,  44,  44,  45,  45,  46,  46,  46,  47,  47,  
//    47,  48,  48,  49,  49,  49,  50,  50,  51,  51,  52,  52,  52,  53,  53,  54,  54,  55,  55,  55,  
//    56,  56,  57,  57,  58,  58,  59,  59,  59,  60,  60,  61,  61,  62,  62,  63,  63,  64,  64,  65,  
//    65,  66,  66,  66,  67,  67,  68,  68,  69,  69,  70,  70,  71,  71,  72,  72,  73,  74,  74,  75,  
//    75,  76,  76,  77,  77,  78,  78,  79,  79,  80,  80,  81,  82,  82,  83,  83,  84,  84,  85,  85,  
//    86,  87,  87,  88,  88,  89,  89,  90,  91,  91,  92,  92,  93,  94,  94,  95,  95,  96,  97,  97,  
//    98,  98,  99,  100, 100, 101, 101, 102, 103, 103, 104, 105, 105, 106, 107, 107, 108, 109, 109, 110, 
//    110, 111, 112, 112, 113, 114, 114, 115, 116, 117, 117, 118, 119, 119, 120, 121, 121, 122, 123, 123, 
//    124, 125, 126, 126, 127, 128, 128, 129, 130, 131, 131, 132, 133, 134, 134, 135, 136, 136, 137, 138, 
//    139, 140, 140, 141, 142, 143, 143, 144, 145, 146, 146, 147, 148, 149, 150, 150, 151, 152, 153, 154, 
//    154, 155, 156, 157, 158, 158, 159, 160, 161, 162, 163, 163, 164, 165, 166, 167, 168, 168, 169, 170, 
//    171, 172, 173, 174, 174, 175, 176, 177, 178, 179, 180, 181, 181, 182, 183, 184, 185, 186, 187, 188, 
//    189, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 202, 203, 204, 205, 206, 
//    207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 
//    227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 243, 244, 245, 246, 247, 
//    248, 249, 250, 251, 252, 253, 254, 255, 256, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 269, 
//    270, 271, 272, 273, 274, 275, 277, 278, 279, 280, 281, 282, 283, 285, 286, 287, 288, 289, 290, 292, 
//    293, 294, 295, 296, 298, 299, 300, 301, 302, 304, 305, 306, 307, 308, 310, 311, 312, 313, 314, 316, 
//    317, 318, 319, 321, 322, 323, 324, 326, 327, 328, 329, 331, 332, 333, 335, 336, 337, 338, 340, 341, 
//    342, 344, 345, 346, 348, 349, 350, 351, 353, 354, 355, 357, 358, 359, 361, 362, 363, 365, 366, 367, 
//    369, 370, 372, 373, 374, 376, 377, 378, 380, 381, 383, 384, 385, 387, 388, 390, 391, 392, 394, 395, 
//    397, 398, 399, 401, 402, 404, 405, 407, 408, 409, 411, 412, 414, 415, 417, 418, 420, 421, 423, 424, 
//    425, 427, 428, 430, 431, 433, 434, 436, 437, 439, 440, 442, 443, 445, 446, 448, 450, 451, 453, 454, 
//    456, 457, 459, 460, 462, 463, 465, 466, 468, 470, 471, 473, 474, 476, 477, 479, 481, 482, 484, 485, 
//    487, 489, 490, 492, 493, 495, 497, 498, 500, 502, 503, 505, 506, 508, 510, 511, 513, 515, 516, 518, 
//    520, 521, 523, 525, 526, 528, 530, 531, 533, 535, 537, 538, 540, 542, 543, 545, 547, 548, 550, 552, 
//    554, 555, 557, 559, 561, 562, 564, 566, 568, 569, 571, 573, 575, 576, 578, 580, 582, 584, 585, 587, 
//    589, 591, 592, 594, 596, 598, 600, 602, 603, 605, 607, 609, 611, 613, 614, 616, 618, 620, 622, 624, 
//    625, 627, 629, 631, 633, 635, 637, 639, 640, 642, 644, 646, 648, 650, 652, 654, 656, 658, 659, 661, 
//    663, 665, 667, 669, 671, 673, 675, 677, 679, 681, 683, 685, 687, 689, 691, 693, 695, 697, 699, 701, 
//    703, 705, 707, 709, 711, 713, 715, 717, 719, 721, 723, 725, 727, 729, 731, 733, 735, 737, 739, 741, 
//    743, 745, 747, 749, 751, 753, 756, 758, 760, 762, 764, 766, 768, 770, 772, 774, 777, 779, 781, 783, 
//    785, 787, 789, 792, 794, 796, 798, 800, 802, 804, 807, 809, 811, 813, 815, 817, 820, 822, 824, 826, 
//    828, 831, 833, 835, 837, 839, 842, 844, 846, 848, 851, 853, 855, 857, 860, 862, 864, 866, 869, 871, 
//    873, 875, 878, 880, 882, 885, 887, 889, 891, 894, 896, 898, 901, 903, 905, 908, 910, 912, 915, 917, 
//    919, 922, 924, 926, 929, 931, 933, 936, 938, 941, 943, 945, 948, 950, 953, 955, 957, 960, 962, 965, 
//    967, 969, 972, 974, 977, 979, 982, 984, 986, 989, 991, 994, 996, 999, 1001,1004,1006,1009,1011,1014,
//    1016,1019,1021,1023
//
//};

//const unsigned int gamma_table_512[512] = {
//    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   
//    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   
//    0,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   2,   2,   2,   2,   
//    2,   2,   2,   2,   2,   3,   3,   3,   3,   3,   3,   3,   3,   4,   4,   4,   4,   4,   4,   4,   
//    5,   5,   5,   5,   5,   5,   6,   6,   6,   6,   6,   7,   7,   7,   7,   7,   7,   8,   8,   8,   
//    8,   9,   9,   9,   9,   9,   10,  10,  10,  10,  11,  11,  11,  11,  12,  12,  12,  13,  13,  13,  
//    13,  14,  14,  14,  15,  15,  15,  16,  16,  16,  16,  17,  17,  17,  18,  18,  18,  19,  19,  20,  
//    20,  20,  21,  21,  21,  22,  22,  23,  23,  23,  24,  24,  24,  25,  25,  26,  26,  27,  27,  27,  
//    28,  28,  29,  29,  30,  30,  31,  31,  32,  32,  33,  33,  33,  34,  34,  35,  35,  36,  37,  37,  
//    38,  38,  39,  39,  40,  40,  41,  41,  42,  42,  43,  44,  44,  45,  45,  46,  47,  47,  48,  48,  
//    49,  50,  50,  51,  51,  52,  53,  53,  54,  55,  55,  56,  57,  57,  58,  59,  59,  60,  61,  61,  
//    62,  63,  64,  64,  65,  66,  67,  67,  68,  69,  70,  70,  71,  72,  73,  73,  74,  75,  76,  77,  
//    77,  78,  79,  80,  81,  81,  82,  83,  84,  85,  86,  87,  87,  88,  89,  90,  91,  92,  93,  94,  
//    94,  95,  96,  97,  98,  99,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 
//    114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 129, 130, 131, 132, 133, 134, 
//    135, 136, 137, 139, 140, 141, 142, 143, 144, 146, 147, 148, 149, 150, 152, 153, 154, 155, 156, 158, 
//    159, 160, 161, 163, 164, 165, 166, 168, 169, 170, 172, 173, 174, 175, 177, 178, 179, 181, 182, 183, 
//    185, 186, 188, 189, 190, 192, 193, 195, 196, 197, 199, 200, 202, 203, 204, 206, 207, 209, 210, 212, 
//    213, 215, 216, 218, 219, 221, 222, 224, 225, 227, 228, 230, 231, 233, 235, 236, 238, 239, 241, 242, 
//    244, 246, 247, 249, 251, 252, 254, 255, 257, 259, 260, 262, 264, 265, 267, 269, 271, 272, 274, 276, 
//    277, 279, 281, 283, 284, 286, 288, 290, 292, 293, 295, 297, 299, 301, 302, 304, 306, 308, 310, 312, 
//    313, 315, 317, 319, 321, 323, 325, 327, 329, 330, 332, 334, 336, 338, 340, 342, 344, 346, 348, 350, 
//    352, 354, 356, 358, 360, 362, 364, 366, 368, 370, 372, 374, 376, 379, 381, 383, 385, 387, 389, 391, 
//    393, 396, 398, 400, 402, 404, 406, 408, 411, 413, 415, 417, 419, 422, 424, 426, 428, 431, 433, 435, 
//    437, 440, 442, 444, 447, 449, 451, 454, 456, 458, 461, 463, 465, 468, 470, 472, 475, 477, 480, 482, 
//    484, 487, 489, 492, 494, 497, 499, 502, 504, 507, 509, 511
//};

//const unsigned int gamma_table_256x16k[256] = {
//    0,      0,      0,      0,      0,      1,      2,      2,      3,      4,      6,      7,      9,      11,     13,     16,     18,     21,     24,     27,     
//    31,     35,     39,     44,     48,     53,     59,     64,     70,     77,     83,     90,     97,     105,    113,    121,    130,    139,    148,    158,    
//    168,    178,    189,    200,    212,    224,    236,    249,    262,    276,    290,    304,    319,    334,    350,    366,    383,    400,    417,    435,    
//    454,    472,    492,    512,    532,    552,    574,    595,    617,    640,    663,    687,    711,    736,    761,    786,    812,    839,    866,    894,    
//    922,    951,    980,    1010,   1040,   1071,   1103,   1135,   1167,   1200,   1234,   1268,   1303,   1338,   1374,   1410,   1447,   1485,   1523,   1562,   
//    1601,   1641,   1682,   1723,   1765,   1807,   1850,   1893,   1938,   1982,   2028,   2074,   2120,   2168,   2215,   2264,   2313,   2363,   2413,   2464,   
//    2516,   2568,   2621,   2675,   2729,   2784,   2840,   2896,   2953,   3010,   3069,   3127,   3187,   3247,   3308,   3370,   3432,   3495,   3559,   3623,   
//    3688,   3754,   3820,   3888,   3955,   4024,   4093,   4163,   4234,   4305,   4377,   4450,   4524,   4598,   4673,   4749,   4825,   4903,   4980,   5059,   
//    5139,   5219,   5300,   5381,   5464,   5547,   5631,   5716,   5801,   5887,   5974,   6062,   6150,   6240,   6330,   6420,   6512,   6604,   6698,   6792,   
//    6886,   6982,   7078,   7175,   7273,   7372,   7471,   7572,   7673,   7775,   7877,   7981,   8085,   8190,   8296,   8403,   8511,   8619,   8728,   8838,   
//    8949,   9061,   9174,   9287,   9401,   9516,   9632,   9749,   9867,   9985,   10104,  10224,  10345,  10467,  10590,  10714,  10838,  10963,  11089,  11217,  
//    11344,  11473,  11603,  11733,  11865,  11997,  12130,  12264,  12399,  12535,  12672,  12809,  12948,  13087,  13227,  13369,  13511,  13654,  13797,  13942,  
//    14088,  14235,  14382,  14530,  14680,  14830,  14981,  15133,  15286,  15440,  15595,  15751,  15908,  16065,  16224,  16383  
//};

//const unsigned int gamma_table_256x32k[256] = {
//    0,      0,      0,      1,      1,      2,      4,      5,      7,      9,      12,     15,     19,     22,     27,     32,     37,     42,     49,     55,     
//    63,     70,     79,     88,     97,     107,    118,    129,    141,    154,    167,    181,    195,    210,    226,    243,    260,    278,    296,    316,    
//    336,    357,    378,    401,    424,    448,    473,    498,    525,    552,    580,    609,    639,    669,    701,    733,    766,    800,    835,    871,    
//    908,    945,    984,    1024,   1064,   1105,   1148,   1191,   1235,   1281,   1327,   1374,   1422,   1472,   1522,   1573,   1625,   1679,   1733,   1788,   
//    1845,   1902,   1961,   2020,   2081,   2143,   2206,   2270,   2335,   2401,   2468,   2536,   2606,   2677,   2748,   2821,   2895,   2971,   3047,   3125,   
//    3203,   3283,   3364,   3446,   3530,   3615,   3700,   3787,   3876,   3965,   4056,   4148,   4241,   4336,   4431,   4528,   4627,   4726,   4827,   4929,   
//    5032,   5137,   5243,   5350,   5459,   5568,   5680,   5792,   5906,   6021,   6138,   6255,   6374,   6495,   6617,   6740,   6865,   6991,   7118,   7247,   
//    7377,   7508,   7641,   7776,   7911,   8048,   8187,   8327,   8468,   8611,   8755,   8901,   9048,   9197,   9347,   9498,   9651,   9806,   9961,   10119,  
//    10278,  10438,  10600,  10763,  10928,  11094,  11262,  11432,  11602,  11775,  11949,  12124,  12301,  12480,  12660,  12841,  13025,  13209,  13396,  13584,  
//    13773,  13964,  14157,  14351,  14547,  14744,  14943,  15144,  15346,  15550,  15755,  15962,  16171,  16381,  16593,  16807,  17022,  17239,  17457,  17677,  
//    17899,  18122,  18348,  18574,  18803,  19033,  19265,  19498,  19734,  19970,  20209,  20449,  20691,  20935,  21180,  21428,  21677,  21927,  22179,  22434,  
//    22689,  22947,  23206,  23467,  23730,  23995,  24261,  24529,  24799,  25070,  25344,  25619,  25896,  26175,  26455,  26738,  27022,  27308,  27595,  27885,  
//    28176,  28470,  28765,  29061,  29360,  29661,  29963,  30267,  30573,  30881,  31191,  31502,  31816,  32131,  32448,  32767   
//};

//const unsigned int gamma_table_256x64k[256] = {
//    0,      0,      0,      2,      3,      5,      8,      11,     15,     19,     25,     31,     38,     45,     54,     64,     74,     85,     98,     111,    
//    126,    141,    158,    176,    195,    215,    236,    259,    283,    308,    334,    362,    390,    421,    452,    486,    520,    556,    593,    632,    
//    672,    714,    757,    802,    849,    896,    946,    997,    1050,   1104,   1160,   1218,   1278,   1339,   1402,   1466,   1533,   1601,   1671,   1742,   
//    1816,   1891,   1968,   2048,   2128,   2211,   2296,   2383,   2471,   2562,   2654,   2749,   2845,   2944,   3044,   3147,   3251,   3358,   3466,   3577,   
//    3690,   3805,   3922,   4041,   4163,   4286,   4412,   4540,   4670,   4802,   4937,   5073,   5212,   5354,   5497,   5643,   5791,   5942,   6094,   6250,   
//    6407,   6567,   6729,   6893,   7060,   7230,   7401,   7575,   7752,   7931,   8113,   8297,   8483,   8672,   8863,   9057,   9254,   9453,   9654,   9859,   
//    10065,  10274,  10486,  10701,  10918,  11137,  11360,  11585,  11812,  12043,  12276,  12511,  12749,  12990,  13234,  13481,  13730,  13982,  14236,  14494,  
//    14754,  15017,  15283,  15552,  15823,  16097,  16374,  16654,  16937,  17222,  17511,  17802,  18097,  18394,  18694,  18997,  19303,  19612,  19923,  20238,  
//    20556,  20876,  21200,  21527,  21856,  22189,  22525,  22864,  23205,  23550,  23898,  24249,  24603,  24960,  25320,  25683,  26050,  26419,  26792,  27168,  
//    27547,  27929,  28314,  28702,  29094,  29489,  29887,  30288,  30692,  31100,  31511,  31925,  32342,  32763,  33186,  33614,  34044,  34478,  34915,  35355,  
//    35798,  36245,  36696,  37149,  37606,  38066,  38530,  38997,  39468,  39941,  40419,  40899,  41383,  41871,  42361,  42856,  43354,  43855,  44359,  44868,  
//    45379,  45894,  46413,  46935,  47460,  47990,  48522,  49058,  49598,  50141,  50688,  51238,  51792,  52350,  52911,  53476,  54044,  54616,  55191,  55770,  
//    56353,  56940,  57530,  58123,  58721,  59322,  59926,  60535,  61147,  61763,  62382,  63005,  63632,  64263,  64897,  65535 
//};

const unsigned int gamma_table_256x1k[256] = {
    0,      0,      0,      0,  0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      1,      1,      1,      1,      1,      
1,      2,      2,      2,      3,      3,      3,      4,      4,      4,      5,      5,      6,      6,      7,      7,      8,      8,      9,      9,      
10,     11,     11,     12,     13,     14,     14,     15,     16,     17,     18,     19,     19,     20,     21,     22,     23,     25,     26,     27,     
28,     29,     30,     32,     33,     34,     35,     37,     38,     40,     41,     42,     44,     46,     47,     49,     50,     52,     54,     55,     
57,     59,     61,     63,     65,     66,     68,     70,     72,     75,     77,     79,     81,     83,     85,     88,     90,     92,     95,     97,     
100,    102,    105,    107,    110,    112,    115,    118,    121,    123,    126,    129,    132,    135,    138,    141,    144,    147,    150,    154,    
157,    160,    163,    167,    170,    174,    177,    181,    184,    188,    191,    195,    199,    202,    206,    210,    214,    218,    222,    226,    
230,    234,    238,    243,    247,    251,    255,    260,    264,    269,    273,    278,    282,    287,    292,    296,    301,    306,    311,    316,    
321,    326,    331,    336,    341,    346,    351,    357,    362,    367,    373,    378,    384,    390,    395,    401,    407,    412,    418,    424,    
430,    436,    442,    448,    454,    460,    466,    473,    479,    485,    492,    498,    505,    511,    518,    525,    531,    538,    545,    552,    
559,    566,    573,    580,    587,    594,    602,    609,    616,    624,    631,    639,    646,    654,    661,    669,    677,    685,    693,    701,    
709,    717,    725,    733,    741,    749,    758,    766,    774,    783,    792,    800,    809,    817,    826,    835,    844,    853,    862,    871,    
880,    889,    898,    908,    917,    926,    936,    945,    955,    965,    974,    984,    994,    1004,   1014,   1023 
};

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */
