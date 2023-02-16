/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     SPI */
/* Version: V01  */
/***********************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(void);
void MSPI1_voidSendReciveSynchronus(u8 Copy_u8DataToTransmit , u8 * Copy_pu8DataToRecive);
void MSPI1_voidSendReciveAsynchronus(u8 Copy_u8DataToTransmit , void (*CallBackFunc)(u8 Copy_u8DataToRecivie));
void MSPI1_voidInitTFT(void);

#endif
