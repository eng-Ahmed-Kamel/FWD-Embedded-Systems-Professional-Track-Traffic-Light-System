/*
 * traffic light sys.c
 *
 * Created: 8/10/2022 3:17:31 AM
 * Author : OZY
 */ 

#include <avr/interrupt.h> // include sys defined header file (<>)
#include "app/app.h"  // include user defined header file ("")
int main(void)
{
	/* Replace with your application code */
	
	APP_init();// function call
	APP_start();// function call
}

ISR(INT0_vect) // interrupt fun
{
	static int value; //declare of variable
	int overflow = 0, counter = 0; // declare of variable
	DIO_read(0, 'A', &value); // func call
	if(value == 1)  //check value
	{
		TCCR0 |= (1<<0); //NO usage of  prescalar
		while (overflow < 19532) //while loop for timer
		{
			while ((TIFR & (1<<0)) == 0);
			TIFR |= (1<<0);
			overflow++; //over flow inc
		}
		overflow = 0; //set overflow value to 0
		TCNT0 = 0x00; //set bit value to 0
	}
	else if (value == 0) // check value 
	{
		LED_off('A', 1);  // turning yellow of car traffic light off
		LED_off('A', 2);  // turning green of car traffic light off
		LED_off('B', 1); // turning yellow of pedestrian traffic light off
		LED_off('B', 0); // turning red of pedestrian traffic light off
		while (overflow < 20) //while  loop
		{
			
			LED_toggle('A', 1); // blinking yellow of cars traffic light 
			LED_toggle('B', 1); // blinking yellow of pedestrian traffic light 
			while (counter < 1000) // while for setup timer 
			{
				while ((TIFR & (1<<0)) == 0);
				TIFR |= (1<<0);
				counter++; //counter increment 
			}
			counter = 0; // make counter = 0
			TCNT0 = 0x00; // force register to zero
			overflow ++; // overflow increment 
		}
		overflow = 0;  // make overflow = 0
		TCNT0 = 0x00;  // force register bit to zero
		GICR&=~(1<<INT0); // clear bit 
		APP_start(); //function  call
	}
}
