/*
 * main.c
 *
 *  Created on: Oct 25, 2023
 *      Author: AHMED
 */

#include "LIB/STD_TYPES.h"
#include <avr/delay.h>


#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Port/Port_Interface.h"
#include "HAL/LCD2/LCD_Interface.h"


u8 P1[8] = {0b01110, 0b01110, 0b00100, 0b11111, 0b00100, 0b01010, 0b01010, 0b11011};
u8 P2[8] = {0b01110, 0b01110, 0b10101, 0b01110, 0b00100, 0b01110, 0b01010, 0b11011};
u8 P3[8] = {0b01110, 0b01110, 0b00101, 0b00110, 0b01100, 0b10100, 0b01010, 0b11011};

u8 line[8] = {0b10000,0b10000,0b10000,0b10000,0b10000,0b10000,0b10000};

#define Delay_Time   1000

void MoveLeft()
{
	u8 start = 10;
	LCD_voidGoToPosition(1,0);
		LCD_voidWriteString((u8*)"5od yalaa");
		_delay_ms(Delay_Time);

	do
	{
		LCD_voidDisplaySpecialChar(P1,0,0,start);
		LCD_voidDisplaySpecialChar(P1,0,0,start-1);
		_delay_ms(350);
		LCD_voidClear(0,start);
		LCD_voidClear(0,start-1);
		start++;
		if(start == 17)
		{
			LCD_voidGoToPosition(2,0);
			LCD_voidWriteString((u8*)"5od t3laa");
		}

	}while(start < 19);
}

void MoveRight()
{
	u8 start = 0;
	do
	{
		LCD_voidGoToPosition(0,0);
		LCD_voidDisplaySpecialChar(P1,0,0,start);
		LCD_voidDisplaySpecialChar(P1,0,0,(19 - start));
		_delay_ms(350);
		LCD_voidClear(0,start);
		LCD_voidClear(0,(19 - start));
		start++;

	}while(start < 9);

	LCD_voidDisplaySpecialChar(P1,0,0,start);
	LCD_voidDisplaySpecialChar(P1,0,0,(19 - start));
	LCD_voidDisplaySpecialChar(line,2,1,10);
	LCD_voidDisplaySpecialChar(line,2,2,10);
	LCD_voidDisplaySpecialChar(line,2,3,10);
}

void Write()
{
	LCD_voidGoToPosition(1,0);
	LCD_voidWriteString((u8*)"Eh da...");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,11);
	LCD_voidWriteString((u8*)"Enta mn");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,0);
	LCD_voidWriteString((u8*)"Ana mn! ");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,0);
	LCD_voidWriteString((u8*)"enta el mn");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,11);
	LCD_voidWriteString((u8*)"ahhh      ");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,11);
	LCD_voidWriteString((u8*)"enta     ");
	LCD_voidGoToPosition(2,11);
	LCD_voidWriteString((u8*)"mat3rf4  ");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,11);
	LCD_voidWriteString((u8*)"     ");
	LCD_voidClearLine(2,19);
	LCD_voidDisplaySpecialChar(line,2,2,10);
	LCD_voidGoToPosition(1,0);
	LCD_voidWriteString((u8*)"la2 mn    ");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,11);
	LCD_voidWriteString((u8*)"na 7zl2om");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,0);
	LCD_voidWriteString((u8*)"7zl2om mn");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,11);
	LCD_voidWriteString((u8*)"7zl2ommm");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,0);
	LCD_voidWriteString((u8*)"aywa meen");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,11);
	LCD_voidWriteString((u8*)"ana el...");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,0);
	LCD_voidWriteString((u8*)"el eh!   ");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,11);
	LCD_voidWriteString((u8*)"el update");
	LCD_voidGoToPosition(2,11);
	LCD_voidWriteString((u8*)"bt3k fe  ");
	LCD_voidGoToPosition(3,11);
	LCD_voidWriteString((u8*)"NTI      ");
	_delay_ms(Delay_Time);
	LCD_voidGoToPosition(1,11);
	LCD_voidWriteString((u8*)"         ");
	LCD_voidClearLine(2,19);
	LCD_voidClearLine(3,19);
	LCD_voidDisplaySpecialChar(line,2,2,10);
	LCD_voidDisplaySpecialChar(line,2,3,10);
	LCD_voidGoToPosition(1,0);
	LCD_voidWriteString((u8*)"Howa da!!");
	LCD_voidGoToPosition(2,0);
	LCD_voidWriteString((u8*)"entaa...");
	_delay_ms(Delay_Time);
	LCD_voidClearLine(2,19);
	LCD_voidClearLine(3,19);
	LCD_voidDisplaySpecialChar(line,2,2,10);
	LCD_voidDisplaySpecialChar(line,2,3,10);

}
int main(void)
{
	PORT_voidInit();
	LCD_voidInit();

	LCD_voidGoToPosition(0,0);
	LCD_voidWriteString((u8*)"Mara 7mok4a kan ma4y");

	for(u8 x=7; x < 13; x++)
	{
		LCD_voidDisplaySpecialChar(P1,0,1,x);
		_delay_ms(150);
		LCD_voidClear(1,x);
	}

	LCD_voidClearLine(0,19);
	LCD_voidClearLine(1,19);
	MoveRight();
	Write();
	MoveLeft();
	LCD_voidSendCommand(LCD_ClearDisplay);
	LCD_voidGoToPosition(1,2);
	LCD_voidWriteString((u8*)"Short Sad Story.");
	LCD_voidGoToPosition(2,6);
	LCD_voidWriteString((u8*)"LOL :D");

	while(1)
	{

	}

	return 0;
}
