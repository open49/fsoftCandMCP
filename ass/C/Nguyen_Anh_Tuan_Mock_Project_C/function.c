/******************************************************************************
*INCLUDE
******************************************************************************/
#include "function.h"
/******************************************************************************
*MACRO
******************************************************************************/
#define num2(A, B) (A << 4) | B
#define num4(A, B, C, D) (A << 12) | (B << 8) | (C << 4) | D
/******************************************************************************
FUNCTION
******************************************************************************/
static int8_t hexToDec(int8_t temp);

static int8_t hexToDec(int8_t temp){
    if (temp >= '0' && temp <= '9'){
        temp = temp - '0';
    }
    else{
        temp = temp - 'A' + 10;
    }
    return temp;
}
/******************************************************************************
FUNCTION read_line
******************************************************************************/
void read_line(int8_t *line, FILE *file, uint8_t *length){
    int8_t temp = 0;
    uint8_t index = 0;

    *length = 0;
    temp = fgetc(file);

    while (temp != '\n' && temp != EOF){
        line[index] = temp;
        index++;
        ++*length;
        temp = fgetc(file);
    }

    line[index] = 0;
}
/******************************************************************************
FUNCTION Check_S
******************************************************************************/
int8_t Check_S(uint8_t line){
    int8_t save_er = 0;

    if (line != 'S'){
        save_er = 1;
    }

    return save_er;
}
/******************************************************************************
FUNCTION Check_Type
******************************************************************************/
int8_t Check_Type(uint8_t type){
    int8_t save_er = 0;

    if (type < '0' || type > '9')
    {
        save_er = 2;
    }

    return save_er;
}
/******************************************************************************
FUNCTION Check_Hexa
******************************************************************************/
int8_t Check_Hexa(int8_t *temp){
    int8_t save_er = 0;
    ++temp;

    while (*temp != 0){
        if (hexToDec(*temp) < 0 || hexToDec(*temp) > 15){
            save_er = 3;
        }
        ++temp;
    }
    return save_er;
}
/******************************************************************************
FUNCTION Check_Byte_Count
******************************************************************************/
int8_t Check_Byte_Count(int8_t *str){
    int8_t save_er = 0;
    uint8_t length = 0;
    uint8_t bytes = 0;

    length = strlen(str) - 4;
    bytes = num2(hexToDec(str[2]), hexToDec(str[3]));

    if (bytes != (length / 2)){
        save_er = 4;
    }

    return save_er;
}
/******************************************************************************
FUNCTION Check_Sum
******************************************************************************/
int8_t Check_Sum(int8_t *str){
    uint8_t lastByte = 0;
    uint8_t length = 0;
    int8_t save_er = 0;
    uint8_t sum = 0;
    uint8_t index = 0;

    length = strlen(str);
    lastByte = ~(num2(hexToDec(str[length - 2]), hexToDec(str[length - 1])));

    for (index = 2; index < length - 2; index += 2){
        sum += num2(hexToDec(str[index]), hexToDec(str[index + 1]));
    }
    if (sum != lastByte){
        save_er = 5;
    }

    return save_er;
}
/******************************************************************************
FUNCTION Check_Line_Count
******************************************************************************/
int8_t Check_Line_Count(int8_t *str, uint16_t count){
    int8_t save_er = 0;
    uint16_t checkLine = 0;

    checkLine = num2(hexToDec(str[4]), hexToDec(str[5]));
    if (count != checkLine){
        save_er = 6;
    }

    return save_er;
}
/******************************************************************************
FUNCTION Check_Terminate
******************************************************************************/
int8_t Check_Terminate(int8_t temp, uint8_t type){
    int8_t save_er = 0;

    if (temp != type){
        save_er = 7;
    }

    return save_er;
}
/******************************************************************************
FUNCTION print_data
******************************************************************************/
void print_data(int8_t *str, int8_t type, uint8_t length, FILE *file){
    uint8_t index = 0;
    if (type == '3'){
        for (index = 4; index < length - 2; index++){
            if (index == 12){
                fprintf(file, " : Address - DATA : ");
                printf(" : Address - DATA : ");
            }
            
            fprintf(file, "%c", str[index]);
            printf("%c", str[index]);
        }
    }
    else if (type == '2'){
        for (index = 4; index < length - 2; index++){
            if (index == 10){
                fprintf(file, " ");
                printf(" ");
            }
            fprintf(file, "%c", str[index]);
            printf("%c", str[index]);
        }
    }
    else if (type == '1'){
        for (index = 4; index < length - 2; index++){
            if (index == 8)
            {
                fprintf(file, " ");
                printf(" ");
            }
            fprintf(file, "%c", str[index]);
            printf("%c", str[index]);
        }
    }
}
/******************************************************************************
*END OF FILE
******************************************************************************/

