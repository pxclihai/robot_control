/*******************************************************************************
* File Name: LED_UP_LOW.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LED_UP_LOW_H) /* Pins LED_UP_LOW_H */
#define CY_PINS_LED_UP_LOW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED_UP_LOW_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LED_UP_LOW__PORT == 15 && ((LED_UP_LOW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LED_UP_LOW_Write(uint8 value) ;
void    LED_UP_LOW_SetDriveMode(uint8 mode) ;
uint8   LED_UP_LOW_ReadDataReg(void) ;
uint8   LED_UP_LOW_Read(void) ;
uint8   LED_UP_LOW_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED_UP_LOW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LED_UP_LOW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LED_UP_LOW_DM_RES_UP          PIN_DM_RES_UP
#define LED_UP_LOW_DM_RES_DWN         PIN_DM_RES_DWN
#define LED_UP_LOW_DM_OD_LO           PIN_DM_OD_LO
#define LED_UP_LOW_DM_OD_HI           PIN_DM_OD_HI
#define LED_UP_LOW_DM_STRONG          PIN_DM_STRONG
#define LED_UP_LOW_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LED_UP_LOW_MASK               LED_UP_LOW__MASK
#define LED_UP_LOW_SHIFT              LED_UP_LOW__SHIFT
#define LED_UP_LOW_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED_UP_LOW_PS                     (* (reg8 *) LED_UP_LOW__PS)
/* Data Register */
#define LED_UP_LOW_DR                     (* (reg8 *) LED_UP_LOW__DR)
/* Port Number */
#define LED_UP_LOW_PRT_NUM                (* (reg8 *) LED_UP_LOW__PRT) 
/* Connect to Analog Globals */                                                  
#define LED_UP_LOW_AG                     (* (reg8 *) LED_UP_LOW__AG)                       
/* Analog MUX bux enable */
#define LED_UP_LOW_AMUX                   (* (reg8 *) LED_UP_LOW__AMUX) 
/* Bidirectional Enable */                                                        
#define LED_UP_LOW_BIE                    (* (reg8 *) LED_UP_LOW__BIE)
/* Bit-mask for Aliased Register Access */
#define LED_UP_LOW_BIT_MASK               (* (reg8 *) LED_UP_LOW__BIT_MASK)
/* Bypass Enable */
#define LED_UP_LOW_BYP                    (* (reg8 *) LED_UP_LOW__BYP)
/* Port wide control signals */                                                   
#define LED_UP_LOW_CTL                    (* (reg8 *) LED_UP_LOW__CTL)
/* Drive Modes */
#define LED_UP_LOW_DM0                    (* (reg8 *) LED_UP_LOW__DM0) 
#define LED_UP_LOW_DM1                    (* (reg8 *) LED_UP_LOW__DM1)
#define LED_UP_LOW_DM2                    (* (reg8 *) LED_UP_LOW__DM2) 
/* Input Buffer Disable Override */
#define LED_UP_LOW_INP_DIS                (* (reg8 *) LED_UP_LOW__INP_DIS)
/* LCD Common or Segment Drive */
#define LED_UP_LOW_LCD_COM_SEG            (* (reg8 *) LED_UP_LOW__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED_UP_LOW_LCD_EN                 (* (reg8 *) LED_UP_LOW__LCD_EN)
/* Slew Rate Control */
#define LED_UP_LOW_SLW                    (* (reg8 *) LED_UP_LOW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED_UP_LOW_PRTDSI__CAPS_SEL       (* (reg8 *) LED_UP_LOW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED_UP_LOW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED_UP_LOW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED_UP_LOW_PRTDSI__OE_SEL0        (* (reg8 *) LED_UP_LOW__PRTDSI__OE_SEL0) 
#define LED_UP_LOW_PRTDSI__OE_SEL1        (* (reg8 *) LED_UP_LOW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED_UP_LOW_PRTDSI__OUT_SEL0       (* (reg8 *) LED_UP_LOW__PRTDSI__OUT_SEL0) 
#define LED_UP_LOW_PRTDSI__OUT_SEL1       (* (reg8 *) LED_UP_LOW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED_UP_LOW_PRTDSI__SYNC_OUT       (* (reg8 *) LED_UP_LOW__PRTDSI__SYNC_OUT) 


#if defined(LED_UP_LOW__INTSTAT)  /* Interrupt Registers */

    #define LED_UP_LOW_INTSTAT                (* (reg8 *) LED_UP_LOW__INTSTAT)
    #define LED_UP_LOW_SNAP                   (* (reg8 *) LED_UP_LOW__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LED_UP_LOW_H */


/* [] END OF FILE */
