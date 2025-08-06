/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Function declarations for basic statistics operations.
 *
 * This header file contains the declarations of functions used to compute and
 * display basic statistics (minimum, maximum, mean, median) on an array of
 * data.
 *
 * @author Oriol Escolà Serra
 * @date 16/07/2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stdint.h>

/**
 * @brief Prints the statistics of an array.
 *
 * This function prints the minimum, maximum, mean, and median values of an
 * array.
 *
 * @param min Minimum value in the array.
 * @param max Maximum value in the array.
 * @param mean Average value of the array.
 * @param median Median value of the array.
 *
 * @return void
 */
void print_statistics(int min, int max, double mean, double median);

/**
 * @brief Prints an array.
 *
 * Given an array of data and a length, prints the array to the screen.
 *
 * @param array Pointer to the array of data.
 * @param length Number of elements in the array.
 *
 * @return void
 */
void print_array(unsigned char *array, unsigned int length);

/**
 * @brief Finds the median of an array.
 *
 * This function calculates the median of an array of data.
 *
 * @param array Pointer to the array of data.
 * @param length Number of elements in the array.
 *
 * @return The median value of the array.
 */
double find_median(unsigned char *array, unsigned int length);

/**
 * @brief Finds the mean of an array.
 *
 * This function calculates the mean of an array of data.
 *
 * @param array Pointer to the array of data.
 * @param length Number of elements in the array.
 *
 * @return The mean value of the array.
 */
double find_mean(unsigned char *array, unsigned int length);

/**
 * @brief Finds the maximum of an array.
 *
 * This function calculates the maximum of an array of data.
 *
 * @param array Pointer to the array of data.
 * @param length Number of elements in the array.
 *
 * @return The maximum value of the array.
 */
int find_maximum(unsigned char *array, unsigned int length);

/**
 * @brief Finds the minimum of an array.
 *
 * This function calculates the minimum of an array of data.
 *
 * @param array Pointer to the array of data.
 * @param length Number of elements in the array.
 *
 * @return The minimum value of the array.
 */
int find_minimum(unsigned char *array, unsigned int length);

/**
 * @brief Sorts an array in descending order.
 *
 * This function sorts an array of data in descending order.
 *
 * @param array Pointer to the array of data.
 * @param length Number of elements in the array.
 *
 * @return void
 */
void sort_array(unsigned char *array, unsigned int length);

/**
 * @brief Demonstrates the statistics functions on a test array.
 *
 * This function demonstrates the use of the statistics functions (mean, median,
 * maximum, minimum) on a predefined test array.
 *
 * @return void
 */
void stats_demo();

#endif /* __STATS_H__ */
