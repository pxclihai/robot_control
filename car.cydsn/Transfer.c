

#include "Transfer.h"
#include "car.h"
 

#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp)	  ) )
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp) + 1) )
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )

dt_flag_t f;					
uint8 data_to_send[50];	


void DT_Data_Exchange(void)
{
	static uint8 cnt = 0;
	static uint8 senser_cnt 	=   10;
	static uint8 status_cnt 	=   15;
	static uint8 rcdata_cnt 	=   20;
	static uint8 motopwm_cnt	=   20;
	static uint8 power_cnt		=	50;
	
	if((cnt % senser_cnt) == (senser_cnt-1))
		f.send_senser = 1;	
	
	if((cnt % status_cnt) == (status_cnt-1))
		f.send_status = 1;	
	
	if((cnt % rcdata_cnt) == (rcdata_cnt-1))
		f.send_rcdata = 1;	
	
	if((cnt % motopwm_cnt) == (motopwm_cnt-1))
		f.send_motopwm = 1;	
	
	if((cnt % power_cnt) == (power_cnt-1))
		f.send_power = 1;		
	
	cnt++;
/////////////////////////////////////////////////////////////////////////////////////
	if(f.send_version)
	{
		f.send_version = 0;
		DT_Send_Version(4,300,100,400,0);
	}
/////////////////////////////////////////////////////////////////////////////////////
	else if(f.send_status)
	{
		//f.send_status = 0;
	//	DT_Send_Status(0,g_Car.set_dir,g_Car.set_car_speed);
	}	

}


void DT_Send_Data(uint8 *dataToSend , uint8 length)
{

    UART_net_PutArray(dataToSend,length);
}

static void DT_Send_Check(uint8 head, uint8 check_sum)
{
	data_to_send[0]=0xAA;
	data_to_send[1]=0xAA;
	data_to_send[2]=0xEF;
	data_to_send[3]=2;
	data_to_send[4]=head;
	data_to_send[5]=check_sum;
	
	
	uint8 sum = 0;
    uint8 i=0;
	for(i=0;i<6;i++)
		sum += data_to_send[i];
	data_to_send[6]=sum;

	DT_Send_Data(data_to_send, 7);
}


void DT_Data_Receive_Prepare(uint8 data)
{
	static uint8 RxBuffer[50];
	static uint8 _data_len = 0,_data_cnt = 0;
	static uint8 state = 0;
	
	if(state==0&&data==0xAA)
	{
		state=1;
		RxBuffer[0]=data;
	}
	else if(state==1&&data==0xAF)
	{
		state=2;
		RxBuffer[1]=data;
	}
	else if(state==2&&data<0XF1) //fuciton
	{
		state=3;
		RxBuffer[2]=data;
	}
	else if(state==3&&data<50)//len
	{
		state = 4;
		RxBuffer[3]=data;
		_data_len = data;
		_data_cnt = 0;
	}
	else if(state==4&&_data_len>0)//data
	{
		_data_len--;
		RxBuffer[4+_data_cnt++]=data;
		if(_data_len==0)
			state = 5;
	}
	else if(state==5)//sum
	{
		state = 0;
		RxBuffer[4+_data_cnt]=data;
		DT_Data_Receive_Anl(RxBuffer,_data_cnt+5);
	}
	else
		state = 0;
}

void DT_Data_Receive_Anl(uint8 *data_buf,uint8 num)
{
	uint8 sum = 0;
    uint8 i=0;
	for( i=0;i<(num-1);i++)
		sum += *(data_buf+i);
	if(!(sum==*(data_buf+num-1)))		return;		//ÅÐ¶Ïsum
	if(!(*(data_buf)==0xAA && *(data_buf+1)==0xAF))		return;		//ÅÐ¶ÏÖ¡Í·
	
	if(*(data_buf+2)==0X01)
	{

	}
	
	if(*(data_buf+2)==0X02)
	{
        g_Car.set_dir = *(data_buf+4);
        g_Car.set_car_speed = (uint16)(*(data_buf+5)<<8)|*(data_buf+6);

	}

	if(*(data_buf+2)==0X10)						
    {

        DT_Send_Check(*(data_buf+2),sum);
		
    }
    if(*(data_buf+2)==0X11)				
    {

        DT_Send_Check(*(data_buf+2),sum);

    }
    if(*(data_buf+2)==0X12)							
    {	

        DT_Send_Check(*(data_buf+2),sum);
	
    }
	if(*(data_buf+2)==0X13)							
	{
		DT_Send_Check(*(data_buf+2),sum);
	}
	if(*(data_buf+2)==0X14)							
	{
		DT_Send_Check(*(data_buf+2),sum);
	}
	{
		DT_Send_Check(*(data_buf+2),sum);
	}
}

