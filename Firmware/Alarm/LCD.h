/*
 * LCD.h
 *
 * Created: 05/02/2016 20:58:36
 *  Author: Renan
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "Bits.h"


#ifndef LCD_H_
	#define lcdControl	PORTB
	#define lcdControlD	DDRB
	#define lcdRS		5
	#define lcdE		4
	#define lcdBus		PORTB
	#define lcdBusD		DDRB
#define LCD_H_
#endif /* LCD_H_ */

char strtemp[8];

void lcdWrite(char byte);

uint32_t Exp(uint8_t pot);

char *toStr(uint32_t value);
char *toStrRigth(uint32_t value);
char *subStr(char *str, uint8_t index, uint8_t length);
void cpyStr(char *toS, char *fromS);
int strLength(char * str);

void lcdprint(char *str);
void lcdprintchar(char byte);
void lcdprintat( int line, int colun, char *str);
void lcdprintatRigth(int line, int colun, char *str);

void lcdClean();

void lcdInit();