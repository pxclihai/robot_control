/*******************************************************************************
* File Name: KEY_UP.h  
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

#if !defined(CY_PINS_KEY_UP_H) /* Pins KEY_UP_H */
#define CY_PINS_KEY_UP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KEY_UP_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KEY_UP__PORT == 15 && ((KEY_UP__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    KEY_UP_Write(uint8 value) ;
void    KEY_UP_SetDriveMode(uint8 mode) ;
uint8   KEY_UP_ReadDataReg(void) ;
uint8   KEY_UP_Read(void) ;
uint8   KEY_UP_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KEY_UP_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define KEY_UP_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define KEY_UP_DM_RES_UP          PIN_DM_RES_UP
#define KEY_UP_DM_RES_DWN         PIN_DM_RES_DWN
#define KEY_UP_DM_OD_LO           PIN_DM_OD_LO
#define KEY_UP_DM_OD_HI           PIN_DM_OD_HI
#define KEY_UP_DM_STRONG          PIN_DM_STRONG
#define KEY_UP_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define KEY_UP_MASK               KEY_UP__MASK
#define KEY_UP_SHIFT              KEY_UP__SHIFT
#define KEY_UP_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KEY_UP_PS                     (* (reg8 *) KEY_UP__PS)
/* Data Register */
#define KEY_UP_DR                     (* (reg8 *) KEY_UP__DR)
/* Port Number */
#define KEY_UP_PRT_NUM                (* (reg8 *) KEY_UP__PRT) 
/* Connect to Analog Globals */                                                  
#define KEY_UP_AG                     (* (reg8 *) KEY_UP__AG)                       
/* Analog MUX bux enable */
#define KEY_UP_AMUX                   (* (reg8 *) KEY_UP__AMUX) 
/* Bidirectional Enable */                                                        
#define KEY_UP_BIE                    (* (reg8 *) KEY_UP__BIE)
/* Bit-mask for Aliased Register Access */
#define KEY_UP_BIT_MASK               (* (reg8 *) KEY_UP__BIT_MASK)
/* Bypass Enable */
#define KEY_UP_BYP                    (* (reg8 *) KEY_UP__BYP)
/* Port wide control signals */                                                   
#define KEY_UP_CTL                    (* (reg8 *) KEY_UP__CTL)
/* Drive Modes */
#define KEY_UP_DM0                    (* (reg8 *) KEY_UP__DM0) 
#define KEY_UP_DM1                    (* (reg8 *) KEY_UP__DM1)
#define KEY_UP_DM2                    (* (reg8 *) KEY_UP__DM2) 
/* Input Buffer Disable Override */
#define KEY_UP_INP_DIS                (* (reg8 *) KEY_UP__INP_DIS)
/* LCD Common or Segment Drive */
#define KEY_UP_LCD_COM_SEG            (* (reg8 *) KEY_UP__LCD_COM_SEG)
/* Enable Segment LCD */
#define KEY_UP_LCD_EN                 (* (reg8 *) KEY_UP__LCD_EN)
/* Slew Rate Control */
#define KEY_UP_SLW                    (* (reg8 *) KEY_UP__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KEY_UP_PRTDSI__CAPS_SEL       (* (reg8 *) KEY_UP__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KEY_UP_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KEY_UP__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KEY_UP_PRTDSI__OE_SEL0        (* (reg8 *) KEY_UP__PRTDSI__OE_SEL0) 
#define KEY_UP_PRTDSI__OE_SEL1        (* (reg8 *) KEY_UP__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KEY_UP_PRTDSI__OUT_SEL0       (* (reg8 *) KEY_UP__PRTDSI__OUT_SEL0) 
#define KEY_UP_PRTDSI__OUT_SEL1       (* (reg8 *) KEY_UP__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KEY_UP_PRTDSI__SYNC_OUT       (* (reg8 *) KEY_UP__PRTDSI__SYNC_OUT) 


#if defined(KEY_UP__INTSTAT)  /* Interrupt Registers */

    #define KEY_UP_INTSTAT                (* (reg8 *) KEY_UP__INTSTAT)
    #define KEY_UP_SNAP                   (* (reg8 *) KEY_UP__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KEY_UP_H */


/* [] END OF FILE */
