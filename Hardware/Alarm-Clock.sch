EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Alarm-Clock"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	2250 6850 2300 6850
Wire Wire Line
	2250 6850 2250 6750
Wire Wire Line
	2250 6750 2300 6750
Wire Wire Line
	8200 1350 8200 1400
Wire Wire Line
	4850 3150 4650 3150
Wire Wire Line
	1400 3100 1150 3100
Wire Wire Line
	9500 1900 9500 1950
Wire Wire Line
	1650 5950 1850 6050
Wire Wire Line
	1650 6350 1850 6250
Wire Wire Line
	8600 1350 8600 1400
Wire Wire Line
	8400 1400 8400 1350
Wire Wire Line
	750  800  750  700 
Wire Wire Line
	750  700  850  700 
Wire Wire Line
	850  700  1350 700 
Wire Wire Line
	1350 700  1350 800 
Wire Wire Line
	1350 700  1450 700 
Wire Wire Line
	1450 700  2050 700 
Wire Wire Line
	2050 700  2050 800 
Wire Wire Line
	2050 700  2150 700 
Wire Wire Line
	2150 700  2650 700 
Wire Wire Line
	2650 700  2650 800 
Wire Wire Line
	850  800  850  700 
Wire Wire Line
	1450 800  1450 700 
Wire Wire Line
	2150 800  2150 700 
Wire Wire Line
	2750 800  2750 700 
Wire Wire Line
	2750 700  2650 700 
Wire Wire Line
	2250 6550 2300 6550
Wire Wire Line
	2300 6650 2250 6650
Wire Wire Line
	2250 6650 2250 6550
Wire Wire Line
	8100 1350 8100 1400
Wire Wire Line
	750  700  500  700 
Wire Wire Line
	1400 3000 1150 3000
Wire Wire Line
	4000 4000 4250 4000
Wire Wire Line
	750  1200 750  1300
Wire Wire Line
	850  1200 850  1300
Wire Wire Line
	850  1300 750  1300
Wire Wire Line
	1350 1400 1350 1300
Wire Wire Line
	1350 1300 1350 1200
Wire Wire Line
	1450 1200 1450 1300
Wire Wire Line
	1450 1300 1350 1300
Wire Wire Line
	2050 1200 2050 1300
Wire Wire Line
	2050 1300 2050 1400
Wire Wire Line
	2150 1200 2150 1300
Wire Wire Line
	2150 1300 2050 1300
Wire Wire Line
	2650 1200 2650 1300
Wire Wire Line
	2650 1300 2650 1400
Wire Wire Line
	2750 1200 2750 1300
Wire Wire Line
	2750 1300 2650 1300
Wire Wire Line
	4850 3250 4650 3250
Wire Wire Line
	4850 3350 4650 3350
Wire Wire Line
	2300 5350 1900 5350
Wire Wire Line
	1400 3200 1150 3200
Wire Wire Line
	1150 3300 1400 3300
Wire Wire Line
	9500 1350 9500 1500
Wire Wire Line
	4850 3450 4000 3450
Wire Wire Line
	4000 3700 4200 3700
Wire Wire Line
	4200 3700 4200 3550
Wire Wire Line
	4200 3550 4850 3550
$Comp
L Alarm-Clock-eagle-import:MEGA8-AI IC1
U 1 1 22F7723E
P 3200 6350
F 0 "IC1" H 2500 4850 59  0000 L BNN
F 1 "MEGA8-AI" H 2500 7500 59  0000 L BNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 3200 6350 50  0001 C CNN
F 3 "" H 3200 6350 50  0001 C CNN
	1    3200 6350
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:CRYSTALHC49S Q1
U 1 1 098A5C63
P 1850 6150
F 0 "Q1" V 1700 6050 59  0000 L BNN
F 1 "16Mhz" V 2050 5900 59  0000 L BNN
F 2 "Alarm-Clock:HC49_S" H 1850 6150 50  0001 C CNN
F 3 "" H 1850 6150 50  0001 C CNN
	1    1850 6150
	0    -1   1    0   
