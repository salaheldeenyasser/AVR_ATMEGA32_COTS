/*
 * TIMER0_private.h
 *
 *  Created on: Aug 31, 2023
 *      Author: dell
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0  *((volatile u8*)0x53)
#define WGM00  6
#define COM01  5
#define COM00  4
#define WGM01  3
#define CS02   2
#define CS01   1
#define CS00   0
#define TCNT0  *((volatile u8*)0x52)
#define OCR0   *((volatile u8*)0x5C)


#define TIMSK  *((volatile u8*)0x59)
#define TOIE0  0
#define OCIE0  1
#define TIFR   *((volatile u8*)0x58)

void __vector_11(void)__attribute__((signal));
void __vector_10(void)__attribute__((signal));


#endif /* TIMER0_PRIVATE_H_ */
