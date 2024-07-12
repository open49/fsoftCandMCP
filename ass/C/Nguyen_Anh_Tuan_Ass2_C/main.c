/*******************************************************************************
* Includes
*******************************************************************************/

#include <stdio.h>
#include "array_manager.h"

/*******************************************************************************
* Code
*******************************************************************************/

int main() {
    uint8_t choice;

    printf("Manage integer arrays\n");
    printf("Type 'c' to clear data of old array and let user input''\n");
    printf("Type 'p' print aray \n");
    printf("Type 'i' add 1 element to the array at position k\n");
    printf("Type 'd' delete1 element in the array at position k\n");
    printf("Type 's' sort numbers in ascending order\n");
    printf("Type 'x' sort numbers in descending order\n");
    printf("Type 't' search X in array\n");
    printf("Type 'a' find max in array\n");
    printf("Type 'w' find min in array\n");
    printf("Type 'e' exit program\n");
    inputArray();

    do {
        printf("Input your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'c':
                clearArray();
                break;
            case 'p':
                printArray();
                break;
            case 'i':
                insertElement();
                break;
            case 'd':
                deleteElement();
                break;
            case 's':
                sortArray(0); /*ascending*/
                break;
            case 'x':
                sortArray(1); /*descending*/
                break;
            case 't':
                searchElement();
                break;
            case 'a':
                printMaxValue();
                break;
            case 'w':
                printMinValue();
                break;
            case 'e':
                printf("Exited the program\n");
                break;
            default:
                printf("The selection is not suitable, please try again\n");
                break;
        }
    } while (choice != 'e');

    return 0;
}
/*******************************************************************************
* End of file
*******************************************************************************/
