#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define GICR *((volatile u8*)0x5B)
#define GIFR *((volatile u8*)0x5A)
#define INT1  7
#define INT0  6
#define INT2  5

#define INTF1  7
#define INTF0  6
#define INTF2  5


#define MCUCR     *((volatile u8*)0x55)
#define MCUCSR    *((volatile u8*)0x54)
#define ISC2      6
#define ISC11     3 
#define ISC10     2 
#define ISC01     1 
#define ISC00     0 

void __vector_1(void)__attribute__((signal));//interrupt proto
/*choices for sense control*/
#define LOW_LEVEL    0
#define ON_CHANGE    1
#define FALLING_EDGE 2
#define RISING_EDGE  3

 

#endif
