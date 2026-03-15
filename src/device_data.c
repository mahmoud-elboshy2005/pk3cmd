#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "../include/device_data.h"

static uint32_t *alloc_words(size_t count)
{
  if (count == 0)
    return NULL;
  return (uint32_t *)malloc(sizeof(uint32_t) * count);
}

int device_data_create(
    device_data_t *device_data,
    size_t prog_mem_size,
    size_t eeprom_mem_size,
    size_t num_configs,
    size_t num_ids,
    uint32_t mem_blank_val,
    int32_t eeprom_bytes,
    int32_t id_bytes,
    const uint16_t config_blank[],
    uint32_t osccal_init)
{
  if (!device_data)
    return -1;

  device_data->program_memory = NULL;
  device_data->program_memory_size = 0;
  device_data->eeprom_memory = NULL;
  device_data->eeprom_memory_size = 0;
  device_data->config_words = NULL;
  device_data->config_words_size = 0;
  device_data->user_ids = NULL;
  device_data->user_ids_size = 0;
  device_data->osccal = 0;
  device_data->band_gap = 0;

  device_data->program_memory = alloc_words(prog_mem_size);
  if (prog_mem_size != 0 && !device_data->program_memory)
  {
    device_data_delete(device_data);
    return -1;
  }
  device_data->program_memory_size = prog_mem_size;

  device_data->eeprom_memory = alloc_words(eeprom_mem_size);
  if (eeprom_mem_size != 0 && !device_data->eeprom_memory)
  {
    device_data_delete(device_data);
    return -1;
  }
  device_data->eeprom_memory_size = eeprom_mem_size;

  device_data->config_words = alloc_words(num_configs);
  if (num_configs != 0 && !device_data->config_words)
  {
    device_data_delete(device_data);
    return -1;
  }
  device_data->config_words_size = num_configs;

  device_data->user_ids = alloc_words(num_ids);
  if (num_ids != 0 && !device_data->user_ids)
  {
    device_data_delete(device_data);
    return -1;
  }
  device_data->user_ids_size = num_ids;

  // init program memory to blank
  if (device_data_clear_program_memory(device_data, mem_blank_val) != 0)
  {
    device_data_delete(device_data);
    return -1;
  }

  // init eeprom to blank
  if (device_data_clear_eeprom_memory(device_data, eeprom_bytes, mem_blank_val) != 0)
  {
    device_data_delete(device_data);
    return -1;
  }

  // init configuration to blank
  if (device_data_clear_config_words(device_data, config_blank) != 0)
  {
    device_data_delete(device_data);
    return -1;
  }

  // init user ids to blank
  if (device_data_clear_user_ids(device_data, id_bytes, mem_blank_val) != 0)
  {
    device_data_delete(device_data);
    return -1;
  }

  // init osccal & band_gap
  device_data->osccal = osccal_init | 0xFF;
  device_data->band_gap = mem_blank_val;

  return 0;
}

int device_data_delete(device_data_t *device_data)
{
  if (!device_data)
    return -1;

  if (device_data->program_memory)
    free(device_data->program_memory);
  device_data->program_memory = NULL;
  device_data->program_memory_size = 0;

  if (device_data->eeprom_memory)
    free(device_data->eeprom_memory);
  device_data->eeprom_memory = NULL;
  device_data->eeprom_memory_size = 0;

  if (device_data->config_words)
    free(device_data->config_words);
  device_data->config_words = NULL;
  device_data->config_words_size = 0;

  if (device_data->user_ids)
    free(device_data->user_ids);
  device_data->user_ids = NULL;
  device_data->user_ids_size = 0;

  device_data->osccal = 0;
  device_data->band_gap = 0;

  return 0;
}

int device_data_clear_program_memory(device_data_t *device_data, uint32_t mem_blank_val)
{
  if (!device_data)
    return -1;

  if (device_data->program_memory_size == 0)
    return 0;

  if (!device_data->program_memory)
    return -1;

  // init program memory to blank
  for (size_t i = 0; i < device_data->program_memory_size; i++)
    device_data->program_memory[i] = mem_blank_val;

  return 0;
}

int device_data_clear_config_words(device_data_t *device_data, const uint16_t config_blank[])
{
  if (!device_data)
    return -1;

  if (device_data->config_words_size == 0)
    return 0;

  if (!device_data->config_words || !config_blank)
    return -1;

  // init configuration to blank
  for (size_t i = 0; i < device_data->config_words_size; i++)
    device_data->config_words[i] = config_blank[i];

  return 0;
}

int device_data_clear_user_ids(device_data_t *device_data, int32_t id_bytes, uint32_t mem_blank_val)
{
  if (!device_data)
    return -1;

  if (device_data->user_ids_size == 0)
    return 0;

  if (!device_data->user_ids)
    return -1;

  // init user ids to blank
  uint32_t id_blank = mem_blank_val;
  if (id_bytes == 1)
  {
    id_blank = 0xFF;
  }
  for (size_t i = 0; i < device_data->user_ids_size; i++)
  {
    device_data->user_ids[i] = id_blank;
  }

  return 0;
}

int device_data_clear_eeprom_memory(device_data_t *device_data, int32_t eeprom_bytes, uint32_t mem_blank_val)
{
  if (!device_data)
    return -1;

  if (device_data->eeprom_memory_size == 0)
    return 0;

  if (!device_data->eeprom_memory)
    return -1;

  // init eeprom to blank
  uint32_t eeprom_blank_val = 0xFF;
  if (eeprom_bytes == 2)
  {
    eeprom_blank_val = 0xFFFF;
  }
  if (mem_blank_val == 0xFFF)
  { // baseline dataflash
    eeprom_blank_val = 0xFFF;
  }
  for (size_t i = 0; i < device_data->eeprom_memory_size; i++)
  {
    device_data->eeprom_memory[i] = eeprom_blank_val; // 8-bit eeprom will just use 8 LSBs
  }
  return 0;
}
