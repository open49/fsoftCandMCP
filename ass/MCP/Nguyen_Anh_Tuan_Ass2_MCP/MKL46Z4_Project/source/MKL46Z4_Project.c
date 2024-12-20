/*******************************************************************************
 * INCLUDES
 *******************************************************************************/
#include "MKL46Z4.h"

#define RED_LED_PIN         (1 << 29)
#define GREEN_LED_PIN       (1 << 5)
#define SW1_PIN             (1 << 3)
#define SW2_PIN             (1 << 12)
#define BLINK_INTERVAL      (500)  // Blink interval in milliseconds (2Hz)

volatile uint32_t g_msTicks = 0;   /* Counter for milliseconds */
/*******************************************************************************
 * FUNCTION
 *******************************************************************************/
void SysTick_Handler(void) {
    g_msTicks++;
}

void initSysTick(void) {
    /* Initialize System Tick Timer to generate interrupts every 1 ms */
    SysTick_Config(SystemCoreClock / 1000);
}

void initLed(void) {
    // Enable clock for PORTE & PORTD
    SIM->SCGC5 |= (1 << 12 | 1 << 13);

    /* Initialize the RED LED (PTE29) */
    PORTE->PCR[29] |= PORT_PCR_MUX(1);
    GPIOE->PDDR |= RED_LED_PIN;

    // Initialize the Green LED (PTD5)
    PORTD->PCR[5] |= PORT_PCR_MUX(1);
    GPIOD->PDDR |= GREEN_LED_PIN;

    /* Turn off LEDs initially */
    GPIOE->PSOR |= RED_LED_PIN;
    GPIOD->PSOR |= GREEN_LED_PIN;
}

void initButtons(void) {
    // Enable clock for PORTC
    SIM->SCGC5 |= (1 << 11);

    /* Configure SW1 and SW2 pins as input */
    PORTC->PCR[3] |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PORTC->PCR[12] |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

void delayMs(uint32_t ms) {
    uint32_t startTicks = g_msTicks;
    while ((g_msTicks - startTicks) < ms) {}
}
/*******************************************************************************
 * MAIN
 *******************************************************************************/
int main(void) {
    initLed();
    initButtons();
    initSysTick();

    while (1) {
        /* Blink RED LED with 2Hz frequency */
        GPIOE->PTOR |= RED_LED_PIN;
        delayMs(BLINK_INTERVAL);

        // Check SW1 for turning on GREEN LED
        if ((GPIOC->PDIR & SW1_PIN) == 0) {
            GPIOD->PCOR |= GREEN_LED_PIN;  // Turn on GREEN LED
        }

        /* Check SW2 for turning off GREEN LED */
        if ((GPIOC->PDIR & SW2_PIN) == 0) {
            GPIOD->PSOR |= GREEN_LED_PIN;  /* Turn off GREEN LED */
        }
    }
}
/*******************************************************************************
 * END OF FILE
 ******************************************************************************/
