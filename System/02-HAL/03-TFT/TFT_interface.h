/**********************************************************************************/
/* Author : Saied Kamara */
/* SWC:     TFT */
/* Version: V01  */
/***********************************************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16 * Copy_pu16Image); // const to force storage in flash
                                                        //u16 as we use 2 bytes for each pixel
void HTFT_voidFillColour(u16 Copy_u16Colour);
void HTFT_voidDrawRect(u8 Copy_u8x1 , u8 Copy_u8x2 , u8 Copy_u8y1 , u8 Copy_u8y2 ,u16 Copy_u16Colour);
void HTFT_voidWriteChar(u8 Copy_u8x , u8 Copy_u8y ,u8 Copy_u8Char,u16 Copy_u16Colour);
void HTFT_voidWriteString(u8 Copy_u8x , u8 Copy_u8y ,u8 *Copy_u8String,u16 Copy_u16Colour);
void HTFT_voidWriteNumber(u8 Copy_u8x , u8 Copy_u8y ,u16 Copy_u16Number,u16 Copy_u16Colour);

#endif
