/*
 * function.c
 *
 *  Created on: 16 Aug 2023
 *      Author: Tuan Nguyen
 */
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "function.h"
/*******************************************************************************
 * Function
 ******************************************************************************/
 int8_t hexToDec(int8_t temp);

 int8_t hexToDec(int8_t temp){
    if (temp >= '0' && temp <= '9'){
        temp = temp - '0';
    }
    else{
        temp = temp - 'A' + 10;
    }
    return temp;
}
 /*******************************************************************************
  * Function
  ******************************************************************************/
void read_line(uint8_t *line, FILE *file, uint8_t *length){
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
/*******************************************************************************
 * Function
 ******************************************************************************/
int8_t Check_S(uint8_t line){
    int8_t save_er = 0;

    if (line != 'S'){
        save_er = 1;
    }

    return save_er;
}
/*******************************************************************************
 * Function
 ******************************************************************************/
int8_t Check_Type(uint8_t type){
    int8_t save_er = 0;

    if (type < '0' || type > '9')
    {
        save_er = 2;
    }

    return save_er;
}
/*******************************************************************************
 * Function
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
/*******************************************************************************
 * Function
 ******************************************************************************/
int8_t Check_Byte_Count(char *str){
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
/*******************************************************************************
 * Function
 ******************************************************************************/
int8_t Check_Sum(char *str){
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
/*******************************************************************************
 * Function
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
/*******************************************************************************
 * Function
 ******************************************************************************/
int8_t Check_Terminate(int8_t temp, uint8_t type){
    int8_t save_er = 0;

    if (temp != type){
        save_er = 7;
    }

    return save_er;
}
/*******************************************************************************
 * Function
 ******************************************************************************/
void print_data(int8_t *str, int8_t type, uint8_t length){
    // , FILE *file
    uint8_t index = 0;
    if (type == '3'){
        for (index = 4; index < length - 2; index++){
            if (index == 12){
                // fprintf(file, " : Address - DATA : ");
                printf(" : Address - DATA : ");
            }

            // fprintf(file, "%c", str[index]);
            printf("%c", str[index]);
        }
    }
    else if (type == '2'){
        for (index = 4; index < length - 2; index++){
            if (index == 10){
                // fprintf(file, " ");
                printf(" ");
            }
            // fprintf(file, "%c", str[index]);
            printf("%c", str[index]);
        }
    }
    else if (type == '1'){
        for (index = 4; index < length - 2; index++){
            if (index == 8)
            {
                // fprintf(file, " ");
                printf(" ");
            }
            // fprintf(file, "%c", str[index]);
            printf("%c", str[index]);
        }
    }
}
/*******************************************************************************
 * Function
 ******************************************************************************/
void UART_Init(void) {
  SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1); // Clock to UART0 MCGFLLCLK 48MHz

  SIM->SCGC4 |= SIM_SCGC4_UART0_MASK; // Enable clock to UART0

  SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK; // Enable clock to PORTA

  PORTA->PCR[1] = PORT_PCR_MUX(2); // PTA1 as UART0_RX

  PORTA->PCR[2] = PORT_PCR_MUX(2); // PTA2 as UART0_TX

  UART0->C2 = 0x00; // TX and RX both disabled

  UART0->BDH = 0x00; // Clear BDH to configure baud rate

  UART0->BDL = 0x0C; // BR = 416 (for 9600 baud with 48MHz clock)

  UART0->C1 = 0x00; // 8-bit data, no parity

  UART0->C3 = 0x00;

  UART0->C4 = 0x0F; // OSR = 16

  UART0->C5 = 0x00; // Default settings

  UART0->C2 = 0x0C; // TX and RX enable
}
/*******************************************************************************
 * Function
 ******************************************************************************/
void WriteDataToFlash(uint32_t *address, uint32_t *data, uint32_t length) {
    // Unlock the Flash memory for write operations
    FTFA->FCCOB0 = 0x40; // Flash Command: Program Longword
    FTFA->FCCOB1 = ((*address) >> 16) & 0xFF; // Address[23:16]
    FTFA->FCCOB2 = ((*address) >> 8) & 0xFF;  // Address[15:8]
    FTFA->FCCOB3 = (*address) & 0xFF;         // Address[7:0]

    // Write data to the FCCOB registers (up to 8 bytes per write)
    for (uint32_t i = 0; i < length; i++) {
        *((uint8_t*)&FTFA->FCCOB7 + i) = (*((uint8_t*)data + i));
    }

    // Launch the Flash command
    FTFA->FSTAT = FTFA_FSTAT_CCIF_MASK; // Start the command execution

    // Wait until the command is completed
    while ((FTFA->FSTAT & FTFA_FSTAT_CCIF_MASK) == 0) {}
}
/*******************************************************************************
 * End Of File
 ******************************************************************************/
