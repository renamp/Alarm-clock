/*
 * IIC.c
 *
 * Created: 12/08/2016 14:06:20
 *  Author: Renan
 */ 

#include "IIC.h"

void IIC_init(){
	// Frequency = CPU Clock / ( 16 + (2*TWBR) * (Prescaller) )
	
	TWSR = 0x00;		// Prescaller	= 1
	TWBR = 0x0C;		// Bit Rate		= 12
	
	// master
	TWAR = 0xFF;
	TWCR = (1<<TWEN);
}


uint8_t IIC_write(uint8_t *buff, uint8_t length){
	int timeout = 1000;
	
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);									// send Start
	while ((TWCR & (1<<TWINT)) == 0)if( --timeout <= 0 ) return 0;			// wait start
	
	TWDR = buff[0]&0xFE;													// device Adr
	TWCR = (1<<TWINT)|(1<<TWEN);											// send
	while ((TWCR & (1<<TWINT)) == 0);										// wait
	if( TWSR & 0x18 ){														//ACK received
		TWDR = buff[1];														// Reg adr
		TWCR = (1<<TWINT)|(1<<TWEN);										// send
		
		for( uint8_t index=2; index < length; index++ ){
			while ((TWCR & (1<<TWINT)) == 0);
			if( TWSR & 0x28){												// ack returned
				TWDR = buff[index];											// next byte
				TWCR = (1<<TWINT)|(1<<TWEN);
			}
			else return 0;
		}
		while ((TWCR & (1<<TWINT)) == 0);
		TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
		return 1;
	}
	return 0;
}


uint8_t IIC_read(uint8_t *buff, uint8_t length){
	int timeout = 1000;
	
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);									// send Start
	while ((TWCR & (1<<TWINT)) == 0)if( --timeout <= 0 ) return 0;			// wait start
	
	// Write Mode
	TWDR = buff[0]&0xFE;													// device Adr (Write)
	TWCR = (1<<TWINT)|(1<<TWEN);											// send
	while ((TWCR & (1<<TWINT)) == 0);										// wait
	if( TWSR & 0x18 ){														// ACK received
		TWDR = buff[1];														// Reg adr
		TWCR = (1<<TWINT)|(1<<TWEN);										// send
		
		// set adr for read
		while ((TWCR & (1<<TWINT)) == 0);									// wait ack
		if( TWSR & 0x28)													// ack returned
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);							// Restart for read
		else return 0;
		
		// Read Mode
		while ((TWCR & (1<<TWINT)) == 0);									// wait
		TWDR = buff[0] | 0x01;												// device Adr (Read)
		TWCR = (1<<TWINT)|(1<<TWEN);										// send
		
		while ((TWCR & (1<<TWINT)) == 0);									// wait
		if( TWSR & 0x40 ){													// ACK received
			//if( length > 1 )TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);							// send
			//else TWCR = (1<<TWINT)|(1<<TWEN);
			
			for( uint8_t index=0; index < length; index++ ){
				if( index < length-1 )TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);							// send
				else TWCR = (1<<TWINT)|(1<<TWEN);
				
				while ((TWCR & (1<<TWINT)) == 0);
				if( TWSR & 0x50){												// ack returned
					buff[index] = TWDR;											// next byte
					//if(index < length-2 && length > 1) TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
					//else TWCR = (1<<TWINT)|(1<<TWEN);
				}
				else return 0;
			}
			TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
			return 1;
		}
	}
	return 0;
}
