/*******************************************************************************
* File Name: MSR_LOW.h  
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

#if !defined(CY_PINS_MSR_LOW_H) /* Pins MSR_LOW_H */
#define CY_PINS_MSR_LOW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MSR_LOW_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MSR_LOW__PORT == 15 && ((MSR_LOW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MSR_LOW_Write(uint8 value) ;
void    MSR_LOW_SetDriveMode(uint8 mode) ;
uint8   MSR_LOW_ReadDataReg(void) ;
uint8   MSR_LOW_Read(void) ;
uint8   MSR_LOW_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MSR_LOW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MSR_LOW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MSR_LOW_DM_RES_UP          PIN_DM_RES_UP
#define MSR_LOW_DM_RES_DWN         PIN_DM_RES_DWN
#define MSR_LOW_DM_OD_LO           PIN_DM_OD_LO
#define MSR_LOW_DM_OD_HI           PIN_DM_OD_HI
#define MSR_LOW_DM_STRONG          PIN_DM_STRONG
#define MSR_LOW_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MSR_LOW_MASK               MSR_LOW__MASK
#define MSR_LOW_SHIFT              MSR_LOW__SHIFT
#define MSR_LOW_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MSR_LOW_PS                     (* (reg8 *) MSR_LOW__PS)
/* Data Register */
#define MSR_LOW_DR                     (* (reg8 *) MSR_LOW__DR)
/* Port Number */
#define MSR_LOW_PRT_NUM                (* (reg8 *) MSR_LOW__PRT) 
/* Connect to Analog Globals */                                                  
#define MSR_LOW_AG                     (* (reg8 *) MSR_LOW__AG)                       
/* Analog MUX bux enable */
#define MSR_LOW_AMUX                   (* (reg8 *) MSR_LOW__AMUX) 
/* Bidirectional Enable */                                                        
#define MSR_LOW_BIE                    (* (reg8 *) MSR_LOW__BIE)
/* Bit-mask for Aliased Register Access */
#define MSR_LOW_BIT_MASK               (* (reg8 *) MSR_LOW__BIT_MASK)
/* Bypass Enable */
#define MSR_LOW_BYP                    (* (reg8 *) MSR_LOW__BYP)
/* Port wide control signals */                                                   
#define MSR_LOW_CTL                    (* (reg8 *) MSR_LOW__CTL)
/* Drive Modes */
#define MSR_LOW_DM0                    (* (reg8 *) MSR_LOW__DM0) 
#define MSR_LOW_DM1                    (* (reg8 *) MSR_LOW__DM1)
#define MSR_LOW_DM2                    (* (reg8 *) MSR_LOW__DM2) 
/* Input Buffer Disable Override */
#define MSR_LOW_INP_DIS                (* (reg8 *) MSR_LOW__INP_DIS)
/* LCD Common or Segment Drive */
#define MSR_LOW_LCD_COM_SEG            (* (reg8 *) MSR_LOW__LCD_COM_SEG)
/* Enable Segment LCD */
#define MSR_LOW_LCD_EN                 (* (reg8 *) MSR_LOW__LCD_EN)
/* Slew Rate Control */
#define MSR_LOW_SLW                    (* (reg8 *) MSR_LOW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MSR_LOW_PRTDSI__CAPS_SEL       (* (reg8 *) MSR_LOW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MSR_LOW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MSR_LOW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MSR_LOW_PRTDSI__OE_SEL0        (* (reg8 *) MSR_LOW__PRTDSI__OE_SEL0) 
#define MSR_LOW_PRTDSI__OE_SEL1        (* (reg8 *) MSR_LOW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MSR_LOW_PRTDSI__OUT_SEL0       (* (reg8 *) MSR_LOW__PRTDSI__OUT_SEL0) 
#define MSR_LOW_PRTDSI__OUT_SEL1       (* (reg8 *) MSR_LOW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MSR_LOW_PRTDSI__SYNC_OUT       (* (reg8 *) MSR_LOW__PRTDSI__SYNC_OUT) 


#if defined(MSR_LOW__INTSTAT)  /* Interrupt Registers */

    #define MSR_LOW_INTSTAT                (* (reg8 *) MSR_LOW__INTSTAT)
    #define MSR_LOW_SNAP                   (* (reg8 *) MSR_LOW__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MSR_LOW_H */


/* [] END OF FILE */
