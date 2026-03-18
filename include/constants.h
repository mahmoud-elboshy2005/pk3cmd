
#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// APPLICATION VERSION
extern const char *APP_VERSION;
extern const uint8_t DEV_FILE_COMPAT_LEVEL;
extern const uint8_t DEV_FILE_COMPAT_LEVEL_MIN;
extern const char *USER_GUIDE_FILE_NAME_PK2;
extern const char *USER_GUIDE_FILE_NAME_PK3;

// min firmware version Pk2
extern const uint8_t FW_VER_MAJOR_REQ;
extern const uint8_t FW_VER_MINOR_REQ;
extern const uint8_t FW_VER_DOT_REQ;
extern const char *FW_FILE_NAME;

// min firmware version Pk3
extern const uint8_t FW_VER_MAJOR_REQ_PK3;
extern const uint8_t FW_VER_MINOR_REQ_PK3;
extern const uint8_t FW_VER_DOT_REQ_PK3;
extern const char *FW_FILE_NAME_PK3;
extern const char *BL_FILE_NAME_PK3; // matches the MPLAB bootlaoder version number

#define PACKET_SIZE         65 // 64 + leading 0
#define USB_REPORT_LENGTH   64
//
#define BIT_MASK_0  0x01
#define BIT_MASK_1  0x02
#define BIT_MASK_2  0x04
#define BIT_MASK_3  0x08
#define BIT_MASK_4  0x10
#define BIT_MASK_5  0x20
#define BIT_MASK_6  0x40
#define BIT_MASK_7  0x80
//
#define MCHIP_VENDOR_ID         0x04D8
#define PK2_DEVICE_ID           0x0033
#define PK3_DEVICE_ID           0x900A
#define PK3_MAGIC_KEY           0x336B50
#define MPLAB_BOOTLOADER_TYPE   0x99;

//
#define CONFIG_ROWS         2
#define CONFIG_COLUMNS      4
#define MAX_READ_CFG_MASKS  8
#define NUM_CONFIG_MASKS    9
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

#define VDD_THRESHOLD_FOR_SELF_POWERED_TARGET   2.3F
#define NO_MESSAGE                  false
#define SHOW_MESSAGE                true
#define UPDATE_MEMORY_DISPLAYS      true
#define DONT_UPDATE_MEMORY_DISPLAYS false
#define ERASE_EEPROM                true
#define WRITE_EEPROM                false

