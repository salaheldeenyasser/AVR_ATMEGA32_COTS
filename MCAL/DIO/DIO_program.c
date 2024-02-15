#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRA_REG,Copy_u8Pin);
		}
		else
		{
			CLR_BIT(DDRA_REG,Copy_u8Pin);
		}
		break;
	case PORTB:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRB_REG,Copy_u8Pin);
		}
		else
		{
			CLR_BIT(DDRB_REG,Copy_u8Pin);
		}
		break;
	case PORTC:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRC_REG,Copy_u8Pin);
		}
		else
		{
			CLR_BIT(DDRC_REG,Copy_u8Pin);
		}
		break;
	case PORTD:
		if(Copy_u8Direction == OUTPUT)
		{
			SET_BIT(DDRD_REG,Copy_u8Pin);
		}
		else
		{
			CLR_BIT(DDRD_REG,Copy_u8Pin);
		}
		break;


	}




}
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	case PORTA :
		if (Copy_u8Value == HIGH)
		{
			SET_BIT(PORTA_REG,Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTA_REG,Copy_u8Pin);
		}
		break;

	case PORTB :
		if (Copy_u8Value == HIGH)
		{
			SET_BIT(PORTB_REG,Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTB_REG,Copy_u8Pin);
		}
		break;
	case PORTC :
		if (Copy_u8Value == HIGH)
		{
			SET_BIT(PORTC_REG,Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTC_REG,Copy_u8Pin);
		}
		break;
	case PORTD :
		if (Copy_u8Value == HIGH)
		{
			SET_BIT(PORTD_REG,Copy_u8Pin);
		}
		else
		{
			CLR_BIT(PORTD_REG,Copy_u8Pin);
		}
		break;


	}
}
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8PinValue = LOW ;
	switch(Copy_u8Port)
	{
	case PORTA :
		Local_u8PinValue = GET_BIT(PINA_REG,Copy_u8Pin);
		break;
	case PORTB :
		Local_u8PinValue = GET_BIT(PINB_REG,Copy_u8Pin);
		break;
	case PORTC :
		Local_u8PinValue = GET_BIT(PINC_REG,Copy_u8Pin);
		break;
	case PORTD :
		Local_u8PinValue = GET_BIT(PIND_REG,Copy_u8Pin);
		break;

	}
	return Local_u8PinValue ;

}

void DIO_voidTogglePinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
	case PORTA : TOG_BIT(PORTA_REG,Copy_u8Pin); break;
	case PORTB : TOG_BIT(PORTB_REG,Copy_u8Pin); break;
	case PORTC : TOG_BIT(PORTC_REG,Copy_u8Pin); break;
	case PORTD : TOG_BIT(PORTD_REG,Copy_u8Pin); break;
	}
}

void DIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction)
{
	switch(Copy_u8Port)
	{
	case PORTA :
		DDRA_REG = Copy_u8Direction;
		break;
	case PORTB :
		DDRB_REG = Copy_u8Direction;
		break;
	case PORTC :
		DDRC_REG = Copy_u8Direction;
		break;
	case PORTD :
		DDRD_REG = Copy_u8Direction;
		break;
	}
}
void DIO_voidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
	case PORTA :
		PORTA_REG = Copy_u8Value;
		break;
	case PORTB :
		PORTB_REG = Copy_u8Value;
		break;
	case PORTC :
		PORTC_REG = Copy_u8Value;
		break;
	case PORTD :
		PORTD_REG = Copy_u8Value;
		break;
	}
}
u8   DIO_u8GetPortValue(u8 Copy_u8Port )
{
	u8 Local_u8PortValue = LOW ;
	switch (Copy_u8Port)
	{
	case PORTA :
		Local_u8PortValue = PINA_REG ; break;
	case PORTB :
		Local_u8PortValue = PINB_REG ; break;
	case PORTC :
		Local_u8PortValue = PINC_REG ; break;
	case PORTD :
		Local_u8PortValue = PIND_REG ; break;
	}

return Local_u8PortValue ;
}
