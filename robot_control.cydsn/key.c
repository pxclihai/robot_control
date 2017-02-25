
#include "key.h"
#include <project.h>
#include "Transfer.h"
#include "control.h"


#define EVENT_CB(ev)   if(handle->cb[ev])handle->cb[ev]((Button*)handle)


#define led_high 100
#define led_medium 40
#define led_low   0
uint8 led_send[4] = {0,0,0,0};
//button handle list head.
static struct Button* head_handle = NULL;

struct Button key_up; 
struct Button key_down; 
struct Button key_left;  
struct Button key_right;

struct Button PTZ_up; 
struct Button PTZ_down; 
struct Button PTZ_left;  
struct Button PTZ_right;

struct Button key_speed_low;
struct Button key_speed_high;


struct Button led_start; 

struct Button STR1; 
struct Button STR2; 
struct Button MSR_high; 
struct Button MSR_low; 
struct Button SWITCH_1_high;
struct Button SWITCH_1_low;
struct Button SWITCH_2_high; 
struct Button SWITCH_2_low; 

uint8 temp;
uint8 temp1;

uint16 Car_speed_base = 1000;



//PTZ
void Callback_PTZ_up_press_up()
{
   DT_Send_Command_Ptz(STOP);
}
void Callback_PTZ_up_press_down()
{
   DT_Send_Command_Ptz(RIGHT);
}

void Callback_PTZ_down_press_up()
{
  DT_Send_Command_Ptz(STOP);
}
void Callback_PTZ_down_press_down()
{
    DT_Send_Command_Ptz(DOWN);
}


void Callback_PTZ_left_press_up()
{
   DT_Send_Command_Ptz(STOP);
}
void Callback_PTZ_left_press_down()
{
    DT_Send_Command_Ptz(LEFT); 
}

void Callback_PTZ_right_press_up()
{
   DT_Send_Command_Ptz(STOP);
}
void Callback_PTZ_right_press_down()
{
    DT_Send_Command_Ptz(UP); 
}
///speed

void Callback_key_speed_low_press_up()
{
    DT_Send_Command_Speed(15000);
}
void Callback_key_speed_low_press_down()
{
    DT_Send_Command_Speed(20000);
}
void Callback_key_speed_high_press_up()
{
     DT_Send_Command_Speed(15000);
}
void Callback_key_speed_high_press_down()
{
     DT_Send_Command_Speed(10000);
}


////2个预留开关
void Callback_STR1_press_up()
{
    DT_Send_Command_mode(0);
    debug("str1_up");
}
void Callback_STR1_down()
{
    DT_Send_Command_mode(1);
    debug("str1_down");
}
void Callback_STR2_press_up()
{
    DT_Send_Command_WireWheel(0);
    debug("str2_up");
}
void Callback_STR2_press_down()
{
   DT_Send_Command_WireWheel(1);
   debug("str2_down");
}    

