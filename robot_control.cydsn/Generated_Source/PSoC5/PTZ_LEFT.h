/*******************************************************************************
* File Name: PTZ_LEFT.h  
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

#if !defined(CY_PINS_PTZ_LEFT_H) /* Pins PTZ_LEFT_H */
#define CY_PINS_PTZ_LEFT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PTZ_LEFT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PTZ_LEFT__PORT == 15 && ((PTZ_LEFT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PTZ_LEFT_Write(uint8 value) ;
void    PTZ_LEFT_SetDriveMode(uint8 mode) ;
uint8   PTZ_LEFT_ReadDataReg(void) ;
uint8   PTZ_LEFT_Read(void) ;
uint8   PTZ_LEFT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PTZ_LEFT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PTZ_LEFT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PTZ_LEFT_DM_RES_UP          PIN_DM_RES_UP
#define PTZ_LEFT_DM_RES_DWN         PIN_DM_RES_DWN
#define PTZ_LEFT_DM_OD_LO           PIN_DM_OD_LO
#define PTZ_LEFT_DM_OD_HI           PIN_DM_OD_HI
#define PTZ_LEFT_DM_STRONG          PIN_DM_STRONG
#define PTZ_LEFT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PTZ_LEFT_MASK               PTZ_LEFT__MASK
#define PTZ_LEFT_SHIFT              PTZ_LEFT__SHIFT
#define PTZ_LEFT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PTZ_LEFT_PS                     (* (reg8 *) PTZ_LEFT__PS)
/* Data Register */
#define PTZ_LEFT_DR                     (* (reg8 *) PTZ_LEFT__DR)
/* Port Number */
#define PTZ_LEFT_PRT_NUM                (* (reg8 *) PTZ_LEFT__PRT) 
/* Connect to Analog Globals */                                                  
#define PTZ_LEFT_AG                     (* (reg8 *) PTZ_LEFT__AG)                       
/* Analog MUX bux enable */
#define PTZ_LEFT_AMUX                   (* (reg8 *) PTZ_LEFT__AMUX) 
/* Bidirectional Enable */                                                        
#define PTZ_LEFT_BIE                    (* (reg8 *) PTZ_LEFT__BIE)
/* Bit-mask for Aliased Register Access */
#define PTZ_LEFT_BIT_MASK               (* (reg8 *) PTZ_LEFT__BIT_MASK)
/* Bypass Enable */
#define PTZ_LEFT_BYP                    (* (reg8 *) PTZ_LEFT__BYP)
/* Port wide control signals */                                                   
#define PTZ_LEFT_CTL                    (* (reg8 *) PTZ_LEFT__CTL)
/* Drive Modes */
#define PTZ_LEFT_DM0                    (* (reg8 *) PTZ_LEFT__DM0) 
#define PTZ_LEFT_DM1                    (* (reg8 *) PTZ_LEFT__DM1)
#define PTZ_LEFT_DM2                    (* (reg8 *) PTZ_LEFT__DM2) 
/* Input Buffer Disable Override */
#define PTZ_LEFT_INP_DIS                (* (reg8 *) PTZ_LEFT__INP_DIS)
/* LCD Common or Segment Drive */
#define PTZ_LEFT_LCD_COM_SEG            (* (reg8 *) PTZ_LEFT__LCD_COM_SEG)
/* Enable Segment LCD */
#define PTZ_LEFT_LCD_EN                 (* (reg8 *) PTZ_LEFT__LCD_EN)
/* Slew Rate Control */
#define PTZ_LEFT_SLW                    (* (reg8 *) PTZ_LEFT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PTZ_LEFT_PRTDSI__CAPS_SEL       (* (reg8 *) PTZ_LEFT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PTZ_LEFT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PTZ_LEFT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PTZ_LEFT_PRTDSI__OE_SEL0        (* (reg8 *) PTZ_LEFT__PRTDSI__OE_SEL0) 
#define PTZ_LEFT_PRTDSI__OE_SEL1        (* (reg8 *) PTZ_LEFT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PTZ_LEFT_PRTDSI__OUT_SEL0       (* (reg8 *) PTZ_LEFT__PRTDSI__OUT_SEL0) 
#define PTZ_LEFT_PRTDSI__OUT_SEL1       (* (reg8 *) PTZ_LEFT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PTZ_LEFT_PRTDSI__SYNC_OUT       (* (reg8 *) PTZ_LEFT__PRTDSI__SYNC_OUT) 


#if defined(PTZ_LEFT__INTSTAT)  /* Interrupt Registers */

    #define PTZ_LEFT_INTSTAT                (* (reg8 *) PTZ_LEFT__INTSTAT)
    #define PTZ_LEFT_SNAP                   (* (reg8 *) PTZ_LEFT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PTZ_LEFT_H */


/* [] END OF FILE */