//
#define UPLOAD_BUFFER_SIZE    128
#define DOWNLOAD_BUFFER_SIZE  256
//
#define READ_FW_FLASH         1
#define WRITE_FW_FLASH        2
#define ERASE_FW_FLASH        3
#define READ_FW_EEPROM_DATA   4
#define WRITE_FW_EEPROM_DATA  5
#define RESET_FW_DEVICE       0xFF
//
#define SWITCH_TO_BL          0x24
#define TEST_BOOTLOADER       0x2A
#define GET_VERSIONS_MPLAB    0x41
#define ENTER_BOOTLOADER      0x42
#define NO_OPERATION          0x5A
#define FIRMWARE_VERSION      0x76
#define SET_VDD               0xA0
#define SET_VPP               0xA1
#define READ_STATUS           0xA2
#define READ_VOLTAGES         0xA3
#define DOWNLOAD_SCRIPT       0xA4
#define RUN_SCRIPT            0xA5
#define EXECUTE_SCRIPT        0xA6
#define CLR_DOWNLOAD_BUFFER   0xA7
#define DOWNLOAD_DATA         0xA8
#define CLR_UPLOAD_BUFFER     0xA9
#define UPLOAD_DATA           0xAA
#define CLR_SCRIPT_BUFFER     0xAB
#define UPLOAD_DATA_NO_LEN    0xAC
#define END_OF_BUFFER         0xAD
#define RESET                 0xAE
#define SCRIPT_BUFFER_CHKSUM  0xAF
#define SET_VOLTAGE_CALS      0xB0
#define WR_INTERNAL_EEPROM    0xB1
#define RD_INTERNAL_EEPROM    0xB2
#define ENTER_UART_MODE       0xB3
#define EXIT_UART_MODE        0xB4
#define ENTER_LEARN_MODE      0xB5
#define EXIT_LEARN_MODE       0xB6
#define ENABLE_PK2GO_MODE     0xB7
#define LOGIC_ANALYZER_GO     0xB8
#define COPY_RAM_UPLOAD       0xB9
// META COMMANDS
#define MC_READ_OSCCAL        0x80
#define MC_WRITE_OSCCAL       0x81
#define MC_START_CHECKSUM     0x82
#define MC_VERIFY_CHECKSUM    0x83
#define MC_CHECK_DEVICE_ID    0x84
#define MC_READ_BANDGAP       0x85
#define MC_WRITE_CFG_BANDGAP  0x86
#define MC_CHANGE_CHKSM_FRMT  0x87
//
#define _VDD_ON               0xFF
#define _VDD_OFF              0xFE
#define _VDD_GND_ON           0xFD
#define _VDD_GND_OFF          0xFC
#define _VPP_ON               0xFB
#define _VPP_OFF              0xFA
#define _VPP_PWM_ON           0xF9
#define _VPP_PWM_OFF          0xF8
#define _MCLR_GND_ON          0xF7
#define _MCLR_GND_OFF         0xF6
#define _BUSY_LED_ON          0xF5
#define _BUSY_LED_OFF         0xF4
#define _SET_ICSP_PINS        0xF3
#define _WRITE_BYTE_LITERAL   0xF2
#define _WRITE_BYTE_BUFFER    0xF1
#define _READ_BYTE_BUFFER     0xF0
#define _READ_BYTE            0xEF
#define _WRITE_BITS_LITERAL   0xEE
#define _WRITE_BITS_BUFFER    0xED
#define _READ_BITS_BUFFER     0xEC
#define _READ_BITS            0xEB
#define _SET_ICSP_SPEED       0xEA
#define _LOOP                 0xE9
#define _DELAY_LONG           0xE8
#define _DELAY_SHORT          0xE7
#define _IF_EQ_GOTO           0xE6
#define _IF_GT_GOTO           0xE5
#define _GOTO_INDEX           0xE4
#define _EXIT_SCRIPT          0xE3
#define _PEEK_SFR             0xE2
#define _POKE_SFR             0xE1

#define _ICD_SLAVE_RX         0xE0
#define _ICD_SLAVE_TX_LIT     0xDF
#define _ICD_SLAVE_TX_BUF     0xDE
#define _LOOP_BUFFER          0xDD
#define _ICSP_STATES_BUFFER   0xDC
#define _POP_DOWNLOAD         0xDB
#define _COREINST18           0xDA
#define _COREINST24           0xD9
#define _NOP24                0xD8
#define _VISI24               0xD7
#define _RD2_BYTE_BUFFER      0xD6
#define _RD2_BITS_BUFFER      0xD5
#define _WRITE_BUFWORD_W      0xD4
#define _WRITE_BUFBYTE_W      0xD3
#define _CONST_WRITE_DL       0xD2

