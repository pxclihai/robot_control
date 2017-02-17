/*******************************************************************************
* File Name: STR2.h  
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

#if !defined(CY_PINS_STR2_H) /* Pins STR2_H */
#define CY_PINS_STR2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "STR2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 STR2__PORT == 15 && ((STR2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    STR2_Write(uint8 value) ;
void    STR2_SetDriveMode(uint8 mode) ;
uint8   STR2_ReadDataReg(void) ;
uint8   STR2_Read(void) ;
uint8   STR2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define STR2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define STR2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define STR2_DM_RES_UP          PIN_DM_RES_UP
#define STR2_DM_RES_DWN         PIN_DM_RES_DWN
#define STR2_DM_OD_LO           PIN_DM_OD_LO
#define STR2_DM_OD_HI           PIN_DM_OD_HI
#define STR2_DM_STRONG          PIN_DM_STRONG
#define STR2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define STR2_MASK               STR2__MASK
#define STR2_SHIFT              STR2__SHIFT
#define STR2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define STR2_PS                     (* (reg8 *) STR2__PS)
/* Data Register */
#define STR2_DR                     (* (reg8 *) STR2__DR)
/* Port Number */
#define STR2_PRT_NUM                (* (reg8 *) STR2__PRT) 
/* Connect to Analog Globals */                                                  
#define STR2_AG                     (* (reg8 *) STR2__AG)                       
/* Analog MUX bux enable */
#define STR2_AMUX                   (* (reg8 *) STR2__AMUX) 
/* Bidirectional Enable */                                                        
#define STR2_BIE                    (* (reg8 *) STR2__BIE)
/* Bit-mask for Aliased Register Access */
#define STR2_BIT_MASK               (* (reg8 *) STR2__BIT_MASK)
/* Bypass Enable */
#define STR2_BYP                    (* (reg8 *) STR2__BYP)
/* Port wide control signals */                                                   
#define STR2_CTL                    (* (reg8 *) STR2__CTL)
/* Drive Modes */
#define STR2_DM0                    (* (reg8 *) STR2__DM0) 
#define STR2_DM1                    (* (reg8 *) STR2__DM1)
#define STR2_DM2                    (* (reg8 *) STR2__DM2) 
/* Input Buffer Disable Override */
#define STR2_INP_DIS                (* (reg8 *) STR2__INP_DIS)
/* LCD Common or Segment Drive */
#define STR2_LCD_COM_SEG            (* (reg8 *) STR2__LCD_COM_SEG)
/* Enable Segment LCD */
#define STR2_LCD_EN                 (* (reg8 *) STR2__LCD_EN)
/* Slew Rate Control */
#define STR2_SLW                    (* (reg8 *) STR2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define STR2_PRTDSI__CAPS_SEL       (* (reg8 *) STR2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define STR2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) STR2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define STR2_PRTDSI__OE_SEL0        (* (reg8 *) STR2__PRTDSI__OE_SEL0) 
#define STR2_PRTDSI__OE_SEL1        (* (reg8 *) STR2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define STR2_PRTDSI__OUT_SEL0       (* (reg8 *) STR2__PRTDSI__OUT_SEL0) 
#define STR2_PRTDSI__OUT_SEL1       (* (reg8 *) STR2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define STR2_PRTDSI__SYNC_OUT       (* (reg8 *) STR2__PRTDSI__SYNC_OUT) 


#if defined(STR2__INTSTAT)  /* Interrupt Registers */

    #define STR2_INTSTAT                (* (reg8 *) STR2__INTSTAT)
    #define STR2_SNAP                   (* (reg8 *) STR2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_STR2_H */


/* [] END OF FILE */
