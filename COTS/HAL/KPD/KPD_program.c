#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"


void KPD_voidInit(void)
{
	/*4 Pins for cols and set them as Input Pull Up*/
	DIO_voidSetPinDirection(KPD_PORT,KPD_COL1,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_COL2,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_COL3,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_COL4,INPUT);
	/*4 Pins for cols and set them as Output High*/
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW1,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW2,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW3,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW4,OUTPUT);
	/*4 as pull 4 as high means that all the port is high*/
	DIO_voidSetPortValue(KPD_PORT,ALL_HIGH);
}
u8   KPD_u8GetPressedKey(void)
{

	u8 Local_u8PressedKey = KPD_NO_KEY_PRESSED ;
	u8 Local_u8RowIdx,Local_u8ColIdx ;
	u8 KPD_KEYS[ROW_NUM][COL_NUM] = KPD_ARR;
	for(Local_u8RowIdx = NULL;Local_u8RowIdx<ROW_NUM;Local_u8RowIdx++)
	{
		DIO_voidSetPinValue(KPD_PORT,Local_u8RowIdx,LOW);
		for(Local_u8ColIdx = NULL;Local_u8ColIdx<COL_NUM;Local_u8ColIdx++)
		{
			if(DIO_u8GetPinValue(KPD_PORT,Local_u8ColIdx+ROW_NUM) == LOW)
			{

				Local_u8PressedKey = KPD_KEYS[Local_u8RowIdx][Local_u8ColIdx];
				while(DIO_u8GetPinValue(KPD_PORT,Local_u8ColIdx+ROW_NUM)== LOW);
				return Local_u8PressedKey;
			}
		}
		DIO_voidSetPinValue(KPD_PORT,Local_u8RowIdx,HIGH);

	}



	return Local_u8PressedKey ;

}