$EndComp
$Comp
L Alarm-Clock-eagle-import:TUXGR_16X2_R2 DIS1
U 1 1 E925ABD7
P 8800 950
F 0 "DIS1" H 8000 1500 59  0000 L BNN
F 1 "TUXGR_16X2_R2" H 8750 1500 59  0000 L BNN
F 2 "Alarm-Clock:TUXGR_16X2_R2" H 8800 950 50  0001 C CNN
F 3 "" H 8800 950 50  0001 C CNN
	1    8800 950 
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:R-EU_0204_5 R5
U 1 1 C6C13DA3
P 8300 1700
F 0 "R5" H 8150 1759 59  0000 L BNN
F 1 "68R" H 8150 1570 59  0000 L BNN
F 2 "Alarm-Clock:0204_5" H 8300 1700 50  0001 C CNN
F 3 "" H 8300 1700 50  0001 C CNN
	1    8300 1700
	0    -1   -1   0   
$EndComp
$Comp
L Alarm-Clock-eagle-import:PINHD-1X8 JP1
U 1 1 9FA72D5F
P 5600 3550
F 0 "JP1" H 5350 4075 59  0000 L BNN
F 1 "MP3-R" H 5350 3050 59  0000 L BNN
F 2 "Alarm-Clock:1X08" H 5600 3550 50  0001 C CNN
F 3 "" H 5600 3550 50  0001 C CNN
	1    5600 3550
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:PINHD-1X8 JP2
U 1 1 83BD4EC0
P 4950 3550
F 0 "JP2" H 4700 4075 59  0000 L BNN
F 1 "MP3-L" H 4700 3050 59  0000 L BNN
F 2 "Alarm-Clock:1X08" H 4950 3550 50  0001 C CNN
F 3 "" H 4950 3550 50  0001 C CNN
	1    4950 3550
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:10-XX S1
U 1 1 788C9994
P 750 1000
F 0 "S1" V 500 900 59  0000 L BNN
F 1 "10-XX" V 600 1125 59  0000 L BNN
F 2 "Alarm-Clock:B3F-10XX" H 750 1000 50  0001 C CNN
F 3 "" H 750 1000 50  0001 C CNN
	1    750  1000
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:10-XX S2
U 1 1 F9B5905E
P 1350 1000
F 0 "S2" V 1100 900 59  0000 L BNN
F 1 "10-XX" V 1200 1125 59  0000 L BNN
F 2 "Alarm-Clock:B3F-10XX" H 1350 1000 50  0001 C CNN
F 3 "" H 1350 1000 50  0001 C CNN
	1    1350 1000
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:10-XX S3
U 1 1 638E9151
P 2050 1000
F 0 "S3" V 1800 900 59  0000 L BNN
F 1 "10-XX" V 1900 1125 59  0000 L BNN
F 2 "Alarm-Clock:B3F-10XX" H 2050 1000 50  0001 C CNN
F 3 "" H 2050 1000 50  0001 C CNN
	1    2050 1000
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:10-XX S4
U 1 1 6EFAC6B7
P 2650 1000
F 0 "S4" V 2400 900 59  0000 L BNN
F 1 "10-XX" V 2500 1125 59  0000 L BNN
F 2 "Alarm-Clock:B3F-10XX" H 2650 1000 50  0001 C CNN
F 3 "" H 2650 1000 50  0001 C CNN
	1    2650 1000
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:PINHD-1X10 JP4
U 1 1 193933AB
P 1500 3200
F 0 "JP4" H 1250 3725 59  0000 L BNN
F 1 "RTC" H 1250 2500 59  0000 L BNN
F 2 "Alarm-Clock:1X10" H 1500 3200 50  0001 C CNN
F 3 "" H 1500 3200 50  0001 C CNN
	1    1500 3200
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:PINHD-1X1 JP7
U 1 1 ADC4B3B7
P 1800 5350
F 0 "JP7" H 1550 5475 59  0000 L BNN
F 1 "PIN" H 1550 5150 59  0000 L BNN
F 2 "Alarm-Clock:1X01" H 1800 5350 50  0001 C CNN
F 3 "" H 1800 5350 50  0001 C CNN
	1    1800 5350
	-1   0    0    1   
