#ifndef FUNC_H
#define FUNC_H
/******************************************************************************
*INCLUDES
******************************************************************************/
#include <stdint.h>

/** 
*@brief adds a new element
*@param position, value
*retval None
*/
void addElement(uint8_t *array, uint8_t position, uint8_t value);

/** 
*@brief delete element
*@param value
*retval None
*/
void deleteElement(uint8_t *array, uint8_t value);

/** 
*@brief print array
*@param none
*retval None
*/
void printArray(uint8_t *array, uint8_t option);

#endif /*_FUNC_H_*/
/******************************************************************************
*END OF FILE
******************************************************************************/

