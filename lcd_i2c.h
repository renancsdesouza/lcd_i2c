#ifndef LCD_I2C_H
#define	LCD_I2C_H

#include <xc.h>
#include "i2c.h"

#define LCD_BACKLIGHT			0x08
#define LCD_NOBACKLIGHT			0x00
#define LCD_FIRST_ROW			0x80
#define LCD_SECOND_ROW			0xC0
#define LCD_THIRD_ROW			0x94
#define LCD_FOURTH_ROW			0xD4
#define LCD_CLEAR				0x01
#define LCD_RETURN_HOME			0x02
#define LCD_ENTRY_MODE_SET		0x04
#define LCD_CURSOR_OFF			0x0C
#define LCD_UNDERLINE_ON		0x0E
#define LCD_BLINK_CURSOR_ON		0x0F
#define LCD_MOVE_CURSOR_LEFT	0x10
#define LCD_MOVE_CURSOR_RIGHT   0x14
#define LCD_TURN_ON				0x0C
#define LCD_TURN_OFF			0x08
#define LCD_SHIFT_LEFT			0x18
#define LCD_SHIFT_RIGHT			0x1E
#define LCD_TYPE				0x02

void LCD_Init(unsigned char address);
void LCD_I2C_Send(unsigned char value);
void LCD_Nibble(unsigned char nibble);
void LCD_Cmd(unsigned char cmd);
void LCD_Set_Cursor(unsigned char row, unsigned char col);
void LCD_Chr(unsigned char row, unsigned char col, char data_);
void LCD_Chr_Cp(char data_);
void LCD_Out(unsigned char row, unsigned char col, char* data_);
void LCD_Out_Cp(char* data_);
void Lcd_Backlight(void);
void Lcd_noBacklight(void);

#endif	//LCD_I2C_H
