/*******************************************************************************
* File Name: BATTERY.h  
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

#if !defined(CY_PINS_BATTERY_H) /* Pins BATTERY_H */
#define CY_PINS_BATTERY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BATTERY_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BATTERY__PORT == 15 && ((BATTERY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    BATTERY_Write(uint8 value) ;
void    BATTERY_SetDriveMode(uint8 mode) ;
uint8   BATTERY_ReadDataReg(void) ;
uint8   BATTERY_Read(void) ;
uint8   BATTERY_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define BATTERY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define BATTERY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define BATTERY_DM_RES_UP          PIN_DM_RES_UP
#define BATTERY_DM_RES_DWN         PIN_DM_RES_DWN
#define BATTERY_DM_OD_LO           PIN_DM_OD_LO
#define BATTERY_DM_OD_HI           PIN_DM_OD_HI
#define BATTERY_DM_STRONG          PIN_DM_STRONG
#define BATTERY_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define BATTERY_MASK               BATTERY__MASK
#define BATTERY_SHIFT              BATTERY__SHIFT
#define BATTERY_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BATTERY_PS                     (* (reg8 *) BATTERY__PS)
/* Data Register */
#define BATTERY_DR                     (* (reg8 *) BATTERY__DR)
/* Port Number */
#define BATTERY_PRT_NUM                (* (reg8 *) BATTERY__PRT) 
/* Connect to Analog Globals */                                                  
#define BATTERY_AG                     (* (reg8 *) BATTERY__AG)                       
/* Analog MUX bux enable */
#define BATTERY_AMUX                   (* (reg8 *) BATTERY__AMUX) 
/* Bidirectional Enable */                                                        
#define BATTERY_BIE                    (* (reg8 *) BATTERY__BIE)
/* Bit-mask for Aliased Register Access */
#define BATTERY_BIT_MASK               (* (reg8 *) BATTERY__BIT_MASK)
/* Bypass Enable */
#define BATTERY_BYP                    (* (reg8 *) BATTERY__BYP)
/* Port wide control signals */                                                   
#define BATTERY_CTL                    (* (reg8 *) BATTERY__CTL)
/* Drive Modes */
#define BATTERY_DM0                    (* (reg8 *) BATTERY__DM0) 
#define BATTERY_DM1                    (* (reg8 *) BATTERY__DM1)
#define BATTERY_DM2                    (* (reg8 *) BATTERY__DM2) 
/* Input Buffer Disable Override */
#define BATTERY_INP_DIS                (* (reg8 *) BATTERY__INP_DIS)
/* LCD Common or Segment Drive */
#define BATTERY_LCD_COM_SEG            (* (reg8 *) BATTERY__LCD_COM_SEG)
/* Enable Segment LCD */
#define BATTERY_LCD_EN                 (* (reg8 *) BATTERY__LCD_EN)
/* Slew Rate Control */
#define BATTERY_SLW                    (* (reg8 *) BATTERY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BATTERY_PRTDSI__CAPS_SEL       (* (reg8 *) BATTERY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BATTERY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BATTERY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BATTERY_PRTDSI__OE_SEL0        (* (reg8 *) BATTERY__PRTDSI__OE_SEL0) 
#define BATTERY_PRTDSI__OE_SEL1        (* (reg8 *) BATTERY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BATTERY_PRTDSI__OUT_SEL0       (* (reg8 *) BATTERY__PRTDSI__OUT_SEL0) 
#define BATTERY_PRTDSI__OUT_SEL1       (* (reg8 *) BATTERY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BATTERY_PRTDSI__SYNC_OUT       (* (reg8 *) BATTERY__PRTDSI__SYNC_OUT) 


#if defined(BATTERY__INTSTAT)  /* Interrupt Registers */

    #define BATTERY_INTSTAT                (* (reg8 *) BATTERY__INTSTAT)
    #define BATTERY_SNAP                   (* (reg8 *) BATTERY__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BATTERY_H */


/* [] END OF FILE */
