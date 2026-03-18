
#ifndef _PICKIT_HELPER_H_
#define _PICKIT_HELPER_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef pickit_helper_t pickit_helper_t;
struct pickit_helper_t
{
  bool fw_download_success;
  uint8_t os_typ;
  uint8_t os_maj;
  uint8_t os_min;
  uint8_t os_rev;
  uint8_t ap_typ;
  uint8_t ap_maj;
  uint8_t ap_min;
  uint8_t ap_rev;
  uint32_t magic_key;
  bool firmware_invalid;
};

extern pickit_helper_t pickit3_helper;

#endif /* _PICKIT_HELPER_H_ */