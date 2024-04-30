#ifndef EXTI_INTEFACE_H_
#define EXTI_INTEFACE_H_

void EXTI0_voidInit(void);
void EXTI0_voidSelectRisingEdge(void);
void EXTI0_voidSelectFallingEdge(void);

void EXTI0_voidEnable(void);
void EXTI0_voidDisable(void);
u8 EXTI0_voidSetCallBack(void(*Ptr_ToFunc)(void));







#endif
