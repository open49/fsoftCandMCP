/******************************************************************************
*API
******************************************************************************/
#ifndef _FUNCTION_H_
#define _FUNCTION_H_
/******************************************************************************
*INCLUDE
******************************************************************************/
#include <stdint.h>
/******************************************************************************
*Type Difinition
******************************************************************************/
typedef struct Student {
    uint32_t id;
    int8_t name[50];
    uint8_t math_score;
    struct Student* next;
} Student;

extern Student* head;
/** 
*@brief adds a new student to the list
*@param None
*retval None
*/
void addStudent();

/** 
*@brief Remove a student from the list based on their id
*@param id the ID os student want to removed
*retval None
*/
void removeStudent(uint32_t id);

/** 
*@brief find a student in the list based on their id and display their information
*@param id the ID os student want to removed
*retval None
*/
void findStudent(uint32_t id);


/** 
*@brief print the menu option
*@param none
*retval None
*/
void displayMenu();

#endif /* FUNCTION_H */
/******************************************************************************
*END OF FILE
******************************************************************************/

