/**
 * @file data.h
 * @author Daniel Vasconcelos (cefet_daniel@yahoo.com.br)
 * @brief This file describes functions to very basic data manipulation
 *        These data manipulation consist of a conversion from int to ascii function,
 *        as well as from ascii to int function
 * @version 0.1
 * @date 2020-02-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "data.h"
#include "memory.h"

#define SIZE_DATA_0 1

// uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
// {
//     uint8_t counter = 0;
// 	int8_t data_greater_then_0 = 1;
// 	int32_t rest;

//     // Handle case where data is 0. No need for any extra processing here
//     // If it is 0 just convert it to string and concatenate \0 at the end
// 	if(data == 0){
// 		*ptr = '0';
// 		*(ptr+1) = '\0';
// 		return SIZE_DATA_0; // Fixed size
// 	}

//     // Here we convert from data to str based on the base
//     // Remember that the conversion by division is 'backwards'
//     *ptr = '\0';
// 	ptr++;
// 	counter++;

//     // We first check for positive or negative number
// 	if(data < 0) {
// 		data_greater_then_0 = 0;
// 		data = data*(-1);
// 	}

// 	while(data != 0) {
// 		rest = data % (int32_t) base;
// 		*ptr = (rest > 9) ? (rest - 10) + 'a' : rest + '0';
// 		data = data/base;
// 		ptr++;
// 		counter++;
// 	}

//     // Now we handle negative numbers
//     if(!data_greater_then_0){
// 		*ptr = '-';
// 		ptr++;
// 		counter++;
// 	}

//     // Now we reverse the order and return the result the size of ptr
// 	uint8_t start = 0; 
//     uint8_t end = counter;
// 	uint8_t tmp;
//     while (start < end) 
//     { 
//         tmp = *(ptr+start);
// 		*(ptr+start) =  *(ptr+end);
// 		*(ptr+end) = tmp;
//         start++; 
//         end--; 
//     }
//     // // return i+1;

//     // my_reverse(ptr, counter);
//     return counter;
// }

// int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
// {
//     int32_t number_from_ascii = 0;
// 	int8_t negative_conversion = 1;

// 	if(*ptr == '-') {
// 		negative_conversion = -1;
// 		ptr++;
// 		digits--;
// 	}

// 	for (uint8_t i = 0; i < digits - 1; ++i){
// 		number_from_ascii *= base + (*ptr - '0');
// 		ptr++;
// 	}

// 	return negative_conversion*number_from_ascii;
// }

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint8_t count = 0;
	int8_t sign = 1;
	int32_t rem;

	if(data == 0){
		*ptr = '0';
		ptr++;
		*ptr = '\0';
		--ptr;
		return 1;
	}

	*ptr = '\0';
	ptr++;
	count++;

	if(data < 0) {
		sign = -1;
		data = -data;
	}

	while(data != 0) {
		rem = data % (int32_t) base;
		*ptr = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		data = data/base;
		ptr++;
		count++;
	}

	if(sign == -1){
		*ptr = '-';
		ptr++;
		count++;
	}

	my_reverse(ptr - count, count);

	return count;
}

int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base)
{
	int32_t result = 0;
	uint32_t multiplier = 1;
	int8_t i;
	uint8_t Negative = 0;
	uint8_t tmp;
	if(*ptr == '-') 
	{
		Negative = 1;
	}
	for(i = digits-2; i >= 0; i--)
	{	if(Negative && i == 0) break;
		if(*(ptr+i) <= '9') tmp = '0';
		else tmp = 'a'-10;
		result += (*(ptr+i) - tmp) * multiplier;
		multiplier *= base;
	}
	if(Negative == 1) result = -1*result;
	return result;
}