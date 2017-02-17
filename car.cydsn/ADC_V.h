/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef _ADC_V_H
#define	_ADC_V_H

#include <project.h>
    
#define SampleNum  10
#define B_CHANANL             0  
#define CAR_X_CHANANL         1
#define CAR_Y_CHANANL         2
#define PTZ_X_CHANANL         3
#define PTZ_Y_CHANANL         4   
#define LED_1_CHANANL         5
#define LED_2_CHANANL         6
#define LED_3_CHANANL         7
#define CAR_SPEED_CHANANL     8
uint16 B_V;
uint16 CAR_X_V;
uint16 CAR_Y_V;
uint16 PTZ_X_V;
uint16 PTZ_Y_V;
uint16 PTZ_Y_V;   
uint16 LED_1_V;
uint16 LED_2_V;
uint16 LED_3_V;
uint16 CAR_SPEED_V;
uint16 Get_Battery_ADvalue(uint8 channal);
 void Monitor_Battery_Init();
extern void Cal_Battery_loop();
#endif
/* [] END OF FILE */
