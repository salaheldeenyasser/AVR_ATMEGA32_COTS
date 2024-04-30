#ifndef TIMR1_INTERFACE_H_
#define TIMR1_INTERFACE_H_

void TIMR1_voidFastPWMInit(void);
void TIMR1_voidNormalInit(void);
void TIMR1_voidSetTimerRegister(u16 Copy_u16Value);
u16 TIMR1_voidGetTimerRegister(void);

void TIMR1_voidSetCompareMatchValue(u16 copy_u16_Value);
void TIMR1_voidSetTopValue(u16 copy_u16_Value) ;



void TIMER1_voidICUInit(void);
void TIMER1_voidICURisingEdge(void);
void TIMER1_voidICUFallingEdge(void);
u8   TIMER1_u8ICUSetCallBack(void(*Ptr_ToFunc)(void));
u16   TIMER1_u8ICUGetValue(void);



#endif /* TMR0_INTERFACE_H_ */
