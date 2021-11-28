/*
 * CFile1.c
 *
 * Created: 05/02/2016 20:54:59
 *  Author: Renan
 */ 

#include "LCD.h"

void lcdWrite(char byte){
	
	lcdBus &= 0xF0;
	lcdBus |= (0x0F&(byte>>4));
	setbit(lcdControl, lcdE);
	_delay_us(1);
	clearbit(lcdControl, lcdE);
	
	lcdBus &= 0xF0;
	lcdBus |= (0x0F&byte);
	setbit(lcdControl, lcdE);
	_delay_us(1);
	clearbit(lcdControl, lcdE);
	
}


uint32_t Exp(uint8_t pot){
	uint32_t exp = 1;
	while( pot > 0 ){ exp *= 10; pot--;}
	return exp;
}

char *toStr(uint32_t value){
	uint8_t index = 0;
	for(uint8_t i=0; i<6; i++){
		uint32_t temp = Exp(5-i);
		if( value >= temp ){
			strtemp[index++] = (value/temp)+0x30;
			value = value % temp;
		}
		else if( index > 0) strtemp[index++] = '0';
	}
	if( index == 0 ) strtemp[index++] = '0';
	strtemp[index] = '\0';
	return strtemp;
}

char *toStrRigth(uint32_t value){
	uint8_t length;
	char* str = toStr(value);
	char temp;
	for(length=0; str[length]!='\0'; length++ );
	for( uint8_t i=0; i<length; i++,length--){
		temp=str[i]; str[i]=str[length-1]; str[length-1]=temp;
	}
	return str;
}

char *subStr(char *str, uint8_t index, uint8_t length){
	uint8_t i = 0;
	for( i=0; i<length && str[i]!='\0'; i++) strtemp[i] = str[i+index];
	strtemp[i] = '\0';
	return strtemp;
}

void cpyStr( char *toS, char *fromS){
	int i;
	for( i=0; fromS[i]!='\0'; i++) toS[i]=fromS[i];
	toS[i] = '\0';
}

int strLength(char * str){
	int length;
	for( length=0; str[length]!='\0'; length++ );
	return length;
}



void lcdprint(char *str){
	setbit(lcdControl, lcdRS);
	for( int i=0; str[i]!='\0'; i++){
		lcdWrite(str[i]);
		_delay_us(50);
	}
	clearbit(lcdControl, lcdRS);
}



void lcdprintchar(char byte){
	setbit(lcdControl, lcdRS);
	lcdWrite(byte);
	_delay_us(50);
	clearbit(lcdControl, lcdRS);
}

void lcdprintat( int line, int colun, char *str){
	char position = line*0x40;
	position += colun;
	lcdWrite(0x80|position);
	_delay_us(50);
	lcdprint(str);
}

void lcdprintatRigth(int line, int colun, char *str){
	lcdWrite(0x04);	// rigth aling
	_delay_us(40);
	lcdprintat(line, colun, str);
	lcdWrite(0x06);	// Left (Default)
	_delay_us(40);
}



void lcdClean(){
	lcdWrite(0x01);		// Clean
	_delay_ms(2);
}

void lcdInit(){

	_delay_ms(50);
	// init
	clearbit(lcdControl, lcdRS);
	clearbit(lcdControl, lcdE);
	setbit(lcdControlD, lcdRS);
	setbit(lcdControlD, lcdE);
	setbit(lcdBusD, 0);
	setbit(lcdBusD, 1);
	setbit(lcdBusD, 2);
	setbit(lcdBusD, 3);
	
	
	lcdWrite(0x33);		// Display MODE
	_delay_us(50);
	lcdWrite(0x33);
	_delay_us(50);
	
	lcdBus = lcdBus&0xF0;
	lcdBus |= (0x2);
	setbit(lcdControl, lcdE);
	_delay_us(1);
	clearbit(lcdControl, lcdE);
	
	_delay_us(50);
	lcdWrite(0x28);		// Display MODE
	_delay_us(50);
	lcdWrite(0x0C);		// Display On/Off
	_delay_us(50);
	
	lcdClean();
}