$EndComp
$Comp
L Alarm-Clock-eagle-import:R-EU_0204_7 R6
U 1 1 17C25599
P 9500 1700
F 0 "R6" H 9350 1759 59  0000 L BNN
F 1 "68R" H 9350 1570 59  0000 L BNN
F 2 "Alarm-Clock:0204_7" H 9500 1700 50  0001 C CNN
F 3 "" H 9500 1700 50  0001 C CNN
	1    9500 1700
	0    -1   -1   0   
$EndComp
$Comp
L Alarm-Clock-eagle-import:PINHD-1X1 JP8
U 1 1 357D3C8D
P 3900 3450
F 0 "JP8" H 3650 3575 59  0000 L BNN
F 1 "PIN" H 3650 3250 59  0000 L BNN
F 2 "Alarm-Clock:1X01" H 3900 3450 50  0001 C CNN
F 3 "" H 3900 3450 50  0001 C CNN
	1    3900 3450
	-1   0    0    1   
$EndComp
$Comp
L Alarm-Clock-eagle-import:PINHD-1X1 JP9
U 1 1 C8B46213
P 3900 3700
F 0 "JP9" H 3650 3825 59  0000 L BNN
F 1 "PIN" H 3650 3500 59  0000 L BNN
F 2 "Alarm-Clock:1X01" H 3900 3700 50  0001 C CNN
F 3 "" H 3900 3700 50  0001 C CNN
	1    3900 3700
	-1   0    0    1   
$EndComp
$Comp
L Alarm-Clock-eagle-import:PINHD-1X1 JP13
U 1 1 9B8C9E68
P 3900 4000
F 0 "JP13" H 3650 4125 59  0000 L BNN
F 1 "PIN" H 3650 3800 59  0000 L BNN
F 2 "Alarm-Clock:1X01" H 3900 4000 50  0001 C CNN
F 3 "" H 3900 4000 50  0001 C CNN
	1    3900 4000
	-1   0    0    1   
$EndComp
Text Label 4200 5650 0    50   ~ 0
PC3
Text Label 750  1400 3    50   ~ 0
PC3
Wire Wire Line
	750  1300 750  1400
Connection ~ 750  1300
Connection ~ 1350 1300
Text Label 1350 1400 3    50   ~ 0
PC2
Text Label 4200 5550 0    50   ~ 0
PC2
Text Label 4200 5450 0    50   ~ 0
PC1
Text Label 2050 1400 3    50   ~ 0
PC1
Text Label 4200 5350 0    50   ~ 0
PC0
Text Label 2650 1400 3    50   ~ 0
PC0
Connection ~ 2650 1300
Connection ~ 2050 1300
Text Label 4200 5750 0    50   ~ 0
PC4
Text Label 1150 3200 2    50   ~ 0
PC4
Text Label 4200 5850 0    50   ~ 0
PC5
Text Label 1150 3300 2    50   ~ 0
PC5
Text Label 4200 6350 0    50   ~ 0
PD1
Text Label 4650 3250 2    50   ~ 0
PD1
Text Label 4650 3350 2    50   ~ 0
PD0
Text Label 4200 6250 0    50   ~ 0
PD0
Text Label 4200 6650 0    50   ~ 0
PD4
Text Label 5300 3150 2    50   ~ 0
PD4
Wire Wire Line
	5300 3150 5500 3150
Wire Wire Line
	9100 1350 9100 1400
Text Label 4200 7150 0    50   ~ 0
PB0
Text Label 9100 1400 3    50   ~ 0
PB0
Text Label 9200 1400 3    50   ~ 0
PB1
Text Label 9300 1400 3    50   ~ 0
PB2
Wire Wire Line
	9200 1350 9200 1400
Wire Wire Line
	9300 1350 9300 1400
Text Label 9400 1400 3    50   ~ 0
PB3
Wire Wire Line
	9400 1350 9400 1400
