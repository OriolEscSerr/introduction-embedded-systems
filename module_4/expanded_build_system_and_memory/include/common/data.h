/******************************************************************************
 * Copyright (C) 2025 by Oriol Escolà Serra
 *
 * This file was created as part of an educational project. You are free to 
 * use, modify, and redistribute this file for personal or educational purposes.
 *
 * Do not submit this code as original work in the Coursera course 
 * "Introduction to Embedded Systems Software and Development Environments" 
 *
 * The author is not liable for any misuse or academic dishonesty.
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of data read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to data via function calls. 
 *
 * @author Oriol Escolà Serra
 * @date 06/08/2025
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stddef.h>

/* Base conversion constants */
#define BASE_2  2
#define BASE_8  8
#define BASE_10 10
#define BASE_16 16

/**
 * @brief Converts a signed int32_t to an ASCII string
 *
 * Converts a signed integer to ASCII based on the given base (2–16)
 * and stores the result in the provided pointer. Adds null terminator.
 *
 * @param data Integer to convert
 * @param ptr Pointer to store ASCII string
 * @param base Conversion base (2 to 16)
 *
 * @return Length of the resulting string (including sign and '\0')
 */
 uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

 /**
 * @brief Converts an ASCII string to a signed int32_t
 *
 * Reads an ASCII string in a given base and returns the
 * corresponding signed integer.
 *
 * @param ptr Pointer to ASCII string
 * @param digits Number of digits to read
 * @param base Conversion base (2 to 16)
 *
 * @return Converted int32_t value
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
 