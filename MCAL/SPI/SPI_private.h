#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*$0F ($2F) SPDR SPI Data Register 136
$0E ($2E) SPSR SPIF WCOL – – – – – SPI2X 136
$0D ($2D) SPCR SPIE SPE DORD MSTR CPOL CPHA SPR1 SPR0
*/

#define SPCR   *((volatile u8*)0x2D)
#define SPIE   7
#define SPE    6
#define DORD   5
#define MSTR   4
#define CPOL   3
#define CPHA   2
#define SPR1   1
#define SPR0   0

#define SPSR   *((volatile u8*)0x2E)
#define SPIF   7
#define WCOL   6
#define SPI2X  0

#define SPDR   *((volatile u8*)0x2F)
#define MSB    7
#define LSB    0

#endif
