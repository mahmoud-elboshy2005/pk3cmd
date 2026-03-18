
#ifndef _PICKIT_FUNCTIONS_H_
#define _PICKIT_FUNCTIONS_H_

#define FIRMWARE_VERSION_MAX_LEN 25
#define DEVICE_FILE_VERSION_MAX_LEN 25
#define TOOL_NAME_MAX_LEN 25
#define SCRIPT_REDIRECT_MAX_LEN 32
#define FAMILY_SEARCH_TABLE_MAX_LEN 100

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "usb.h"
#include "constants.h"
#include "device_file.h"
#include "device_data.h"

typedef struct pickit_t pickit_t;
struct pickit_t
{
  char firmware_version[FIRMWARE_VERSION_MAX_LEN];
  char device_file_version[DEVICE_FILE_VERSION_MAX_LEN];
  device_file_t dev_file;
  device_data_t device_buffers;
  uint8_t usb_write_array[PACKET_SIZE];
  uint8_t usb_read_array[PACKET_SIZE];
  int32_t active_part;
  uint32_t last_device_id;
  int32_t last_device_rev;
  bool learn_mode;
  uint8_t last_icsp_speed;
  char tool_name[TOOL_NAME_MAX_LEN];
  bool is_pk3;
};

extern pickit_t pickit;

/**
 * @brief Checks communication with the PICkit device by sending a known command sequence and verifying the response.
 * @return true if communication is successful, false otherwise.
 */
bool check_comm();

/**
 * @brief Retrieves the firmware version and device file version from the PICkit device in the format expected by MPLAB.
 * @return true if the versions were successfully retrieved, false otherwise.
 */
bool get_versions_mplab();

/**
 * @brief Disconnects the currently connected PICkit 2 unit by closing the USB connection.
 */
void disconnect_pickit2_unit();

/**
 * @brief Retrieves the serial unit ID of the currently connected PICkit device.
 * @return A pointer to a string containing the serial unit ID.
 */
char *get_serial_unit_id();

/**
 * @brief Detects a PICkit 2 device and retrieves its information.
 * @param pk2_id The ID of the PICkit 2 device to detect.
 * @param read_fw Whether to read the firmware version.
 * @return The status of the detection process.
 */
enum pickit_2_usb_t detect_pickit2_device(uint16_t pk2_id, bool read_fw);

/**
 * @brief Writes a command list to the PICkit device over USB.
 * @param command_list An array of bytes representing the command list to be sent.
 * @param len The length of the command list array.
 * @return true if the command list was successfully written to the device, false otherwise.
 */
bool write_usb(uint8_t command_list[], size_t len);

/**
 * @brief Writes a command list to the PICkit device over USB in the format expected from an MPLAB host.
 * @param command_list An array of bytes representing the command list to be sent.
 * @param len The length of the command list array.
 * @return true if the command list was successfully written to the device, false otherwise.
 */
bool write_usb_mplab(uint8_t command_list[], size_t len);

/**
 * @brief Reads data from the PICkit device over USB into the pickit.usb_read_array buffer.
 * @return true if data was successfully read from the device, false otherwise.
 */
bool read_usb();

#endif // _PICKIT_FUNCTIONS_H_