/*
 * TIMER0_interface.h
 *
 *  Created on: Aug 31, 2023
 *      Author: dell
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_
/*Normal Mode*/
void TIMER0_voidNormalModeInit(void);
u8   TIMER0_voidSetCallBack(void(*Ptr_ToFunc)(void));
void TIMER0_voidNormalModeSetPreLoadValue(u8 Copy_u8Value);
/*CTC MODE*/
void TIMER_voidCTCInit(void);
void TIMER0_voidCTCSetCompareMatchValue(u8 Copy_u8Value);
/*PWM MODE*/

void TIMER0_voidFastPwmInit(void);




#endif /* TIMER0_INTERFACE_H_ */
