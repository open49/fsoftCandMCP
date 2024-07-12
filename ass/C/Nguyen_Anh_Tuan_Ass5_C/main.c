/******************************************************************************
*INCLUDE
******************************************************************************/
#include <stdio.h>
#include "function.h"

/******************************************************************************
*MAIN
******************************************************************************/
/** 
*@brief option for you choose
*@param none
*retval None
*/
uint32_t main() {
    uint32_t choice;
    uint32_t id;
    displayMenu();

    do {
        printf("Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                printf("Enter ID to remove: ");
                scanf("%u", &id);
                removeStudent(id);
                break;
            case 3:
                printf("Enter ID to find: ");
                scanf("%u", &id);
                findStudent(id);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}

/******************************************************************************
*END OF FILE
******************************************************************************/

