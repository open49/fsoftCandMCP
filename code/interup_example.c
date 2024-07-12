#include "MKL46Z4.h"

// LED GREEN --> PIN 5


void init_LED()

{

   // enable clock led green  --> PORTD

    SIM->SCGC5 |= 1 << 12;



    // Config mode GPIO  --> mux

    PORTD->PCR[5] |= 1 << 8;

    PORTD->PCR[5] &= ~(1 << 9);

    PORTD->PCR[5] &= ~(1 << 10);



    // Config direction as ouput

    GPIOD->PDDR |= 1 << 5;



    // Init value

    GPIOD->PCOR |= 1 << 5;

}



// init switch for PTC3 as interrupt

void init_sw()

{

    // enable clock for port 3

    SIM->SCGC5 |= 1 << 11;



    // Config GPIO - MUX

    PORTC->PCR[3] |= 1 << 8;

    PORTC->PCR[3] &= ~(1 << 9);

    PORTC->PCR[3] &= ~(1 << 10);



    // Config direction as input

    GPIOC->PDDR &= ~(1 << 3);



    // Enable pull

    PORTC->PCR[3] |= 1 << 1;



    // Allow pull up

    PORTC->PCR[3] |= 1 << 0;



    // config for interrupt

    // Config falling edge

    PORTC->PCR[3] |= 1 << 17;

    PORTC->PCR[3] |= 1 << 19;

    PORTC->PCR[3] &= ~(1 << 16);

    PORTC->PCR[3] &= ~(1 << 18);



    // enable interrupt

    __NVIC_EnableIRQ(PORTC_PORTD_IRQn);

}





int main()

{

    init_LED();



    init_sw();

    while (1)

    {



    }

}





void PORTC_PORTD_IRQHandler()

{

    GPIOD->PTOR |= 1 << 5;

}

