/******************************************************************************
*INCLUDE
******************************************************************************/
#include "function.h"
/******************************************************************************
*MAIN
******************************************************************************/
int main(){
    uint16_t lineCount = 1;
    
    FILE *inputFile = fopen("Srec1.txt", "r");
    FILE *outputFile = fopen("Output.txt", "w");

    if (inputFile == NULL){
        printf("\nUnable to open the input file");
        return 1;
    }

    if (outputFile == NULL){
        printf("\nUnable to open the output file");
        return 1;
    }
    else{
        while (!feof(inputFile)){
            if (fgetc(inputFile) == '\n'){
                lineCount++;
            }
        }
    }
    rewind(inputFile);
    
    uint16_t index = 0;
    uint8_t length = 0;
    uint8_t count = 0;
    int8_t endType = 0;
    int8_t type = 0;
    int8_t line[MAX];
    
    for (index = 0; index < lineCount - 1; index++)
    {
        printf("\nLine : %d || ", index + 1);
        fprintf(outputFile, "Line : %d || ", index + 1);
        read_line(line, inputFile, &length);
        

        if (line[1] == '1' || line[1] == '2' || line[1] == '3'){
            if (line[1] == '1'){
                type = '1';
                endType = '9';
            }
            else if (line[1] == '2'){
                type = '2';
                endType = '8';
            }
            else if (line[1] == '3'){
                type = '3';
                endType = '7';
            }
            count++;
        }
        if (Check_S(line[0]) != 0){
            fprintf(outputFile, "Error: Check S");
            printf("Error: Check S");
        }
        else if (Check_Type(line[1]) != 0){
            fprintf(outputFile, "Error: Record type");
            printf("Error: Record type");
        }
        else if (Check_Hexa(line) != 0){
            fprintf(outputFile, "Error: Check Hexa");
            printf("Error: Check Hexa");
        }
        else if (Check_Byte_Count(line) != 0){
            fprintf(outputFile, "Error: Byte count");
            printf("Error: Byte count");
        }
        else if (Check_Sum(line) != 0){
            fprintf(outputFile, "Error: Checksum");
            printf("Error: Checksum");
        }
        else if (type == 5 || type == 6){
            if (Check_Line_Count(line, count) != 0){
                fprintf(outputFile, "Error: Line count");
                printf("Error: Line count");
            }
        }
        else if(index != 0 && index != lineCount - 2 && index != lineCount - 1){
            print_data(line, type, length, outputFile);
        }
        else if (index == lineCount - 1){
            if (Check_Terminate(line[1], endType) != 0){
                fprintf(outputFile, "Error: Terminated");
                printf("Error: Terminated");
            }
        }
        fprintf(outputFile, "\n");
    }
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
/******************************************************************************
*END OF FLIE
******************************************************************************/

