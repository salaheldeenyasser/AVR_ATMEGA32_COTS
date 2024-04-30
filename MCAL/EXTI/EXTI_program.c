#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*G_Ptr_ToFunc)(void)=NULL;

void EXTI0_voidSelectRisingEdge(void)
{
	SET_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
}
void EXTI0_voidSelectFallingEdge(void)
{
	SET_BIT(MCUCR,ISC01);
	CLR_BIT(MCUCR,ISC00);
}
void EXTI0_voidInit(void)
{
#if INT0_SENSE_CONTROL == FALLING_EDGE

	SET_BIT(MCUCR,ISC01);
	CLR_BIT(MCUCR,ISC00);
#elif INT0_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
#elif INT0_SENSE_CONTROL == ON_CHANGE
	CLR_BIT(MCUCR,ISC01);
	SET_BIT(MCUCR,ISC00);
#elif INT0_SENSE_CONTROL == LOW_LEVEL
	CLR_BIT(MCUCR,ISC01);
	CLR_BIT(MCUCR,ISC00);
#endif
}

void EXTI0_voidEnable(void)
{
	SET_BIT(GICR,INT0);
}
void EXTI0_voidDisable(void)
{
	CLR_BIT(GICR,INT0);

}
u8 EXTI0_voidSetCallBack(void(*Ptr_ToFunc)(void))
{
	u8 Local_u8ErrorState = OK ;
	if(Ptr_ToFunc == NULL)
	{

		Local_u8ErrorState = NULL_POINTER;
	}
	else
	{
		G_Ptr_ToFunc=Ptr_ToFunc;
	}
	return Local_u8ErrorState ;
}

void __vector_1(void)
{
	if(G_Ptr_ToFunc == NULL)
	{
		/*Do Nothing*/
	}
	else
	{
		G_Ptr_ToFunc();
	}
}
