/******************************************************************************
 * Copyright (C) 2020 by Daniel Vasconcelos
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Daniel Vasconcelos is not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/

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

/**
 * @brief Function to convert data from a standard integer type into an ASCII string.
 * 
 * @param data that is to be converted
 * @param ptr Copy of the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
 * @param base to convert to
 * @return uint8_t the length of the converted data
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief Function to convert data back from an ASCII represented string into an integer type.
 * 
 * @param ptr The character string to convert
 * @param digits The number of digits in your character set
 * @param base to convert to
 * @return uint32_t resulting conversion from ascii to integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);