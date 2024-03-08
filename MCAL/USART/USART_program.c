#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
//#include "USART_config.h"


void USART_voidInit(void)
{
	/*full duplex*/
	SET_BIT(UCSRB ,RXEN);
	SET_BIT(UCSRB ,TXEN);
	/*select the baudrate*/
	UBRRL=51;
	u8  Local_UCSRC = 0;
	/*setting for the ucsrc values*/
	/*to enable writing to the UCSRC*/
	SET_BIT(Local_UCSRC,URSEL);
	/*SELECTING THE MODE*/
	CLR_BIT(Local_UCSRC,UMSEL);
	/*SELECTING THE parity*/
	CLR_BIT(Local_UCSRC,UPM1);
	CLR_BIT(Local_UCSRC,UPM0);
	/*SELECTING # of stop bytes*/
	CLR_BIT(Local_UCSRC,USBS);
	/*SELECTING the ch size*/
	CLR_BIT(UCSRB,UCSZ2);
	SET_BIT(Local_UCSRC,UCSZ1);
	SET_BIT(Local_UCSRC,UCSZ0);
	/*SELECTING THE clock polarity*/
	SET_BIT(Local_UCSRC,UCPOL);
	
	UCSRC = Local_UCSRC ;
	
}

void USART_voidSendChar(u8 copy_u8Byte)
{
	/*checking the buffer*/
	while (GET_BIT(UCSRA ,UDRE)!= 1) ;
	UDR = copy_u8Byte ;
	
}


u8 USART_u8RecieveByte()
{
	/*checking THE COMPLETION OF RECEPTION*/
	while ((GET_BIT(UCSRA,RXC) != 1)) ;

		return UDR ;

}


void USART_voidSendByte(u8 *Ptr_u8ToString)
{
	u8 LocalCounter = 0;
	while(Ptr_u8ToString[LocalCounter] != '\0')
	{
		USART_voidSendChar(Ptr_u8ToString[LocalCounter]);
		LocalCounter++;
	}
}





