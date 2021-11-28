/*
 * IIC.h
 *
 * Created: 12/08/2016 14:06:41
 *  Author: Renan
 */ 


#ifndef IIC_H_
#define IIC_H_

#endif /* IIC_H_ */

#include <avr/io.h>


void IIC_init();

// write new time
//uint8_t param[]={0xD0, 0x00, 0x00, 0x08, (1<<6)|0x20, 0x06, 0x12, 0x08, 0x16};
//if( IIC_write(param, 9) ){ UART_Write('O'); UART_Write('K');}

// read time
//uint8_t param[]={0xD0, 0, 0, 0, 0, 0, 0};
//if( IIC_read(param, 7) ){
//	for( int i=0; i< 7; i++) UART_Write(param[i]);
//}


//////////////////////////////////////////////////////////////////
// Write a Vet of bytes
// first byte must be Device Adr
//
uint8_t IIC_write(uint8_t *buff, uint8_t length);


//////////////////////////////////////////////////////////////////
// Read a Vet of bytes
// first byte must be Device Adr
// second byte is Initial Reg Adr
uint8_t IIC_read(uint8_t *buff, uint8_t length);