Text Label 4200 7250 0    50   ~ 0
PB1
Text Label 4200 7350 0    50   ~ 0
PB2
Text Label 4200 7450 0    50   ~ 0
PB3
Text Label 4200 7550 0    50   ~ 0
PB4
Text Label 8600 1400 3    50   ~ 0
PB4
Text Label 4200 7650 0    50   ~ 0
PB5
Text Label 8400 1400 3    50   ~ 0
PB5
Text Label 8100 1400 3    50   ~ 0
GND
Text Label 500  700  2    50   ~ 0
GND
Text Label 1150 3000 2    50   ~ 0
GND
Text Label 4650 3750 2    50   ~ 0
GND
Text Label 2250 6550 2    50   ~ 0
GND
Connection ~ 750  700 
Connection ~ 850  700 
Connection ~ 1350 700 
Connection ~ 1450 700 
Connection ~ 2050 700 
Connection ~ 2150 700 
Connection ~ 2650 700 
Text Notes 900  400  0    197  ~ 0
Inputs
Text Label 2300 5550 2    50   ~ 0
GND
Wire Wire Line
	9600 1350 9600 1400
Text Label 9600 1400 3    50   ~ 0
GND
Wire Wire Line
	8500 1350 8500 1400
Text Label 8500 1400 3    50   ~ 0
GND
Text Label 4650 3150 2    50   ~ 0
VCC
Text Label 1150 3100 2    50   ~ 0
VCC
Wire Wire Line
	8300 1350 8300 1500
Text Label 8300 1950 3    50   ~ 0
VCC
Text Label 8200 1400 3    50   ~ 0
VCC
Wire Wire Line
	8300 1900 8300 1950
Text Label 9500 1950 3    50   ~ 0
VCC
Text Label 4200 6550 0    50   ~ 0
PD3
Text Label 4200 6450 0    50   ~ 0
PD2
Text Label 2250 6750 2    50   ~ 0
VUSB
Connection ~ 1850 6250
Wire Wire Line
	5600 900  5600 1000
Connection ~ 5600 1000
Wire Wire Line
	4650 1000 4650 1350
Connection ~ 4650 1000
Wire Wire Line
	4700 1000 4650 1000
Wire Wire Line
	4650 900  4650 1000
Text Label 4350 1350 2    50   ~ 0
GND
Wire Wire Line
	4000 1000 4050 1000
Wire Wire Line
	4000 1350 4000 1000
Wire Wire Line
	4350 1350 4000 1350
Wire Wire Line
	4550 1000 4550 1350
Connection ~ 4550 1000
Wire Wire Line
	4450 1000 4550 1000
Wire Wire Line
	4550 900  4550 1000
$Comp
L Alarm-Clock-eagle-import:R-EU_0204_5 R3
U 1 1 A04F324A
P 4250 1000
F 0 "R3" H 4200 1050 59  0000 L BNN
F 1 "1M" H 4200 850 59  0000 L BNN
F 2 "Alarm-Clock:0204_5" H 4250 1000 50  0001 C CNN
F 3 "" H 4250 1000 50  0001 C CNN
	1    4250 1000
	-1   0    0    1   
$EndComp
Text Label 5600 900  0    50   ~ 0
VUSB
Text Label 4550 400  1    50   ~ 0
PD2
Wire Wire Line
	4550 500  4550 400 
$Comp
L Alarm-Clock-eagle-import:R-EU_0204_7 R2
U 1 1 897A6941
P 4650 700
F 0 "R2" H 4450 750 59  0000 L BNN
F 1 "68R" H 4600 750 59  0000 L BNN
F 2 "Alarm-Clock:0204_7" H 4650 700 50  0001 C CNN
F 3 "" H 4650 700 50  0001 C CNN
	1    4650 700 
	0    1    1    0   
$EndComp
Text Label 4650 400  1    50   ~ 0
PD3
Text Label 4000 1000 2    50   ~ 0
GND
Wire Wire Line
	4750 1350 4950 1350
Text Label 4750 1350 0    50   ~ 0
VCC
$Comp
L Alarm-Clock-eagle-import:MINI-USB-32005-201 X1
U 1 1 8679BB61
P 4550 1550
F 0 "X1" H 4500 1100 70  0000 L BNN
F 1 "MINI-USB-32005-201" V 4950 950 70  0000 L BNN
F 2 "Alarm-Clock:32005-201" H 4550 1550 50  0001 C CNN
F 3 "" H 4550 1550 50  0001 C CNN
	1    4550 1550
	0    1    1    0   
