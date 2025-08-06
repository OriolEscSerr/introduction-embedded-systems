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
 * @file data.c
 * @brief Abstraction of data read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to data via function calls. There is also a globally
 * allocated buffer array used for manipulation.

 * @author Oriol Escolà Serra
 * @date 06/08/2025
 */

 #include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint8_t *start = ptr;
    int is_negative = 0;

    // Handle negative numbers
    if (data < 0) {
        is_negative = 1;
        data = -data;  // work with absolute value
    }

    // Convert digits starting from the least significant
    uint8_t *temp_ptr = ptr;
    do {
        int rem = data % base;
        if (rem < 10) {
            *temp_ptr = '0' + rem;
        } else {
            *temp_ptr = 'A' + (rem - 10);  // For base > 10
        }
        temp_ptr++;
        data /= base;
    } while (data > 0);

    // Add '-' sign if the number was negative
    if (is_negative) {
        *temp_ptr = '-';
        temp_ptr++;
    }

    // Add null terminator at the end
    *temp_ptr = '\0';

    // Reverse the characters (except the null terminator)
    uint8_t *end = temp_ptr - 1;
    while (start < end) {
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    // Return the length of the converted string (excluding null terminator)
    return (uint8_t)(temp_ptr - ptr);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int is_negative = 0;

    // Check for negative sign
    if (*ptr == '-') {
        is_negative = 1;
        ptr++;        // Skip the minus sign
        digits--;     // One less digit to process
    }

    // Process each digit
    for (uint8_t i = 0; i < digits; i++) {
        uint8_t ch = *ptr;
        int digit = 0;

        // Convert ASCII character to numeric digit
        if (ch >= '0' && ch <= '9') {
            digit = ch - '0';
        } else if (ch >= 'A' && ch <= 'F') {
            digit = ch - 'A' + 10;
        }

        // Accumulate the result
        result = result * base + digit;
        ptr++;
    }

    // Apply sign if necessary
    if (is_negative) {
        result = -result;
    }

    return result;
}

 