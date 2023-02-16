/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     USART */
/* Version: V01  */
/***********************************************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct {
volatile u32 SR ;
volatile u32 DR ;
volatile u32 BRR ;
volatile u32 CR1 ;
volatile u32 CR2 ;
volatile u32 CR3 ;
volatile u32 GRPR ;
}MUART_t;

#define  MUSART1    ((volatile MUART_t * )0x40013800)


#endif
