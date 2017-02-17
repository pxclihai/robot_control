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


char8 command_connect[] = "AT+CONNL";

extern uint8 time_5ms_state;
extern uint8 time_1s_state;
void put_num(uint16 n);
int main()
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
  
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
  //  bzr_Init();
    init_button();
   
    UART_net_Init();
     
    UART_net_Start();
 
    Timer_1_Start(); 
    isr_timer_Start();
    
    isr_rx_net_Start();
    Monitor_Battery_Init();

   // CyDelay(100);
   // UART_net_PutString(command_connect);
 //  CyDelay(500);
//    bzr_SetBell(400,400,1,0,1); 
  //  isr_net_Start();
  //  PWM_MOTOR_WriteCompare1(100);
    CyDelay(3000);
    UART_net_PutString("Init_ok \r\n");
    UART_net_PutString("Hardware--V5.0\r\n");
    UART_net_PutString("Software--V.C.1.0\r\n");
    WARNING_BLUE_Write(0);
    WARNING_GREEN_Write(0);
    WARNING_RED_Write(0);
    for(;;)
    {
      /* Place your application code here. */
      // UART_net_WriteTxData(0xff);
    
        
      // DT_Data_Exchange();
      // UART_net_PutChar(0xfe);
      //Car_Dir(UP,1000);
    if( time_1s_state == 1)
    {
        Cal_Battery_loop();
        printf("CAR_X:%d | CAR_Y:%d | PTZ_X:%d |PTZ_Y:%d | LED1:%d | LED2:%d | LED3:%d | SPEED:%d \r\n",CAR_X_V,CAR_Y_V,PTZ_X_V,PTZ_Y_V,LED_1_V,LED_2_V,LED_3_V,CAR_SPEED_V);
        
        time_1s_state = 0;
        
    }
   if(time_5ms_state == 1)
    {
           button_ticks();
           time_5ms_state = 0;
           
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
