#ifndef USART_interface_H_
#define USART_interface_H_
void USART_voidInit(void);
void USART_voidSendChar(u8 copy_u8Byte);
u8   USART_u8RecieveByte();
void USART_voidSendByte(u8 *Ptr_u8ToString);

#endif
