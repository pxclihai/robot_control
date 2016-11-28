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
#include "Transfer.h"
#include "key.h"
#include "buzzer.h"

char8 command_connect[] = "AT+CONNL";

extern uint8 time_5ms_state;
extern uint8 time_1s_state;

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
  //  BUZZER_SET(1);	

   // CyDelay(100);
   // UART_net_PutString(command_connect);
 //  CyDelay(500);
//    bzr_SetBell(400,400,1,0,1); 
  //  isr_net_Start();
  //  PWM_MOTOR_WriteCompare1(100);
    for(;;)
    {
      /* Place your application code here. */
      // UART_net_WriteTxData(0xff);
    
        
      // DT_Data_Exchange();
      // UART_net_PutChar(0xfe);
      //Car_Dir(UP,1000);
    if( time_1s_state == 1)
    {
        //UART_net_PutChar(0xfe);
        time_1s_state = 0;
    }
   if(time_5ms_state == 1)
    {
           button_ticks();
           time_5ms_state = 0;
    }
    }
}

/* [] END OF FILE */
