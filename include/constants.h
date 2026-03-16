
#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

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

const uint32_t PACKET_SIZE = 65; // 64 + leading 0
const uint32_t USB_REPORT_LENGTH = 64;
//
const uint8_t BIT_MASK_0 = 0x01;
const uint8_t BIT_MASK_1 = 0x02;
const uint8_t BIT_MASK_2 = 0x04;
const uint8_t BIT_MASK_3 = 0x08;
const uint8_t BIT_MASK_4 = 0x10;
const uint8_t BIT_MASK_5 = 0x20;
const uint8_t BIT_MASK_6 = 0x40;
const uint8_t BIT_MASK_7 = 0x80;
//
const uint16_t MCHIP_VENDOR_ID = 0x04D8;
const uint16_t PK2_DEVICE_ID = 0x0033;
const uint16_t PK3_DEVICE_ID = 0x900A;
const int PK3_MAGIC_KEY = 0x336B50;
const uint8_t MPLAB_BOOTLOADER_TYPE = 0x99;

//
const uint16_t CONFIG_ROWS = 2;
const uint16_t CONFIG_COLUMNS = 4;
const uint16_t MAX_READ_CFG_MASKS = 8;
const uint16_t NUM_CONFIG_MASKS = 9;
//
enum pickit_2_usb_t
{
  FOUND,              // implies firmware version is good.
  NOT_FOUND,
  WRITE_ERROR,
  READ_ERROR,
  FIRMWARE_INVALID,
  BOOTLOADER,
  READ_WRITE_ERROR,
  PK3_MPLAB,            // a valid mplab ready pk3 that doesn't have scripting firmware
  FIRMWARE_OLD_VERSION
};

enum pickit_2_pwr_t
{
  NO_RESPONSE,
  VDD_ON,
  VDD_OFF,
  VDD_ERROR,
  VPP_ERROR,
  VDD_VPP_ERROR,
  SELF_POWERED,
  UNPOWERED
};

enum file_read_t
{
  SUCCESS,
  FAILED,
  NO_CONFIG,
  PARTIAL_CONFIG,
  LARGE_MEM
};

enum status_color_t
{
  NORMAL,
  GREEN,
  YELLOW,
  RED
};

enum vdd_target_select_t
{
  AUTO,
  PICKIT_2,
  TARGET
};

enum mplab_error_codes_t
{
  UNKNOWN_ERROR,
  BOOTLOADER_NOT_FOUND
};

const float VDD_THRESHOLD_FOR_SELF_POWERED_TARGET = 2.3F;
const bool NO_MESSAGE = false;
const bool SHOW_MESSAGE = true;
const bool UPDATE_MEMORY_DISPLAYS = true;
const bool DONT_UPDATE_MEMORY_DISPLAYS = false;
const bool ERASE_EEPROM = true;
const bool WRITE_EEPROM = false;