void DT_Send_Version(uint8 hardware_type, uint16 hardware_ver,uint16 software_ver,uint16 protocol_ver,uint16 bootloader_ver)
{
	uint8 _cnt=0;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0x00;
	data_to_send[_cnt++]=0;
	
	data_to_send[_cnt++]=hardware_type;
	data_to_send[_cnt++]=BYTE1(hardware_ver);
	data_to_send[_cnt++]=BYTE0(hardware_ver);
	data_to_send[_cnt++]=BYTE1(software_ver);
	data_to_send[_cnt++]=BYTE0(software_ver);
	data_to_send[_cnt++]=BYTE1(protocol_ver);
	data_to_send[_cnt++]=BYTE0(protocol_ver);
	data_to_send[_cnt++]=BYTE1(bootloader_ver);
	data_to_send[_cnt++]=BYTE0(bootloader_ver);
	
	data_to_send[3] = _cnt-4;
	
	uint8 sum = 0;
    uint8 i=0;
	for( i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	
	DT_Send_Data(data_to_send, _cnt);
}
void DT_Send_Status(enum CAR_DIR car_dir)
{
	uint8 _cnt=0;
    uint8 _temp;
	uint16 _temp1;

	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAF;
	data_to_send[_cnt++]=0x02;
	data_to_send[_cnt++]=0;
    
	_temp = car_dir;
	data_to_send[_cnt++]=_temp;

	
	data_to_send[3] = _cnt-4;
	
	uint8 sum = 0;
    uint8 i=0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	
	DT_Send_Data(data_to_send, _cnt);
}
void DT_Send_Command_Ptz(enum CAR_DIR car_dir)
{
	uint8 _cnt=0;
    uint8 _temp;
	uint16 _temp1;

	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAF;
	data_to_send[_cnt++]=0x05;
	data_to_send[_cnt++]=0;
    
	_temp = car_dir;
	data_to_send[_cnt++]=_temp;

	
	data_to_send[3] = _cnt-4;
	
	uint8 sum = 0;
    uint8 i=0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	
	DT_Send_Data(data_to_send, _cnt);
}
void DT_Send_Command_Speed(uint16 car_speed)
{
	uint8 _cnt=0;
    uint8 _temp;
	uint16 _temp1;

	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAF;
	data_to_send[_cnt++]=0x03;
	data_to_send[_cnt++]=0;
    
	_temp1 =  car_speed;
	data_to_send[_cnt++]=BYTE1(_temp1);
	data_to_send[_cnt++]=BYTE0(_temp1);
	
	data_to_send[3] = _cnt-4;
	
	uint8 sum = 0;
    uint8 i=0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	
	DT_Send_Data(data_to_send, _cnt);
}
void DT_Send_Command_Lock(uint8 car_lock)
{
	uint8 _cnt=0;
    uint8 _temp;

	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAF;
	data_to_send[_cnt++]=0x01;
	data_to_send[_cnt++]=0;
    
	
	data_to_send[_cnt++]=car_lock;

	
	data_to_send[3] = _cnt-4;
	
	uint8 sum = 0;
    uint8 i=0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	
	DT_Send_Data(data_to_send, _cnt);
}
void DT_Send_Command_Led(uint8 car_led[])
{
	uint8 _cnt=0;
    uint8 _temp;
	uint16 _temp1;

	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAF;
	data_to_send[_cnt++]=0x04;
	data_to_send[_cnt++]=0;
    

	data_to_send[_cnt++]=car_led[0];
	data_to_send[_cnt++]=car_led[1];
	data_to_send[_cnt++]=car_led[2];
	data_to_send[_cnt++]=car_led[3];
	data_to_send[3] = _cnt-4;
	
	uint8 sum = 0;
    uint8 i=0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	
	DT_Send_Data(data_to_send, _cnt);
}

void DT_Send_Senser(int16 a_x,int16 a_y,int16 a_z,int16 g_x,int16 g_y,int16 g_z,int16 m_x,int16 m_y,int16 m_z,int32 bar)
{
	uint8 _cnt=0;
	int16 _temp;
	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0x02;
	data_to_send[_cnt++]=0;
	
	_temp = a_x;
	data_to_send[_cnt++]=BYTE1(_temp);
	data_to_send[_cnt++]=BYTE0(_temp);
	_temp = a_y;
	data_to_send[_cnt++]=BYTE1(_temp);
	data_to_send[_cnt++]=BYTE0(_temp);
	_temp = a_z;	
	data_to_send[_cnt++]=BYTE1(_temp);
	data_to_send[_cnt++]=BYTE0(_temp);
	
	_temp = g_x;	
	data_to_send[_cnt++]=BYTE1(_temp);
	data_to_send[_cnt++]=BYTE0(_temp);
	_temp = g_y;	
	data_to_send[_cnt++]=BYTE1(_temp);
	data_to_send[_cnt++]=BYTE0(_temp);
	_temp = g_z;	
	data_to_send[_cnt++]=BYTE1(_temp);
	data_to_send[_cnt++]=BYTE0(_temp);
	
	_temp = m_x;	
	data_to_send[_cnt++]=BYTE1(_temp);
	data_to_send[_cnt++]=BYTE0(_temp);
	_temp = m_y;	
	data_to_send[_cnt++]=BYTE1(_temp);
	data_to_send[_cnt++]=BYTE0(_temp);
	_temp = m_z;	
	data_to_send[_cnt++]=BYTE1(_temp);
	data_to_send[_cnt++]=BYTE0(_temp);
	
	data_to_send[3] = _cnt-4;
	
	uint8 sum = 0;
    uint8 i=0;
	for( i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++] = sum;
	
	DT_Send_Data(data_to_send, _cnt);
}
void DT_Send_RCData(uint16 thr,uint16 yaw,uint16 rol,uint16 pit,uint16 aux1,uint16 aux2,uint16 aux3,uint16 aux4,uint16 aux5,uint16 aux6)
{
	uint8 _cnt=0;
	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0x03;
	data_to_send[_cnt++]=0;
	data_to_send[_cnt++]=BYTE1(thr);
	data_to_send[_cnt++]=BYTE0(thr);
	data_to_send[_cnt++]=BYTE1(yaw);
	data_to_send[_cnt++]=BYTE0(yaw);
	data_to_send[_cnt++]=BYTE1(rol);
	data_to_send[_cnt++]=BYTE0(rol);
	data_to_send[_cnt++]=BYTE1(pit);
	data_to_send[_cnt++]=BYTE0(pit);
	data_to_send[_cnt++]=BYTE1(aux1);
	data_to_send[_cnt++]=BYTE0(aux1);
	data_to_send[_cnt++]=BYTE1(aux2);
	data_to_send[_cnt++]=BYTE0(aux2);
	data_to_send[_cnt++]=BYTE1(aux3);
	data_to_send[_cnt++]=BYTE0(aux3);
	data_to_send[_cnt++]=BYTE1(aux4);
	data_to_send[_cnt++]=BYTE0(aux4);
	data_to_send[_cnt++]=BYTE1(aux5);
	data_to_send[_cnt++]=BYTE0(aux5);
	data_to_send[_cnt++]=BYTE1(aux6);
	data_to_send[_cnt++]=BYTE0(aux6);

	data_to_send[3] = _cnt-4;
	
	uint8 sum = 0;
    uint8 i=0;
	for( i=0;i<_cnt;i++)
		sum += data_to_send[i];
	
	data_to_send[_cnt++]=sum;
	
	DT_Send_Data(data_to_send, _cnt);
}
void DT_Send_Power(uint16 votage, uint16 current)
{
	uint8 _cnt=0;
	uint16 temp;
	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0x05;
	data_to_send[_cnt++]=0;
	
	temp = votage;
	data_to_send[_cnt++]=BYTE1(temp);
	data_to_send[_cnt++]=BYTE0(temp);
	temp = current;
	data_to_send[_cnt++]=BYTE1(temp);
	data_to_send[_cnt++]=BYTE0(temp);
	
	data_to_send[3] = _cnt-4;
	
	uint8 sum = 0;
    uint8 i=0;
	for( i=0;i<_cnt;i++)
		sum += data_to_send[i];
	
	data_to_send[_cnt++]=sum;
	
	DT_Send_Data(data_to_send, _cnt);
}
void DT_Send_MotoPWM(uint16 m_1,uint16 m_2,uint16 m_3,uint16 m_4,uint16 m_5,uint16 m_6,uint16 m_7,uint16 m_8)
{
	uint8 _cnt=0;
	
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0x06;
	data_to_send[_cnt++]=0;
	
	data_to_send[_cnt++]=BYTE1(m_1);
	data_to_send[_cnt++]=BYTE0(m_1);
	data_to_send[_cnt++]=BYTE1(m_2);
	data_to_send[_cnt++]=BYTE0(m_2);
	data_to_send[_cnt++]=BYTE1(m_3);
	data_to_send[_cnt++]=BYTE0(m_3);
	data_to_send[_cnt++]=BYTE1(m_4);
	data_to_send[_cnt++]=BYTE0(m_4);
	data_to_send[_cnt++]=BYTE1(m_5);
	data_to_send[_cnt++]=BYTE0(m_5);
	data_to_send[_cnt++]=BYTE1(m_6);
	data_to_send[_cnt++]=BYTE0(m_6);
	data_to_send[_cnt++]=BYTE1(m_7);
	data_to_send[_cnt++]=BYTE0(m_7);
	data_to_send[_cnt++]=BYTE1(m_8);
	data_to_send[_cnt++]=BYTE0(m_8);
	
	data_to_send[3] = _cnt-4;
	
	uint8 sum = 0;
    uint8 i=0;
	for(i=0;i<_cnt;i++)
		sum += data_to_send[i];
	
	data_to_send[_cnt++]=sum;
	
	DT_Send_Data(data_to_send, _cnt);
}


/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/
