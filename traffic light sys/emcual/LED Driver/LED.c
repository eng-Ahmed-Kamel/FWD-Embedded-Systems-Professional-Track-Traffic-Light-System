/*
 * LED.c
 *
 * Created: 8/10/2022 4:43:46 AM
 *  Author: OZY
 */ 
#include "LED.h" //include user defined header file(LED) ("")
void LED_init(uint8_t ledPort, uint8_t ledPin){		// function led initialization definition
	DIO_init(ledPin, ledPort, OUT);
	
	}

void LED_on(uint8_t ledPort, uint8_t ledPin){ // function led on definition
	DIO_write(ledPin, ledPort, HIGH);
}
void LED_off(uint8_t ledPort, uint8_t ledPin){ // function led off definition
	DIO_write(ledPin, ledPort, LOW);
}
void LED_toggle(uint8_t ledPort, uint8_t ledPin){  // function led toggle definition
	DIO_toggle(ledPin, ledPort);
}