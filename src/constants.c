#include <stdint.h>
#include <stdbool.h>
#include "../include/constants.h"

// APPLICATION VERSION
const char *APP_VERSION = "3.10.00";
const uint8_t DEV_FILE_COMPAT_LEVEL = 6;
const uint8_t DEV_FILE_COMPAT_LEVEL_MIN = 0;
const char *USER_GUIDE_FILE_NAME_PK2 = "\\PICkit2 User Guide 51553E.pdf";
const char *USER_GUIDE_FILE_NAME_PK3 = "\\PICkit 3 Programmer Application User's Guide 50002158a.pdf";

// min firmware version Pk2
const uint8_t FW_VER_MAJOR_REQ = 2;
const uint8_t FW_VER_MINOR_REQ = 32;
const uint8_t FW_VER_DOT_REQ = 0;
const char *FW_FILE_NAME = "PK2V023200.hex";

// min firmware version Pk3
const uint8_t FW_VER_MAJOR_REQ_PK3 = 02;
const uint8_t FW_VER_MINOR_REQ_PK3 = 00;
const uint8_t FW_VER_DOT_REQ_PK3 = 05;
const char *FW_FILE_NAME_PK3 = "PK3OSV020005.hex";
const char *BL_FILE_NAME_PK3 = "PK3BLV011405.hex"; // matches the MPLAB bootlaoder version number

// OSCCAL regeration
const uint32_t BASELINE_CAL[] = {
        0x0C00, 0x0025, 0x0067, 0x0068, 0x0069, 0x0066, 0x0CFE, 0x0006, 
        0x0626, 0x0A08, 0x0726, 0x0A0A, 0x0070, 0x0C82, 0x0031, 0x02F0, 
        0x0A0F, 0x02F1, 0x0A0F, 0x0CF9, 0x0030, 0x0CC8, 0x0031, 0x0506, 
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x02F0, 0x0A18, 0x0000, 
        0x0CF9, 0x0030, 0x0000, 0x0000, 0x0000, 0x02F1, 0x0A18, 0x0406, 
        0x0A08 };

const uint32_t MR16F676FAM_CAL[] = {
        0x3000, 0x2805, 0x0000, 0x0000, 0x0009, 0x1683, 0x0090, 0x0191, 
        0x019F, 0x30FE, 0x0085, 0x1283, 0x3007, 0x0099, 0x0185, 0x1885, 
        0x280F, 0x1C85, 0x2811, 0x01A0, 0x3082, 0x00A1, 0x0BA0, 0x2816, 
        0x0BA1, 0x2816, 0x30F9, 0x00A0, 0x30C8, 0x00A1, 0x1405, 0x0000, 
        0x0000, 0x0000, 0x0000, 0x0000, 0x0BA0, 0x281F, 0x0000, 0x30F9, 
        0x00A0, 0x0000, 0x0000, 0x0000, 0x0BA1, 0x281F, 0x1005, 0x280F};
