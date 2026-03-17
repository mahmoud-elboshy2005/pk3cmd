
#ifndef _PICKIT_FUNCTIONS_H_
#define _PICKIT_FUNCTIONS_H_

#define FIRMWARE_VERSION_MAX_LEN 25
#define DEVICE_FILE_VERSION_MAX_LEN 25
#define TOOL_NAME_MAX_LEN 25
#define SCRIPT_REDIRECT_MAX_LEN 32
#define FAMILY_SEARCH_TABLE_MAX_LEN 100

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

#endif // _PICKIT_FUNCTIONS_H_