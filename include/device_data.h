
#ifndef _DEVICE_DATA_H_
#define _DEVICE_DATA_H_

#include <stddef.h>
#include <stdint.h>

typedef struct device_data_t device_data_t;
struct device_data_t {
  uint32_t *program_memory;
  size_t program_memory_size;
  uint32_t *eeprom_memory;
  size_t eeprom_memory_size;
  uint32_t *config_words;
  size_t config_words_size;
  uint32_t *user_ids;
  size_t user_ids_size;
  uint32_t osccal;
  uint32_t band_gap;
};

/**
 * @brief Initializes a device_data_t structure with allocated memory and default values.
 * @param device_data Pointer to the device_data_t structure to initialize.
 * @param prog_mem_size Size of the program memory.
 * @param eeprom_mem_size Size of the EEPROM memory.
 * @param num_configs Number of configuration words.
 * @param num_ids Number of user IDs.
 * @param mem_blank_val Blank value for memory initialization.
 * @param eeprom_bytes Number of bytes per EEPROM location.
 * @param id_bytes Number of bytes per user ID.
 * @param config_blank Array of blank values for configuration words.
 * @param osccal_init Initial value for the oscillator calibration.
 * @return 0 on success, -1 on failure.
 */
int device_data_create(device_data_t *device_data,
                        size_t prog_mem_size,
                        size_t eeprom_mem_size,
                        size_t num_configs,
                        size_t num_ids,
                        uint32_t mem_blank_val,
                        int32_t eeprom_bytes,
                        int32_t id_bytes,
                        const uint16_t config_blank[],
                        uint32_t osccal_init);

/**
 * @brief Frees allocated memory and resets the device_data_t structure.
 * @param device_data Pointer to the device_data_t structure to delete.
 * @return 0 on success, -1 on failure.
 */
int device_data_delete(device_data_t *device_data);

/**
 * @brief Clears the program memory by setting all locations to a blank value.
 * @param device_data Pointer to the device_data_t structure containing the program memory.
 * @param mem_blank_val Blank value to set for each location in the program memory.
 * @return 0 on success, -1 on failure.
 */
int device_data_clear_program_memory(device_data_t *device_data, uint32_t mem_blank_val);

/**
 * @brief Clears the configuration words by setting all locations to a blank value.
 * @param device_data Pointer to the device_data_t structure containing the configuration words.
 * @param config_blank Array of blank values for configuration words.
 * @return 0 on success, -1 on failure.
 */
int device_data_clear_config_words(device_data_t *device_data, const uint16_t config_blank[]);

/**
 * @brief Clears the user IDs by setting all locations to a blank value.
 * @param device_data Pointer to the device_data_t structure containing the user IDs.
 * @param id_bytes Number of bytes per user ID.
 * @param mem_blank_val Blank value to set for each location in the user IDs.
 * @return 0 on success, -1 on failure.
 */
int device_data_clear_user_ids(device_data_t *device_data, int32_t id_bytes, uint32_t mem_blank_val);

/**
 * @brief Clears the EEPROM memory by setting all locations to a blank value.
 * @param device_data Pointer to the device_data_t structure containing the EEPROM memory.
 * @param eeprom_bytes Number of bytes per EEPROM location.
 * @param mem_blank_val Blank value to set for each location in the EEPROM memory.
 * @return 0 on success, -1 on failure.
 */
int device_data_clear_eeprom_memory(device_data_t *device_data, int32_t eeprom_bytes, uint32_t mem_blank_val);

#endif // _DEVICE_DATA_H_