void Callback_MSR_low_press_up()
{
     DT_Send_Command_MSR(WHEEL_STOP);
     debug("MSR_low_up");
}
void Callback_MSR_low_press_down()
{
     DT_Send_Command_MSR(FORWARD);
     debug("MSR_low_down");
}
void Callback_MSR_high_press_up()
{
     DT_Send_Command_MSR(WHEEL_STOP);
    debug("MSR_high_up");
}
void Callback_MSR_high_press_down()
{
    DT_Send_Command_MSR(WHEEL_STOP);
    debug("MSR_high_down");
}    
//SWITCH_1
void Callback_SWITCH_1_low_press_up()
{
      g_Control.bianbei = 0;
      debug("Callback_SWITCH_1_low_press_up");
}
void Callback_SWITCH_1_low_press_down()
{
       g_Control.bianbei = 1;
       debug("Callback_SWITCH_1_low_press_down");
}
void Callback_SWITCH_1_high_press_up()
{
      g_Control.bianbei = 0;
    debug("Callback_SWITCH_1_high_press_up");
}
void Callback_SWITCH_1_high_press_down()
{
       g_Control.bianbei = 2;
    debug("Callback_SWITCH_1_high_press_down");
}    
//SWITCH_2
void Callback_SWITCH_2_low_press_up()
{
    g_Control.jiaoju = 0;
   debug("Callback_SWITCH_2_low_press_up");
}
void Callback_SWITCH_2_low_press_down()
{
    g_Control.jiaoju  = 1;
    debug("Callback_SWITCH_2_low_press_down");
}
void Callback_SWITCH_2_high_press_up()
{
    g_Control.jiaoju = 0;
    debug("Callback_SWITCH_2_high_press_up");
}
void Callback_SWITCH_2_high_press_down()
{
    g_Control.jiaoju = 2;
   debug("Callback_SWITCH_2_high_press_down");
}
void init_button(void)
{

  //2个预留开关
    button_init   (&STR1, STR1_Read, 0);
    button_attach (&STR1, PRESS_UP, Callback_STR1_press_up);
    button_start  (&STR1);
    button_init   (&STR1, STR1_Read, 0);
    button_attach (&STR1, PRESS_DOWN, Callback_STR1_down);
    button_start  (&STR1);
    button_init   (&STR2, STR2_Read, 0);
    button_attach (&STR2, PRESS_UP, Callback_STR2_press_up);
    button_start  (&STR2);
    button_init  (&STR2, STR2_Read, 0);
    button_attach (&STR2, PRESS_DOWN, Callback_STR2_press_down);
    button_start  (&STR2);
 ///测厚仪3段式开关MSR
    
    button_init  (&MSR_low, MSR_LOW_Read, 0);
    button_attach(&MSR_low, PRESS_UP, Callback_MSR_low_press_up);
    button_start (&MSR_low);
    button_init  (&MSR_low, MSR_LOW_Read, 0);
    button_attach(&MSR_low, PRESS_DOWN, Callback_MSR_low_press_down);
    button_start (&MSR_low);
    button_init  (&MSR_high, MSR_HIGH_Read, 0);
    button_attach(&MSR_high, PRESS_UP, Callback_MSR_high_press_up);
    button_start (&MSR_high);
     button_init  (&MSR_high, MSR_HIGH_Read, 0);
    button_attach(&MSR_high, PRESS_DOWN, Callback_MSR_high_press_down);
    button_start (&MSR_high);
    
    
    
//SWITCH_1
    button_init  (&SWITCH_1_low, SWITCH_1_LOW_Read, 0);
    button_attach(&SWITCH_1_low, PRESS_UP, Callback_SWITCH_1_low_press_up);
    button_start (&SWITCH_1_low);
    button_init  (&SWITCH_1_low, SWITCH_1_LOW_Read, 0);
    button_attach(&SWITCH_1_low, PRESS_DOWN, Callback_SWITCH_1_low_press_down);
    button_start (&SWITCH_1_low);
    
    button_init  (&SWITCH_1_high, SWITCH_1_HIGH_Read, 0);
    button_attach(&SWITCH_1_high, PRESS_UP, Callback_SWITCH_1_high_press_up);
    button_start (&SWITCH_1_high);
    button_init  (&SWITCH_1_high, SWITCH_1_HIGH_Read, 0);
    button_attach(&SWITCH_1_high, PRESS_DOWN, Callback_SWITCH_1_high_press_down);
    button_start (&SWITCH_1_high);
//SWITCH_2
    button_init  (&SWITCH_2_low, SWITCH_2_LOW_Read, 0);
    button_attach(&SWITCH_2_low, PRESS_UP, Callback_SWITCH_2_low_press_up);
    button_start (&SWITCH_2_low);
    button_init  (&SWITCH_2_low, SWITCH_2_LOW_Read, 0);
    button_attach(&SWITCH_2_low, PRESS_DOWN, Callback_SWITCH_2_low_press_down);
    button_start (&SWITCH_2_low);
    
    button_init  (&SWITCH_2_high, SWITCH_2_HIGH_Read, 0);
    button_attach(&SWITCH_2_high, PRESS_UP, Callback_SWITCH_2_high_press_up);
    button_start (&SWITCH_2_high);
    button_init  (&SWITCH_2_high, SWITCH_2_HIGH_Read, 0);
    button_attach(&SWITCH_2_high, PRESS_DOWN, Callback_SWITCH_2_high_press_down);
    button_start (&SWITCH_2_high);    
    ////1
//    if(LED_UP_LOW_Read() == 0)
//    {
//     led_send[0] = led_low;
// 
//    }
//    else if(LED_UP_HIGH_Read() == 0)
//    {
//     led_send[0] = led_high;
//   
//    }
//   
//    else 
//    {
//     led_send[0] = led_medium;
//    
//    } 
//    
//    CyDelay(2);
    
    ///2
//    if(LED_DOWN_LOW_Read() == 0)
//    {
//     led_send[1] = led_low;
//  
//    }
//    else if(LED_DOWN_HIGH_Read() == 0)
//    {
//     led_send[1] = led_high;
//  
//    }
//    else 
//    {
//     led_send[1] = led_medium;
//
//    }
//        CyDelay(2);
//   if(LED_LEFT_LOW_Read() == 0)
//    {
//     led_send[2] = led_low;
// 
//    }
//    else if(LED_LEFT_HIGH_Read() == 0)
//    {
//     led_send[2] = led_high;
//  
//    }
//    else 
//    {
//     led_send[2] = led_medium;
//   
//    }
//        CyDelay(2);
//        if(LED_RIGHT_LOW_Read() == 0)
//    {
//     led_send[3] = led_low;
//
//    }
//    else if(LED_RIGHT_HIGH_Read() == 0)
//    {
//     led_send[3] = led_high;
//   
//    }
//    else 
//    {
//     led_send[3] = led_medium;
//     
//    }
//    DT_Send_Command_Led(led_send);
//        CyDelay(2);
//    if(KEY_SPEED_LOW_Read() == 0)
//    {
//        DT_Send_Command_Speed(20000);
//    }
//    else if(KEY_SPEED_HIGH_Read() == 0)
//    {
//         DT_Send_Command_Speed(10000);
//    }
//    else
//    {
//         DT_Send_Command_Speed(15000);
//    }
   
}

