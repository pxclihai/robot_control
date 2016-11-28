/*******************************************************************************
* File Name: KEY_DOWN.h  
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

#if !defined(CY_PINS_KEY_DOWN_H) /* Pins KEY_DOWN_H */
#define CY_PINS_KEY_DOWN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KEY_DOWN_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KEY_DOWN__PORT == 15 && ((KEY_DOWN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    KEY_DOWN_Write(uint8 value) ;
void    KEY_DOWN_SetDriveMode(uint8 mode) ;
uint8   KEY_DOWN_ReadDataReg(void) ;
uint8   KEY_DOWN_Read(void) ;
uint8   KEY_DOWN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KEY_DOWN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define KEY_DOWN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define KEY_DOWN_DM_RES_UP          PIN_DM_RES_UP
#define KEY_DOWN_DM_RES_DWN         PIN_DM_RES_DWN
#define KEY_DOWN_DM_OD_LO           PIN_DM_OD_LO
#define KEY_DOWN_DM_OD_HI           PIN_DM_OD_HI
#define KEY_DOWN_DM_STRONG          PIN_DM_STRONG
#define KEY_DOWN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define KEY_DOWN_MASK               KEY_DOWN__MASK
#define KEY_DOWN_SHIFT              KEY_DOWN__SHIFT
#define KEY_DOWN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KEY_DOWN_PS                     (* (reg8 *) KEY_DOWN__PS)
/* Data Register */
#define KEY_DOWN_DR                     (* (reg8 *) KEY_DOWN__DR)
/* Port Number */
#define KEY_DOWN_PRT_NUM                (* (reg8 *) KEY_DOWN__PRT) 
/* Connect to Analog Globals */                                                  
#define KEY_DOWN_AG                     (* (reg8 *) KEY_DOWN__AG)                       
/* Analog MUX bux enable */
#define KEY_DOWN_AMUX                   (* (reg8 *) KEY_DOWN__AMUX) 
/* Bidirectional Enable */                                                        
#define KEY_DOWN_BIE                    (* (reg8 *) KEY_DOWN__BIE)
/* Bit-mask for Aliased Register Access */
#define KEY_DOWN_BIT_MASK               (* (reg8 *) KEY_DOWN__BIT_MASK)
/* Bypass Enable */
#define KEY_DOWN_BYP                    (* (reg8 *) KEY_DOWN__BYP)
/* Port wide control signals */                                                   
#define KEY_DOWN_CTL                    (* (reg8 *) KEY_DOWN__CTL)
/* Drive Modes */
#define KEY_DOWN_DM0                    (* (reg8 *) KEY_DOWN__DM0) 
#define KEY_DOWN_DM1                    (* (reg8 *) KEY_DOWN__DM1)
#define KEY_DOWN_DM2                    (* (reg8 *) KEY_DOWN__DM2) 
/* Input Buffer Disable Override */
#define KEY_DOWN_INP_DIS                (* (reg8 *) KEY_DOWN__INP_DIS)
/* LCD Common or Segment Drive */
#define KEY_DOWN_LCD_COM_SEG            (* (reg8 *) KEY_DOWN__LCD_COM_SEG)
/* Enable Segment LCD */
#define KEY_DOWN_LCD_EN                 (* (reg8 *) KEY_DOWN__LCD_EN)
/* Slew Rate Control */
#define KEY_DOWN_SLW                    (* (reg8 *) KEY_DOWN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KEY_DOWN_PRTDSI__CAPS_SEL       (* (reg8 *) KEY_DOWN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KEY_DOWN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KEY_DOWN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KEY_DOWN_PRTDSI__OE_SEL0        (* (reg8 *) KEY_DOWN__PRTDSI__OE_SEL0) 
#define KEY_DOWN_PRTDSI__OE_SEL1        (* (reg8 *) KEY_DOWN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KEY_DOWN_PRTDSI__OUT_SEL0       (* (reg8 *) KEY_DOWN__PRTDSI__OUT_SEL0) 
#define KEY_DOWN_PRTDSI__OUT_SEL1       (* (reg8 *) KEY_DOWN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KEY_DOWN_PRTDSI__SYNC_OUT       (* (reg8 *) KEY_DOWN__PRTDSI__SYNC_OUT) 


#if defined(KEY_DOWN__INTSTAT)  /* Interrupt Registers */

    #define KEY_DOWN_INTSTAT                (* (reg8 *) KEY_DOWN__INTSTAT)
    #define KEY_DOWN_SNAP                   (* (reg8 *) KEY_DOWN__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KEY_DOWN_H */


/* [] END OF FILE */
