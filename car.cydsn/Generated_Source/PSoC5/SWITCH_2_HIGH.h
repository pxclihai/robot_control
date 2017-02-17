/*******************************************************************************
* File Name: SWITCH_2_HIGH.h  
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

#if !defined(CY_PINS_SWITCH_2_HIGH_H) /* Pins SWITCH_2_HIGH_H */
#define CY_PINS_SWITCH_2_HIGH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SWITCH_2_HIGH_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SWITCH_2_HIGH__PORT == 15 && ((SWITCH_2_HIGH__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SWITCH_2_HIGH_Write(uint8 value) ;
void    SWITCH_2_HIGH_SetDriveMode(uint8 mode) ;
uint8   SWITCH_2_HIGH_ReadDataReg(void) ;
uint8   SWITCH_2_HIGH_Read(void) ;
uint8   SWITCH_2_HIGH_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SWITCH_2_HIGH_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SWITCH_2_HIGH_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SWITCH_2_HIGH_DM_RES_UP          PIN_DM_RES_UP
#define SWITCH_2_HIGH_DM_RES_DWN         PIN_DM_RES_DWN
#define SWITCH_2_HIGH_DM_OD_LO           PIN_DM_OD_LO
#define SWITCH_2_HIGH_DM_OD_HI           PIN_DM_OD_HI
#define SWITCH_2_HIGH_DM_STRONG          PIN_DM_STRONG
#define SWITCH_2_HIGH_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SWITCH_2_HIGH_MASK               SWITCH_2_HIGH__MASK
#define SWITCH_2_HIGH_SHIFT              SWITCH_2_HIGH__SHIFT
#define SWITCH_2_HIGH_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SWITCH_2_HIGH_PS                     (* (reg8 *) SWITCH_2_HIGH__PS)
/* Data Register */
#define SWITCH_2_HIGH_DR                     (* (reg8 *) SWITCH_2_HIGH__DR)
/* Port Number */
#define SWITCH_2_HIGH_PRT_NUM                (* (reg8 *) SWITCH_2_HIGH__PRT) 
/* Connect to Analog Globals */                                                  
#define SWITCH_2_HIGH_AG                     (* (reg8 *) SWITCH_2_HIGH__AG)                       
/* Analog MUX bux enable */
#define SWITCH_2_HIGH_AMUX                   (* (reg8 *) SWITCH_2_HIGH__AMUX) 
/* Bidirectional Enable */                                                        
#define SWITCH_2_HIGH_BIE                    (* (reg8 *) SWITCH_2_HIGH__BIE)
/* Bit-mask for Aliased Register Access */
#define SWITCH_2_HIGH_BIT_MASK               (* (reg8 *) SWITCH_2_HIGH__BIT_MASK)
/* Bypass Enable */
#define SWITCH_2_HIGH_BYP                    (* (reg8 *) SWITCH_2_HIGH__BYP)
/* Port wide control signals */                                                   
#define SWITCH_2_HIGH_CTL                    (* (reg8 *) SWITCH_2_HIGH__CTL)
/* Drive Modes */
#define SWITCH_2_HIGH_DM0                    (* (reg8 *) SWITCH_2_HIGH__DM0) 
#define SWITCH_2_HIGH_DM1                    (* (reg8 *) SWITCH_2_HIGH__DM1)
#define SWITCH_2_HIGH_DM2                    (* (reg8 *) SWITCH_2_HIGH__DM2) 
/* Input Buffer Disable Override */
#define SWITCH_2_HIGH_INP_DIS                (* (reg8 *) SWITCH_2_HIGH__INP_DIS)
/* LCD Common or Segment Drive */
#define SWITCH_2_HIGH_LCD_COM_SEG            (* (reg8 *) SWITCH_2_HIGH__LCD_COM_SEG)
/* Enable Segment LCD */
#define SWITCH_2_HIGH_LCD_EN                 (* (reg8 *) SWITCH_2_HIGH__LCD_EN)
/* Slew Rate Control */
#define SWITCH_2_HIGH_SLW                    (* (reg8 *) SWITCH_2_HIGH__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SWITCH_2_HIGH_PRTDSI__CAPS_SEL       (* (reg8 *) SWITCH_2_HIGH__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SWITCH_2_HIGH_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SWITCH_2_HIGH__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SWITCH_2_HIGH_PRTDSI__OE_SEL0        (* (reg8 *) SWITCH_2_HIGH__PRTDSI__OE_SEL0) 
#define SWITCH_2_HIGH_PRTDSI__OE_SEL1        (* (reg8 *) SWITCH_2_HIGH__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SWITCH_2_HIGH_PRTDSI__OUT_SEL0       (* (reg8 *) SWITCH_2_HIGH__PRTDSI__OUT_SEL0) 
#define SWITCH_2_HIGH_PRTDSI__OUT_SEL1       (* (reg8 *) SWITCH_2_HIGH__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SWITCH_2_HIGH_PRTDSI__SYNC_OUT       (* (reg8 *) SWITCH_2_HIGH__PRTDSI__SYNC_OUT) 


#if defined(SWITCH_2_HIGH__INTSTAT)  /* Interrupt Registers */

    #define SWITCH_2_HIGH_INTSTAT                (* (reg8 *) SWITCH_2_HIGH__INTSTAT)
    #define SWITCH_2_HIGH_SNAP                   (* (reg8 *) SWITCH_2_HIGH__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SWITCH_2_HIGH_H */


/* [] END OF FILE */
