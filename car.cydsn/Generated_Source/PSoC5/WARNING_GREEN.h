/*******************************************************************************
* File Name: WARNING_GREEN.h  
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

#if !defined(CY_PINS_WARNING_GREEN_H) /* Pins WARNING_GREEN_H */
#define CY_PINS_WARNING_GREEN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "WARNING_GREEN_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 WARNING_GREEN__PORT == 15 && ((WARNING_GREEN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    WARNING_GREEN_Write(uint8 value) ;
void    WARNING_GREEN_SetDriveMode(uint8 mode) ;
uint8   WARNING_GREEN_ReadDataReg(void) ;
uint8   WARNING_GREEN_Read(void) ;
uint8   WARNING_GREEN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define WARNING_GREEN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define WARNING_GREEN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define WARNING_GREEN_DM_RES_UP          PIN_DM_RES_UP
#define WARNING_GREEN_DM_RES_DWN         PIN_DM_RES_DWN
#define WARNING_GREEN_DM_OD_LO           PIN_DM_OD_LO
#define WARNING_GREEN_DM_OD_HI           PIN_DM_OD_HI
#define WARNING_GREEN_DM_STRONG          PIN_DM_STRONG
#define WARNING_GREEN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define WARNING_GREEN_MASK               WARNING_GREEN__MASK
#define WARNING_GREEN_SHIFT              WARNING_GREEN__SHIFT
#define WARNING_GREEN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WARNING_GREEN_PS                     (* (reg8 *) WARNING_GREEN__PS)
/* Data Register */
#define WARNING_GREEN_DR                     (* (reg8 *) WARNING_GREEN__DR)
/* Port Number */
#define WARNING_GREEN_PRT_NUM                (* (reg8 *) WARNING_GREEN__PRT) 
/* Connect to Analog Globals */                                                  
#define WARNING_GREEN_AG                     (* (reg8 *) WARNING_GREEN__AG)                       
/* Analog MUX bux enable */
#define WARNING_GREEN_AMUX                   (* (reg8 *) WARNING_GREEN__AMUX) 
/* Bidirectional Enable */                                                        
#define WARNING_GREEN_BIE                    (* (reg8 *) WARNING_GREEN__BIE)
/* Bit-mask for Aliased Register Access */
#define WARNING_GREEN_BIT_MASK               (* (reg8 *) WARNING_GREEN__BIT_MASK)
/* Bypass Enable */
#define WARNING_GREEN_BYP                    (* (reg8 *) WARNING_GREEN__BYP)
/* Port wide control signals */                                                   
#define WARNING_GREEN_CTL                    (* (reg8 *) WARNING_GREEN__CTL)
/* Drive Modes */
#define WARNING_GREEN_DM0                    (* (reg8 *) WARNING_GREEN__DM0) 
#define WARNING_GREEN_DM1                    (* (reg8 *) WARNING_GREEN__DM1)
#define WARNING_GREEN_DM2                    (* (reg8 *) WARNING_GREEN__DM2) 
/* Input Buffer Disable Override */
#define WARNING_GREEN_INP_DIS                (* (reg8 *) WARNING_GREEN__INP_DIS)
/* LCD Common or Segment Drive */
#define WARNING_GREEN_LCD_COM_SEG            (* (reg8 *) WARNING_GREEN__LCD_COM_SEG)
/* Enable Segment LCD */
#define WARNING_GREEN_LCD_EN                 (* (reg8 *) WARNING_GREEN__LCD_EN)
/* Slew Rate Control */
#define WARNING_GREEN_SLW                    (* (reg8 *) WARNING_GREEN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define WARNING_GREEN_PRTDSI__CAPS_SEL       (* (reg8 *) WARNING_GREEN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define WARNING_GREEN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) WARNING_GREEN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define WARNING_GREEN_PRTDSI__OE_SEL0        (* (reg8 *) WARNING_GREEN__PRTDSI__OE_SEL0) 
#define WARNING_GREEN_PRTDSI__OE_SEL1        (* (reg8 *) WARNING_GREEN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define WARNING_GREEN_PRTDSI__OUT_SEL0       (* (reg8 *) WARNING_GREEN__PRTDSI__OUT_SEL0) 
#define WARNING_GREEN_PRTDSI__OUT_SEL1       (* (reg8 *) WARNING_GREEN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define WARNING_GREEN_PRTDSI__SYNC_OUT       (* (reg8 *) WARNING_GREEN__PRTDSI__SYNC_OUT) 


#if defined(WARNING_GREEN__INTSTAT)  /* Interrupt Registers */

    #define WARNING_GREEN_INTSTAT                (* (reg8 *) WARNING_GREEN__INTSTAT)
    #define WARNING_GREEN_SNAP                   (* (reg8 *) WARNING_GREEN__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_WARNING_GREEN_H */


/* [] END OF FILE */
