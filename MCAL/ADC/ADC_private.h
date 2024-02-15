#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

//define for adc registers
#define ADMUX *((volatile u8*)0x27)
#define ADCSRA *((volatile u8*)0x26)
#define ADCH *((volatile u8*)0x25)
#define ADCL  *((volatile u8*)0x24)
#define ADC_DATA  *((volatile u16*)0x24)
#define SFIOR  *((volatile u16*)0x50)


#endif