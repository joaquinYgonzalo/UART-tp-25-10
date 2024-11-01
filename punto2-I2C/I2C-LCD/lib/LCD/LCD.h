#ifndef "LCD_h"
#define "LCD_h"
void LCD_sendCmd(uint8_t command); 
void LCD_sendByte(uint8_t byte); 
void LCD_init(); 
void LCD_clear();
void LCD_scrollDisplayLeft();
void LCD_scrollDisplayRight();
void LCD_print(char* str);
void LCD_setCursor(int row, int col);
void LCD_createChar(uint8_t nByte, uint8_t[] nuevoCaracter)
#endif