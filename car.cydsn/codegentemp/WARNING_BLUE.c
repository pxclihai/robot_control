/*******************************************************************************
* File Name: WARNING_BLUE.c  
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
#include "WARNING_BLUE.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 WARNING_BLUE__PORT == 15 && ((WARNING_BLUE__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: WARNING_BLUE_Write
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
void WARNING_BLUE_Write(uint8 value) 
{
    uint8 staticBits = (WARNING_BLUE_DR & (uint8)(~WARNING_BLUE_MASK));
    WARNING_BLUE_DR = staticBits | ((uint8)(value << WARNING_BLUE_SHIFT) & WARNING_BLUE_MASK);
}


/*******************************************************************************
* Function Name: WARNING_BLUE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  WARNING_BLUE_DM_STRONG     Strong Drive 
*  WARNING_BLUE_DM_OD_HI      Open Drain, Drives High 
*  WARNING_BLUE_DM_OD_LO      Open Drain, Drives Low 
*  WARNING_BLUE_DM_RES_UP     Resistive Pull Up 
*  WARNING_BLUE_DM_RES_DWN    Resistive Pull Down 
*  WARNING_BLUE_DM_RES_UPDWN  Resistive Pull Up/Down 
*  WARNING_BLUE_DM_DIG_HIZ    High Impedance Digital 
*  WARNING_BLUE_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void WARNING_BLUE_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(WARNING_BLUE_0, mode);
}


/*******************************************************************************
* Function Name: WARNING_BLUE_Read
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
*  Macro WARNING_BLUE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 WARNING_BLUE_Read(void) 
{
    return (WARNING_BLUE_PS & WARNING_BLUE_MASK) >> WARNING_BLUE_SHIFT;
}


/*******************************************************************************
* Function Name: WARNING_BLUE_ReadDataReg
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
uint8 WARNING_BLUE_ReadDataReg(void) 
{
    return (WARNING_BLUE_DR & WARNING_BLUE_MASK) >> WARNING_BLUE_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(WARNING_BLUE_INTSTAT) 

    /*******************************************************************************
    * Function Name: WARNING_BLUE_ClearInterrupt
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
    uint8 WARNING_BLUE_ClearInterrupt(void) 
    {
        return (WARNING_BLUE_INTSTAT & WARNING_BLUE_MASK) >> WARNING_BLUE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
