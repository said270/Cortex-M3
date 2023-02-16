/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     NVIC */
/* Version: V01  */
/***********************************************************************************/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

#define GROUP_XXXX      0x05FA0300  // 4 bits for group and none for sub
#define GROUP_XXXY      0x05FA0400  // 3 bits for group and 1 for sub
#define GROUP_XXYY      0x05FA0500  // 2 bits for group and 2 for sub
#define GROUP_XYYY      0x05FA0600  // 1 bits for group and 3 for sub
#define GROUP_YYYY      0x05FA0700  // none bits for group and 4 for sub

#define NVIC_GroupingSystem   GROUP_XXYY

#endif
