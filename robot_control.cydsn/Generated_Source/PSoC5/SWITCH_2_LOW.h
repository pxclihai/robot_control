/*******************************************************************************
* File Name: SWITCH_2_LOW.h  
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

#if !defined(CY_PINS_SWITCH_2_LOW_H) /* Pins SWITCH_2_LOW_H */
#define CY_PINS_SWITCH_2_LOW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SWITCH_2_LOW_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SWITCH_2_LOW__PORT == 15 && ((SWITCH_2_LOW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SWITCH_2_LOW_Write(uint8 value) ;
void    SWITCH_2_LOW_SetDriveMode(uint8 mode) ;
uint8   SWITCH_2_LOW_ReadDataReg(void) ;
uint8   SWITCH_2_LOW_Read(void) ;
uint8   SWITCH_2_LOW_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SWITCH_2_LOW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SWITCH_2_LOW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SWITCH_2_LOW_DM_RES_UP          PIN_DM_RES_UP
#define SWITCH_2_LOW_DM_RES_DWN         PIN_DM_RES_DWN
#define SWITCH_2_LOW_DM_OD_LO           PIN_DM_OD_LO
#define SWITCH_2_LOW_DM_OD_HI           PIN_DM_OD_HI
#define SWITCH_2_LOW_DM_STRONG          PIN_DM_STRONG
#define SWITCH_2_LOW_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SWITCH_2_LOW_MASK               SWITCH_2_LOW__MASK
#define SWITCH_2_LOW_SHIFT              SWITCH_2_LOW__SHIFT
#define SWITCH_2_LOW_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SWITCH_2_LOW_PS                     (* (reg8 *) SWITCH_2_LOW__PS)
/* Data Register */
#define SWITCH_2_LOW_DR                     (* (reg8 *) SWITCH_2_LOW__DR)
/* Port Number */
#define SWITCH_2_LOW_PRT_NUM                (* (reg8 *) SWITCH_2_LOW__PRT) 
/* Connect to Analog Globals */                                                  
#define SWITCH_2_LOW_AG                     (* (reg8 *) SWITCH_2_LOW__AG)                       
/* Analog MUX bux enable */
#define SWITCH_2_LOW_AMUX                   (* (reg8 *) SWITCH_2_LOW__AMUX) 
/* Bidirectional Enable */                                                        
#define SWITCH_2_LOW_BIE                    (* (reg8 *) SWITCH_2_LOW__BIE)
/* Bit-mask for Aliased Register Access */
#define SWITCH_2_LOW_BIT_MASK               (* (reg8 *) SWITCH_2_LOW__BIT_MASK)
/* Bypass Enable */
#define SWITCH_2_LOW_BYP                    (* (reg8 *) SWITCH_2_LOW__BYP)
/* Port wide control signals */                                                   
#define SWITCH_2_LOW_CTL                    (* (reg8 *) SWITCH_2_LOW__CTL)
/* Drive Modes */
#define SWITCH_2_LOW_DM0                    (* (reg8 *) SWITCH_2_LOW__DM0) 
#define SWITCH_2_LOW_DM1                    (* (reg8 *) SWITCH_2_LOW__DM1)
#define SWITCH_2_LOW_DM2                    (* (reg8 *) SWITCH_2_LOW__DM2) 
/* Input Buffer Disable Override */
#define SWITCH_2_LOW_INP_DIS                (* (reg8 *) SWITCH_2_LOW__INP_DIS)
/* LCD Common or Segment Drive */
#define SWITCH_2_LOW_LCD_COM_SEG            (* (reg8 *) SWITCH_2_LOW__LCD_COM_SEG)
/* Enable Segment LCD */
#define SWITCH_2_LOW_LCD_EN                 (* (reg8 *) SWITCH_2_LOW__LCD_EN)
/* Slew Rate Control */
#define SWITCH_2_LOW_SLW                    (* (reg8 *) SWITCH_2_LOW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SWITCH_2_LOW_PRTDSI__CAPS_SEL       (* (reg8 *) SWITCH_2_LOW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SWITCH_2_LOW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SWITCH_2_LOW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SWITCH_2_LOW_PRTDSI__OE_SEL0        (* (reg8 *) SWITCH_2_LOW__PRTDSI__OE_SEL0) 
#define SWITCH_2_LOW_PRTDSI__OE_SEL1        (* (reg8 *) SWITCH_2_LOW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SWITCH_2_LOW_PRTDSI__OUT_SEL0       (* (reg8 *) SWITCH_2_LOW__PRTDSI__OUT_SEL0) 
#define SWITCH_2_LOW_PRTDSI__OUT_SEL1       (* (reg8 *) SWITCH_2_LOW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SWITCH_2_LOW_PRTDSI__SYNC_OUT       (* (reg8 *) SWITCH_2_LOW__PRTDSI__SYNC_OUT) 


#if defined(SWITCH_2_LOW__INTSTAT)  /* Interrupt Registers */

    #define SWITCH_2_LOW_INTSTAT                (* (reg8 *) SWITCH_2_LOW__INTSTAT)
    #define SWITCH_2_LOW_SNAP                   (* (reg8 *) SWITCH_2_LOW__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SWITCH_2_LOW_H */


/* [] END OF FILE */
