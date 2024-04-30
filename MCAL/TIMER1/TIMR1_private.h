/*
 * TMR1_registers.h
 *
 *  Created on: Sep 13, 2021
 *      Author: dell
 */

#ifndef TIMR1_PRIVATE_H_
#define TIMR1_PRIVATE_H_

/*Timer/Counter1 Control Register A – TCCR1A*/
#define TCCR1A         *((volatile u8*)0x4F)
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0
/*Timer/Counter1 Control Register B – TCCR1B*/

#define TCCR1B         *((volatile u8*)0x4E)
#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0
/*Timer/Counter1 – TCNT1H and TCNT1L*/
#define TCNT1L        *((volatile u16*)0x4C)
#define TCNT1H		  *((volatile u8*)0x4D)
/*Output Compare Register 1 A – OCR1AH and OCR1AL */
#define OCR1AL        *((volatile u16*)0x4A)
/*Output Compare Register 1 B  – OCR1BH and OCR1BL*/
#define OCR1BL        *((volatile u16*)0x48)
/*Input Capture Register 1 – ICR1H and ICR1L*/
#define ICR1L         *((volatile u16*)0x46)
/*Timer/Counter Interrupt Mask Register – TIMSK*/

#define TIMSK1		  *((volatile u8*)0x59)
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
void __vector_6(void)__attribute__((signal));



#endif /* TIMR1_PRIVATE_H_ */
