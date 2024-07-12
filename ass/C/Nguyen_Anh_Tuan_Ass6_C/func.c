/******************************************************************************
*INCLUDES
******************************************************************************/
#include <stdio.h>
#include "func.h"
/******************************************************************************
*FUNCTION
******************************************************************************/

void addElement(uint8_t *array, uint8_t position, uint8_t value) {
    int32_t i;
    if (position < 0 || position > 19) {
        printf("Invalid position.\n");
        return;
    }

    if (array[position] != 0xFF) {
        printf("Position is already has value.\n");
        return;
    }

    if (value < 0 || value > 100) {
        printf("Value Invalid.\n");
        return;
    }
    
    for (i = 0; i < 20; i++) {
        if (array[i] == value) {
            printf("Value already exists.\n");
            return;
        }
    }

    array[position] = value;

    printf("Value %d has been added at position %d \n", value, position);
}

void deleteElement(uint8_t *array, uint8_t value) {
    int32_t found = 0;
    int32_t i;
    if (value < 0 || value > 100) {
        printf("Value Invalid.\n");
        return;
    }

    for (i = 0; i < 20; i++) {
        if (array[i] == value) {
            array[i] = 0xFF;
            found = 1;
        }
    }

    if (found) {
        printf("Value %d has been deleted.\n", value);
    } else {
        printf("Value does not exist\n");
    }
}

void printArray(uint8_t *array, uint8_t option) {
    if (option == 1) {
        printf("Value unsort\n");
        int32_t i;
        for (i = 0; i < 20; i++) {
            if (array[i] != 0xFF) {
                printf("%hhu ", array[i]);
            }
        }
        printf("\n");
    } else if (option == 2) {
        printf("Value sorted\n");
        // Use bubble sort
        int32_t i,j;
        for (i = 0; i < 19; i++) {
            for (j = 0; j < 19 - i; j++) {
                if (array[j] > array[j + 1]) {
                    uint8_t temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        for (i = 0; i < 20; i++) {
            if (array[i] != 0xFF) {
                printf("%hhu ", array[i]);
            }
        }
        printf("\n");
    } else {
        printf("Error option.\n");
    }
}

/******************************************************************************
*END OF FILE
******************************************************************************/


