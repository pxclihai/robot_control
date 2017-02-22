/*******************************************************************************
* File Name: CAR_SPEED.h  
* Version 2.5
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

#if !defined(CY_PINS_CAR_SPEED_H) /* Pins CAR_SPEED_H */
#define CY_PINS_CAR_SPEED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CAR_SPEED_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CAR_SPEED__PORT == 15 && ((CAR_SPEED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CAR_SPEED_Write(uint8 value) ;
void    CAR_SPEED_SetDriveMode(uint8 mode) ;
uint8   CAR_SPEED_ReadDataReg(void) ;
uint8   CAR_SPEED_Read(void) ;
uint8   CAR_SPEED_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CAR_SPEED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CAR_SPEED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CAR_SPEED_DM_RES_UP          PIN_DM_RES_UP
#define CAR_SPEED_DM_RES_DWN         PIN_DM_RES_DWN
#define CAR_SPEED_DM_OD_LO           PIN_DM_OD_LO
#define CAR_SPEED_DM_OD_HI           PIN_DM_OD_HI
#define CAR_SPEED_DM_STRONG          PIN_DM_STRONG
#define CAR_SPEED_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CAR_SPEED_MASK               CAR_SPEED__MASK
#define CAR_SPEED_SHIFT              CAR_SPEED__SHIFT
#define CAR_SPEED_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CAR_SPEED_PS                     (* (reg8 *) CAR_SPEED__PS)
/* Data Register */
#define CAR_SPEED_DR                     (* (reg8 *) CAR_SPEED__DR)
/* Port Number */
#define CAR_SPEED_PRT_NUM                (* (reg8 *) CAR_SPEED__PRT) 
/* Connect to Analog Globals */                                                  
#define CAR_SPEED_AG                     (* (reg8 *) CAR_SPEED__AG)                       
/* Analog MUX bux enable */
#define CAR_SPEED_AMUX                   (* (reg8 *) CAR_SPEED__AMUX) 
/* Bidirectional Enable */                                                        
#define CAR_SPEED_BIE                    (* (reg8 *) CAR_SPEED__BIE)
/* Bit-mask for Aliased Register Access */
#define CAR_SPEED_BIT_MASK               (* (reg8 *) CAR_SPEED__BIT_MASK)
/* Bypass Enable */
#define CAR_SPEED_BYP                    (* (reg8 *) CAR_SPEED__BYP)
/* Port wide control signals */                                                   
#define CAR_SPEED_CTL                    (* (reg8 *) CAR_SPEED__CTL)
/* Drive Modes */
#define CAR_SPEED_DM0                    (* (reg8 *) CAR_SPEED__DM0) 
#define CAR_SPEED_DM1                    (* (reg8 *) CAR_SPEED__DM1)
#define CAR_SPEED_DM2                    (* (reg8 *) CAR_SPEED__DM2) 
/* Input Buffer Disable Override */
#define CAR_SPEED_INP_DIS                (* (reg8 *) CAR_SPEED__INP_DIS)
/* LCD Common or Segment Drive */
#define CAR_SPEED_LCD_COM_SEG            (* (reg8 *) CAR_SPEED__LCD_COM_SEG)
/* Enable Segment LCD */
#define CAR_SPEED_LCD_EN                 (* (reg8 *) CAR_SPEED__LCD_EN)
/* Slew Rate Control */
#define CAR_SPEED_SLW                    (* (reg8 *) CAR_SPEED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CAR_SPEED_PRTDSI__CAPS_SEL       (* (reg8 *) CAR_SPEED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CAR_SPEED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CAR_SPEED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CAR_SPEED_PRTDSI__OE_SEL0        (* (reg8 *) CAR_SPEED__PRTDSI__OE_SEL0) 
#define CAR_SPEED_PRTDSI__OE_SEL1        (* (reg8 *) CAR_SPEED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CAR_SPEED_PRTDSI__OUT_SEL0       (* (reg8 *) CAR_SPEED__PRTDSI__OUT_SEL0) 
#define CAR_SPEED_PRTDSI__OUT_SEL1       (* (reg8 *) CAR_SPEED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CAR_SPEED_PRTDSI__SYNC_OUT       (* (reg8 *) CAR_SPEED__PRTDSI__SYNC_OUT) 


#if defined(CAR_SPEED__INTSTAT)  /* Interrupt Registers */

    #define CAR_SPEED_INTSTAT                (* (reg8 *) CAR_SPEED__INTSTAT)
    #define CAR_SPEED_SNAP                   (* (reg8 *) CAR_SPEED__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CAR_SPEED_H */


/* [] END OF FILE */
