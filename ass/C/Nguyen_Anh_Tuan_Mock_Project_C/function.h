/******************************************************************************
*API
******************************************************************************/
#ifndef _FUNCTION_H_
#define _FUNCTION_H_

/******************************************************************************
*INCLUDE
******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************
*MAIN
******************************************************************************/
#define MAX 256
/** 
*@brief read line in file srec1.txt
*@param None
*retval None
*/
void read_line(int8_t *line, FILE *file, uint8_t *length);
/** 
*@brief check s error
*@param None
*retval None
*/
int8_t Check_S(uint8_t line);
/** 
*@brief check type
*@param None
*retval None
*/
int8_t Check_Type(uint8_t type);
/** 
*@brief check hecxa
*@param None
*retval None
*/
int8_t Check_Hexa(int8_t *temp);
/** 
*@brief check byte count
*@param None
*retval None
*/
int8_t Check_Byte_Count(int8_t *str);
/** 
*@brief check sum
*@param None
*retval None
*/
int8_t Check_Sum(int8_t *str);
/** 
*@brief check line count
*@param None
*retval None
*/
int8_t Check_Line_Count(int8_t *str, uint16_t count);
/** 
*@brief check terminate
*@param None
*retval None
*/
int8_t Check_Terminate(int8_t temp, uint8_t type);
/** 
*@brief printf data to cmd and output.txt
*@param None
*retval None
*/
void print_data(int8_t *str, int8_t type, uint8_t length, FILE *file);

#endif /*_FUNCTION_H_*/
/******************************************************************************
*END OF FILE
******************************************************************************/

