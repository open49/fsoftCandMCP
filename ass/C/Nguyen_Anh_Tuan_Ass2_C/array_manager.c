/*******************************************************************************
* Includes
*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include "array_manager.h"

#define ARRAY_SIZE 100

/*******************************************************************************
* Code
*******************************************************************************/

static int32_t arr[ARRAY_SIZE];
static int32_t count = 0;

void inputArray() {
    count = 0;
    printf("Enter the number of elements in the array:");
    scanf("%d", &count);

    if (count > ARRAY_SIZE) {
        printf("The number of elements exceeds the array size");
        count = ARRAY_SIZE;
    }

    printf("Enter the elements of the array:\n");
    int32_t i;
    for (i = 0; i < count; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Array import successful\n");
}
void clearArray() {
	int32_t i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = 0;
    }
    count = 0;
    printf("Deleted\n");
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &count);

    if (count > ARRAY_SIZE) {
        printf("The number of elements exceeds the array size\n");
        count = ARRAY_SIZE;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < count; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Array import successful\n");
}

void printArray() {
    if (count == 0) {
        printf("Empty Array\n");
        return;
    }

    printf("Elements in array:");
    int32_t i;
    for (i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement() {
    if (count == ARRAY_SIZE) {
        printf("Array full, do not import more element\n");
        return;
    }

    int32_t value, position;
    printf("enter the element you want to add:");
    scanf("%d", &value);
    printf("Enter position you want to insert:");
    scanf("%d", &position);

    if (position < 0 || position > count) {
        printf("inappropriate position\n");
        return;
    }


    int32_t i;
    for (i = count; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    
    arr[position] = value;
    count++;

    printf("added element %d to position %d\n", value, position);
}

void deleteElement() {
    if (count == 0) {
        printf("Empty array . No element to delete\n");
        return;
    }

    int32_t position;
    printf("Enter the possition you want to delete");
    scanf("%d", &position);

    if (position < 0 || position >= count) {
        printf("inappropriate position\n");
        return;
    }

    int32_t deletedValue = arr[position];

    
    int32_t i;
    for (i = position; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }

    count--;

    printf("Deleted element %d at position %d.\n", deletedValue, position);
}

void sortArray(int32_t order) {
	int32_t i,j;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (order == 0) { /*ascending*/
                if (arr[i] > arr[j]) {
                    int32_t temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            } else { /*descending*/
                if (arr[i] < arr[j]) {
                    int32_t temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    if (order == 0) {
        printf("Array has been sorted ascending.\n");
    } else {
        printf("Array has been sorted descending\n");
    }
    
}

void searchElement() {
    if (count == 0) {
        printf("Empty array . No element to search \n");
        return;
    }

    int32_t value;
    printf("Enter element want to search");
    scanf("%d", &value);
    int32_t i;

    for (i = 0; i < count; i++) {
        if (arr[i] == value) {
            printf("element %d searched at position %d.\n", value, i);
            return;
        }
    }

    printf("%d do not find in array\n", value);
}

void printMaxValue() {
    if (count == 0) {
        printf("Empty array . No element to search\n");
        return;
    }

    int32_t max = arr[0];
    int32_t i;
    for (i = 1; i < count; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Max of array=  %d.\n", max);
}

void printMinValue() {
    if (count == 0) {
        printf("Empty array . No element to search\n");
        return;
    }

    int32_t min = arr[0];
    int32_t i;
    for (i = 1; i < count; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Min of Array = %d.\n", min);
}

/*******************************************************************************
* End of file
*******************************************************************************/

