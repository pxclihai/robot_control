/*******************************************************************************
* File Name: Beep.c  
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
#include "Beep.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Beep__PORT == 15 && ((Beep__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Beep_Write
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
void Beep_Write(uint8 value) 
{
    uint8 staticBits = (Beep_DR & (uint8)(~Beep_MASK));
    Beep_DR = staticBits | ((uint8)(value << Beep_SHIFT) & Beep_MASK);
}


/*******************************************************************************
* Function Name: Beep_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Beep_DM_STRONG     Strong Drive 
*  Beep_DM_OD_HI      Open Drain, Drives High 
*  Beep_DM_OD_LO      Open Drain, Drives Low 
*  Beep_DM_RES_UP     Resistive Pull Up 
*  Beep_DM_RES_DWN    Resistive Pull Down 
*  Beep_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Beep_DM_DIG_HIZ    High Impedance Digital 
*  Beep_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Beep_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Beep_0, mode);
}


/*******************************************************************************
* Function Name: Beep_Read
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
*  Macro Beep_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Beep_Read(void) 
{
    return (Beep_PS & Beep_MASK) >> Beep_SHIFT;
}


/*******************************************************************************
* Function Name: Beep_ReadDataReg
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
uint8 Beep_ReadDataReg(void) 
{
    return (Beep_DR & Beep_MASK) >> Beep_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Beep_INTSTAT) 

    /*******************************************************************************
    * Function Name: Beep_ClearInterrupt
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
    uint8 Beep_ClearInterrupt(void) 
    {
        return (Beep_INTSTAT & Beep_MASK) >> Beep_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
