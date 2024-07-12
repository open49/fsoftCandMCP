/******************************************************************************
*INCLUDES
******************************************************************************/
#include <stdio.h>
#include "func.h"
/******************************************************************************
*MAIN
******************************************************************************/

/** 
*@brief option for you choose
*@param none
*retval None
*/
int main() {
    uint8_t assignment4[20] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                               0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                               0xFF, 0xFF, 0xFF, 0xFF};

    int32_t choice;
    uint8_t value, position;
    printf("\n--- MENU ---\n");
    printf("1. Input element\n");
    printf("2. Delete\n");
    printf("3. Printf\n");
    printf("4. Exit\n");

    while (1) {
        printf("--------------\n");
        printf("Your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position (0->19): ");
                scanf("%hhu", &position);
                printf("Enter Value (0->100): ");
                scanf("%hhu", &value);
                addElement(assignment4, position, value);
                break;
            case 2:
                printf("Enter Value need to delete (0->100): ");
                scanf("%hhu", &value);
                deleteElement(assignment4, value);
                break;
            case 3:
                printf("Your option : \n");
                printf("1. Printf unsort\n");
                printf("2. Printf sorted\n");
                printf("Your Option: ");
                scanf("%hhu", &value);
                printArray(assignment4, value);
                break;
            case 4:
                printf("Exit.\n");
                return 0;
            default:
                printf("Error choice !.\n");
                break;
        }
    }
}
/******************************************************************************
*END OF FILE
******************************************************************************/
