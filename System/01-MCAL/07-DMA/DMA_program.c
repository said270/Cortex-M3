/***********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     DMA */
/* Version: V01 */
/***********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"


void MDMA_voidChannelInit(void){
	/*
	 * 1- MEM2MEM
	 * 2- Very high priority
	 * 3- Source and destination size = 32bit
	 * 4- MINC , PINC activated
	 * 5- No circular
	 * 6- direction :
	 * 7- transfer interrupt enable
	 */
#if CHANNEL_ID == 1
DMA -> Channel[0].CCR =0b00000000000000000111101011010010;

#endif
}

void MDMA_voidChannelStart(u32 * Copy_pu32SourceAddress , u32 * Copy_pu32DestinationAddress ,u16 Copy_16BlockLength){
/* Make sure Channel is disabled */
CLR_BIT(DMA -> Channel[0].CCR , 0);
/* Write Address */
DMA -> Channel[0].CPAR = Copy_pu32SourceAddress ;
DMA -> Channel[0].CMAR = Copy_pu32DestinationAddress;
/* assign block length */
DMA -> Channel[0].CNDTR = Copy_16BlockLength;
/*Enable Channel */
SET_BIT(DMA -> Channel[0].CCR , 0);
}

