#ifndef USART_private_H_
#define USART_private_H_


/*USART I/O Data Register � UDR*/
#define UDR            *((volatile u8*)0x2C)
/*USART Control and Status Register A � UCSRA*/
#define UCSRA          *((volatile u8*)0x2B)
#define RXC      7
#define TXC      6
#define UDRE     5
#define FE       4
#define DOR      3
#define PE       2
#define U2X      1
#define MPCM     0
/*USART Control and Status Register B � UCSRB*/
#define UCSRB          *((volatile u8*)0x2A)
#define RXCIE    7
#define TXCIE    6
#define UDRIE    5
#define RXEN     4
#define TXEN     3
#define UCSZ2    2
#define RXB8     1
#define TXB8     0
/**USART Control and Status  Register C � UCSRC*/
#define UCSRC          *((volatile u8*)0x40)
#define URSEL    7
#define UMSEL    6
#define UPM1     5
#define UPM0     4
#define USBS     3
#define UCSZ1    2
#define UCSZ0    1
#define UCPOL    0
/*USART Baud Rate Registers � UBRRL and UBRRH*/
#define UBRRH          *((volatile u8*)0x40)
#define UBRRL          *((volatile u8*)0x29)

#endif
