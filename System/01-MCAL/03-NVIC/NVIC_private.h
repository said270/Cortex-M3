/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     NVIC */
/* Version: V01  */
/***********************************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* 0xE000E100 Base */
#define NVIC_ISER0     *((u32*)0xE000E100)   //enable external from 0 to 31
#define NVIC_ISER1     *((u32*)0xE000E104)   //enable external from 32 to 63


#define NVIC_ICER0     *((u32*)0xE000E180)   //disable external from 0 to 31
#define NVIC_ICER1     *((u32*)0xE000E184)   //disable external from 32 to 63

#define NVIC_ISPR0     *((u32*)0xE000E200)   //Set pending flag external from 0 to 31
#define NVIC_ISPR1     *((u32*)0xE000E204)   //Set pending flag external from 32 to 63

#define NVIC_ICPR0     *((u32*)0xE000E280)   //Clear pending flag external from 0 to 31
#define NVIC_ICPR1     *((u32*)0xE000E284)   //Clear pending flag external from 32 to 63

#define NVIC_IABR0     *((volatile u32*)0xE000E300)   //read Active flag
#define NVIC_IABR1     *((volatile u32*)0xE000E304)   //read Active flag

#define NVIC_IPR       ((volatile u8*)0xE000E400)    //software priority

#endif
