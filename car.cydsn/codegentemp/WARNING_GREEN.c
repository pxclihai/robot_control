/*******************************************************************************
* File Name: WARNING_GREEN.c  
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
#include "WARNING_GREEN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 WARNING_GREEN__PORT == 15 && ((WARNING_GREEN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: WARNING_GREEN_Write
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
void WARNING_GREEN_Write(uint8 value) 
{
    uint8 staticBits = (WARNING_GREEN_DR & (uint8)(~WARNING_GREEN_MASK));
    WARNING_GREEN_DR = staticBits | ((uint8)(value << WARNING_GREEN_SHIFT) & WARNING_GREEN_MASK);
}


/*******************************************************************************
* Function Name: WARNING_GREEN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  WARNING_GREEN_DM_STRONG     Strong Drive 
*  WARNING_GREEN_DM_OD_HI      Open Drain, Drives High 
*  WARNING_GREEN_DM_OD_LO      Open Drain, Drives Low 
*  WARNING_GREEN_DM_RES_UP     Resistive Pull Up 
*  WARNING_GREEN_DM_RES_DWN    Resistive Pull Down 
*  WARNING_GREEN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  WARNING_GREEN_DM_DIG_HIZ    High Impedance Digital 
*  WARNING_GREEN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void WARNING_GREEN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(WARNING_GREEN_0, mode);
}


/*******************************************************************************
* Function Name: WARNING_GREEN_Read
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
*  Macro WARNING_GREEN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 WARNING_GREEN_Read(void) 
{
    return (WARNING_GREEN_PS & WARNING_GREEN_MASK) >> WARNING_GREEN_SHIFT;
}


/*******************************************************************************
* Function Name: WARNING_GREEN_ReadDataReg
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
uint8 WARNING_GREEN_ReadDataReg(void) 
{
    return (WARNING_GREEN_DR & WARNING_GREEN_MASK) >> WARNING_GREEN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(WARNING_GREEN_INTSTAT) 

    /*******************************************************************************
    * Function Name: WARNING_GREEN_ClearInterrupt
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
    uint8 WARNING_GREEN_ClearInterrupt(void) 
    {
        return (WARNING_GREEN_INTSTAT & WARNING_GREEN_MASK) >> WARNING_GREEN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
