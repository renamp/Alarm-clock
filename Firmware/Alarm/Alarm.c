/*
 * Alarm.c
 *
 * Created: 09/08/2016 22:58:37
 *  Author: Renan
 */ 

/*
	DDRD, 4 = DFReadyBusy
	DDRD, 5 = Backligth
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>

#include "IIC.h"
#include "UART.h"
#include "Bits.h"
#include "LCD.h"

#define tw_nack 0
#define tw_ack 1

// DFPlayer
#define dfIsReady (PIND&(1<<4))
uint8_t dfVolume;

// RTC
#define rtcTimerReset rtcTimer=12		//12x10ms
uint8_t rtcTimer;
uint8_t param[7];


// config Timer
#define timer10ms (255-156)
#define blickTimerOn 3
#define blinkTimerReset 11		// 13 x 100ms
uint8_t vtimer100ms = 10;		// 10 x 10ms
uint8_t blinktimer;				


/////////////////////////////////////////////////////
// backligth control
uint8_t backlightTimerReset;							// time for backligth on
uint8_t backlightTimer;									// backligth counter
#define backlightSetON backlightTimer=backlightTimerReset;
#define testBacklight (PORTD&(1<<5))


////////////////////////////////////////////////
// Menu Control
uint8_t menu;
uint8_t menuTimer;
#define menuTimerReset menuTimer=12

///////////////////////////////////////////////
// Keys Control
#define keysTimerReset keysTimer=19
uint8_t keysTimer;
uint8_t keys;
#define keyMENU 3
#define keyENTER 2
#define keyLEFT 1
#define keyRIGHT 0
#define testKey(value) (keys&(1<<value))


///////////////////////////////////////////////
// Alarm Control
uint8_t AlarmId;
uint8_t AlarmDir[99];
uint8_t AlarmMus[99];
uint8_t AlarmMin[99];
uint8_t AlarmHor[99];
uint8_t AlarmDayDat[99];
uint8_t AlarmMon[99];

void setBackligth(uint8_t value){
	if( value ) setbit(PORTD, 5);
	else clearbit(PORTD, 5);
}


ISR( TIMER0_OVF_vect ){
	TCNT0 = timer10ms;
	vtimer100ms--;
	
	////////////////////////////////////////////
	// each 10ms
	if( keysTimer ) keysTimer--;
	if( rtcTimer ) rtcTimer--;
	if( menuTimer ) menuTimer--;
	
	////////////////////////////////////////////
	// each 100ms
	if( vtimer100ms == 0 ){ vtimer100ms = 10;
		// tempo para backligth
		if(backlightTimer) backlightTimer--;
		if( blinktimer ) blinktimer--;
	}
}

void dfPlayer(uint8_t cmd, uint8_t param1, uint8_t param2 ){
	uint16_t crc = 0x105 + cmd + param1 + param2;
	crc = (~crc)+1;
	
	UART_Write(0x7E);
	UART_Write(0xFF);
	UART_Write(0x06);
	UART_Write(cmd);
	UART_Write(0x00);
	UART_Write(param1);
	UART_Write(param2);
	UART_Write(crc>>8);
	UART_Write(crc);
	UART_Write(0xEF);
}
void dfPrintTime(uint8_t *param){
	lcdClean();
	lcdprintchar((param[2]>>4)	+ 0x30);	// hours
	lcdprintchar((param[2]&0x0F)+ 0x30);	//
	lcdprintchar(':');
	
	lcdprintchar((param[1]>>4)	+ 0x30);	// min
	lcdprintchar((param[1]&0x0F)+ 0x30);	//
	lcdprintchar(':');
	
	lcdprintchar((param[0]>>4)	+ 0x30);	// seconds
	lcdprintchar((param[0]&0x0F)+ 0x30);	//
	lcdprintchar(' ');
	
	lcdprintchar((param[4]>>4)	+ 0x30);	// date
	lcdprintchar((param[4]&0x0F)+ 0x30);	//
	lcdprintchar('/');
	
	lcdprintchar(((param[5]>>4)&7)+ 0x30);	// month
	lcdprintchar((param[5]&0x0F)+ 0x30);	//
}

void lcdprintDay(uint8_t day){
	if( !day ) lcdprint("ALL");
	else if( day == 1 )lcdprint("Sun");
	else if( day == 2 )lcdprint("Mon");
	else if( day == 3 )lcdprint("Tue");
	else if( day == 4 )lcdprint("Wed");
	else if( day == 5 )lcdprint("Thu");
	else if( day == 6 )lcdprint("Fri");
	else if( day == 7 )lcdprint("Sat");
}

void UpdateKeys(){
	keys = (~PINC)&0x0F;
	keysTimerReset;
}

void TestMenu(){
	
	// temp Key for testing
	if( testKey(keyRIGHT) ){ dfPlayer(1, 0, 0); }
	else if( testKey(keyLEFT) ){ dfPlayer(2, 0, 0);}
	else if( testKey(keyENTER) ){
		if( dfIsReady ) dfPlayer(0xD, 0, 0);
		else dfPlayer(0xE, 0, 0);
	}
	if( testKey(keyLEFT) && testKey(keyRIGHT) ){
		// write new time/
		//uint8_t param[]={0xD0, 0x00, 0x00, 0x15, 0x21, 0x01, 0x04, 0x09, 0x16};
		//if( IIC_write(param, 9) ){ lcdClean(); lcdprint("Time Changed"); _delay_ms(1000);}
	}
}

void LoadAlarm(){
	uint16_t adr = 0;
	for(uint8_t index =0; index<99; index++ ){
		AlarmDir[index] = eeprom_read_byte((uint8_t*)adr++);
		AlarmMus[index] = eeprom_read_byte((uint8_t*)adr++);
		AlarmDayDat[index] = eeprom_read_byte((uint8_t*)adr++);
		uint16_t temp = eeprom_read_word((uint16_t*)adr); adr+=2;
		AlarmMin[index] = temp&0x3F; temp >>= 6;
		AlarmHor[index] = temp&0x1F; temp >>=5;
		AlarmMon[index] = temp&0x0F;
	}
}
void SaveAlarm(){
/*
 Byte 0,1 Folder, Music 
 Byte 2,(3,4) daydate, (month-4, hour-5, min-6)
*/
	 uint16_t adr = (uint16_t)(AlarmId*5);
	 eeprom_write_byte((uint8_t*)adr++, AlarmDir[AlarmId]);
	 eeprom_write_byte((uint8_t*)adr++, AlarmMus[AlarmId]);
	 eeprom_write_byte((uint8_t*)adr++, AlarmDayDat[AlarmId]);
	 uint16_t mon_hor_min = AlarmMon[AlarmId]; mon_hor_min <<= 5;
	 mon_hor_min |= AlarmHor[AlarmId]; mon_hor_min <<= 6;
	 mon_hor_min |= AlarmMin[AlarmId];
	 eeprom_write_word((uint16_t*)adr, mon_hor_min);
}
void SaveEEPROM(){
	eeprom_write_byte((uint8_t*)511, dfVolume);
	
	lcdClean();lcdprintat(1,6,"Saved!");_delay_ms(300);
}
void LoadEEPROM(){
	dfVolume = eeprom_read_byte((uint8_t*)511);
	dfPlayer(0x06, 1, dfVolume);
}
void start(){
	UART_init(9600);
	
	// Buttons
	clearbit(DDRD, 4);
	clearbit(SFIOR, PUD);	// pull up enable
	PORTC = 0xFF;
	DDRC = 0xF0;
	
	IIC_init();
	
	// LCD
	// backligth
	setbit(DDRD, 5);   // output
	setbit(PORTD, 5);	// high
	lcdInit();			// already done in Firmware
	lcdClean();
	lcdprintat(0, 2,"Starting..");
	
	// Init Timer
	TCCR0 = 0x05;		// div 1024
	setbit(TIMSK, TOIE0);
	sei();
	
	
	keysTimerReset;
	rtcTimerReset;
	
	/////////////////////////////////////
	// Debug Only
	backlightTimerReset = 100;
	backlightSetON;
	/////////////////////////////////////
	
	_delay_ms(300);
	
	LoadEEPROM();
	LoadAlarm();
}
int main(void)
{	
	start();
	menu = 0;
	
    while(1){
		setBackligth(backlightTimer);
		if( !keysTimer ) UpdateKeys();					// read keys each amount of time
		if( !blinktimer ) blinktimer=blinkTimerReset;
		
		uint8_t menustat = menu>>4;
		
		/////////////////////////////////////////////////////
		// Keys Controller
		if( !testBacklight ){								// check if backlight off
			if( keys ) backlightSetON;						// turn on backlight if any key pressed
		} 
		else{
			if( keys ) backlightSetON;						// if any key pressed keep backlight on
			
			////////////////////////////////////////////////////////////////
			// Default screen
			if( menu == 0 ){
				if( testKey(keyMENU) ) menu = 0x10;		// enter main menu
				TestMenu();
			}
			// Menu Alarm Config
			else if( menustat==1 && menu>0x10 ){
				if( testKey(keyENTER) ){	
					if( menu<0x17) menu++;
					else menu = 0x11;
				}
				else if( testKey(keyRIGHT) ){
					if( menu == 0x11 && AlarmId<99){SaveAlarm(); AlarmId++;}
					else if( menu == 0x12 )AlarmDir[AlarmId]++;
					else if( menu == 0x13 )AlarmMus[AlarmId]++;
					else if( menu == 0x14 )AlarmHor[AlarmId]++;
					else if( menu == 0x15 )AlarmMin[AlarmId]++;
					else if( menu == 0x16 )AlarmDayDat[AlarmId]+=0x20;
					else if( menu == 0x17 && AlarmDayDat[AlarmId]<31)AlarmDayDat[AlarmId]++;
				}
				else if( testKey(keyLEFT) ){
					if(menu == 0x11 && AlarmId){SaveAlarm(); AlarmId--;}
					else if( menu == 0x12 && AlarmDir[AlarmId])AlarmDir[AlarmId]--;
					else if( menu == 0x13 && AlarmMus[AlarmId])AlarmMus[AlarmId]--;
					else if( menu == 0x14 && AlarmHor[AlarmId])AlarmHor[AlarmId]--;
					else if( menu == 0x15 && AlarmMin[AlarmId])AlarmMin[AlarmId]--;
					else if( menu == 0x16 )AlarmDayDat[AlarmId]-=0x20;
					else if( menu == 0x17 && AlarmDayDat[AlarmId]>0) AlarmDayDat[AlarmId]--;
				}
				else if( testKey(keyMENU) ){
					if( menu > 0x11) menu--;
					else{
						SaveAlarm();
						menu &= 0xF0;
					}
				}
			}
			// Menu Volume
			else if( menu == 0x31){
				if( testKey(keyMENU) || testKey(keyENTER)){ SaveEEPROM(); menu--; }
				else if( testKey(keyRIGHT) && dfVolume<30) dfPlayer(0x06, 1, ++dfVolume);	// volume++
				else if( testKey(keyLEFT) && dfVolume>0) dfPlayer(0x06, 1, --dfVolume);		// volume--
			}
			// Main Menu
			else if( menustat ){
				if(!(menu&0xF)){
					if( testKey(keyMENU) )menu = 0 ;
					else if( testKey(keyLEFT) && menustat>1) menu -= 0x10;			// main menu
					else if( testKey(keyRIGHT)&& menustat<3) menu += 0x10;			// main menu
					else if( testKey(keyENTER))	menu++;					// Enter subMenu
				}
				else {
					if( testKey(keyMENU) ) menu--;
				}
			}
		}
		
		
		//////////////////////////////////////////////////////////////////////////////
		// Update Time
		if( !rtcTimer ){
			rtcTimerReset;
			
			param[0] = 0xD0; param[1]=0;
			if( IIC_read(param, 7) ){
				if( dfIsReady  && (param[1]==0x00 && param[2]==0x22)) dfPlayer(0xf, 0x2, 0x1);
				else if( dfIsReady  && (param[1]==0x00 && param[2]==0x08)) dfPlayer(0xf, 0x2, 0x1);
			}
		}
		
		
		////////////////////////////////////////////////////////////////////////////
		// Timer  - Control LCD
		if( !menuTimer ){
			menuTimerReset;
			
			lcdClean();
			// Normal Operation
			if( menu == 0 ){
				dfPrintTime(param);
				if( !dfIsReady ) lcdprintat(0,15,">");
			}
			// Main Menu
			else if( menustat && !(menu&0x0F) ){
				lcdprintchar(0x7E);
				uint8_t id = menu>>4;
				if( id==1 ) lcdprintat(id-1,1, "Alarm Config");
				if( id==1||id==2 ) lcdprintat(id-2,1, "Time Config");
				if( id==2||id==3 ) lcdprintat(id-3,1, "Volume");
			}
			// Alarm Config
			else if( menustat==1 && menu>0x10){
				//lcdprint("Id:");		if( blinktimer>blickTimerOn || menu!=0x11 )lcdprint(toStr(AlarmId+1));
				//lcdprintat(0,6,"F:");	if( blinktimer>blickTimerOn || menu!=0x12 )lcdprint(toStr(AlarmDir[AlarmId]));
				//lcdprintat(0,11,"M:");	if( blinktimer>blickTimerOn || menu!=0x13 )lcdprint(toStr(AlarmMus[AlarmId]));
				lcdprint("Alarm Id:"); if( blinktimer>blickTimerOn || menu!=0x11 )lcdprint(toStr(AlarmId+1));
				if( menu == 0x12 ){ lcdprintat(1,0,"Folder "); if( blinktimer>blickTimerOn )lcdprint(toStr(AlarmDir[AlarmId])); }
				else if( menu == 0x13 ){ lcdprintat(1,0,"Music "); if( blinktimer>blickTimerOn )lcdprint(toStr(AlarmMus[AlarmId])); }
				else if( menu == 0x14 || menu == 0x15){ 
					lcdprintat(1,0,"Time H");
					if( blinktimer>blickTimerOn || menu!=0x14 ){ //lcdWrite(0xC1); _delay_us(50);
						if( AlarmHor[AlarmId] < 10) lcdprint("0"); lcdprint(toStr(AlarmHor[AlarmId]));
					}
					lcdprintat(1,9,"M");
					if( blinktimer>blickTimerOn || menu!=0x15 ){ //lcdWrite(0xC4); _delay_us(50);
						if( AlarmMin[AlarmId] < 10) lcdprint("0"); lcdprint(toStr(AlarmMin[AlarmId]));
					}
				}
				else if( menu == 0x16 || menu == 0x17 ){
					uint8_t day = AlarmDayDat[AlarmId]>>5;
					uint8_t data = AlarmDayDat[AlarmId]&0x1F;
					lcdprintat(1,0,"Day ");
					if( blinktimer>blickTimerOn || menu!=0x16 ) lcdprintDay(day);
					if( !day ){
						lcdprintat(1,8,"");
						if( !data && (blinktimer>blickTimerOn || menu!=0x17) ) lcdprint("--");
						else if(blinktimer>blickTimerOn || menu!=0x17){ if( data<10 ) lcdprint("0"); lcdprint(toStr(data)); }
						lcdprintat(1,10,"/");
					}
				}
			}
			// Volume
			else if( menu==0x31 ){
				lcdprint("Volume = ");
				if( blinktimer>blickTimerOn ) lcdprint(toStr(dfVolume));
			}
		}
		
		////////////////////////////////////
		// after main routine
		
		keys = 0;			// reset keys
    }
}