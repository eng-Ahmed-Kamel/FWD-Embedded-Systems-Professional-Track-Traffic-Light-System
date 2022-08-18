/*
 * LED.h
 *
 * Created: 8/10/2022 4:43:27 AM
 *  Author: OZY
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../mcal/DIO Driver/dio.h" //include user defined header file(DIO) ("")
void LED_init(uint8_t ledPort, uint8_t ledPin); // function lead initialization prototype
void LED_on(uint8_t ledPort, uint8_t ledPin);  // function lead on prototype
void LED_off(uint8_t ledPort, uint8_t ledPin);  // function lead off prototype
void LED_toggle(uint8_t ledPort, uint8_t ledPin); // function lead toggle prototype



#endif /* LED_H_ */