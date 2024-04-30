/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_reg.h"


void SPI_voidInit(void)
{
	/* 1- Data order
	 * 2- Master or slave mode
	 * 3- Clk polarity
	 * 4- Clk Phase
	 * 5- Enable SPI*/

	/* Interrupt Enable */
#if SPI_u8_INT_STATE == SPI_u8_INT_DISABLE
	CLR_BIT(SPCR,SPCR_SPIE);
#elif SPI_u8_INT_STATE == SPI_u8_INT_ENABLE
	SET_BIT(SPCR,SPCR_SPIE);
#endif

	/*if( SPI_u8_INT_STATE == SPI_u8_INT_ENABLE )
	{
		SET_BIT(SPCR,SPCR_SPIE);
	}*/

	/* Master mode or slave Mode */

#if SPI_u8_SELECTMODE == SPI_u8_MASTER
	SET_BIT(SPCR,SPCR_MSTR);
#if SPI_u8_CLK_RATE  == SPI_CLK_OVER_4
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPCR,SPCR_SPR0);
#elif SPI_u8_CLK_RATE  == SPI_CLK_OVER_16
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);
#elif SPI_u8_CLK_RATE  == SPI_CLK_OVER_64
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
#elif SPI_u8_CLK_RATE  == SPI_CLK_OVER_128
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);
#elif SPI_u8_CLK_RATE  == SPI_HCLK_OVER_2
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8_CLK_RATE  == SPI_HCLK_OVER_8
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8_CLK_RATE  == SPI_HCLK_OVER_32
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_u8_CLK_RATE  == SPI_HCLK_OVER_64
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPSR,SPSR_SPI2X);
#endif
#elif SPI_u8_SELECTMODE == SPI_u8_SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);
#endif

	/* Select Data order */
#if SPI_u8_DATA_ORDER == SPI_u8_MSB
	CLR_BIT(SPCR,SPCR_DORD);
#elif SPI_u8_DATA_ORDER == SPI_u8_LSB
	SET_BIT(SPCR,SPCR_DORD);

#endif

	/* Select the Clk Polarity */
#if SPI_u8_CLK_POL == SPI_u8_RAISING_EDGE
	CLR_BIT(SPCR,SPCR_CPOL);
#elif SPI_u8_CLK_POL == SPI_u8_FALLING_EDGE
	SET_BIT(SPCR,SPCR_CPOL);
#endif

	/* Select the Clk Phase */
#if SPI_u8_CLK_PHASE == SPI_u8_SAMPLE
	CLR_BIT(SPCR,SPCR_CPHA);
#elif SPI_u8_CLK_PHASE == SPI_u8_SETUP
	SET_BIT(SPCR,SPCR_CPHA);

#endif

	/* Enable SPI */
	SET_BIT(SPCR,SPCR_SPE);

}

u8 SPI_u8SendRecieveByte(u8 Copy_u8Data, u8 *Copy_pu8RecData)
{
	u8 Local_u8ReturnState = 1;
	/* Check the pointer */
	if(Copy_pu8RecData == NULL)
	{
		Local_u8ReturnState = 0;
	}
	else
	{
		/* Write Data Byte */
		SPDR = Copy_u8Data;
		/* wait until transmission is completed */
		while(GET_BIT(SPSR,SPSR_SPIF) == 0);
		/* Get the Data */
		*Copy_pu8RecData = SPDR;
	}

	return Local_u8ReturnState;
}
