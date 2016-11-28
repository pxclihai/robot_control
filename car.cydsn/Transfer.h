#ifndef _DATA_TRANSFER_H
#define	_DATA_TRANSFER_H


#include <project.h>
#include "car.h"
typedef struct 
{
		uint8 send_version;
		uint8 send_status;
		uint8 send_senser;
		uint8 send_pid1;
		uint8 send_pid2;
		uint8 send_pid3;
		uint8 send_pid4;
		uint8 send_pid5;
		uint8 send_pid6;
		uint8 send_rcdata;
		uint8 send_offset;
		uint8 send_motopwm;
		uint8 send_power;

}dt_flag_t;

extern dt_flag_t f;

void DT_Data_Exchange(void);
void DT_Data_Receive_Prepare(uint8 data);
void DT_Data_Receive_Anl(uint8 *data_buf,uint8 num);
void DT_Send_Version(uint8 hardware_type, uint16 hardware_ver,uint16 software_ver,uint16 protocol_ver,uint16 bootloader_ver);

void DT_Send_Senser(int16 a_x,int16 a_y,int16 a_z,int16 g_x,int16 g_y,int16 g_z,int16 m_x,int16 m_y,int16 m_z,int32 bar);
void DT_Send_RCData(uint16 thr,uint16 yaw,uint16 rol,uint16 pit,uint16 aux1,uint16 aux2,uint16 aux3,uint16 aux4,uint16 aux5,uint16 aux6);
void DT_Send_Power(uint16 votage, uint16 current);
void DT_Send_MotoPWM(uint16 m_1,uint16 m_2,uint16 m_3,uint16 m_4,uint16 m_5,uint16 m_6,uint16 m_7,uint16 m_8);
void DT_Send_PID(uint8 group,float p1_p,float p1_i,float p1_d,float p2_p,float p2_i,float p2_d,float p3_p,float p3_i,float p3_d);
void DT_Send_Command_Led(uint8 car_led[]);

void DT_Send_Status(enum CAR_DIR car_dir);
void DT_Send_Command_Ptz(enum CAR_DIR car_dir);
void DT_Send_Command_Speed(uint16 car_speed);
void DT_Send_Command_Lock(uint8 car_lock);

#endif

