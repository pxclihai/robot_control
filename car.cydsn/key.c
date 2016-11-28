
#include "key.h"
#include <project.h>
#include "Transfer.h"
#include "car.h"
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
struct Button led_up_low; 
struct Button led_down_low; 
struct Button led_left_low;  
struct Button led_right_low;
struct Button led_up_high; 
struct Button led_down_high; 
struct Button led_left_high;  
struct Button led_right_high;

uint8 temp;
uint8 temp1;

uint16 Car_speed_base = 1000;

void Callback_key_up_press_up()
{
   DT_Send_Status(STOP);
}
void Callback_key_up_press_down()
{
   DT_Send_Status(DOWN);
}

void Callback_key_down_press_up()
{
  DT_Send_Status(STOP);
}
void Callback_key_down_press_down()
{
    DT_Send_Status(UP);
}


void Callback_key_left_press_up()
{
   DT_Send_Status(STOP);
}
void Callback_key_left_press_down()
{
    DT_Send_Status(LEFT); 
}

void Callback_key_right_press_up()
{
   DT_Send_Status(STOP);
}
void Callback_key_right_press_down()
{
    DT_Send_Status(RIGHT); 
}

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
///led

void Callback_led_start_press_up()
{
  DT_Send_Command_Lock(0); 
}
void Callback_led_start_press_down()
{
  DT_Send_Command_Lock(1); 
}
////------up
void Callback_led_up_low_press_up()
{
    led_send[0] = led_medium;
    DT_Send_Command_Led(led_send); 
}
void Callback_led_up_low_press_down()
{
    led_send[0] = led_low;
    DT_Send_Command_Led(led_send);
}
void Callback_led_up_high_press_up()
{
    led_send[0] = led_medium;
    DT_Send_Command_Led(led_send);
}
void Callback_led_up_high_press_down()
{
    led_send[0] = led_high;
    DT_Send_Command_Led(led_send);
}
////down
void Callback_led_down_low_press_up()
{
    led_send[2] = led_medium;
    DT_Send_Command_Led(led_send); 
}
void Callback_led_down_low_press_down()
{
    led_send[2] = led_high;
    DT_Send_Command_Led(led_send);
}
void Callback_led_down_high_press_up()
{
    led_send[2] = led_medium;
    DT_Send_Command_Led(led_send);
}
void Callback_led_down_high_press_down()
{
    led_send[2] = led_low;
    DT_Send_Command_Led(led_send);
}    
////////////left
void Callback_led_left_low_press_up()
{
    led_send[3] = led_medium;
    DT_Send_Command_Led(led_send); 
}
void Callback_led_left_low_press_down()
{
    led_send[3] = led_high;
    DT_Send_Command_Led(led_send);
}
void Callback_led_left_high_press_up()
{
    led_send[3] = led_medium;
    DT_Send_Command_Led(led_send);
}
void Callback_led_left_high_press_down()
{
    led_send[3] = led_low;
    DT_Send_Command_Led(led_send);
}    
/////
void Callback_led_right_low_press_up()
{
    led_send[1] = led_medium;
    DT_Send_Command_Led(led_send); 
}
void Callback_led_right_low_press_down()
{
    led_send[1] = led_low;
    DT_Send_Command_Led(led_send);
}
void Callback_led_right_high_press_up()
{
    led_send[1] = led_medium;
    DT_Send_Command_Led(led_send);
}
void Callback_led_right_high_press_down()
{
    led_send[1] = led_high;
     DT_Send_Command_Led(led_send);
}    
///
void init_button(void)
{
    button_init(&key_up, KEY_UP_Read, 0);
    button_attach(&key_up, PRESS_UP, Callback_key_up_press_up);
    button_attach(&key_up, PRESS_DOWN, Callback_key_up_press_down);
    button_start(&key_up);
    
    button_init(&key_down, KEY_DOWN_Read, 0);
    button_attach(&key_down, PRESS_UP, Callback_key_down_press_up);
    button_attach(&key_down, PRESS_DOWN, Callback_key_down_press_down);
    button_start(&key_down);
    
    button_init(&key_left, KEY_LEFT_Read, 0);
    button_attach(&key_left, PRESS_UP,   Callback_key_left_press_up);
    button_attach(&key_left, PRESS_DOWN, Callback_key_left_press_down);
    button_start(&key_left);
    
    button_init(&key_right, KEY_RIGHT_Read, 0);
    button_attach(&key_right, PRESS_UP,   Callback_key_right_press_up);
    button_attach(&key_right, PRESS_DOWN, Callback_key_right_press_down);
    button_start(&key_right);
    
    
    button_init(&PTZ_up, PTZ_UP_Read, 0);
    button_attach(&PTZ_up, PRESS_UP,   Callback_PTZ_up_press_up);
    button_attach(&PTZ_up, PRESS_DOWN, Callback_PTZ_up_press_down);
    button_start(&PTZ_up);
    
    button_init(&PTZ_down, PTZ_DOWN_Read, 0);
    button_attach(&PTZ_down, PRESS_UP, Callback_PTZ_down_press_up);
    button_attach(&PTZ_down, PRESS_DOWN, Callback_PTZ_down_press_down);
    button_start(&PTZ_down);
    
    button_init(&PTZ_left, PTZ_LEFT_Read, 0);
    button_attach(&PTZ_left, PRESS_UP,   Callback_PTZ_left_press_up);
    button_attach(&PTZ_left, PRESS_DOWN, Callback_PTZ_left_press_down);
    button_start(&PTZ_left);
    
    button_init(&PTZ_right, PTZ_RIGHT_Read, 0);
    button_attach(&PTZ_right, PRESS_UP,   Callback_PTZ_right_press_up);
    button_attach(&PTZ_right, PRESS_DOWN, Callback_PTZ_right_press_down);
    button_start(&PTZ_right);
    /////speed
    button_init  (&key_speed_low, KEY_SPEED_LOW_Read, 0);
    button_attach(&key_speed_low, PRESS_UP, Callback_key_speed_low_press_up);
    button_start (&key_speed_low);
    button_init  (&key_speed_low, KEY_SPEED_LOW_Read, 0);
    button_attach(&key_speed_low, PRESS_DOWN, Callback_key_speed_low_press_down);
    button_start (&key_speed_low);
    
    button_init  (&key_speed_high, KEY_SPEED_HIGH_Read, 0);
    button_attach(&key_speed_high, PRESS_UP, Callback_key_speed_high_press_up);
    button_start (&key_speed_high);
    
    button_init  (&key_speed_high, KEY_SPEED_HIGH_Read, 0);
    button_attach(&key_speed_high, PRESS_DOWN, Callback_key_speed_high_press_down);
    button_start (&key_speed_high);
    ////
    
    

    button_init(&led_start, LED_START_Read, 0);
    button_attach(&led_start, PRESS_UP,   Callback_led_start_press_up);
    button_start(&led_start);
    button_init(&led_start, LED_START_Read, 0);
    button_attach(&led_start, PRESS_DOWN,   Callback_led_start_press_down);
    button_start(&led_start);
    
    //led --button -1
    button_init  (&led_up_low, LED_UP_LOW_Read, 0);
    button_attach(&led_up_low, PRESS_UP, Callback_led_up_low_press_up);
    button_start (&led_up_low);
    button_init  (&led_up_low, LED_UP_LOW_Read, 0);
    button_attach(&led_up_low, PRESS_DOWN, Callback_led_up_low_press_down);
    button_start (&led_up_low);
    
    button_init  (&led_up_high, LED_UP_HIGH_Read, 0);
    button_attach(&led_up_high, PRESS_UP, Callback_led_up_high_press_up);
    button_start (&led_up_high);
    button_init  (&led_up_high, LED_UP_HIGH_Read, 0);
    button_attach(&led_up_high, PRESS_DOWN, Callback_led_up_high_press_down);
    button_start (&led_up_high);
    
    
    //led button 2
     button_init  (&led_down_low, LED_DOWN_LOW_Read, 0);
    button_attach(&led_down_low, PRESS_UP, Callback_led_down_low_press_up);
    button_start (&led_down_low);
      button_init  (&led_down_low, LED_DOWN_LOW_Read, 0);
    button_attach(&led_down_low, PRESS_DOWN, Callback_led_down_low_press_down);
    button_start (&led_down_low);
    button_init  (&led_down_high, LED_DOWN_HIGH_Read, 0);
    button_attach(&led_down_high, PRESS_UP, Callback_led_down_high_press_up);
    button_start (&led_down_high);
     button_init  (&led_down_high, LED_DOWN_HIGH_Read, 0);
    button_attach(&led_down_high, PRESS_DOWN, Callback_led_down_high_press_down);
    button_start (&led_down_high);
 ////////   
    
        button_init  (&led_left_low, LED_LEFT_LOW_Read, 0);
    button_attach(&led_left_low, PRESS_UP, Callback_led_left_low_press_up);
    button_start (&led_left_low);
         button_init  (&led_left_low, LED_LEFT_LOW_Read, 0);
    button_attach(&led_left_low, PRESS_DOWN, Callback_led_left_low_press_down);
    button_start (&led_left_low);
    button_init  (&led_left_high, LED_LEFT_HIGH_Read, 0);
    button_attach(&led_left_high, PRESS_UP, Callback_led_left_high_press_up);
    button_start (&led_left_high);
      button_init  (&led_left_high, LED_LEFT_HIGH_Read, 0);
    button_attach(&led_left_high, PRESS_DOWN, Callback_led_left_high_press_down);
    button_start (&led_left_high);
    
        button_init  (&led_right_low, LED_RIGHT_LOW_Read, 0);
    button_attach(&led_right_low, PRESS_UP, Callback_led_right_low_press_up);
    button_start (&led_right_low);
        button_init  (&led_right_low, LED_RIGHT_LOW_Read, 0);
    button_attach(&led_right_low, PRESS_DOWN, Callback_led_right_low_press_down);
    button_start (&led_right_low);
    
    button_init  (&led_right_high, LED_RIGHT_HIGH_Read, 0);
    button_attach(&led_right_high, PRESS_UP, Callback_led_right_high_press_up);
    button_start (&led_right_high);
        button_init  (&led_right_high, LED_RIGHT_HIGH_Read, 0);
    button_attach(&led_right_high, PRESS_DOWN, Callback_led_right_high_press_down);
    button_start (&led_right_high);
    
    
    ////1
    if(LED_UP_LOW_Read() == 0)
    {
     led_send[0] = led_low;
 
    }
    else if(LED_UP_HIGH_Read() == 0)
    {
     led_send[0] = led_high;
   
    }
   
    else 
    {
     led_send[0] = led_medium;
    
    } 
    
    CyDelay(2);
    
    ///2
        if(LED_DOWN_LOW_Read() == 0)
    {
     led_send[1] = led_low;
  
    }
    else if(LED_DOWN_HIGH_Read() == 0)
    {
     led_send[1] = led_high;
  
    }
    else 
    {
     led_send[1] = led_medium;

    }
        CyDelay(2);
   if(LED_LEFT_LOW_Read() == 0)
    {
     led_send[2] = led_low;
 
    }
    else if(LED_LEFT_HIGH_Read() == 0)
    {
     led_send[2] = led_high;
  
    }
    else 
    {
     led_send[2] = led_medium;
   
    }
        CyDelay(2);
        if(LED_RIGHT_LOW_Read() == 0)
    {
     led_send[3] = led_low;

    }
    else if(LED_RIGHT_HIGH_Read() == 0)
    {
     led_send[3] = led_high;
   
    }
    else 
    {
     led_send[3] = led_medium;
     
    }
    DT_Send_Command_Led(led_send);
        CyDelay(2);
    if(KEY_SPEED_LOW_Read() == 0)
    {
        DT_Send_Command_Speed(20000);
    }
    else if(KEY_SPEED_HIGH_Read() == 0)
    {
         DT_Send_Command_Speed(10000);
    }
    else
    {
         DT_Send_Command_Speed(15000);
    }
   
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