$EndComp
$Comp
L Alarm-Clock-eagle-import:1N4148DO35-7 D2
U 1 1 0CADE672
P 5050 1350
F 0 "D2" H 5100 1400 59  0000 L BNN
F 1 "1N4148" H 4950 1150 59  0000 L BNN
F 2 "Alarm-Clock:DO35-7" H 5050 1350 50  0001 C CNN
F 3 "" H 5050 1350 50  0001 C CNN
	1    5050 1350
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:1N4148DO35-7 D1
U 1 1 C78C3FBD
P 5450 1350
F 0 "D1" H 5500 1400 59  0000 L BNN
F 1 "1N4148" H 5400 1150 59  0000 L BNN
F 2 "Alarm-Clock:DO35-7" H 5450 1350 50  0001 C CNN
F 3 "" H 5450 1350 50  0001 C CNN
	1    5450 1350
	1    0    0    -1  
$EndComp
$Comp
L Alarm-Clock-eagle-import:R-EU_0204_7 R4
U 1 1 7E68E8B0
P 4900 1000
F 0 "R4" H 4850 1050 59  0000 L BNN
F 1 "1K5" H 4800 850 59  0000 L BNN
F 2 "Alarm-Clock:0204_7" H 4900 1000 50  0001 C CNN
F 3 "" H 4900 1000 50  0001 C CNN
	1    4900 1000
	-1   0    0    1   
$EndComp
$Comp
L Alarm-Clock-eagle-import:R-EU_0204_7 R1
U 1 1 58428EFC
P 4550 700
F 0 "R1" H 4350 600 59  0000 L BNN
F 1 "68R" H 4500 600 59  0000 L BNN
F 2 "Alarm-Clock:0204_7" H 4550 700 50  0001 C CNN
F 3 "" H 4550 700 50  0001 C CNN
	1    4550 700 
	0    1    1    0   
$EndComp
Wire Wire Line
	5150 1350 5350 1350
Wire Wire Line
	5600 1350 5600 1000
Wire Wire Line
	5550 1350 5600 1350
Wire Wire Line
	5100 1000 5600 1000
Wire Wire Line
	4650 500  4650 400 
Text Notes 3350 400  0    197  ~ 0
USB
Wire Notes Line
	0    2200 11700 2200
Text Notes 6400 400  0    197  ~ 0
Display
Text Label 2300 5750 2    50   ~ 0
VUSB
$Comp
L Alarm-Clock-eagle-import:C-EU025-024X044 C2
U 1 1 AFDC56A7
P 1550 5950
F 0 "C2" H 1610 5965 59  0000 L BNN
F 1 "27p" H 1610 5765 59  0000 L BNN
F 2 "Alarm-Clock:C025-024X044" H 1550 5950 50  0001 C CNN
F 3 "" H 1550 5950 50  0001 C CNN
	1    1550 5950
	0    1    1    0   
$EndComp
Connection ~ 1850 6050
Wire Wire Line
	1850 6050 2300 6050
$Comp
L Alarm-Clock-eagle-import:C-EU025-024X044 C1
U 1 1 CB58E417
P 1550 6350
F 0 "C1" H 1610 6365 59  0000 L BNN
F 1 "27p" H 1610 6165 59  0000 L BNN
F 2 "Alarm-Clock:C025-024X044" H 1550 6350 50  0001 C CNN
F 3 "" H 1550 6350 50  0001 C CNN
	1    1550 6350
	0    1    1    0   
$EndComp
Text Label 1250 6150 2    50   ~ 0
GND
Wire Wire Line
	1350 5950 1250 5950
Wire Wire Line
	1250 5950 1250 6350
Wire Wire Line
	1250 6350 1350 6350
Wire Wire Line
	2300 6250 1850 6250
Text Notes 200  2550 0    197  ~ 0
RTC module
Wire Notes Line
	3150 0    3150 4400
Wire Wire Line
	4250 4000 4250 3750
Wire Wire Line
	4250 3750 4850 3750
Text Notes 3400 2600 0    197  ~ 0
DFPlayer
Wire Notes Line
	6150 0    6150 4400
Wire Notes Line
	0    4400 6150 4400
Text Notes 300  4850 0    197  ~ 0
Microcontroller
$EndSCHEMATC
