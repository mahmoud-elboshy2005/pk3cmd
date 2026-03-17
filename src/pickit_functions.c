#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
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
// static int32_t usb_byte_count = 0;
