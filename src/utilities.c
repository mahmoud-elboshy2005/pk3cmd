#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include "../include/utilities.h"

static int parse_binary_value(const char *digits)
{
  int value = 0;

  if (!digits || digits[0] == '\0')
  {
    return 0;
  }

  for (size_t i = 0; digits[i] != '\0'; ++i)
  {
    value <<= 1;
    if (digits[i] == '1')
    {
      value |= 1;
    }
    else if (digits[i] != '0')
    {
      return 0;
    }
  }

  return value;
}

int convert_value_to_int(const char *p_value)
{
  // Supports decimal, 0x-prefixed hex, b/0b-prefixed binary, and Y/N values.
  if (!p_value || p_value[0] == '\0')
  {
    return 0;
  }

  if (p_value[0] == 'Y' || p_value[0] == 'y')
  {
    return 1;
  }

  if (p_value[0] == 'N' || p_value[0] == 'n')
  {
    return 0;
  }

  if ((p_value[0] == '0' && (p_value[1] == 'b' || p_value[1] == 'B')) ||
      (p_value[0] == 'b' || p_value[0] == 'B'))
  {
    const char *digits = (p_value[0] == '0') ? (p_value + 2) : (p_value + 1);
    return parse_binary_value(digits);
  }

  if (p_value[0] == '0' && (p_value[1] == 'x' || p_value[1] == 'X'))
  {
    char *end_ptr = NULL;
    long value;

    errno = 0;
    value = strtol(p_value + 2, &end_ptr, 16);
    if (errno != 0 || !end_ptr || *end_ptr != '\0')
    {
      return 0;
    }
    return (int)value;
  }

  {
    char *end_ptr = NULL;
    long value;

    errno = 0;
    value = strtol(p_value, &end_ptr, 10);
    if (errno != 0 || !end_ptr || *end_ptr != '\0')
    {
      return 0;
    }
    return (int)value;
  }
}

int convert_int_to_ascii(int to_convert, int num_bytes, char *p_out, size_t len)
{
  unsigned int value = (unsigned int)to_convert;

  if (!p_out || num_bytes <= 0 || num_bytes > 4 || len < (size_t)num_bytes + 1U)
  {
    return -1;
  }

  for (int i = num_bytes; i > 0; --i)
  {
    unsigned char c = (unsigned char)value;
    p_out[i - 1] = (c >= 0x20U && c <= 0x7EU) ? (char)c : '.';
    value >>= 8;
  }

  p_out[num_bytes] = '\0';
  return 0;
}

int convert_int_to_ascii_reverse(int to_convert, int num_bytes, char *p_out, size_t len)
{
  // ASCII characters are output in reverse byte order with spaces between bytes.
  unsigned int value = (unsigned int)to_convert;
  size_t out_len;

  if (!p_out || num_bytes <= 0 || num_bytes > 4)
  {
    return -1;
  }

  out_len = (size_t)(2 * num_bytes - 1);
  if (len < out_len + 1U)
  {
    return -1;
  }

  for (size_t i = 0; i < out_len; ++i)
  {
    if ((i % 2U) == 1U)
    {
      p_out[i] = ' ';
    }
    else
    {
      unsigned char c = (unsigned char)value;
      p_out[i] = (c >= 0x20U && c <= 0x7EU) ? (char)c : '.';
      value >>= 8;
    }
  }

  p_out[out_len] = '\0';
  return 0;
}
