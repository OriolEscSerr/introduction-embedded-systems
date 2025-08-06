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
 * @file stats.c
 * @brief Implementation of basic statistics operations.
 *
 * Simple application that performs statistical analytics on a dataset (minimum,
 * maximum, mean, median).
 *
 * @author Oriol Escolà Serra
 * @date 16/07/2025
 *
 */

#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(int min, int max, double mean, double median) {
#ifdef VERBOSE
  printf("Statistics:\n\n");
  printf("Minimum: %d\n", min);
  printf("Maximum: %d\n", max);
  printf("Mean:    %g\n", mean);
  printf("Median:  %g\n", median);
#endif
}

void print_array(unsigned char *array, unsigned int length) {
#ifdef VERBOSE
  for (unsigned int i = 0; i < length; i++) {
    if (i != length - 1) {
      printf("%d, ", array[i]);
    } else {
      printf("%d", array[i]); // Last element without comma
    }
  }
  printf("\n\n");
#endif
}

double find_median(unsigned char *array, unsigned int length) {
  if (length % 2 == 0) {
    // If even, return the average of the two middle elements
    return (array[length / 2 - 1] + array[length / 2]) / 2.0;
  } else {
    // If odd, return the middle element
    return array[length / 2];
  }
}

double find_mean(unsigned char *array, unsigned int length) {
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += array[i];
  }
  return (double)sum / length; // Return the mean value
}

int find_maximum(unsigned char *array, unsigned int length) {
  int max = array[0];
  for (int i = 1; i < length; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max; // Return the maximum value
}

int find_minimum(unsigned char *array, unsigned int length) {
  int min = array[0];
  for (int i = 1; i < length; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min; // Return the minimum value
}

void sort_array(unsigned char *array, unsigned int length) {
  for (unsigned int i = 0; i < length - 1; i++) {
    for (unsigned int j = i + 1; j < length; j++) {
      if (array[i] < array[j]) {
        // Swap elements
        unsigned char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

/* Other Implementation File Code */
