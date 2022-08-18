/*
 * app.c
 *
 * Created: 8/10/2022 10:00:21 AM
 *  Author: OZY
 */ 
#include "app.h"
#include <avr/interrupt.h>
void APP_init(void) // function initialize app definition
{
	DIO_init(2, 'D', IN); // specialize as input 
	DIO_init(0, 'A', OUT); // specialize as output 
	DIO_init(1, 'A', OUT);	// specialize as output
	DIO_init(2, 'A', OUT);	// specialize as output
	DIO_init(0, 'B', OUT);	// specialize as output
	DIO_init(1, 'B', OUT);	// specialize as output
	DIO_init(2, 'B', OUT);	// specialize as output
}
void APP_start(void)  // function start app definition
{
	unsigned int overflow = 0; // definition of variable
	int counter = 0; // definition of variable
	sei(); // interrupter usage 
	MCUCR |= (1<<ISC00) | (1<<ISC01); // rising up interrupt
	GICR |= (1<<INT0);  // set bit of global interrupt control register 
	TCCR0 = 0x00; //Normal Mode
	TCNT0 = 0x00; //set initial value to 0
	TCCR0 |= (1<<0);  //set bit value to 1
	while (1) 
	{
		LED_on('A', 0);
		LED_on('B', 2);
		TCCR0 |= (1<<0); //NO usage of  prescalar
		while (overflow < 19532) //while loop for timer 
		{
			while ((TIFR & (1<<0)) == 0);
			TIFR |= (1<<0);
			overflow++; //over flow inc 
		}
		overflow = 0; //set overflow value to 0
		TCNT0 = 0x00; //set bit value to 0
		LED_off('A', 0);
		LED_off('B', 2);
		while (overflow < 20) //blinking mood
		{
			
			LED_toggle('A', 1);
			LED_toggle('B', 1);
			while (counter < 1000)
			{
				while ((TIFR & (1<<0)) == 0);
				TIFR |= (1<<0); 
				counter++; // counter inc
			}
			counter = 0; //set counter value to 0
			TCNT0 = 0x00; //set bit value to 0
			overflow ++; // overflow inc
		}
		overflow = 0; //set overflow value to 0
		TCNT0 = 0x00;
		LED_off('A', 1);
		LED_off('B', 1);
		LED_on('A', 2);
		LED_on('B', 0);
		while (overflow < 19532)
		{
			while ((TIFR & (1<<0)) == 0);
			TIFR |= (1<<0); //set bit value to 0
			overflow++; // overflow inc
		}
		overflow = 0;//set overflow value to 0
		TCNT0 = 0x00; //set bit value to 0
		LED_off('A', 2);
		LED_off('B', 0);
		while (overflow < 20) //blinking mood
		{
			
			LED_toggle('A', 1);
			LED_toggle('B', 1);
			while (counter < 1000)
			{
				while ((TIFR & (1<<0)) == 0);
				TIFR |= (1<<0);
				counter++; // counter inc
			}
			counter = 0; //set counter value to 0
			TCNT0 = 0x00; //set bit value to 0
			overflow ++; //overflow inc
		}
		overflow = 0; //set overflow value to 0
		TCNT0 = 0x00; //set bit value to 0
		LED_off('A', 1);
		LED_off('B', 1);
	}
}