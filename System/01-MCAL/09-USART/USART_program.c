/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     USART */
/* Version: V01  */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"

void MUSART1_voidInit(void){
/* Baud Rate : 9600 BRR=0x341  */
MUSART1 -> BRR = 0x341;
/* Baud Rate : 115200 BRR=  */
//

/* Enable RX
 * Enable TX
 * Enable USART
 */
SET_BIT(MUSART1 -> CR1 ,2);
SET_BIT(MUSART1 -> CR1 ,3);
SET_BIT(MUSART1 -> CR1 ,13);
/* Clear SR */
MUSART1 -> SR = 0;
}
void MUSART1_voidTransmit(u8 * Copy_pu8Data){
	u8 Local_u8Counter = 0;
	while(Copy_pu8Data[Local_u8Counter] != '\0')
		{
		MUSART1 -> DR = Copy_pu8Data[Local_u8Counter];
			while(GET_BIT(MUSART1 -> SR, 6) == 0);
			Local_u8Counter++;

		}

}
u8 MUSART1_u8Recive(void){
 /* wait till receive complete */
	while (GET_BIT(MUSART1 -> SR , 5 ) == 0 );

	/* read only 8 bits */
	return (0xFF &(MUSART1 -> DR)) ;
}
