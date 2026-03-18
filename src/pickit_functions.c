#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../include/usb.h"
#include "../include/constants.h"
#include "../include/utilities.h"
#include "../include/device_file.h"
#include "../include/device_data.h"
#include "../include/pickit_functions.h"

typedef struct script_redirect_t script_redirect_t;
struct script_redirect_t
{
  uint8_t redirect_to_script_location;
  int32_t device_file_script_number;
};

pickit_t pickit = {
  .firmware_version = "NA",
  .device_file_version = "NA",
  .active_part = 0,
  .last_device_id = 0,
  .last_device_rev = 0,
  .learn_mode = false,
  .last_icsp_speed = 0,
  .tool_name = "PICkit 3",
  .is_pk3 = true,
  // .tool_name[TOOL_NAME_MAX_LEN] = "PICkit 2",
  // .is_pk3 = false,
};


static usb_ctx_t usb_ctx;
static uint16_t last_pk2_number = 0xFF;
static int32_t family_search_table[FAMILY_SEARCH_TABLE_MAX_LEN]; // index is search priority, value is family array index.
static bool vdd_on = false;
static float vdd_last_set = 3.3F;  // needed when a family VPP=VDD (PIC18J, PIC24, etc.)
static bool target_self_powered = false;
static bool fast_programming = true;
static bool assert_mclr = false;
static bool vpp_first_enabled = false;
static bool lvp_enabled = false;
static uint32_t script_buffer_checksum = 0;
static int32_t last_found_part = 0;
static script_redirect_t script_redirect_table[SCRIPT_REDIRECT_MAX_LEN]; // up to 32 scripts in FW
static int32_t usb_byte_count = 0;


bool check_comm()
{
  uint8_t command_array[17];
  command_array[0] = CLR_DOWNLOAD_BUFFER;
  command_array[1] = DOWNLOAD_DATA;
  command_array[2] = 8;
  command_array[3] = 0x01;
  command_array[4] = 0x02;
  command_array[5] = 0x03;
  command_array[6] = 0x04;
  command_array[7] = 0x05;
  command_array[8] = 0x06;
  command_array[9] = 0x07;
  command_array[10] = 0x08;
  command_array[11] = COPY_RAM_UPLOAD;   // DL buffer starts at 0x100
  command_array[12] = 0x00;
  command_array[13] = 0x01;
  command_array[14] = UPLOAD_DATA;
  command_array[15] = CLR_DOWNLOAD_BUFFER;
  command_array[16] = CLR_UPLOAD_BUFFER;

  if (write_usb(command_array, sizeof(command_array)))
  {
    if (read_usb())
    {
      if (pickit.usb_read_array[1] == 63)
      {
        for (int i = 1; i < 9; i++)
        {
          if (pickit.usb_read_array[1 + i] != i)
          {
            return false;
          }
        }
        return true;
      }
    }
  }
  return false;
}


bool write_usb(uint8_t command_list[], size_t len)
{
  if (!command_list || len == 0 || len > PACKET_SIZE - 1) // -1 because first byte of packet is reserved for report ID (must be zero)
    return false;

  int bytes_written = 0;

  // usb_byte_count += len;
  // usb_byte_count++;

  pickit.usb_write_array[0] = 0;                         // first byte must always be zero.        
  for (size_t index = 1; index < sizeof(pickit.usb_write_array); index++)
  {
    pickit.usb_write_array[index] = END_OF_BUFFER;              // init array to all END_OF_BUFFER cmds.
  }
  
  memcpy(pickit.usb_write_array + 1, command_list, len); // copy command list to array starting at index 1.

  bytes_written = usb_write_packet(&usb_ctx, pickit.usb_write_array, sizeof(pickit.usb_write_array));
  
  if (bytes_written != (int)sizeof(pickit.usb_write_array))
  {
    return false;
  }
  return true;
}

// Simiar to write_usb but uses the format expected from an MPLAB host with the length at the end of the USB buffer
bool write_usb_mplab(uint8_t command_list[], size_t len)
{
  if (!command_list || len == 0 || len > PACKET_SIZE - 1) // -1 because first byte of packet is reserved for report ID (must be zero)
    return false;

  int bytes_written = 0;
  int command_length = len;

  pickit.usb_write_array[0] = 0;                         // first byte must always be zero.        
  for (size_t index = 1; index < sizeof(pickit.usb_write_array); index++)
  {
    pickit.usb_write_array[index] = END_OF_BUFFER;              // init array to all END_OF_BUFFER cmds.
  }
  memcpy(pickit.usb_write_array + 1, command_list, len);

  // Emded the length as expected from an MPLAB host
  pickit.usb_write_array[61] = (uint8_t)(command_length & 0xFF);
  pickit.usb_write_array[62] = (uint8_t)((command_length >> 8) & 0xFF);
  pickit.usb_write_array[63] = (uint8_t)((command_length >> 16) & 0xFF);
  pickit.usb_write_array[64] = (uint8_t)((command_length >> 24) & 0xFF);

  bytes_written = usb_write_packet(&usb_ctx, pickit.usb_write_array, sizeof(pickit.usb_write_array));
  
  if (bytes_written != (int)sizeof(pickit.usb_write_array))
  {
    return false;
  }
  return true;
}

bool read_usb()
{
  int bytes_read = 0;

  if (pickit.learn_mode)
    return true;

  bytes_read = usb_read_packet(&usb_ctx, pickit.usb_read_array, sizeof(pickit.usb_read_array), 1000);
  if (bytes_read != (int)sizeof(pickit.usb_read_array))
  {
    return false;
  }
  return true;
}