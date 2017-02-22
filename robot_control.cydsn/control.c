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
#include "control.h"
#include "ADC_V.h"
#include "Transfer.h"
#include "key.h"
void Cal_car_dir()
{
    static uint8 send_dir = STOP;
    static uint8 pre_dir  = 0;
    if(CAR_X_V < 500 || CAR_Y_V <500)
    {
        if(CAR_X_V < 500 && CAR_Y_V <500)
        {
            send_dir = DOWN_LEFT;
          //DT_Send_Status(DOWN_LEFT);
          debug("CAR_DOWN_LEFT");
        }
        else if(CAR_X_V < 500)
        {
          send_dir = LEFT;
          // DT_Send_Status(LEFT);
          debug("CAR_LEFT");
        }
        else if (CAR_Y_V <500)
        {
            send_dir = RIGHT;
         // DT_Send_Status(RIGHT);
          debug("CAR_DOWN");
        }
    }
    else if(CAR_X_V < 500 || CAR_Y_V >3500)
    {
        if(CAR_X_V < 500 && CAR_Y_V >3500)
        {
            send_dir = UP_LEFT;
       //   DT_Send_Status(UP_LEFT);
          debug("CAR_UP_LEFT");
        }
        else if(CAR_Y_V >3500)
        {
            send_dir = UP;
        //  DT_Send_Status(UP);
          debug("CAR_UP");
        }
    }
    else if(CAR_X_V > 3500 || CAR_Y_V >3500)
    {
        if(CAR_X_V > 3500 && CAR_Y_V >3500)
        {
            send_dir = UP_RIGHT;
         // DT_Send_Status(UP_RIGHT);
          debug("CAR_UP_RIGHT");
        }
        else if(CAR_X_V > 3500)
        {
            send_dir = RIGHT;
        //  DT_Send_Status(RIGHT);
          debug("CAR_RIGHT");
        }
    }
    else if(CAR_X_V > 3500 && CAR_Y_V < 500)
    {
        send_dir = DOWN_RIGHT;
        // DT_Send_Status(DOWN_RIGHT);
         debug("CAR_DOWN_RIGHT");
    }
    else
    {
        send_dir = STOP;
       //  DT_Send_Status(STOP);
    }
    if(pre_dir != send_dir)
    {
       DT_Send_Status(send_dir);
       pre_dir = send_dir;
    }
   
}

void Cal_ptz_dir()
{
     static uint8 send_dir = STOP;
    static uint8 pre_dir  = 0;
    if(PTZ_X_V < 500 || PTZ_Y_V <500)
    {
        if(PTZ_X_V < 500 && PTZ_Y_V <500)
        {
            send_dir = DOWN_LEFT;
          //DT_Send_Status(DOWN_LEFT);
          debug("CAR_DOWN_LEFT");
        }
        else if(PTZ_X_V < 500)
        {
          send_dir = LEFT;
          // DT_Send_Status(LEFT);
          debug("CAR_LEFT");
        }
        else if (PTZ_Y_V <500)
        {
            send_dir = RIGHT;
         // DT_Send_Status(RIGHT);
          debug("CAR_DOWN");
        }
    }
    else if(PTZ_X_V < 500 || PTZ_Y_V >3500)
    {
        if(PTZ_X_V < 500 && PTZ_Y_V >3500)
        {
            send_dir = UP_LEFT;
       //   DT_Send_Status(UP_LEFT);
          debug("CAR_UP_LEFT");
        }
        else if(PTZ_Y_V >3500)
        {
            send_dir = UP;
        //  DT_Send_Status(UP);
          debug("CAR_UP");
        }
    }
    else if(PTZ_X_V > 3500 || PTZ_Y_V >3500)
    {
        if(PTZ_X_V > 3500 && PTZ_Y_V >3500)
        {
            send_dir = UP_RIGHT;
         // DT_Send_Status(UP_RIGHT);
          debug("CAR_UP_RIGHT");
        }
        else if(PTZ_X_V > 3500)
        {
            send_dir = RIGHT;
        //  DT_Send_Status(RIGHT);
          debug("CAR_RIGHT");
        }
    }
    else if(PTZ_X_V > 3500 && PTZ_Y_V < 500)
    {
        send_dir = DOWN_RIGHT;
        // DT_Send_Status(DOWN_RIGHT);
         debug("CAR_DOWN_RIGHT");
    }
    else
    {
        send_dir = STOP;
       //  DT_Send_Status(STOP);
    }
    if(pre_dir != send_dir)
    {
       DT_Send_Command_Ptz(send_dir);
       pre_dir = send_dir;
    }
}

uint8 Get_LED_Value(uint16 LED_VALUE)
{
    if(0<= LED_VALUE && LED_VALUE<= 100)
    {
        return 0;
    }
    else if(100< LED_VALUE && LED_VALUE<= 500 )
    {
        return 20;
    }
    else if (500< LED_VALUE && LED_VALUE <= 1000)
    {
        return 30; 
    }
    else if (1000< LED_VALUE && LED_VALUE<= 1500)
    {
        return 40; 
    }
    else if (1500< LED_VALUE && LED_VALUE<= 2000)
    {
         return 50; 
    }
    else if (2000< LED_VALUE && LED_VALUE<= 2500)
    {
        return 60; 
    }
    else if (2500< LED_VALUE && LED_VALUE<= 3000)
    {
        return 70;
    }
    else if (3000< LED_VALUE && LED_VALUE<= 3500)
    {
        return 80;
    }
    else if (3500< LED_VALUE && LED_VALUE<= 4000)
    {
        return 90;
    }
    else if (4000< LED_VALUE && LED_VALUE<= 4500)
    {
        return 100;
    }
    else
        return 0;
    
}
void Cal_LED_1_value()
{
    static uint8 cur_value[4];
    static uint8 pre_value[4];
    uint8 i;
    cur_value[0] = Get_LED_Value(LED_1_V);
    cur_value[1] = Get_LED_Value(LED_2_V);
    cur_value[2] = Get_LED_Value(LED_3_V);
    
    for(i =0 ;i <4 ; i++)
    {
        if(pre_value[i] != cur_value [i])
        {
           DT_Send_Command_Led(cur_value); 
           
           pre_value[i] = cur_value[i];
           printf("led%d : %d",i,cur_value);
        }
    }
    
}
/* [] END OF FILE */
