/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     SPI */
/* Version: V01  */
/***********************************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIGE_H

/* Please Select PORT,PIN */
#define MSPI1_SLAVE_PIN     GPIOA,0


/*Options :
 * 1-WRITE_READ
 * 2-READ_WRITE
 */
#define MSPI1_CLK_PHASE      WRITE_READ

/*Options
 * 1-IDLE_0
 * 2-IDLE_1
 */
#define MSPI1_CLK_POLAIRT      IDLE_0

/*Options :
 * 1-SLAVE
 * 2-MASTER
 */
#define MSPI1_MSTR_SELECT          MASTER


/*Options
 * 1-DIV_2
 * 2-DIV_4
 * 3-DIV_8
 * 4-DIV_16
 */
#define MSPI1_BAUD_RATE    DIV_16

/*Options
 * 1-MSB_FIRST
 * 2-LSB_FIRST
 */
#define MSPI1_FRAME_FORMAT  MSB_FIRST



#endif
