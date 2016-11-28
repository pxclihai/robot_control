/********************************START OF FILE**********************************
* File Name        : buzzer.h
* Author           : 
* Version          : V1.0
* Date             :
* Description      : None
********************************************************************************
*
*
*
*******************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BUZZER_H_
#define __BUZZER_H_
#include <project.h>
/* Includes ------------------------------------------------------------------*/



/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define BZR_TIME_STEP			51
#define BUZZER_SET(s)			Beep_Write(s)

/* Exported define -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void bzr_Init();
void cb_bzr_Main();
void bzr_SetBell(uint32_t ton, uint32_t toff,uint32_t cont,uint32_t t3, uint32_t cyc);
uint8_t bzr_ifBusy(void);

#endif  /*__BUZZER_H_*/
/*********************************END OF FILE**********************************/
