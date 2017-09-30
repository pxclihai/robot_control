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
#include <project.h>
#include "ADC_V.h"
#include "Transfer.h"
#include "key.h"
#include "buzzer.h"



extern uint8 time_5ms_state;
extern uint8 time_1s_state;
extern uint8 time_100ms_state;
uint16 adc_b;
void put_num(uint16 n);
int main()
{
    int i;
    CyGlobalIntEnable; /* Enable global interrupts. */
  
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    EEPROM_Start();
    init_button();
   
    UART_net_Init();
    
    UART_net_Start();
 
    Timer_1_Start(); 
    isr_timer_Start();
    
    isr_rx_net_Start();
    Monitor_Battery_Init();

    CyDelay(3000);
    
    WARNING_BLUE_Write(1);                      
    WARNING_GREEN_Write(1);
    WARNING_RED_Write(1);
    for(i = 0;i<8;i++)//读取按键
    {
        if(i<4)
            g_Car.Car_dir[i]   = EEPROM_ReadByte(i);
        else if(i<8)
            g_Car.Ptz_dir[i-4] = EEPROM_ReadByte(i);
    }
    g_Car.Car_dir[8] = 8;
    g_Car.Ptz_dir[8] = 8;
    for(;;)
    {
      /* Place your application code here. */
   
    
        if( time_1s_state == 1)
        {
          
            adc_b = g_Control.Battery*3300/4096;
         //  printf("|CAR_X:%d | CAR_Y:%d | PTZ_X:%d | PTZ_Y:%d | LED1:%d | LED2:%d | LED3:%d | SPEED:%d \r\n",CAR_X_V,CAR_Y_V,PTZ_X_V,PTZ_Y_V,LED_1_V,LED_2_V,LED_3_V,CAR_SPEED_V);
            
            time_1s_state = 0;
            
        }
        if(time_100ms_state == 1)
        {
            Cal_Battery_loop();
            Cal_car_dir();
            Cal_ptz_dir();
            Cal_Speed_value();
            Cal_LED_value();
            time_100ms_state = 0;
        }
        if(time_5ms_state == 1)
        {
            button_ticks();
            time_5ms_state = 0;
            DT_Data_Exchange();
        }
    }
}

int _write(int file, char *ptr, int len)
{
    int i;
    file = file;
    for (i = 0; i < len; i++)
    {
        UART_net_PutChar(*ptr++);
    }
    return len;
}
/* [] END OF FILE */