#define _WRITE_BITS_LIT_HLD   0xD1
#define _WRITE_BITS_BUF_HLD   0xD0
#define _SET_AUX              0xCF
#define _AUX_STATE_BUFFER     0xCE
#define _I2C_START            0xCD
#define _I2C_STOP             0xCC
#define _I2C_WR_BYTE_LIT      0xCB
#define _I2C_WR_BYTE_BUF      0xCA
#define _I2C_RD_BYTE_ACK      0xC9
#define _I2C_RD_BYTE_NACK     0xC8
#define _SPI_WR_BYTE_LIT      0xC7
#define _SPI_WR_BYTE_BUF      0xC6
#define _SPI_RD_BYTE_BUF      0xC5
#define _SPI_RDWR_BYTE_LIT    0xC4
#define _SPI_RDWR_BYTE_BUF    0xC3
#define _ICD_SLAVE_RX_BL      0xC2
#define _ICD_SLAVE_TX_LIT_BL  0xC1
#define _ICD_SLAVE_TX_BUF_BL  0xC0
#define _MEASURE_PULSE        0xBF
#define _UNIO_TX              0xBE
#define _UNIO_TX_RX           0xBD
#define _JT2_SETMODE          0xBC
#define _JT2_SENDCMD          0xBB
#define _JT2_XFERDATA8_LIT    0xBA
#define _JT2_XFERDATA32_LIT   0xB9
#define _JT2_XFRFASTDAT_LIT   0xB8
#define _JT2_XFRFASTDAT_BUF   0xB7
#define _JT2_XFERINST_BUF     0xB6
#define _JT2_GET_PE_RESP      0xB5
#define _JT2_WAIT_PE_RESP     0xB4
//
#define SEARCH_ALL_FAMILIES   0xFFFFFF
//
// Script Buffer Reserved Locations
#define PROG_ENTRY        0
#define PROG_EXIT         1
#define RD_DEVID          2
#define PROGMEM_RD        3
#define ERASE_CHIP_PREP   4
#define PROGMEM_ADDRSET   5
#define PROGMEM_WR_PREP   6
#define PROGMEM_WR        7
#define EEPROM_RD_PREP    8
#define EEPROM_RD         9
#define EEPROM_WR_PREP    10
#define EEPROM_WR         11
#define CONFIG_RD_PREP    12
#define CONFIG_RD         13
#define CONFIG_WR_PREP    14
#define CONFIG_WR         15
#define USERID_RD_PREP    16
#define USERID_RD         17
#define USERID_WR_PREP    18
#define USERID_WR         19
#define OSSCAL_RD         20
#define OSSCAL_WR         21
#define ERASE_CHIP        22
#define ERASE_PROGMEM     23
#define ERASE_EE          24
#define ERASE_CONFIG      25
#define ROW_ERASE         26
#define TEST_MEM_RD       27
#define EEPROM_ROW_ERASE  28

// OSCCAL valid mask in config masks
#define OSCCAL_MASK       7

// EEPROM config words
#define PROTOCOL_CFG      0
#define ADR_MASK_CFG      1
#define ADR_BITS_CFG      2
#define CS_PINS_CFG       3
// EEPROM Protocols
#define I2C_BUS           1
#define SPI_BUS           2
#define MICROWIRE_BUS     3
#define UNIO_BUS          4
#define READ_BIT          true
#define WRITE_BIT         false

// for user32.dll window flashing
//Stop flashing. The system restores the window to its original state. 
#define FLASHW_STOP       0
//Flash the window caption. 
#define FLASHW_CAPTION    1
//Flash the taskbar button. 
#define FLASHW_TRAY       2
//Flash both the window caption and taskbar button.
//This is equivalent to setting the FLASHW_CAPTION | FLASHW_TRAY flags. 
#define FLASHW_ALL        3
//Flash continuously, until the FLASHW_STOP flag is set. 
#define FLASHW_TIMER      4
//Flash continuously until the window comes to the foreground. 
#define FLASHW_TIMERNOFG  12

// PICkit 2 internal EEPROM Locations
#define ADC_CAL_L         0x00
#define ADC_CAL_H         0x01
#define CPP_OFFSET        0x02
#define CPP_CAL           0x03
#define UNIT_ID           0xF0  //through 0xFF

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
#define P32_PROGRAM_FLASH_START_ADDR  0x1D000000
#define P32_BOOT_FLASH_START_ADDR     0x1FC00000

// OSCCAL regeration
extern const uint32_t BASELINE_CAL[];
extern const uint32_t MR16F676FAM_CAL[];

#endif // _CONSTANTS_H_