void button_init(struct Button* handle, uint8_t(*pin_level)(), uint8_t active_level)
{
	memset(handle, sizeof(struct Button), 0);
	handle->event = (uint8_t)NONE_PRESS;
	handle->hal_button_Level = pin_level;
	handle->button_level = handle->hal_button_Level();
	handle->active_level = active_level;
}

void button_attach(struct Button* handle, PressEvent event, BtnCallback cb)
{
	handle->cb[event] = cb;
}


PressEvent get_button_event(struct Button* handle)
{
	return (PressEvent)(handle->event);
}


void button_handler(struct Button* handle)
{
	uint8_t read_gpio_level = handle->hal_button_Level();

	//ticks counter working..
	if((handle->state) > 0) handle->ticks++;

	/*------------button debounce handle---------------*/
	if(read_gpio_level != handle->button_level) { //not equal to prev one
		//continue read 3 times same new level change
		if(++(handle->debounce_cnt) >= DEBOUNCE_TICKS) {
			handle->button_level = read_gpio_level;
			handle->debounce_cnt = 0;
		}
	} else { //leved not change ,counter reset.
		handle->debounce_cnt = 0;
	}

	/*-----------------State machine-------------------*/
	switch (handle->state) {
	case 0:
		if(handle->button_level == handle->active_level) {	//start press down
			handle->event = (uint8_t)PRESS_DOWN;
			EVENT_CB(PRESS_DOWN);
			handle->ticks = 0;
			handle->repeat = 1;
			handle->state = 1;
		} else {
			handle->event = (uint8_t)NONE_PRESS;
		}
		break;

	case 1:
		if(handle->button_level != handle->active_level) { //released press up
			handle->event = (uint8_t)PRESS_UP;
			EVENT_CB(PRESS_UP);
			handle->ticks = 0;
			handle->state = 2;

		} else if(handle->ticks > LONG_TICKS) {
			handle->event = (uint8_t)LONG_RRESS_START;
			EVENT_CB(LONG_RRESS_START);
			handle->state = 5;
		}
		break;

	case 2:
		if(handle->button_level == handle->active_level) { //press down again
			handle->event = (uint8_t)PRESS_DOWN;
			EVENT_CB(PRESS_DOWN);
			handle->repeat++;
			if(handle->repeat == 2) {
				EVENT_CB(DOUBLE_CLICK); // repeat hit
			} 
			EVENT_CB(PRESS_REPEAT); // repeat hit
			handle->ticks = 0;
			handle->state = 3;
		} else if(handle->ticks > SHORT_TICKS) { //released timeout
			if(handle->repeat == 1) {
				handle->event = (uint8_t)SINGLE_CLICK;
				EVENT_CB(SINGLE_CLICK);
			} else if(handle->repeat == 2) {
				handle->event = (uint8_t)DOUBLE_CLICK;
			}
			handle->state = 0;
		}
		break;

	case 3:
		if(handle->button_level != handle->active_level) { //released press up
			handle->event = (uint8_t)PRESS_UP;
			EVENT_CB(PRESS_UP);
			if(handle->ticks < SHORT_TICKS) {
				handle->ticks = 0;
				handle->state = 2; //repeat press
			} else {
				handle->state = 0;
			}
		}
		break;

	case 5:
		if(handle->button_level == handle->active_level) {
			//continue hold trigger
			handle->event = (uint8_t)LONG_PRESS_HOLD;
			EVENT_CB(LONG_PRESS_HOLD);

		} else { //releasd
			handle->event = (uint8_t)PRESS_UP;
			EVENT_CB(PRESS_UP);
			handle->state = 0; //reset
		}
		break;
	}
}


int button_start(struct Button* handle)
{
	struct Button* target = head_handle;
	while(target) {
		if(target == handle) return -1;	//already exist.
		target = target->next;
	}
	handle->next = head_handle;
	head_handle = handle;
	return 0;
}

void button_stop(struct Button* handle)
{
	struct Button** curr;
	for(curr = &head_handle; *curr; ) {
		struct Button* entry = *curr;
		if (entry == handle) {
			*curr = entry->next;
//			free(entry);
		} else
			curr = &entry->next;
	}
}


void button_ticks()
{
	struct Button* target;
	for(target=head_handle; target; target=target->next) {
		button_handler(target);
	}
}
/* [] END OF FILE */
