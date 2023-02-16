/**********************************************************************************/
/* Author : Saied Kamara
/* SWC:     RCC
/* Version: V01
/***********************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register Defenition */

#define RCC_CR            *((u32*)0x40021000)
#define RCC_CFGR          *((u32*)0x40021004)
#define RCC_CIR           *((u32*)0x40021008)
#define RCC_ABP2RSTR      *((u32*)0x4002100C)
#define RCC_ABP1RSTR      *((u32*)0x40021010)
#define RCC_AHBENR        *((u32*)0x40021014)
#define RCC_ABP2ENR       *((u32*)0x40021018)
#define RCC_ABP1ENR       *((u32*)0x4002101C)
#define RCC_BDCR          *((u32*)0x40021020)
#define RCC_CSR           *((u32*)0x40021024)

/* Clock Types */
#define RCC_HSE_CRYSTAL         0
#define RCC_HSR_RC              1
#define RCC_HSI                 2
#define RCC_PLL                 3

/*PLL options */
#define RCC_PLL_IN_HSI_DIV_2    0
#define RCC_PLL_IN_HSE_DIV_2    1
#define RCC_PLL_IN_HSE          2

#endif