//
const int UPLOAD_BUFFER_SIZE = 128;
const int DOWNLOAD_BUFFER_SIZE = 256;
//
const uint8_t READ_FW_FLASH = 1;
const uint8_t WRITE_FW_FLASH = 2;
const uint8_t ERASE_FW_FLASH = 3;
const uint8_t READ_FW_EEPROM_DATA = 4;
const uint8_t WRITE_FW_EEPROM_DATA = 5;
const uint8_t RESET_FW_DEVICE = 0xFF;
//
const uint8_t SWITCH_TO_BL = 0x24;
const uint8_t TEST_BOOTLOADER = 0x2A;
const uint8_t GET_VERSIONS_MPLAB = 0x41;
const uint8_t ENTER_BOOTLOADER = 0x42;
const uint8_t NO_OPERATION = 0x5A;
const uint8_t FIRMWARE_VERSION = 0x76;
const uint8_t SET_VDD = 0xA0;
const uint8_t SET_VPP = 0xA1;
const uint8_t READ_STATUS = 0xA2;
const uint8_t READ_VOLTAGES = 0xA3;
const uint8_t DOWNLOAD_SCRIPT = 0xA4;
const uint8_t RUN_SCRIPT = 0xA5;
const uint8_t EXECUTE_SCRIPT = 0xA6;
const uint8_t CLR_DOWNLOAD_BUFFER = 0xA7;
const uint8_t DOWNLOAD_DATA = 0xA8;
const uint8_t CLR_UPLOAD_BUFFER = 0xA9;
const uint8_t UPLOAD_DATA = 0xAA;
const uint8_t CLR_SCRIPT_BUFFER = 0xAB;
const uint8_t UPLOAD_DATA_NO_LEN = 0xAC;
const uint8_t END_OF_BUFFER = 0xAD;
const uint8_t RESET = 0xAE;
const uint8_t SCRIPT_BUFFER_CHKSUM = 0xAF;
const uint8_t SET_VOLTAGE_CALS = 0xB0;
const uint8_t WR_INTERNAL_EEPROM = 0xB1;
const uint8_t RD_INTERNAL_EEPROM = 0xB2;
const uint8_t ENTER_UART_MODE = 0xB3;
const uint8_t EXIT_UART_MODE = 0xB4;
const uint8_t ENTER_LEARN_MODE = 0xB5;
const uint8_t EXIT_LEARN_MODE = 0xB6;
const uint8_t ENABLE_PK2GO_MODE = 0xB7;
const uint8_t LOGIC_ANALYZER_GO = 0xB8;
const uint8_t COPY_RAM_UPLOAD = 0xB9;
// META COMMANDS
const uint8_t MC_READ_OSCCAL = 0x80;
const uint8_t MC_WRITE_OSCCAL = 0x81;
const uint8_t MC_START_CHECKSUM = 0x82;
const uint8_t MC_VERIFY_CHECKSUM = 0x83;
const uint8_t MC_CHECK_DEVICE_ID = 0x84;
const uint8_t MC_READ_BANDGAP = 0x85;
const uint8_t MC_WRITE_CFG_BANDGAP = 0x86;
const uint8_t MC_CHANGE_CHKSM_FRMT = 0x87;
//
const uint8_t _VDD_ON = 0xFF;
const uint8_t _VDD_OFF = 0xFE;
const uint8_t _VDD_GND_ON = 0xFD;
const uint8_t _VDD_GND_OFF = 0xFC;
const uint8_t _VPP_ON = 0xFB;
const uint8_t _VPP_OFF = 0xFA;
const uint8_t _VPP_PWM_ON = 0xF9;
const uint8_t _VPP_PWM_OFF = 0xF8;
const uint8_t _MCLR_GND_ON = 0xF7;
const uint8_t _MCLR_GND_OFF = 0xF6;
const uint8_t _BUSY_LED_ON = 0xF5;
const uint8_t _BUSY_LED_OFF = 0xF4;
const uint8_t _SET_ICSP_PINS = 0xF3;
const uint8_t _WRITE_BYTE_LITERAL = 0xF2;
const uint8_t _WRITE_BYTE_BUFFER = 0xF1;
const uint8_t _READ_BYTE_BUFFER = 0xF0;
const uint8_t _READ_BYTE = 0xEF;
const uint8_t _WRITE_BITS_LITERAL = 0xEE;
const uint8_t _WRITE_BITS_BUFFER = 0xED;
const uint8_t _READ_BITS_BUFFER = 0xEC;
const uint8_t _READ_BITS = 0xEB;
const uint8_t _SET_ICSP_SPEED = 0xEA;
const uint8_t _LOOP = 0xE9;
const uint8_t _DELAY_LONG = 0xE8;
const uint8_t _DELAY_SHORT = 0xE7;
const uint8_t _IF_EQ_GOTO = 0xE6;
const uint8_t _IF_GT_GOTO = 0xE5;
const uint8_t _GOTO_INDEX = 0xE4;
const uint8_t _EXIT_SCRIPT = 0xE3;
const uint8_t _PEEK_SFR = 0xE2;
const uint8_t _POKE_SFR = 0xE1;

const uint8_t _ICD_SLAVE_RX = 0xE0;
const uint8_t _ICD_SLAVE_TX_LIT = 0xDF;
const uint8_t _ICD_SLAVE_TX_BUF = 0xDE;
const uint8_t _LOOP_BUFFER = 0xDD;
const uint8_t _ICSP_STATES_BUFFER = 0xDC;
const uint8_t _POP_DOWNLOAD = 0xDB;
const uint8_t _COREINST18 = 0xDA;
const uint8_t _COREINST24 = 0xD9;
const uint8_t _NOP24 = 0xD8;
const uint8_t _VISI24 = 0xD7;
const uint8_t _RD2_BYTE_BUFFER = 0xD6;
const uint8_t _RD2_BITS_BUFFER = 0xD5;
const uint8_t _WRITE_BUFWORD_W = 0xD4;
const uint8_t _WRITE_BUFBYTE_W = 0xD3;
const uint8_t _CONST_WRITE_DL = 0xD2;

