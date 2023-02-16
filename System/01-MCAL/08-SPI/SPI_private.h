/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     SPI */
/* Version: V01  */
/***********************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct {
	volatile u32 CR1 ;
	volatile u32 CR2 ;
	volatile u32 SR  ;
	volatile u32 DR  ;
	volatile u32 CRCPR ;
	volatile u32 RXCRC ;
	volatile u32 TXCRC ;
	volatile u32 I2SCFGR ;
	volatile u32 I2SPR ;
}SPI_REGISTER;

#define SPI1  ((volatile SPI_REGISTER *)0x40013000)


#define WRITE_READ      1
#define READ_WRITE      0

#define IDLE_0          0
#define IDLE_1          1

#define MASTER          1
#define SLAVE           0

#define DIV_2          0
#define DIV_4          1
#define DIV_8          2
#define DIV_16         3

#define MSB_FIRST      1
#define LSB_FIRST      0

#endif
