/*******************************************************************************
* File Name: PTZ_X.h  
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

#if !defined(CY_PINS_PTZ_X_H) /* Pins PTZ_X_H */
#define CY_PINS_PTZ_X_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PTZ_X_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PTZ_X__PORT == 15 && ((PTZ_X__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PTZ_X_Write(uint8 value) ;
void    PTZ_X_SetDriveMode(uint8 mode) ;
uint8   PTZ_X_ReadDataReg(void) ;
uint8   PTZ_X_Read(void) ;
uint8   PTZ_X_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PTZ_X_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PTZ_X_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PTZ_X_DM_RES_UP          PIN_DM_RES_UP
#define PTZ_X_DM_RES_DWN         PIN_DM_RES_DWN
#define PTZ_X_DM_OD_LO           PIN_DM_OD_LO
#define PTZ_X_DM_OD_HI           PIN_DM_OD_HI
#define PTZ_X_DM_STRONG          PIN_DM_STRONG
#define PTZ_X_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PTZ_X_MASK               PTZ_X__MASK
#define PTZ_X_SHIFT              PTZ_X__SHIFT
#define PTZ_X_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PTZ_X_PS                     (* (reg8 *) PTZ_X__PS)
/* Data Register */
#define PTZ_X_DR                     (* (reg8 *) PTZ_X__DR)
/* Port Number */
#define PTZ_X_PRT_NUM                (* (reg8 *) PTZ_X__PRT) 
/* Connect to Analog Globals */                                                  
#define PTZ_X_AG                     (* (reg8 *) PTZ_X__AG)                       
/* Analog MUX bux enable */
#define PTZ_X_AMUX                   (* (reg8 *) PTZ_X__AMUX) 
/* Bidirectional Enable */                                                        
#define PTZ_X_BIE                    (* (reg8 *) PTZ_X__BIE)
/* Bit-mask for Aliased Register Access */
#define PTZ_X_BIT_MASK               (* (reg8 *) PTZ_X__BIT_MASK)
/* Bypass Enable */
#define PTZ_X_BYP                    (* (reg8 *) PTZ_X__BYP)
/* Port wide control signals */                                                   
#define PTZ_X_CTL                    (* (reg8 *) PTZ_X__CTL)
/* Drive Modes */
#define PTZ_X_DM0                    (* (reg8 *) PTZ_X__DM0) 
#define PTZ_X_DM1                    (* (reg8 *) PTZ_X__DM1)
#define PTZ_X_DM2                    (* (reg8 *) PTZ_X__DM2) 
/* Input Buffer Disable Override */
#define PTZ_X_INP_DIS                (* (reg8 *) PTZ_X__INP_DIS)
/* LCD Common or Segment Drive */
#define PTZ_X_LCD_COM_SEG            (* (reg8 *) PTZ_X__LCD_COM_SEG)
/* Enable Segment LCD */
#define PTZ_X_LCD_EN                 (* (reg8 *) PTZ_X__LCD_EN)
/* Slew Rate Control */
#define PTZ_X_SLW                    (* (reg8 *) PTZ_X__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PTZ_X_PRTDSI__CAPS_SEL       (* (reg8 *) PTZ_X__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PTZ_X_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PTZ_X__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PTZ_X_PRTDSI__OE_SEL0        (* (reg8 *) PTZ_X__PRTDSI__OE_SEL0) 
#define PTZ_X_PRTDSI__OE_SEL1        (* (reg8 *) PTZ_X__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PTZ_X_PRTDSI__OUT_SEL0       (* (reg8 *) PTZ_X__PRTDSI__OUT_SEL0) 
#define PTZ_X_PRTDSI__OUT_SEL1       (* (reg8 *) PTZ_X__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PTZ_X_PRTDSI__SYNC_OUT       (* (reg8 *) PTZ_X__PRTDSI__SYNC_OUT) 


#if defined(PTZ_X__INTSTAT)  /* Interrupt Registers */

    #define PTZ_X_INTSTAT                (* (reg8 *) PTZ_X__INTSTAT)
    #define PTZ_X_SNAP                   (* (reg8 *) PTZ_X__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PTZ_X_H */


/* [] END OF FILE */
