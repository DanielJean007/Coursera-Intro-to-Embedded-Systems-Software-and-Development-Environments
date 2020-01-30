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



#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
short sorted_array = 0;

void main()
{
  unsigned char a[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  // unsigned char a[] = {4, 65, 2, 31, 0, 99, 2, 83, 255};
  unsigned char n = sizeof a / sizeof a[0];
  print_array(a, n);
  
  if(sorted_array == 0) //Helps improving efficency of program. Only sorts if it wasn't sorted before.
  {
    sort_array(a, n);
    sorted_array = 1;    
  }
  
  print_array(a, n);
  printf("Maximum: %u\n", find_maximum(a, n));
  printf("Minimum: %u\n", find_minimum(a, n));
  printf("Mean: %u\n", find_mean(a, n));
  printf("Median: %u\n", find_median(a, n));
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
  printf("Printing out the array: \n");
  for (int i = 0; i < arr_size; i++)
  {
    printf("%d%s", element_arr[i], i == arr_size - 1 ? "\n" : " ");
  }
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
    printf("Array of odd size: %u\n", arr_size);
    median = element_arr[middle];
  }else
  {  
    printf("Array of even size: %u\n", arr_size);
    median = (element_arr[middle-1] + element_arr[middle])/2;
  }
  
  return (unsigned char)median;
}