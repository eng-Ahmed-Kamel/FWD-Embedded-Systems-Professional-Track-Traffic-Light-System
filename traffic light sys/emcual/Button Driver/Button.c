/*
 * Button.c
 *
 * Created: 8/10/2022 4:56:16 AM
 *  Author: OZY
 */ 
#include "button.h" //include user defined header file(Button) ("")
//button initialize function definition
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin) // Button is an input device
{
	DIO_init(buttonPin, buttonPort, IN);
}
// button read function definition
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
	DIO_read(buttonPin, buttonPort, value);
}