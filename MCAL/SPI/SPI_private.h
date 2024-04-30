/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


/* SPCR Bits */
#define SPCR_SPIE                   7
#define SPCR_SPE                    6
#define SPCR_DORD                   5
#define SPCR_MSTR                   4
#define SPCR_CPOL                   3
#define SPCR_CPHA                   2
#define SPCR_SPR1                   1
#define SPCR_SPR0                   0


/* SPSR BITS */
#define SPSR_SPIF                   7
#define SPSR_WCOL                   6
#define SPSR_SPI2X                  0


/* Macros for Config */

/* Master or slave Mode */

#define SPI_u8_MASTER               0
#define SPI_u8_SLAVE                1

/* Macros For Interrupt Enable */

#define SPI_u8_INT_ENABLE           0
#define SPI_u8_INT_DISABLE          1

/* Config Macros For THe data order */
#define SPI_u8_MSB                  0
#define SPI_u8_LSB                  1

/* Config Macros for CLK Polarity */
#define SPI_u8_RAISING_EDGE         0
#define SPI_u8_FALLING_EDGE         1

/* Config Macros for CLK PHASE */
#define SPI_u8_SAMPLE               0
#define SPI_u8_SETUP                1


/* Config Macros for CLK in Master Mode */
#define SPI_CLK_OVER_4              0
#define SPI_CLK_OVER_16             1
#define SPI_CLK_OVER_64             2
#define SPI_CLK_OVER_128            3
#define SPI_HCLK_OVER_2             4
#define SPI_HCLK_OVER_8             5
#define SPI_HCLK_OVER_32            6
#define SPI_HCLK_OVER_64            7





#endif /* SPI_PRIVATE_H_ */
