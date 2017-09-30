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
void Control_init()
{
    g_Car.Car_dir[UP] = UP;
    g_Car.Car_dir[DOWN] = DOWN;
    g_Car.Car_dir[LEFT] = UP;
    g_Car.Car_dir[RIGHT] = RIGHT;
    g_Car.Ptz_dir[UP] = UP;
    g_Car.Ptz_dir[DOWN] = DOWN;
    g_Car.Ptz_dir[LEFT] = LEFT;
    g_Car.Ptz_dir[RIGHT] = RIGHT;
}
void Cal_car_dir()
{
    static uint8 send_dir = STOP;
    static uint8 pre_dir  = 0;
   
     
        if(CAR_X_V < 500 &&CAR_Y_V <500)
        {
            send_dir = DOWN_LEFT;
            
            debug("CAR_DOWN_LEFT");
            
        }
        else if(CAR_X_V < 500 && CAR_Y_V >3500)
        {
            send_dir = UP_LEFT;
     
            debug("CAR_UP_LEFT");
        }
        else if(CAR_X_V > 3500 && CAR_Y_V >3500)
        {
            send_dir = UP_RIGHT;
        
            debug("CAR_UP_RIGHT");
        }
        else if(CAR_X_V > 3500 && CAR_Y_V < 500)
        {
            send_dir = DOWN_RIGHT;
         
            debug("CAR_DOWN_RIGHT");
        }
        else if(CAR_X_V < 500)
        {
            send_dir = RIGHT;
   
            debug("CAR_RIGHT");
        }
        else if (CAR_Y_V <500)
        {
            send_dir = UP;
    
            debug("CAR_UP");
        }
        else if(CAR_Y_V >3500)
        {
            send_dir = DOWN;
     
            debug("CAR_DOWN");
        }
        else if(CAR_X_V > 3500)
        {
            send_dir = LEFT;
   
            debug("CAR_ LEFT");
        }
        else
        {
            send_dir = STOP;
            
        }
    if(pre_dir != send_dir)
    { 
        
       DT_Send_Command_Car(g_Car.Car_dir[send_dir]);
       pre_dir = send_dir;
    }
}

void Cal_ptz_dir()
{
    static uint8 send_dir = STOP;
    static uint8 pre_dir  = 0;
   
     
    if(PTZ_X_V < 500 && PTZ_Y_V <500)
    {
        send_dir = DOWN_LEFT;

        debug("PTZ_DOWN_LEFT");
        
    }
    else if(PTZ_X_V < 500 && PTZ_Y_V >3500)
    {
        send_dir = UP_LEFT;
 
      debug("PTZ_UP_LEFT");
    }
    else if(PTZ_X_V > 3500 && PTZ_Y_V >3500)
    {
        send_dir = UP_RIGHT;
    
      debug("PTZ_UP_RIGHT");
    }
    else if(PTZ_X_V > 3500 && PTZ_Y_V < 500)
    {
        send_dir = DOWN_RIGHT;
     
         debug("PTZ_DOWN_RIGHT");
    }
    else if(PTZ_X_V < 500)
    {
      send_dir = LEFT;

      debug("PTZ_LEFT");
    }
    else if (PTZ_Y_V <500)
    {
        send_dir = UP;

      debug("PTZ_UP");
    }
    else if(PTZ_Y_V >3500)
    {
        send_dir = DOWN;
 
      debug("PTZ_DOWN");
    }
    else if(PTZ_X_V > 3500)
    {
        send_dir = RIGHT;

      debug("PTZ_RIGHT");
    }
    else
    {
        send_dir = STOP;
        
    }
    if(pre_dir != send_dir)
    { 
       //  printf("--------------dir:%d-----------------",send_dir);
       DT_Send_Command_Ptz(g_Car.Ptz_dir[send_dir]);
       
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
void Cal_LED_value()
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
          // printf("LED-[%d]:%d\r\n", i,cur_value[i]);
           
           pre_value[i] = cur_value[i];
         
        }
    }
    
}

uint16 Get_Speed_Value(uint16 speed_value)
{
    if(0<= speed_value && speed_value<= 100)
    {
        return 6000;
    }
    else if(100< speed_value && speed_value<= 500 )
    {
        return 8000;
    }
    else if (500< speed_value && speed_value <= 1000)
    {
        return 10000; 
    }
    else if (1000< speed_value && speed_value<= 1500)
    {
        return 13000; 
    }
    else if (1500< speed_value && speed_value<= 2000)
    {
         return 15000; 
    }
    else if (2000< speed_value && speed_value<= 2500)
    {
        return 16000; 
    }
    else if (2500< speed_value && speed_value<= 3000)
    {
        return 17000;
    }
    else if (3000< speed_value && speed_value<= 3500)
    {
        return 18000;
    }
    else if (3500< speed_value && speed_value<= 4000)
    {
        return 19000;
    }
    else if (4000< speed_value && speed_value<= 4500)
    {
        return 20000;
    }
    else
        return 14000;
}
void Cal_Speed_value()
{
     static uint16 cur_value;
     static uint16 pre_value;
     cur_value = Get_Speed_Value(CAR_SPEED_V);
     if(pre_value != cur_value )
    {
        DT_Send_Command_Speed(cur_value);
        printf("Speed:%d \r\n",cur_value);
        pre_value = cur_value;
    }
}


/* [] END OF FILE */
