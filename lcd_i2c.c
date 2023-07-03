#include "lcd_i2c.h"

unsigned char RS, addr;

void LCD_Init(unsigned char address) {
	addr = address;
	LCD_I2C_Send(0);
    __delay_ms(40);
	LCD_Cmd(3);
    __delay_ms(5);
	LCD_Cmd(3);
    __delay_ms(5);
	LCD_Cmd(3);
    __delay_ms(5);
	LCD_Cmd(LCD_RETURN_HOME);
    __delay_ms(5);
	LCD_Cmd(0x20 | (LCD_TYPE << 2));
    __delay_ms(50);
	LCD_Cmd(LCD_TURN_ON);
    __delay_ms(50);
	LCD_Cmd(LCD_CLEAR);__delay_ms(50);
	LCD_Cmd(LCD_ENTRY_MODE_SET | LCD_RETURN_HOME);
    __delay_ms(50);
}

void LCD_I2C_Send(unsigned char value) {
	I2C_Start();
	I2C_Write(addr);
	I2C_Write(value | LCD_BACKLIGHT);
	I2C_Stop();
}

void LCD_Nibble(unsigned char nibble) {
	nibble |= RS;
	LCD_I2C_Send(nibble | 0x04);
	__delay_us(1);
	LCD_I2C_Send(nibble & 0xFB);
	__delay_us(100);
}

void LCD_Cmd(unsigned char cmd) {
	RS = 0;
	LCD_Nibble(cmd & 0xF0);
	LCD_Nibble((cmd << 4) & 0xF0);
	if((cmd == LCD_CLEAR) || (cmd == LCD_RETURN_HOME))
		__delay_ms(2);
}

void LCD_Chr(unsigned char row, unsigned char col, char data_) {
	LCD_Set_Cursor(row, col);
	LCD_Chr_Cp(data_);
}

void LCD_Chr_Cp(char data_) {
	RS = 1;
	LCD_Nibble(data_ & 0xF0);
	LCD_Nibble((data_ << 4) & 0xF0);
}

void LCD_Out(unsigned char row, unsigned char col, char* data_) {
	LCD_Set_Cursor(row, col);
	LCD_Out_Cp(data_);
}

void LCD_Out_Cp(char* data_) {
	unsigned char i;
	for(i = 0; data_[i] != '\0'; i++) LCD_Chr_Cp(data_[i]);
}

void LCD_Set_Cursor(unsigned char row, unsigned char col) {
	switch(row) {
		case 2: LCD_Cmd(LCD_SECOND_ROW + col - 1); break;
		case 3: LCD_Cmd(LCD_THIRD_ROW  + col - 1); break;
		case 4: LCD_Cmd(LCD_FOURTH_ROW + col - 1); break;
		default:LCD_Cmd(LCD_FIRST_ROW  + col - 1);
	}
}
