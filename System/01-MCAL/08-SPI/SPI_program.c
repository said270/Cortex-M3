/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     SPI */
/* Version: V01  */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"

#include "GPIO_interface.h"

void (*CallBackFunction)(u8 Data)=NULL;
void MSPI1_voidInit(void){
/* Masking Control Register */
	SPI1->CR1 &= 0xffff0000;
	SPI1->CR1 |= 0x00000311;
#if MSPI1_CLK_PHASE  == WRITE_READ
 SET_BIT(SPI1->CR1,0);
#elif MSPI1_CLK_PHASE  == READ_WRITE
 CLR_BIT(SPI1->CR1,0);
#endif

#if MSPI1_CLK_POLAIRT    ==  IDLE_0
 CLR_BIT(SPI1->CR1,1);
#elif MSPI1_CLK_POLAIRT    ==  IDLE_1
 SET_BIT(SPI1->CR1,1);
#endif

#if MSPI1_MSTR_SELECT     ==     MASTER
 SET_BIT(SPI1->CR1,2);
#elif MSPI1_MSTR_SELECT      ==    SLAVE
 CLR_BIT(SPI1->CR1,2);
#endif

#if MSPI1_FRAME_FORMAT == MSB_FIRST
CLR_BIT(SPI1->CR1,7);
#elif MSPI1_FRAME_FORMAT == LSB_FIRST
SET_BIT(SPI1->CR1,7);
#endif

#if MSPI1_BAUD_RATE  ==  DIV_2
CLR_BIT(SPI1->CR1,3);
CLR_BIT(SPI1->CR1,4);
CLR_BIT(SPI1->CR1,5);

#elif MSPI1_BAUD_RATE  ==  DIV_4
SET_BIT(SPI1->CR1,3);
CLR_BIT(SPI1->CR1,4);
CLR_BIT(SPI1->CR1,5);

#elif MSPI1_BAUD_RATE  ==  DIV_8
CLR_BIT(SPI1->CR1,3);
SET_BIT(SPI1->CR1,4);
CLR_BIT(SPI1->CR1,5);

#elif MSPI1_BAUD_RATE  ==  DIV_16
SET_BIT(SPI1->CR1,3);
SET_BIT(SPI1->CR1,4);
CLR_BIT(SPI1->CR1,5);
#endif

/*Enable SPI */
SET_BIT(SPI1->CR1,6);
}
void MSPI1_voidInitTFT(void){
	/* CPOL = 1 CPHA=1 PRESC=Clk/2  MSB First SPI Enable */
	SPI1->CR1 = 0x0347;
}
void MSPI1_voidSendReciveSynchronus(u8 Copy_u8DataToTransmit , u8 * Copy_pu8DataToRecive){
 /* Clear For Slave Select Pin */
	GPIO_voidSetPinValue(MSPI1_SLAVE_PIN,PIN_LOW);
/* Send Data */
 SPI1 -> DR = Copy_u8DataToTransmit;
while (GET_BIT(SPI1 -> SR,7) == 1) ; /* wait for Busy flag */
/* Receive Data */
*Copy_pu8DataToRecive = SPI1->DR ;
/* Clear For Slave Select Pin */
	GPIO_voidSetPinValue(MSPI1_SLAVE_PIN,PIN_HIGH);
}
void MSPI1_voidSendReciveAsynchronus(u8 Copy_u8DataToTransmit , void (*CallBackFunc)(u8 Copy_u8DataToRecivie)){
CallBackFunction = CallBackFunc;
/* Clear For Slave Select Pin */
	GPIO_voidSetPinValue(MSPI1_SLAVE_PIN,PIN_LOW);
/* Send Data */
 SPI1 -> DR = Copy_u8DataToTransmit;
}

void SPI1_IRQHandler(void){
CallBackFunction(SPI1 -> DR);
}