const uint8_t _WRITE_BITS_LIT_HLD = 0xD1;
const uint8_t _WRITE_BITS_BUF_HLD = 0xD0;
const uint8_t _SET_AUX = 0xCF;
const uint8_t _AUX_STATE_BUFFER = 0xCE;
const uint8_t _I2C_START = 0xCD;
const uint8_t _I2C_STOP = 0xCC;
const uint8_t _I2C_WR_BYTE_LIT = 0xCB;
const uint8_t _I2C_WR_BYTE_BUF = 0xCA;
const uint8_t _I2C_RD_BYTE_ACK = 0xC9;
const uint8_t _I2C_RD_BYTE_NACK = 0xC8;
const uint8_t _SPI_WR_BYTE_LIT = 0xC7;
const uint8_t _SPI_WR_BYTE_BUF = 0xC6;
const uint8_t _SPI_RD_BYTE_BUF = 0xC5;
const uint8_t _SPI_RDWR_BYTE_LIT = 0xC4;
const uint8_t _SPI_RDWR_BYTE_BUF = 0xC3;
const uint8_t _ICD_SLAVE_RX_BL = 0xC2;
const uint8_t _ICD_SLAVE_TX_LIT_BL = 0xC1;
const uint8_t _ICD_SLAVE_TX_BUF_BL = 0xC0;
const uint8_t _MEASURE_PULSE = 0xBF;
const uint8_t _UNIO_TX = 0xBE;
const uint8_t _UNIO_TX_RX = 0xBD;
const uint8_t _JT2_SETMODE = 0xBC;
const uint8_t _JT2_SENDCMD = 0xBB;
const uint8_t _JT2_XFERDATA8_LIT = 0xBA;
const uint8_t _JT2_XFERDATA32_LIT = 0xB9;
const uint8_t _JT2_XFRFASTDAT_LIT = 0xB8;
const uint8_t _JT2_XFRFASTDAT_BUF = 0xB7;
const uint8_t _JT2_XFERINST_BUF = 0xB6;
const uint8_t _JT2_GET_PE_RESP = 0xB5;
const uint8_t _JT2_WAIT_PE_RESP = 0xB4;
//
const int SEARCH_ALL_FAMILIES = 0xFFFFFF;
//
// Script Buffer Reserved Locations
const uint8_t PROG_ENTRY = 0;
const uint8_t PROG_EXIT = 1;
const uint8_t RD_DEVID = 2;
const uint8_t PROGMEM_RD = 3;
const uint8_t ERASE_CHIP_PREP = 4;
const uint8_t PROGMEM_ADDRSET = 5;
const uint8_t PROGMEM_WR_PREP = 6;
const uint8_t PROGMEM_WR = 7;
const uint8_t EEPROM_RD_PREP = 8;
const uint8_t EEPROM_RD = 9;
const uint8_t EEPROM_WR_PREP = 10;
const uint8_t EEPROM_WR = 11;
const uint8_t CONFIG_RD_PREP = 12;
const uint8_t CONFIG_RD = 13;
const uint8_t CONFIG_WR_PREP = 14;
const uint8_t CONFIG_WR = 15;
const uint8_t USERID_RD_PREP = 16;
const uint8_t USERID_RD = 17;
const uint8_t USERID_WR_PREP = 18;
const uint8_t USERID_WR = 19;
const uint8_t OSSCAL_RD = 20;
const uint8_t OSSCAL_WR = 21;
const uint8_t ERASE_CHIP = 22;
const uint8_t ERASE_PROGMEM = 23;
const uint8_t ERASE_EE = 24;
//const uint8_t ERASE_CONFIG      = 25;
const uint8_t ROW_ERASE = 26;
const uint8_t TEST_MEM_RD = 27;
const uint8_t EEPROM_ROW_ERASE = 28;

// OSCCAL valid mask in config masks
const int OSCCAL_MASK = 7;

// EEPROM config words
const int PROTOCOL_CFG = 0;
const int ADR_MASK_CFG = 1;
const int ADR_BITS_CFG = 2;
const int CS_PINS_CFG = 3;
// EEPROM Protocols
const int I2C_BUS = 1;
const int SPI_BUS = 2;
const int MICROWIRE_BUS = 3;
const int UNIO_BUS = 4;
const bool READ_BIT = true;
const bool WRITE_BIT = false;

// for user32.dll window flashing
//Stop flashing. The system restores the window to its original state. 
const uint32_t FLASHW_STOP = 0;
//Flash the window caption. 
const uint32_t FLASHW_CAPTION = 1;
//Flash the taskbar button. 
const uint32_t FLASHW_TRAY = 2;
//Flash both the window caption and taskbar button.
//This is equivalent to setting the FLASHW_CAPTION | FLASHW_TRAY flags. 
const uint32_t FLASHW_ALL = 3;
//Flash continuously, until the FLASHW_STOP flag is set. 
const uint32_t FLASHW_TIMER = 4;
//Flash continuously until the window comes to the foreground. 
const uint32_t FLASHW_TIMERNOFG = 12;

// PICkit 2 internal EEPROM Locations
const uint8_t ADC_CAL_L = 0x00;
const uint8_t ADC_CAL_H = 0x01;
const uint8_t CPP_OFFSET = 0x02;
const uint8_t CPP_CAL = 0x03;
const uint8_t UNIT_ID = 0xF0;  //through 0xFF

/*

struct OVERLAPPED
{
  int Internal;
  int InternalHigh;
  int Offset;
  int OffsetHigh;
  int hEvent;
};
  */



// PIC32 related
const uint32_t P32_PROGRAM_FLASH_START_ADDR = 0x1D000000;
const uint32_t P32_BOOT_FLASH_START_ADDR = 0x1FC00000;

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


#endif // _CONSTANTS_H_