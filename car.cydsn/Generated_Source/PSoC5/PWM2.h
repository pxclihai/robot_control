/*******************************************************************************
* File Name: PWM2.h  
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

#if !defined(CY_PINS_PWM2_H) /* Pins PWM2_H */
#define CY_PINS_PWM2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWM2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PWM2__PORT == 15 && ((PWM2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PWM2_Write(uint8 value) ;
void    PWM2_SetDriveMode(uint8 mode) ;
uint8   PWM2_ReadDataReg(void) ;
uint8   PWM2_Read(void) ;
uint8   PWM2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWM2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PWM2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PWM2_DM_RES_UP          PIN_DM_RES_UP
#define PWM2_DM_RES_DWN         PIN_DM_RES_DWN
#define PWM2_DM_OD_LO           PIN_DM_OD_LO
#define PWM2_DM_OD_HI           PIN_DM_OD_HI
#define PWM2_DM_STRONG          PIN_DM_STRONG
#define PWM2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PWM2_MASK               PWM2__MASK
#define PWM2_SHIFT              PWM2__SHIFT
#define PWM2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWM2_PS                     (* (reg8 *) PWM2__PS)
/* Data Register */
#define PWM2_DR                     (* (reg8 *) PWM2__DR)
/* Port Number */
#define PWM2_PRT_NUM                (* (reg8 *) PWM2__PRT) 
/* Connect to Analog Globals */                                                  
#define PWM2_AG                     (* (reg8 *) PWM2__AG)                       
/* Analog MUX bux enable */
#define PWM2_AMUX                   (* (reg8 *) PWM2__AMUX) 
/* Bidirectional Enable */                                                        
#define PWM2_BIE                    (* (reg8 *) PWM2__BIE)
/* Bit-mask for Aliased Register Access */
#define PWM2_BIT_MASK               (* (reg8 *) PWM2__BIT_MASK)
/* Bypass Enable */
#define PWM2_BYP                    (* (reg8 *) PWM2__BYP)
/* Port wide control signals */                                                   
#define PWM2_CTL                    (* (reg8 *) PWM2__CTL)
/* Drive Modes */
#define PWM2_DM0                    (* (reg8 *) PWM2__DM0) 
#define PWM2_DM1                    (* (reg8 *) PWM2__DM1)
#define PWM2_DM2                    (* (reg8 *) PWM2__DM2) 
/* Input Buffer Disable Override */
#define PWM2_INP_DIS                (* (reg8 *) PWM2__INP_DIS)
/* LCD Common or Segment Drive */
#define PWM2_LCD_COM_SEG            (* (reg8 *) PWM2__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWM2_LCD_EN                 (* (reg8 *) PWM2__LCD_EN)
/* Slew Rate Control */
#define PWM2_SLW                    (* (reg8 *) PWM2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWM2_PRTDSI__CAPS_SEL       (* (reg8 *) PWM2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWM2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWM2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWM2_PRTDSI__OE_SEL0        (* (reg8 *) PWM2__PRTDSI__OE_SEL0) 
#define PWM2_PRTDSI__OE_SEL1        (* (reg8 *) PWM2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWM2_PRTDSI__OUT_SEL0       (* (reg8 *) PWM2__PRTDSI__OUT_SEL0) 
#define PWM2_PRTDSI__OUT_SEL1       (* (reg8 *) PWM2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWM2_PRTDSI__SYNC_OUT       (* (reg8 *) PWM2__PRTDSI__SYNC_OUT) 


#if defined(PWM2__INTSTAT)  /* Interrupt Registers */

    #define PWM2_INTSTAT                (* (reg8 *) PWM2__INTSTAT)
    #define PWM2_SNAP                   (* (reg8 *) PWM2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PWM2_H */


/* [] END OF FILE */
