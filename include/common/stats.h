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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

/**
 * @brief Main function. The main entry point for your program
 * 
 */
void main(void);

/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 * 
 * @param char 
 * @param arr_size 
 */
void print_statistics(unsigned char* element_arr, unsigned int arr_size);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 * 
 * @param char 
 * @param arr_size 
 */
void print_array(unsigned char* element_arr, unsigned int arr_size);

/**
 * @brief Given an array of data and a length, returns the median value
 * 
 * @param char 
 * @param arr_size 
 * @return unsigned char 
 */
unsigned char find_median(unsigned char* element_arr, unsigned int arr_size);

/**
 * @brief Given an array of data and a length, returns the mean
 * 
 * @param char 
 * @param arr_size 
 * @return unsigned char 
 */
unsigned char find_mean(unsigned char* element_arr, unsigned int arr_size);

/**
 * @brief Given an array of data and a length, returns the maximum
 * 
 * @param char 
 * @param arr_size 
 * @return unsigned char 
 */
unsigned char find_maximum(unsigned char* element_arr, unsigned int arr_size);

/**
 * @brief Given an array of data and a length, returns the minimum
 * 
 * @param char 
 * @param arr_size 
 * @return unsigned char 
 */
unsigned char find_minimum(unsigned char* element_arr, unsigned int arr_size);

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest. 
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 * 
 * @param char 
 * @param arr_size 
 */
void sort_array(unsigned char* element_arr, unsigned char arr_size);

/**
 * @brief Implements the merge of merge and sort algorithm
 * Adapted from: https://rosettacode.org/wiki/Sorting_algorithms/Merge_sort#C
 * 
 * @param char 
 * @param arr_size 
 */
void merge(unsigned char* element_arr, unsigned char arr_size, unsigned char middle);

#endif /* __STATS_H__ */
