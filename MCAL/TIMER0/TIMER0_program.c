#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"

void(*G_Ptr_ToFunc)(void) = NULL ;
void TIMER0_voidNormalModeInit(void)
{

	/*Select Normal Mode*/
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	/*Select Prescaler 8MHZ */
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	/*OV interrupt enable*/
	SET_BIT(TIMSK,TOIE0);

}
void TIMER0_voidFastPwmInit(void)
{
	/*Select Fast PWM Mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*Select Prescaler 8MHZ */
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	/*Clear on cmp set on top*/
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);




}
u8   TIMER0_voidSetCallBack(void(*Ptr_ToFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if (Ptr_ToFunc == NULL)
	{

		Local_u8ErrorState = NULL_POINTER ;

	}
	else
	{
		G_Ptr_ToFunc = Ptr_ToFunc ;
	}
}
void TIMER0_voidNormalModeSetPreLoadValue(u8 Copy_u8Value)
{

	TCNT0 = Copy_u8Value ;

}
void TIMER_voidCTCInit(void)
{

	/*Select CTC Mode*/
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*Select Prescaler 8MHZ */
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	/*OC interrupt enable*/
	SET_BIT(TIMSK,OCIE0);
}

void TIMER0_voidCTCSetCompareMatchValue(u8 Copy_u8Value)
{
	OCR0 =  Copy_u8Value ;
}
void __vector_11(void)
{
	if(G_Ptr_ToFunc == NULL)
	{
		/*do nothing*/
	}
	else
	{
		G_Ptr_ToFunc();
	}


}
void __vector_10(void)
{
	if(G_Ptr_ToFunc == NULL)
	{
		/*do nothing*/
	}
	else
	{
		G_Ptr_ToFunc();
	}


}

