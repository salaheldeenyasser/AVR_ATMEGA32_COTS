#ifndef _BIT_MATH_H
#define _BIT_MATH_H

// Bit manipulation macros for AVR microcontroller programming
#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)
#define ASSIGN_BIT(VAR,BITNO,VAL) (VAR) = ((VAR) & ~(1 << (BITNO))) | ((VAL) << (BITNO))

// NIBBLE Operations
#define SET_NIBBLE(VAR) (VAR) |= 0x0F
#define CLR_NIBBLE(VAR) (VAR) &= 0xF0
#define TOG_NIBBLE(VAR) (VAR) ^= 0x0F
#define GET_NIBBLE(VAR) ((VAR) & 0x0F)
#define ASSIGN_NIBBLE(VAR,VAL) (VAR) = ((VAR) & 0xF0) | ((VAL) & 0x0F)

// Byte Operations
#define SET_BYTE(VAR) (VAR) |= 0xFF
#define CLR_BYTE(VAR) (VAR) &= 0x00
#define TOG_BYTE(VAR) (VAR) ^= 0xFF
#define GET_BYTE(VAR) ((VAR) & 0xFF)
#define ASSIGN_BYTE(VAR,VAL) (VAR) = (VAL)

// Word Operations (for 16-bit registers)
#define SET_WORD(VAR) (VAR) |= 0xFFFF
#define CLR_WORD(VAR) (VAR) &= 0x0000
#define TOG_WORD(VAR) (VAR) ^= 0xFFFF
#define GET_WORD(VAR) ((VAR) & 0xFFFF)
#define ASSIGN_WORD(VAR,VAL) (VAR) = (VAL)

// Additional utility macros
#define BIT_MASK(BITNO) (1 << (BITNO))
#define NIBBLE_MASK(NIBBLENO) (0x0F << ((NIBBLENO) * 4))
#define BYTE_MASK(BYTENO) (0xFF << ((BYTENO) * 8))
#define WORD_MASK(WORDNO) (0xFFFF << ((WORDNO) * 16))

/* Example usage:
 To set bit 3 of PORTA: SET_BIT(PORTA, 3);
 To clear bit 2 of PORTB: CLR_BIT(PORTB, 2);
 To toggle bit 0 of PORTC: TOG_BIT(PORTC, 0);
 To get the value of bit 1 of PORTD: GET_BIT(PORTD, 1);
 To assign value 1 to bit 4 of PORTE: ASSIGN_BIT(PORTE, 4, 1);
 To set the lower nibble of PORTF: SET_NIBBLE(PORTF);
 To clear the upper nibble of PORTG: CLR_NIBBLE(PORTG);
 To toggle the entire byte of PORTH: TOG_BYTE(PORTH);
 To get the value of the entire byte of PORTJ: GET_BYTE(PORTJ);
 To assign value 0xAB to the entire byte of PORTK: ASSIGN_BYTE(PORTK, 0xAB);
 Note: These macros are designed for use with AVR microcontroller registers and may need to be adapted for other platforms or data types.
*/


#endif