/**********************************************************************************/
/* Author : Saied Kamara
/* SWC:     SYSTICK
/* Version: V01
/***********************************************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define SYSTICK_BASE_ADDRESS   0xE000E010

#define STK_CTRL  *((volatile u32*)(SYSTICK_BASE_ADDRESS + 0x00))
#define STK_LOAD  *((u32*)(SYSTICK_BASE_ADDRESS + 0x04))
#define STK_VAL   *((u32*)(SYSTICK_BASE_ADDRESS + 0x08))

#define AHB          0
#define AHB_DIV_8    1
#endif
