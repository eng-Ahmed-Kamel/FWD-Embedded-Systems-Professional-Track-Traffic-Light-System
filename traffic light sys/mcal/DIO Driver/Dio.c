/*
 * Dio.c
 *
 * Created: 8/10/2022 3:28:41 AM
 *  Author: OZY
 */ 
// include.h
#include "Dio.h"  // include user defined header file(DIO) ("")
// function definition of DIO Initialize 
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	switch(portNumber) //switch case 
{
	case PORT_A:
	if(direction == IN) // check
	{
		DDRA &= ~(1 << pinNumber); //input
	}
	else if (direction == OUT)// check
	{
			DDRA |= (1 << pinNumber);// Output
	}
	break;
	case PORT_B:
   if(direction == IN)// check
    {
	DDRB &= ~(1 << pinNumber);//input
	}
	else if (direction == OUT)// check
	{
	DDRB |= (1 << pinNumber);// Output
	}
	break;
	case PORT_C:
	if(direction == IN)// check
	{
		DDRC &= ~(1 << pinNumber); //input
	}
	else if (direction == OUT)// check
	{
		DDRC |= (1 << pinNumber);// Output
	}
	break;
	case PORT_D:
	if(direction == IN)// check
	{
		DDRD &= ~(1 << pinNumber); //input
	}
	else if (direction == OUT)// check
	{
		DDRD |= (1 << pinNumber);// Output
	}
	break;
}
}
// function definition of  DIO toggle 
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber){
	switch(portNumber) //switch case 
	{
		case PORT_A:
			PORTA ^=(1 << pinNumber); //toggle Xor bit with 1
			
			break;
		case PORT_B:
			PORTB ^=(1 << pinNumber); //toggle Xor bit with 1
			
			break;
		case PORT_C:
			PORTC ^=(1 << pinNumber); //toggle Xor bit with 1
			
			break;
		case PORT_D:
			PORTD ^=(1 << pinNumber); //toggle Xor bit with 1
			
			break;
		default:
		break;
	}
}


// function definition of DIO write 
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value){
switch(portNumber) // switch case
{
	case PORT_A:
	if(value == LOW) // check 
	{
		PORTA &=~(1 << pinNumber); // (write 0) And bit with 0
	}
	else if(value == HIGH)// check
	{
		PORTA |= (1 << pinNumber);  // ( write 1) or bit with 1
	}
	break;
	case PORT_B:
	if(value == LOW)// check
	{
		PORTB &=~(1 << pinNumber); // (write 0) And bit with 0
	}
	else if(value == HIGH)// check
	{
		PORTB |= (1 << pinNumber);  // ( write 1) or bit with 1
	}
	break;
	case PORT_C:
	if(value == LOW)// check
	{
		PORTC &=~(1 << pinNumber); // (write 0) And bit with 0
	}
	else if(value == HIGH)// check
	{
		PORTC |= (1 << pinNumber);  // ( write 1) or bit with 1
	}
	break;
	case PORT_D:
	if(value == LOW)// check
	{
		PORTD &=~(1 << pinNumber); // (write 0) And bit with 0
	}
	else if(value == HIGH)// check
	{
		PORTD |= (1 << pinNumber); // ( write 1) or bit with 1
	}
	break;
	default:
	break;
}
}

// function definition of DIO read 
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	switch (portNumber) //switch case 
	{
		case PORT_A:
		*value= (PINA & (1 << pinNumber))>> pinNumber; // get state-> read bit
		break;
		case PORT_B:
		*value= (PINB & (1 << pinNumber))>> pinNumber; // get state-> read bit
		break;
		case PORT_C:
		*value=(PINC & (1 << pinNumber))>> pinNumber; // get state-> read bit
		break;
		case PORT_D:
		*value=(PIND & (1 << pinNumber))>> pinNumber; // get state -> read bit 0 or 1
		break;
		default:
		break;}}