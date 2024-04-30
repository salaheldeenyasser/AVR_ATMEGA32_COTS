#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"


void SPI_voidMasterInit(void)
{
	/*enable SPI*/
	SET_BIT(SPCR,SPE);
	/*enable master*/
	SET_BIT(SPCR,MSTR);
	/*set clock rate*/
	SET_BIT(SPCR,SPI2X);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPCR,SPR0);
}
void SPI_voidSlaveInit(void)
{
	/*enable SPI*/
	SET_BIT(SPCR,SPE);
	/*enable slave*/
	CLR_BIT(SPCR,MSTR);
}
u8 SPI_voidTranceive(u8 Copy_u8Byte)
{
	SPDR = Copy_u8Byte;
	while(GET_BIT(SPSR,SPIF) != 1)
	return SPDR;
}
