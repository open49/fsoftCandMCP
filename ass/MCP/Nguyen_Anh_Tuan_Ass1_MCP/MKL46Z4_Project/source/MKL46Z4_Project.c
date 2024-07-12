#include "MKL46Z4.h"

#define DELAY_CNT           (1000000)
#define RED_LED_PIN         (1 << 29)
#define SW1_PIN             (1 << 3)
#define SW2_PIN             (1 << 12)

#define MODE1               1
#define MODE2               2

void initLed();
void initButtons();
void delay();
void mode1();
void mode2();

volatile uint8_t currentMode = MODE1;
volatile uint8_t brightnessLevel = 0;

int main(void)
{
    initLed();
    initButtons();

    while (1)
    {
        if (currentMode == MODE1)
        {
            mode1();
        }
        else if (currentMode == MODE2)
        {
            mode2();
        }
    }
}

void initLed()
{
    /* Enable clock for PORTE */
    SIM->SCGC5 |= (1 << 13);

    /* Initialize the RED LED (PTE29) */
    /* Set the PTE29 pin multiplexer to GPIO mode */
    PORTE->PCR[29] |= PORT_PCR_MUX(1);
    /* Set the pin's direction to output */
    GPIOE->PDDR |= RED_LED_PIN;
    /* Set the initial output state to low (LED off) */
    GPIOE->PCOR |= RED_LED_PIN;
}

void initButtons()
{
    /* Enable clock for PORTC */
    SIM->SCGC5 |= (1 << 11);

    /* Set the SW1 and SW2 pins (PTC3 and PTC12) as input */
    GPIOC->PDDR &= ~(SW1_PIN | SW2_PIN);

    /* Enable the internal pull-up resistors for SW1 and SW2 */
    PORTC->PCR[3] |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PORTC->PCR[12] |= PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;

    /* Enable interrupt for SW2 (PTC12) */
    NVIC_EnableIRQ(PORTA_IRQn); // Corrected: Assign the interrupt to PORTC
    PORTC->PCR[12] |= PORT_PCR_IRQC(0x9); // Falling edge interrupt
}


void delay()
{
    uint32_t i;
    for (i = 0; i < DELAY_CNT; i++)
    {
        __asm("nop");
    }
}

void mode1()
{
    while (currentMode == MODE1)
    {
        /* Fade in the LED */
        for (brightnessLevel = 0; brightnessLevel <= 100; brightnessLevel += 5)
        {
            GPIOE->PCOR = RED_LED_PIN;  // Turn off the LED
            delay();

            // Calculate delay time based on brightness level
            uint32_t delayTime = (brightnessLevel * DELAY_CNT) / 100;
            for (uint32_t i = 0; i < delayTime; i++)
            {
                __asm("nop");
            }

            GPIOE->PSOR = RED_LED_PIN;  // Turn on the LED
            delay();

            /* Calculate delay time based on brightness level */
            delayTime = ((100 - brightnessLevel) * DELAY_CNT) / 100;
            for (uint32_t i = 0; i < delayTime; i++)
            {
                __asm("nop");
            }
        }

        /* Delay for 2 seconds */
        for (int i = 0; i < 4; i++)
        {
            delay();
        }

        // Fade out the LED
        for (brightnessLevel = 100; brightnessLevel >= 0; brightnessLevel -= 5)
        {
            GPIOE->PCOR = RED_LED_PIN;  // Turn off the LED
            delay();

            // Calculate delay time based on brightness level
            uint32_t delayTime = (brightnessLevel * DELAY_CNT) / 100;
            for (uint32_t i = 0; i < delayTime; i++)
            {
                __asm("nop");
            }

            GPIOE->PSOR = RED_LED_PIN;  // Turn on the LED
            delay();

            /* Calculate delay time based on brightness level */
            delayTime = ((100 - brightnessLevel) * DELAY_CNT) / 100;
            for (uint32_t i = 0; i < delayTime; i++)
            {
                __asm("nop");
            }
        }

        // Delay for 2 seconds
        for (int i = 0; i < 4; i++)
        {
            delay();
        }
    }
}


void mode2()
{
    while (currentMode == MODE2)
    {
        if ((GPIOC->PDIR & SW1_PIN) == 0)
        {
            /* SW1 is pressed, increase brightness level */
            brightnessLevel += 25;
            if (brightnessLevel > 100)
            {
                brightnessLevel = 0;
            }

            /* Debounce delay to avoid rapid changes when holding the button */
            delay();
        }
    }
}

void PORTC_IRQHandler()
{
    /* Check if SW2 is pressed (Mode switch) */
    if ((GPIOC->PDIR & SW2_PIN) == 0)
    {
        /* SW2 is pressed, change the mode */
        if (currentMode == MODE1)
        {
            currentMode = MODE2;
        }
        else
        {
            currentMode = MODE1;
            /* Reset brightness level when switching back to Mode 1 */
            brightnessLevel = 0;
        }

        /* Clear the interrupt by writing 1 to the corresponding bit in the ISFR */
        PORTC->ISFR |= SW2_PIN;

        /* Debounce delay to avoid rapid mode switching */
        delay();
    }
}
