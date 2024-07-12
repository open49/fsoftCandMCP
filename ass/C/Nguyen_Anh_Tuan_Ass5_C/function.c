/******************************************************************************
*INCLUDE
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "function.h"

/******************************************************************************
*VARIABLE
******************************************************************************/
Student* head = NULL;


bool isIdDuplicate(unsigned int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return true;
        }
        current = current->next;
    }
    return false;
}
/******************************************************************************
*FUNCTION ADD STUDENT
******************************************************************************/
void addStudent() {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    
    if (newStudent == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    
    printf("Enter name: ");
    scanf(" %[^\n]s", newStudent->name);
    
    printf("Enter ID: ");
    scanf("%u", &newStudent->id);
    
    if (isIdDuplicate(newStudent->id)) {
        printf("ID already exists. Cannot add student.\n");
        free(newStudent); 
        /*Free the allocated memory since we are not adding the student.*/
        return;
    }
    
    printf("Enter math score: ");
    scanf("%hhu", &newStudent->math_score);

    newStudent->next = head;
    head = newStudent;

    printf("Added successfully.\n");
}
/******************************************************************************
FUNCTION REMOVE STUDENT
******************************************************************************/
void removeStudent(uint32_t id) {
    Student* current = head;
    Student* prev = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("ID %u removed successfully.\n", id);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("ID %u not found.\n", id);
}
/******************************************************************************
*FUNCTION FIND STUDENT
******************************************************************************/
void findStudent(uint32_t id) {
    Student* current = head;

    while (current != NULL) {
        if (current->id == id) {
            printf("Student Information:\n");
            
            printf("Name: %s\n", current->name);
            printf("ID: %u\n", current->id);
            printf("Math Score: %hhu\n", current->math_score);
            return;
        }
        current = current->next;
    }

    printf("ID %u not found.\n", id);
}

void displayMenu() {
    printf("Choose an option:\n");
    printf("1. Add student\n");
    printf("2. Remove student\n");
    printf("3. Find student\n");
    printf("4. Exit\n");
    
}

/******************************************************************************
*END OF FILE
******************************************************************************/

