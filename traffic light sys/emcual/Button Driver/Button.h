/*
 * Button.h
 *
 * Created: 8/10/2022 4:56:00 AM
 *  Author: OZY
 */ 

 
#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../mcal/DIO Driver/dio.h" //include user defined header file(DIO) ("")
// button state  macros
#define LOW 0
#define HIGH 1
// button port macro 
#define BUTTON_1_PORT PORT_D
// button pin macro
#define BUTTON_1_PIN PIN2
// button initialize function prototype
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
// button read function prototype
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);

#endif /* BUTTON_H_ */