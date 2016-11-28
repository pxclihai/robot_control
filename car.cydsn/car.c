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
#include "car.h"

//static void Command_Car_UP(uint16 speed);
//static void Command_Car_Down(uint16 speed);
//static void Set_Left_Front_Speed_Turn(uint16 speed,enum WHEEL_DIR turn);
//static void Set_Left_Behind_Speed_Turn(uint16 speed,enum WHEEL_DIR turn);
//static void Set_Right_Front_Speed_Turn(uint16 speed,enum WHEEL_DIR turn);
//static void Set_Right_Behind_Speed_Turn(uint16 speed,enum WHEEL_DIR turn);
//
//void Control_Car()
//{
//    Car_Dir(g_Car.set_dir,g_Car.set_car_speed); 
//}
//void Car_Dir(enum CAR_DIR dir,uint16 speed)
//{
//    if(dir == UP)
//    {
//       Command_Car_UP  (speed);
//    }
//    if(dir == DOWN)
//    {
//       Command_Car_Down(speed);
//    }
//    if(dir == LEFT)
//    {
//        
//    }
//}
//void Command_Car_UP(uint16 speed)
//{
//  Set_Left_Front_Speed_Turn(speed,FORWARD);
//  Set_Left_Behind_Speed_Turn(speed,FORWARD);
//  Set_Right_Behind_Speed_Turn(speed,FORWARD);
//  Set_Right_Behind_Speed_Turn(speed,FORWARD);
//
//}
//void Command_Car_Down(uint16 speed)
//{
//  Set_Left_Front_Speed_Turn  (speed,REVERSAL);
//  Set_Left_Behind_Speed_Turn (speed,REVERSAL);
//  Set_Right_Behind_Speed_Turn(speed,REVERSAL);
//  Set_Right_Behind_Speed_Turn(speed,REVERSAL);
//}
//void Command_Car_Left(uint16 speed)
//{
//  Set_Left_Front_Speed_Turn  (0,WHEEL_STOP);
//  Set_Left_Behind_Speed_Turn (0,WHEEL_STOP);
//  Set_Right_Behind_Speed_Turn(speed,REVERSAL);
//  Set_Right_Behind_Speed_Turn(speed,REVERSAL);
//}
//void Command_Car_Right(uint16 speed)
//{
//  Set_Left_Front_Speed_Turn  (speed,REVERSAL);
//  Set_Left_Behind_Speed_Turn (speed,REVERSAL);
//  Set_Right_Behind_Speed_Turn(0,WHEEL_STOP);
//  Set_Right_Behind_Speed_Turn(0,WHEEL_STOP);
//}
//void Command_Car_brake()
//{
//  Set_Left_Front_Speed_Turn  (0,WHEEL_STOP);
//  Set_Left_Behind_Speed_Turn (0,WHEEL_STOP);
//  Set_Right_Behind_Speed_Turn(0,WHEEL_STOP);
//  Set_Right_Behind_Speed_Turn(0,WHEEL_STOP);
//}
////set every one motor
//void Set_Left_Front_Speed_Turn(uint16 speed,enum WHEEL_DIR turn)
//{
//    PWM_MOTOR_WriteCompare1(speed);
//    if(turn == FORWARD)
//        { L_IN_1_Write(1);L_IN_2_Write(0);}
//    else if(turn == REVERSAL)
//        { L_IN_1_Write(0);L_IN_2_Write(1);}
//    else
//         {L_IN_1_Write(0);L_IN_2_Write(0);}
//}
//void Set_Left_Behind_Speed_Turn(uint16 speed,enum WHEEL_DIR turn)
//{
//    PWM_MOTOR_WriteCompare1(speed);
//    if(turn == FORWARD)
//        { L_IN_1_Write(1);L_IN_2_Write(0);}
//    else if(turn == REVERSAL)
//        { L_IN_1_Write(0);L_IN_2_Write(1);}
//    else
//         {L_IN_1_Write(0);L_IN_2_Write(0);}
//}
//void Set_Right_Front_Speed_Turn(uint16 speed,enum WHEEL_DIR turn)
//{
//    PWM_MOTOR_WriteCompare2(speed);
//    if(turn == FORWARD)
//        { R_IN_1_Write(1);R_IN_2_Write(0);}
//    else if(turn == REVERSAL)
//        { R_IN_1_Write(0);R_IN_2_Write(1);}
//    else
//         {R_IN_1_Write(0);R_IN_2_Write(0);}
//}
//void Set_Right_Behind_Speed_Turn(uint16 speed,enum WHEEL_DIR turn)
//{
//    PWM_MOTOR_WriteCompare1(speed);
//    if(turn == FORWARD)
//        { R_IN_1_Write(1);R_IN_2_Write(0);}
//    else if(turn == REVERSAL)
//        { R_IN_1_Write(0);R_IN_2_Write(1);}
//    else
//         {R_IN_1_Write(0);R_IN_2_Write(0);}
//}
/* [] END OF FILE */
