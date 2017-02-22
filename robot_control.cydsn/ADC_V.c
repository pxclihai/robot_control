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
#include "ADC_V.h"

#include "control.h"


int16 retADCValue[SampleNum] = {0};


void Monitor_Battery_Init()
{
    ADC_Start();
    ADC_StartConvert();
    
}
//int16 Get_C_Battery_ADvalue(void)
//{
//
//    uint8 i = 0;
//    int16 retval = 0;
//    int32 sum = 0;
//    for(i = 0;i < SampleNum;i++)
//    {
//        retADCValue2[i] = C_Battery_GetResult16();
//    
//    }
//
//    for(i = 0;i < SampleNum;i++)
//    {
//        sum += retADCValue2[i];
//    }
//    retval = sum/SampleNum;
//    return retval;
//    
//}
uint16 Get_Battery_ADvalue(uint8 channal)
{

    uint8 i = 0;
    int16 retval = 0;
    int32 sum = 0;
    for(i = 0;i < SampleNum;i++)
    {
        retADCValue[i] = ADC_GetResult16(channal);
    }

    for(i = 0;i < SampleNum;i++)
    {
        sum += retADCValue[i];
    }
    retval = sum/SampleNum;
    return retval;
    
}

void Cal_Battery_loop()
{
    g_Control.Battery = Get_Battery_ADvalue(B_CHANANL);
    CAR_X_V = Get_Battery_ADvalue(CAR_X_CHANANL);
    CAR_Y_V = Get_Battery_ADvalue(CAR_Y_CHANANL);   
    PTZ_X_V = Get_Battery_ADvalue(PTZ_X_CHANANL);  
    PTZ_Y_V = Get_Battery_ADvalue(PTZ_Y_CHANANL); 
    LED_1_V = Get_Battery_ADvalue(LED_1_CHANANL); 
    LED_2_V = Get_Battery_ADvalue(LED_2_CHANANL); 
    LED_3_V = Get_Battery_ADvalue(LED_3_CHANANL); 
    CAR_SPEED_V = Get_Battery_ADvalue(CAR_SPEED_CHANANL); 

}
/* [] END OF FILE */
