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
 * @file Stats.c
 * @brief Final assignement course1 embedded systems
 *
 * @author Daniel Vasconcelos
 * @date 2020-02-08
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)
short sorted_array = 0;

void main_stats()
{
  //In the assignment it says the print_array, but
  // this is the function that prints out the stats
  // So I'm generalizing the constraints.
  // In the description it says that if the directive is
  // not set then nothing should print.
#ifdef VERBOSE
  unsigned char a[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  // unsigned char a[] = {4, 65, 2, 31, 0, 99, 2, 83, 255};
  unsigned int n = sizeof a / sizeof a[0];

  print_statistics(a, n);
#endif
}


void merge(unsigned char* element_arr, unsigned char arr_size, unsigned char middle)
{
    int i, j, k;
    int *tmp = malloc(arr_size * sizeof (element_arr));
    
    for (i = 0, j = middle, k = 0; k < arr_size; k++)
    {
        tmp[k] = j == arr_size ? element_arr[i++] :
                i == middle ? element_arr[j++] : 
                element_arr[j] > element_arr[i] ? element_arr[j++] :
                element_arr[i++];
    }
    for (i = 0; i < arr_size; i++)
    {
        element_arr[i] = tmp[i];
    }

    free(tmp);
}
 

void sort_array(unsigned char* element_arr, unsigned char arr_size)
{
  
  if (arr_size < 2)
  {
    return;
  }
  
  int middle = arr_size / 2;
  
  sort_array(element_arr, middle);
  sort_array(element_arr + middle, arr_size - middle);
  merge(element_arr, arr_size, middle);      
}


void print_array(unsigned char* element_arr, unsigned int arr_size)
{
  PRINTF("Printing out the array: \n");
  int counter = 0;
  for (int i = 0; i < arr_size; i++)
  {
    counter++;
    PRINTF("%d%s", element_arr[i], counter==10? "\n" : "\t");
    if(counter==10) counter = 0;
  }
  PRINTF("\n\n");
}


unsigned char find_maximum(unsigned char* element_arr, unsigned int arr_size)
{
  if(sorted_array == 0) //Helps improving efficency of program. Only sorts if it wasn't sorted before.
  {
    sort_array(element_arr, arr_size);
    sorted_array = 1;    
  }

  return element_arr[arr_size-1];
}


unsigned char find_minimum(unsigned char* element_arr, unsigned int arr_size)
{
  if(sorted_array == 0) //Helps improving efficency of program. Only sorts if it wasn't sorted before.
  {
    sort_array(element_arr, arr_size);
    sorted_array = 1;    
  }
  
  return element_arr[0];
}


unsigned char find_mean(unsigned char* element_arr, unsigned int arr_size)
{
  int sum = 0;
  for (int i = 0; i < arr_size; i++)
  {
    sum += element_arr[i];
  }

  return (unsigned char)(sum/arr_size);
}


unsigned char find_median(unsigned char* element_arr, unsigned int arr_size)
{
  int median = 0;
  int middle = (arr_size/2); 

  if(sorted_array == 0) //Helps improving efficency of program. Only sorts if it wasn't sorted before.
  {
    sort_array(element_arr, arr_size);
    sorted_array = 1;    
  }
  
  if(arr_size%2 != 0) //Odd size?
  {
    PRINTF("Array of odd size: %u\n", arr_size);
    median = element_arr[middle];
  }else
  {  
    PRINTF("Array of even size: %u\n", arr_size);
    median = (element_arr[middle-1] + element_arr[middle])/2;
  }
  
  return (unsigned char)median;
}


void print_statistics(unsigned char* element_arr, unsigned int arr_size)
{
  print_array(element_arr, arr_size);
  if(sorted_array == 0) //Helps improving efficency of program. Only sorts if it wasn't sorted before.
  {
    sort_array(element_arr, arr_size);
    sorted_array = 1;    
  }
  print_array(element_arr, arr_size);

  PRINTF("Maximum: %u\n", find_maximum(element_arr, arr_size));
  PRINTF("Minimum: %u\n", find_minimum(element_arr, arr_size));
  PRINTF("Mean: %u\n", find_mean(element_arr, arr_size));
  PRINTF("Median: %u\n", find_median(element_arr, arr_size));
}