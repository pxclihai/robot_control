/*******************************************************************************
* File Name: SWITCH_1_HIGH.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SWITCH_1_HIGH.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SWITCH_1_HIGH__PORT == 15 && ((SWITCH_1_HIGH__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SWITCH_1_HIGH_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void SWITCH_1_HIGH_Write(uint8 value) 
{
    uint8 staticBits = (SWITCH_1_HIGH_DR & (uint8)(~SWITCH_1_HIGH_MASK));
    SWITCH_1_HIGH_DR = staticBits | ((uint8)(value << SWITCH_1_HIGH_SHIFT) & SWITCH_1_HIGH_MASK);
}


/*******************************************************************************
* Function Name: SWITCH_1_HIGH_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SWITCH_1_HIGH_DM_STRONG     Strong Drive 
*  SWITCH_1_HIGH_DM_OD_HI      Open Drain, Drives High 
*  SWITCH_1_HIGH_DM_OD_LO      Open Drain, Drives Low 
*  SWITCH_1_HIGH_DM_RES_UP     Resistive Pull Up 
*  SWITCH_1_HIGH_DM_RES_DWN    Resistive Pull Down 
*  SWITCH_1_HIGH_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SWITCH_1_HIGH_DM_DIG_HIZ    High Impedance Digital 
*  SWITCH_1_HIGH_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SWITCH_1_HIGH_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SWITCH_1_HIGH_0, mode);
}


/*******************************************************************************
* Function Name: SWITCH_1_HIGH_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro SWITCH_1_HIGH_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SWITCH_1_HIGH_Read(void) 
{
    return (SWITCH_1_HIGH_PS & SWITCH_1_HIGH_MASK) >> SWITCH_1_HIGH_SHIFT;
}


/*******************************************************************************
* Function Name: SWITCH_1_HIGH_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 SWITCH_1_HIGH_ReadDataReg(void) 
{
    return (SWITCH_1_HIGH_DR & SWITCH_1_HIGH_MASK) >> SWITCH_1_HIGH_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SWITCH_1_HIGH_INTSTAT) 

    /*******************************************************************************
    * Function Name: SWITCH_1_HIGH_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 SWITCH_1_HIGH_ClearInterrupt(void) 
    {
        return (SWITCH_1_HIGH_INTSTAT & SWITCH_1_HIGH_MASK) >> SWITCH_1_HIGH_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
