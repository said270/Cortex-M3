/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     AFIO */
/* Version: V01  */
/***********************************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct {
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
}AFIO_t;

#define  AFIO   ((volatile AFIO_t *) 0x40010000 )

#define PORTA    0b0000
#define PORTB    0b0001
#define PORTC    0b0010

#endif
