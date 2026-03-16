
#ifndef _DEVICE_FILE_H_
#define _DEVICE_FILE_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define FAMILY_NAME_MAX_LEN 25
#define PART_NAME_MAX_LEN 21
#define SCRIPT_NAME_MAX_LEN 21
#define COMMENT_MAX_LEN 21
#define VERSION_NOTES_MAX_LEN 513

typedef struct device_file_params_t device_file_params_t;
struct device_file_params_t
{
  // One instance of this structure is included at the start of the Device File
  int32_t version_major;    // Device file version number major.minor.dot
  int32_t version_minor;
  int32_t version_dot;

  char version_notes[VERSION_NOTES_MAX_LEN]; // Max 512 characters + null terminator

  int32_t number_families;  // # number of DeviceFamilyParams sets
  int32_t number_parts;     // # number of DevicePartParams sets
  int32_t number_scripts;   // # number of DeviceScripts sets
  uint8_t compatibility;
  uint8_t unused_1a;
  uint16_t unused_1b;
  uint32_t unused_2;
};

typedef struct device_family_params_t device_family_params_t;
struct device_family_params_t
{
  // a single struct instance describes the parameters for an entire part family.
  uint16_t family_id;             // # essentially, its array index number.
  uint16_t family_type;           // also used as the display order in the Device Family Menu - lower first
  uint16_t search_priority;
  char family_name[FAMILY_NAME_MAX_LEN];           // 16 -> 24 chars max (v2.50)
  uint16_t prog_entry_script;
  uint16_t prog_exit_script;
  uint16_t read_dev_id_script;
  uint32_t device_id_mask;           // HEX
  uint32_t blank_value;             // HEX
  uint8_t bytes_per_location;
  uint8_t address_increment; 
  bool part_detect;
  uint16_t prog_entry_vpp_script;   // program entry VPP first
  uint16_t unused_1;    
  uint8_t eeprom_mem_bytes_per_word;
  uint8_t eeprom_mem_address_increment;
  uint8_t user_id_hex_bytes;
  uint8_t user_id_bytes;
  uint8_t prog_mem_hex_bytes;   // added 7-10-06
  uint8_t eeprom_mem_hex_bytes;   // added 7-10-06
  uint8_t prog_mem_shift;   // added 7-10-06
  uint32_t test_memory_start;        // HEX
  uint16_t test_memory_length;
  float vpp;
};

typedef struct device_part_params_t device_part_params_t;
struct device_part_params_t
{
  // a single struct instance describes parameters for a single silicon part.
  char part_name[PART_NAME_MAX_LEN];             // 20 chars max
  uint16_t family;               // references FamilyID in DeviceFamilyParams
  uint32_t device_id;
  uint32_t program_mem;
  uint16_t eeprom_mem;
  uint32_t eeprom_addr;
  uint8_t config_words;
  uint32_t config_addr;             // HEX
  uint8_t user_id_words;
  uint32_t user_id_addr;             // HEX
  uint32_t band_gap_mask;            // HEX
  uint16_t *config_masks;        // HEX 
  uint16_t *config_blank;        // HEX 
  uint16_t cp_mask;               // HEX
  uint8_t cp_config;
  bool osccal_save;
  uint32_t ignore_address;          // HEX
  float vdd_min;
  float vdd_max;
  float vdd_erase;
  uint8_t calibration_words;
  uint16_t chip_erase_script;
  uint16_t prog_mem_addr_set_script;
  uint8_t prog_mem_addr_bytes;
  uint16_t prog_mem_rd_script;
  uint16_t prog_mem_rd_words;
  uint16_t eeprom_rd_prep_script;
  uint16_t eeprom_rd_script;
  uint16_t eeprom_rd_locations;
  uint16_t user_id_rd_prep_script;
  uint16_t user_id_rd_script;
  uint16_t config_rd_prep_script;
  uint16_t config_rd_script;
  uint16_t prog_mem_wr_prep_script;
  uint16_t prog_mem_wr_script;
  uint16_t prog_mem_wr_words;
  uint8_t  prog_mem_panel_bufs;
  uint32_t prog_mem_panel_offset;
  uint16_t eeprom_wr_prep_script;
  uint16_t eeprom_wr_script;
  uint16_t eeprom_wr_locations;
  uint16_t user_id_wr_prep_script;
  uint16_t user_id_wr_script;
  uint16_t config_wr_prep_script;
  uint16_t config_wr_script;
  uint16_t osccal_rd_script;
  uint16_t osccal_wr_script;
  uint16_t dp_mask;
  bool write_cfg_on_erase;
  bool blank_check_skip_usr_ids;
  uint16_t ignore_bytes;            
  uint16_t chip_erase_prep_script;
  uint32_t boot_flash;
  // uint32_t UNUSED4;
  uint16_t config_9_mask;
  uint16_t config_9_blank;
  uint16_t prog_mem_erase_script; // added 7-10-06
  uint16_t eeprom_mem_erase_script; // added 7-10-06
  uint16_t config_mem_erase_script; // added 7-10-06
  uint16_t reserved_1_erase_script; // added 7-10-06
  uint16_t reserved_2_erase_script; // added 7-10-06
  uint16_t test_memory_rd_script;
  uint16_t test_memory_rd_words;
  uint16_t eeprom_row_erase_script;
  uint16_t eeprom_row_erase_words;
  bool export_to_mplab;
  uint16_t debug_halt_script;
  uint16_t debug_run_script;
  uint16_t debug_status_script;
  uint16_t debug_read_exec_ver_script;
  uint16_t debug_single_step_script;
  uint16_t debug_bulk_wr_data_script;
  uint16_t debug_bulk_rd_data_script;
  uint16_t debug_write_vector_script;
  uint16_t debug_read_vector_script;
  uint16_t debug_row_erase_script;
  uint16_t debug_row_erase_size;
  uint16_t debug_reserved_5_script;
  uint16_t debug_reserved_6_script;
  uint16_t debug_reserved_7_script;
  uint16_t debug_reserved_8_script;
  // uint16_t debug_reserved_9_script;
  uint16_t lvp_script;
};

typedef struct device_scripts_t device_scripts_t;
struct device_scripts_t
{
  uint16_t script_number;         // # Essentially, its array index number - 1 based 0 reserved for no script
  // referred to in the XxxxxxScript fields of DevicePartParams
  char script_name[SCRIPT_NAME_MAX_LEN];           // 20 Chars max
  uint16_t script_version;        // increments on each change
  uint32_t unused_1;
  uint16_t script_length;
  uint16_t *script;
  char comment[COMMENT_MAX_LEN];            // 20 max
};

typedef struct device_file_t device_file_t;
struct device_file_t
{
  device_file_params_t info;
  device_family_params_t *families;
  device_part_params_t *parts_list;
  device_scripts_t *scripts;
};

#endif /* _DEVICE_FILE_H_ */