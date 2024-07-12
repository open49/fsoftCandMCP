/*
 * function.h
 *
 *  Created on: 16 Aug 2023
 *      Author: Tuan Nguyen
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "MKL46Z4.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define FLASH_START_ADDRESS 0x00080000
#define MAX 256
#define num2(A, B) (A << 4) | B
#define num4(A, B, C, D) (A << 12) | (B << 8) | (C << 4) | D

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief Read a line from a file and calculate its length.
 *
 * @param line    Pointer to store the read line.
 * @param file    Pointer to the file to read from.
 * @param length  Pointer to store the length of the read line.
 */
void read_line(uint8_t *line, FILE *file, uint8_t *length);
/*!
 * @brief Convert a hex character to its decimal equivalent.
 *
 * @param temp  The hex character to be converted.
 * @return      The decimal equivalent of the hex character.
 */
int8_t hexToDec(int8_t temp);
/*!
 * @brief Check if the provided line starts with 'S'.
 *
 * @param line  The line to be checked.
 * @return      1 if the line does not start with 'S', 0 otherwise.
 */
int8_t Check_S(uint8_t line);
/*!
 * @brief Check if the provided type is a valid SREC type.
 *
 * @param type  The SREC type character to be checked.
 * @return      2 if the type is not valid, 0 otherwise.
 */
int8_t Check_Type(uint8_t type);
/*!
 * @brief Check if the characters after the SREC type are valid hexadecimal values.
 *
 * @param temp  Pointer to the character after the SREC type.
 * @return      3 if any character is not a valid hex digit, 0 otherwise.
 */
int8_t Check_Hexa(int8_t *temp);
/*!
 * @brief Check if the byte count in the SREC matches the actual data length.
 *
 * @param str  The SREC line to be checked.
 * @return     4 if byte count doesn't match actual data length, 0 otherwise.
 */
int8_t Check_Byte_Count(char *str);
/*!
 * @brief Check if the checksum of the SREC line is valid.
 *
 * @param str  The SREC line to be checked.
 * @return     5 if checksum is invalid, 0 otherwise.
 */
int8_t Check_Sum(char *str);
/*!
 * @brief Check if the line count in the SREC matches the expected line count.
 *
 * @param str    The SREC line to be checked.
 * @param count  The expected line count.
 * @return       6 if line count doesn't match expected value, 0 otherwise.
 */
int8_t Check_Line_Count(int8_t *str, uint16_t count);
/*!
 * @brief Check if the line termination character matches the expected type.
 *
 * @param temp  The character to be checked.
 * @param type  The expected termination character.
 * @return      7 if termination character doesn't match expected type, 0 otherwise.
 */
int8_t Check_Terminate(int8_t temp, uint8_t type);
/*!
 * @brief Print the data portion of the SREC line.
 *
 * @param str      The SREC line to be printed.
 * @param type     The SREC type character.
 * @param length   The length of the SREC line.
 */
void print_data(int8_t *str, int8_t type, uint8_t length);
/*!
 * @brief Write data to the Flash memory at the specified address.
 *
 * @param address  Pointer to the address to write data to.
 * @param data     Pointer to the data to be written.
 * @param length   The length of the data to be written.
 */
void WriteDataToFlash(uint32_t *address, uint32_t *data, uint32_t length);
/*!
 * @brief Initialize the UART communication.
 */
void UART_Init(void);

#endif /* FUNCTION_H_ */
/*******************************************************************************
 * end of file
 ******************************************************************************/
