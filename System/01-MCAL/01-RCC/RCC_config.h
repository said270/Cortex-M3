/**********************************************************************************/
/* Author : Saied Kamara
/* SWC:     RCC
/* Version: V01
/***********************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*options :  RCC_HSE_CRYSTAL
             RCC_HSR_RC
			 RCC_HSI
			 RCC_PLL
			 */
#define RCC_CLOCK_TYPE     RCC_HSI

/*options : RCC_PLL_IN_HSI_DIV_2
            RCC_PLL_IN_HSE_DIV_2
			RCC_PLL_IN_HSE         */
/*Note: Selected only if PLL as input source */
#if RCC_CLOCK_TYPE == RCC_PLL
    #define RCC_PLL_INPUT      RCC_PLL_IN_HSE
#endif

/*Note: Selected only if PLL as input source */
/*Options : 2 to 16 */
#if RCC_CLOCK_TYPE == RCC_PLL
#define   RCC_PLL_MUL_VAL      2
#endif


#endif