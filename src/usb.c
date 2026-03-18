
// usb_linux.c
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <hidapi/hidapi.h>
#include "../include/usb.h"

static void wide_to_utf8(const wchar_t *w, char *out, size_t out_sz)
{
  if (!w || !out || out_sz == 0)
    return;
  
  size_t n = wcstombs(out, w, out_sz - 1);
  if (n == (size_t)-1)
  {
    out[0] = '\0';
    return;
  }
  out[n] = '\0';
}

static void set_fallback_serial(usb_ctx_t *ctx, const char *fallback)
{
  if (!ctx || !fallback)
    return;

  size_t len = strlen(ctx->unit_id);
  strncpy(ctx->unit_id, fallback, len - 1);
  ctx->unit_id[len - 1] = '\0';
}

int find_this_device(uint16_t vendor_id,
                     uint16_t product_id,
                     uint16_t index,
                     usb_ctx_t *ctx)
{
  if (!ctx)
    return -1;

  // Ensure wchar/multibyte conversions behave according to current locale.
  setlocale(LC_CTYPE, "");
  memset(ctx, 0, sizeof(*ctx));

  struct hid_device_info *devs = NULL, *cur = NULL;
  uint16_t found = 0;
  wchar_t serial_w[64];

  if (hid_init() != 0)
    return -1;

  devs = hid_enumerate(vendor_id, product_id);
  cur = devs;

  while (cur)
  {
    if (found == index)
    {
      ctx->handle = hid_open_path(cur->path);

      if (!ctx->handle)
        break;

      memset(serial_w, 0, sizeof(serial_w));
      if (hid_get_serial_number_string(ctx->handle, serial_w, 64) == 0)
      {
        if (serial_w[0] == L'\t' || serial_w[0] == L'\0')
          set_fallback_serial(ctx, "Blank Serial Number");
        else
          wide_to_utf8(serial_w, ctx->unit_id, sizeof(ctx->unit_id));
      }
      else
      {
        set_fallback_serial(ctx, "Unknown Serial Number");
      }

      hid_free_enumeration(devs);
      return 0;
    }

    found++;
    cur = cur->next;
  }

  hid_free_enumeration(devs);
  hid_exit();
  return -1;
}

int usb_write_packet(usb_ctx_t *ctx, const uint8_t *buf, size_t len)
{
  if (!ctx || !ctx->handle || !buf || len == 0)
    return -1;

  // hidapi expects report ID at byte 0. For devices without report IDs, set byte 0 = 0.
  return hid_write(ctx->handle, (const unsigned char *)buf, len);
}

int usb_read_packet(usb_ctx_t *ctx, uint8_t *buf, size_t len, int timeout_ms)
{
  if (!ctx || !ctx->handle || !buf || timeout_ms < 0 || len == 0)
    return -1;
  // hid_read_timeout returns number of bytes read, 0 on timeout, -1 on error
  return hid_read_timeout(ctx->handle, (unsigned char *)buf, len, timeout_ms);
}

void usb_close(usb_ctx_t *ctx)
{
  if (!ctx)
    return;

  if (ctx->handle)
  {
    hid_close(ctx->handle);
    ctx->handle = NULL;
  }
  ctx->unit_id[0] = '\0';

  hid_exit();
}
