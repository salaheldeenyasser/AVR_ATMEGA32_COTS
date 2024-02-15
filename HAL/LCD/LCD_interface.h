#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_CLEAR            0x01          /* replace all characters with ASCII 'space'                       */
#define LCD_HOME             0x02          /* return cursor to first position on first line                   */
#define LCD_ENTRY_MODE       0x06          // shift cursor from left to right on read/write
#define LCD_DISPLAY_OFF      0x08          // turn display off
#define LCD_DISPLAY_ON       0x0C          // display on, cursor off, don't blink character
#define LCD_FUNCTION_RESET   0x30          // reset the LCD
#define LCD_FUNCTION_8BIT    0x38          // 8-bit data, 2-line display, 5 x 7 font
#define LCD_SET_CURSOR       0x80          // set cursor position

void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendChar(u8 Copy_u8Char);
void LCD_voidInit(void);
void LCD_voidSendString(u8* Ptr_u8string);
void LCD_voidClearDisplay(void);
void LCD_voidGoTo(u8 COLS, u8 ROWS);

void LCD_voidDisplayNumber (u8 copy_u8Number);


#endif
