/*******************************************************************************
* File Name: KEY_SPEED_LOW.h  
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

#if !defined(CY_PINS_KEY_SPEED_LOW_H) /* Pins KEY_SPEED_LOW_H */
#define CY_PINS_KEY_SPEED_LOW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KEY_SPEED_LOW_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KEY_SPEED_LOW__PORT == 15 && ((KEY_SPEED_LOW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    KEY_SPEED_LOW_Write(uint8 value) ;
void    KEY_SPEED_LOW_SetDriveMode(uint8 mode) ;
uint8   KEY_SPEED_LOW_ReadDataReg(void) ;
uint8   KEY_SPEED_LOW_Read(void) ;
uint8   KEY_SPEED_LOW_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KEY_SPEED_LOW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define KEY_SPEED_LOW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define KEY_SPEED_LOW_DM_RES_UP          PIN_DM_RES_UP
#define KEY_SPEED_LOW_DM_RES_DWN         PIN_DM_RES_DWN
#define KEY_SPEED_LOW_DM_OD_LO           PIN_DM_OD_LO
#define KEY_SPEED_LOW_DM_OD_HI           PIN_DM_OD_HI
#define KEY_SPEED_LOW_DM_STRONG          PIN_DM_STRONG
#define KEY_SPEED_LOW_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define KEY_SPEED_LOW_MASK               KEY_SPEED_LOW__MASK
#define KEY_SPEED_LOW_SHIFT              KEY_SPEED_LOW__SHIFT
#define KEY_SPEED_LOW_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KEY_SPEED_LOW_PS                     (* (reg8 *) KEY_SPEED_LOW__PS)
/* Data Register */
#define KEY_SPEED_LOW_DR                     (* (reg8 *) KEY_SPEED_LOW__DR)
/* Port Number */
#define KEY_SPEED_LOW_PRT_NUM                (* (reg8 *) KEY_SPEED_LOW__PRT) 
/* Connect to Analog Globals */                                                  
#define KEY_SPEED_LOW_AG                     (* (reg8 *) KEY_SPEED_LOW__AG)                       
/* Analog MUX bux enable */
#define KEY_SPEED_LOW_AMUX                   (* (reg8 *) KEY_SPEED_LOW__AMUX) 
/* Bidirectional Enable */                                                        
#define KEY_SPEED_LOW_BIE                    (* (reg8 *) KEY_SPEED_LOW__BIE)
/* Bit-mask for Aliased Register Access */
#define KEY_SPEED_LOW_BIT_MASK               (* (reg8 *) KEY_SPEED_LOW__BIT_MASK)
/* Bypass Enable */
#define KEY_SPEED_LOW_BYP                    (* (reg8 *) KEY_SPEED_LOW__BYP)
/* Port wide control signals */                                                   
#define KEY_SPEED_LOW_CTL                    (* (reg8 *) KEY_SPEED_LOW__CTL)
/* Drive Modes */
#define KEY_SPEED_LOW_DM0                    (* (reg8 *) KEY_SPEED_LOW__DM0) 
#define KEY_SPEED_LOW_DM1                    (* (reg8 *) KEY_SPEED_LOW__DM1)
#define KEY_SPEED_LOW_DM2                    (* (reg8 *) KEY_SPEED_LOW__DM2) 
/* Input Buffer Disable Override */
#define KEY_SPEED_LOW_INP_DIS                (* (reg8 *) KEY_SPEED_LOW__INP_DIS)
/* LCD Common or Segment Drive */
#define KEY_SPEED_LOW_LCD_COM_SEG            (* (reg8 *) KEY_SPEED_LOW__LCD_COM_SEG)
/* Enable Segment LCD */
#define KEY_SPEED_LOW_LCD_EN                 (* (reg8 *) KEY_SPEED_LOW__LCD_EN)
/* Slew Rate Control */
#define KEY_SPEED_LOW_SLW                    (* (reg8 *) KEY_SPEED_LOW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KEY_SPEED_LOW_PRTDSI__CAPS_SEL       (* (reg8 *) KEY_SPEED_LOW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KEY_SPEED_LOW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KEY_SPEED_LOW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KEY_SPEED_LOW_PRTDSI__OE_SEL0        (* (reg8 *) KEY_SPEED_LOW__PRTDSI__OE_SEL0) 
#define KEY_SPEED_LOW_PRTDSI__OE_SEL1        (* (reg8 *) KEY_SPEED_LOW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KEY_SPEED_LOW_PRTDSI__OUT_SEL0       (* (reg8 *) KEY_SPEED_LOW__PRTDSI__OUT_SEL0) 
#define KEY_SPEED_LOW_PRTDSI__OUT_SEL1       (* (reg8 *) KEY_SPEED_LOW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KEY_SPEED_LOW_PRTDSI__SYNC_OUT       (* (reg8 *) KEY_SPEED_LOW__PRTDSI__SYNC_OUT) 


#if defined(KEY_SPEED_LOW__INTSTAT)  /* Interrupt Registers */

    #define KEY_SPEED_LOW_INTSTAT                (* (reg8 *) KEY_SPEED_LOW__INTSTAT)
    #define KEY_SPEED_LOW_SNAP                   (* (reg8 *) KEY_SPEED_LOW__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KEY_SPEED_LOW_H */


/* [] END OF FILE */
