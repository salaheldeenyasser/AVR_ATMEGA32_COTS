/*
 * SPI_config.h
 *
 *  Created on: Apr 20, 2020
 *      Author: KAPOO
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* Config For SPI MODE
 *
 * Select option from : SPI_u8_MASTER
						SPI_u8_SLAVE */

#define SPI_u8_SELECTMODE   SPI_u8_MASTER

/* Config for Interrupt enable or disable */
/* Select option from : SPI_u8_INT_ENABLE
						SPI_u8_INT_DISABLE */

#define SPI_u8_INT_STATE   SPI_u8_INT_DISABLE

/* Config for The Data order */
/* Select option from : SPI_u8_MSB
                        SPI_u8_LSB */

#define SPI_u8_DATA_ORDER  SPI_u8_MSB


/* Config For The Clk Polarity  */
/* Options : SPI_u8_RAISING_EDGE
             SPI_u8_FALLING_EDGE */

#define SPI_u8_CLK_POL     SPI_u8_RAISING_EDGE

/* Config for The CLK Phase */
/* Options : SPI_u8_SAMPLE
			 SPI_u8_SETUP   */

#define SPI_u8_CLK_PHASE   SPI_u8_SETUP

/* Config Master Clk */
/* Options : SPI_CLK_OVER_4
             SPI_CLK_OVER_16
             SPI_CLK_OVER_64
             SPI_CLK_OVER_128
             SPI_HCLK_OVER_2
             SPI_HCLK_OVER_8
             SPI_HCLK_OVER_32
             SPI_HCLK_OVER_64 */

#define SPI_u8_CLK_RATE    SPI_CLK_OVER_16

/* Config for The Timeout */

#define SPI_u16_TIMEOUT   50000

#endif /* SPI_CONFIG_H_ */
