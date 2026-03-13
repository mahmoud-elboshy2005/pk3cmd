
#ifndef _USB_H_
#define _USB_H_

#include <stdint.h>
#include <hidapi/hidapi.h>

/**
 * @brief USB context structure to hold device handle and unit ID (serial number)
 */
typedef struct usb_ctx_t
{
  hid_device *handle; // same handle for read/write
  char unit_id[128];  // UTF-8 serial
} usb_ctx_t;

/**
 * @brief Find and open a USB HID device by vendor ID, product ID, and index.
 * @param vendor_id The vendor ID of the device to find
 * @param product_id The product ID of the device to find
 * @param index Zero-based index among matching devices.
 * @param ctx The USB context structure to initialize.
 * @return 0 on success, -1 on failure.
 */
int find_this_device(uint16_t vendor_id,
                     uint16_t product_id,
                     uint16_t index,
                     usb_ctx_t *ctx);

/**
 * @brief Write a packet to the USB device.
 * @param ctx The USB context with an open device handle
 * @param buf The buffer containing the data to write
 * @param len The length of the data to write
 * @return Number of bytes written on success, -1 on failure.
 */
int usb_write_packet(usb_ctx_t *ctx, const uint8_t *buf, size_t len);

/**
 * @brief Read a packet from the USB device with a timeout.
 * @param ctx The USB context with an open device handle
 * @param buf The buffer to store the read data
 * @param len The maximum length of data to read
 * @param timeout_ms The timeout in milliseconds for the read operation
 * @return Number of bytes read on success, 0 on timeout, -1 on failure.
 */
int usb_read_packet(usb_ctx_t *ctx, uint8_t *buf, size_t len, int timeout_ms);

/**
 * @brief Close the USB device and clean up HID resources.
 * @param ctx The USB context to clean up
 */
void usb_close(usb_ctx_t *ctx);

#endif // _USB_H_