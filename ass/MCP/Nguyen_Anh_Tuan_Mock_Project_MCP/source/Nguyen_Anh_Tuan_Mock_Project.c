/******************************************************************************
*INCLUDE
******************************************************************************/
#include "function.h"
/*******************************************************************************
 * Codes
 ******************************************************************************/
int main() {
    UART_Init();

    FILE *inputFile = fopen("Blink_Led_premitive.s19", "r");
    if (inputFile == NULL){
        printf("\nUnable to open the input file");
        return 1;
    }

    while (!feof(inputFile)){
        uint8_t line[MAX];
        uint8_t length = 0;
        read_line(line, inputFile, &length);

        // Assuming line is a valid SREC line
        int8_t type = line[1];
        uint8_t srecData[MAX]; // Store the SREC data here
        uint8_t srecLength = 0; // Length of the SREC data
        uint32_t srecAddress = FLASH_START_ADDRESS;

        // Extract and process the SREC data (skip error checking for now)
        for (uint8_t index = 4; index < length - 2; index += 2){
            srecData[srecLength] = (hexToDec(line[index]) << 4) | hexToDec(line[index + 1]);
            srecLength++;
        }

        // Check for record types 1, 2, and 3
        if (type == '1' || type == '2' || type == '3'){
            // Process the data and write to Flash memory if needed
            if (type == '3'){
                // Assuming you have the starting address for Flash memory (srecAddress)
                // and the SREC data (srecData) extracted above
                WriteDataToFlash(&srecAddress, (uint32_t *)srecData, srecLength / 4);
            }
        }
    }

    fclose(inputFile);

    return 0;
}
/*******************************************************************************
 * End Of File
 ******************************************************************************/
