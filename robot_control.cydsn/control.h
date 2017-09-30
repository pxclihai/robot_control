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
#ifndef _CONTROL_H
#define	_CONTROL_H
#include <project.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_LEFT 4
#define UP_RIGHT 5 
#define DOWN_LEFT 6
#define DOWN_RIGHT 7
#define STOP 8
    

enum WHEEL_DIR{FORWARD,REVERSAL,WHEEL_STOP};


typedef struct 
{
   uint16 pwm;
  // enum WHEEL_DIR dir;
}S_WHEEL;  
typedef struct 
{ 
    uint8 Car_dir[9];
    uint8 Ptz_dir[9];
    uint8 Car_lock;
   
   // enum CAR_DIR set_dir;
    uint16   set_car_speed;
    S_WHEEL  left_front_wheel;
    S_WHEEL  left_behind_wheel;
    S_WHEEL  right_front_wheel;
    S_WHEEL  right_behind_wheel;
}S_CAR ;
S_CAR g_Car ;
typedef struct 
{
    uint16 Battery;
    uint8  bianbei;
    uint8  jiaoju;
   
}S_CONTROL;
S_CONTROL g_Control;
void Cal_car_dir();
void Cal_ptz_dir();
void Cal_LED_value();
void Cal_Speed_value();
#endif
/* [] END OF FILE */
