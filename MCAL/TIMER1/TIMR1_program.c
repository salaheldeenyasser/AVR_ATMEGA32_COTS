#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMR1_interface.h"
#include "TIMR1_private.h"

static void (*G_Ptr_ToFunc)(void) = NULL;
void TIMR1_voidNormalInit(void)
{
	/*Choosing the wave generation mode for fast pwm icr1 is the top value*/
	CLR_BIT(TCCR1A,WGM11); // TCCR1A REG
	CLR_BIT(TCCR1A,WGM10); // TCCR1A REG
	CLR_BIT(TCCR1B,WGM13); // TCCR1B REG
	CLR_BIT(TCCR1B,WGM12); // TCCR1B REG
	/*prescaller Choosing  = div by 8 */
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);
}
void TIMR1_voidSetTimerRegister(u16 Copy_u16Value)
{
	TCNT1L = Copy_u16Value;
}
u16 TIMR1_voidGetTimerRegister(void)
{
	return TCNT1L ;
}

void TIMR1_voidFastPWMInit(void)
{
	/*Timer 1 Mode = FastPWm Set on top Clear on compare*/
	SET_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1A0);

	/*Choosing the wave generation mode for fast pwm icr1 is the top value*/
	SET_BIT(TCCR1A,WGM11); // TCCR1A REG
	CLR_BIT(TCCR1A,WGM10); // TCCR1A REG
	SET_BIT(TCCR1B,WGM13); // TCCR1B REG
	SET_BIT(TCCR1B,WGM12); // TCCR1B REG
	/*prescaller Choosing  = div by 8 */
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);
}

void TIMR1_voidSetTopValue(u16 copy_u16_Value)
{
	ICR1L = copy_u16_Value ;


}

void TIMR1_voidSetCompareMatchValue(u16 copy_u16_Value)
{
	OCR1AL = copy_u16_Value ;

}

void TIMER1_voidICUInit(void)
{

	/*prescaller Choosing  = div by 8 */
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);
	/*enable icu interrupt*/
	SET_BIT(TIMSK1,TICIE1);
}
void TIMER1_voidICURisingEdge(void)
{
	SET_BIT(TCCR1B,ICES1);

}
void TIMER1_voidICUFallingEdge(void)
{

	CLR_BIT(TCCR1B,ICES1);
}
u8   TIMER1_u8ICUSetCallBack(void(*Ptr_ToFunc)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Ptr_ToFunc== NULL)
	{
		Local_u8ErrorState = NULL_POINTER;

	}
	else
	{
		G_Ptr_ToFunc = Ptr_ToFunc;
	}
	return Local_u8ErrorState ;


}
u16  TIMER1_u8ICUGetValue(void)
{

	return ICR1L ;
}
void __vector_6(void)
{

	if (G_Ptr_ToFunc == NULL)
	{
		/*Do Nothing*/
	}
	else
	{
		G_Ptr_ToFunc();


	}



}


