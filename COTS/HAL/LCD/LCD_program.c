#include "STD_TYPES.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include "DIO_interface.h"
#include <util/delay.h>


void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Reset to RS and RW*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,LOW);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);
	/*Sending the command*/
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);
	/*set e pin then wait for 1ms then reset it*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,LOW);


}
void LCD_voidSendChar(u8 Copy_u8Char)
{
	/*set  RS and reset RW*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,HIGH);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);
	/*Sending the char*/
	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Char);
	/*set e pin then wait for 1ms then reset it*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,LOW);



}
void LCD_voidInit(void)
{
	DIO_voidSetPortDirection(LCD_DATA_PORT,ALL_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RW_PIN,OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_E_PIN,OUTPUT);

	/*delay for 30 ms*/
	_delay_ms(40);
	/*Function Set*/
	LCD_voidSendCommand(LCD_FUNCTION_RESET);
	LCD_voidSendCommand(LCD_FUNCTION_8BIT);
	/*delay for 40 micro second*/
	_delay_us(40);
	/*init the display*/
	LCD_voidSendCommand(LCD_DISPLAY_ON);
	/*delay 40 micro*/
	_delay_us(40);
	/*LCD Clear*/
	LCD_voidSendCommand(LCD_CLEAR);
	_delay_ms(2);
}
void LCD_voidSendString(u8* Ptr_u8string)
{
	u8 LocalCounter = 0 ;
	while(Ptr_u8string[LocalCounter] != '\0')
	{
		LCD_voidSendChar(Ptr_u8string[LocalCounter]);
		LocalCounter++;
	}
}
void LCD_voidClearDisplay(void)
{

	LCD_voidSendCommand(LCD_CLEAR);
	LCD_voidSendCommand(LCD_HOME);


}
void LCD_voidGoTo(u8 COLS, u8 ROWS)
{
	u8 Local_u8Location = 0 ;
	switch(ROWS)
	{
	case 0 : Local_u8Location = COLS;break;
	case 1 : Local_u8Location = COLS + 0x40; break;
	}
	LCD_voidSendCommand(LCD_SET_CURSOR|Local_u8Location);



}
void LCD_voidDisplayNumber (u8 copy_u8Number) {
	s8 * localPtr_str[16] = {0};
	itoa(copy_u8Number, (char *)localPtr_str, 10);
	LCD_voidSendString((u8 *)localPtr_str);
}
