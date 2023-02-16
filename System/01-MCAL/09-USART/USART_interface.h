/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     USART */
/* Version: V01  */
/***********************************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


void MUSART1_voidInit(void);
void MUSART1_voidTransmit(u8 * Copy_pu8Data);
u8 MUSART1_u8Recive(void);

#endif
