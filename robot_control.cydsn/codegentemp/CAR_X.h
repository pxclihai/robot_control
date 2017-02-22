/*******************************************************************************
* File Name: CAR_X.h  
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

#if !defined(CY_PINS_CAR_X_H) /* Pins CAR_X_H */
#define CY_PINS_CAR_X_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CAR_X_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CAR_X__PORT == 15 && ((CAR_X__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CAR_X_Write(uint8 value) ;
void    CAR_X_SetDriveMode(uint8 mode) ;
uint8   CAR_X_ReadDataReg(void) ;
uint8   CAR_X_Read(void) ;
uint8   CAR_X_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CAR_X_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CAR_X_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CAR_X_DM_RES_UP          PIN_DM_RES_UP
#define CAR_X_DM_RES_DWN         PIN_DM_RES_DWN
#define CAR_X_DM_OD_LO           PIN_DM_OD_LO
#define CAR_X_DM_OD_HI           PIN_DM_OD_HI
#define CAR_X_DM_STRONG          PIN_DM_STRONG
#define CAR_X_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CAR_X_MASK               CAR_X__MASK
#define CAR_X_SHIFT              CAR_X__SHIFT
#define CAR_X_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CAR_X_PS                     (* (reg8 *) CAR_X__PS)
/* Data Register */
#define CAR_X_DR                     (* (reg8 *) CAR_X__DR)
/* Port Number */
#define CAR_X_PRT_NUM                (* (reg8 *) CAR_X__PRT) 
/* Connect to Analog Globals */                                                  
#define CAR_X_AG                     (* (reg8 *) CAR_X__AG)                       
/* Analog MUX bux enable */
#define CAR_X_AMUX                   (* (reg8 *) CAR_X__AMUX) 
/* Bidirectional Enable */                                                        
#define CAR_X_BIE                    (* (reg8 *) CAR_X__BIE)
/* Bit-mask for Aliased Register Access */
#define CAR_X_BIT_MASK               (* (reg8 *) CAR_X__BIT_MASK)
/* Bypass Enable */
#define CAR_X_BYP                    (* (reg8 *) CAR_X__BYP)
/* Port wide control signals */                                                   
#define CAR_X_CTL                    (* (reg8 *) CAR_X__CTL)
/* Drive Modes */
#define CAR_X_DM0                    (* (reg8 *) CAR_X__DM0) 
#define CAR_X_DM1                    (* (reg8 *) CAR_X__DM1)
#define CAR_X_DM2                    (* (reg8 *) CAR_X__DM2) 
/* Input Buffer Disable Override */
#define CAR_X_INP_DIS                (* (reg8 *) CAR_X__INP_DIS)
/* LCD Common or Segment Drive */
#define CAR_X_LCD_COM_SEG            (* (reg8 *) CAR_X__LCD_COM_SEG)
/* Enable Segment LCD */
#define CAR_X_LCD_EN                 (* (reg8 *) CAR_X__LCD_EN)
/* Slew Rate Control */
#define CAR_X_SLW                    (* (reg8 *) CAR_X__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CAR_X_PRTDSI__CAPS_SEL       (* (reg8 *) CAR_X__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CAR_X_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CAR_X__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CAR_X_PRTDSI__OE_SEL0        (* (reg8 *) CAR_X__PRTDSI__OE_SEL0) 
#define CAR_X_PRTDSI__OE_SEL1        (* (reg8 *) CAR_X__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CAR_X_PRTDSI__OUT_SEL0       (* (reg8 *) CAR_X__PRTDSI__OUT_SEL0) 
#define CAR_X_PRTDSI__OUT_SEL1       (* (reg8 *) CAR_X__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CAR_X_PRTDSI__SYNC_OUT       (* (reg8 *) CAR_X__PRTDSI__SYNC_OUT) 


#if defined(CAR_X__INTSTAT)  /* Interrupt Registers */

    #define CAR_X_INTSTAT                (* (reg8 *) CAR_X__INTSTAT)
    #define CAR_X_SNAP                   (* (reg8 *) CAR_X__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CAR_X_H */


/* [] END OF FILE */
