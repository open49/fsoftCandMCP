#include "MKL46Z4.h"

// LED GREEN --. PIN 5

void init_LED()
{
	// ENEBAL CLOCK LED GREN - > PORTD
	SIM->SCGC5 |=  1 << 12;
	// CONFIG MODE GPIO

	PORTD->PCR[5] |= 1 << 8;
	PORTD->PCR[5] &= ~ (1 << 9);
	PORTD->PCR[5] &= ~ (1 << 10);


	//CONFIG DIRECTION AS OUTPUT

	GPIO->PDDR |= 1 << 5;

	//INIT VALUE

	GPIO->PCOR 1 << 5 ;


}
// INIT SWITCH FOR PCT3 AS INTERUP
void init_sw()
{
	// ENABLE CLOCK FOR PORT 3

	SIM->SCGC5 |= 1 << 11;
	// CONFIG GPIO
	PORTC->PCR[3] |= 1 << 8;
	PORTC->PCR[3] &= ~ (1 << 9);
	PORTC->PCR[3] &= ~ (1 << 10);


	// CONFIG DIRECTION AS INPUT

	GPIOC->PDDR &= ~ (1 << 3);
	// ENABLE PULL

	PORT->PCR[3] |= 1 << 1;

	// ALLOW PULL UP

	PORTC->PCR[3] |= 1 << 0;

	// CONFIG INTERRUPT

	PORT->PCR[3] |= 1 << 17;
	PORT->PCR[3] |= 1 << 19;
	PORT->PCR[3] &=  ~ (1 << 16);
	PORT->PCR[3] &=  ~ (1 << 18);



}

int main()
{
	init_LED();
	init_sw();
	while(1)
	{

	}


}
