
#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <stddef.h>

/**
 * @brief Converts a string representing a numeric value to an integer.
 * @param p_value The string representing the numeric value.
 * @return The converted integer.
 */
int convert_value_to_int(const char *p_value);

/**
 * @brief Converts an integer to ASCII representation.
 * @param to_convert The integer to convert.
 * @param num_bytes The number of bytes to convert.
 * @param p_out The output buffer.
 * @param len The length of the output buffer.
 * @return 0 on success, -1 on failure.
 */
int convert_int_to_ascii(int to_convert, int num_bytes, char *p_out, size_t len);

/**
 * @brief Converts an integer to ASCII representation in reverse order.
 * @param to_convert The integer to convert.
 * @param num_bytes The number of bytes to convert.
 * @param p_out The output buffer.
 * @param len The length of the output buffer.
 * @return 0 on success, -1 on failure.
 */
int convert_int_to_ascii_reverse(int to_convert, int num_bytes, char *p_out, size_t len);

#endif // _UTILITIES_H_