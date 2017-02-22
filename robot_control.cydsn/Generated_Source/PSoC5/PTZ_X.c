/*******************************************************************************
* File Name: PTZ_X.c  
* Version 2.5
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
#include "PTZ_X.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PTZ_X__PORT == 15 && ((PTZ_X__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PTZ_X_Write
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
void PTZ_X_Write(uint8 value) 
{
    uint8 staticBits = (PTZ_X_DR & (uint8)(~PTZ_X_MASK));
    PTZ_X_DR = staticBits | ((uint8)(value << PTZ_X_SHIFT) & PTZ_X_MASK);
}


/*******************************************************************************
* Function Name: PTZ_X_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PTZ_X_DM_STRONG     Strong Drive 
*  PTZ_X_DM_OD_HI      Open Drain, Drives High 
*  PTZ_X_DM_OD_LO      Open Drain, Drives Low 
*  PTZ_X_DM_RES_UP     Resistive Pull Up 
*  PTZ_X_DM_RES_DWN    Resistive Pull Down 
*  PTZ_X_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PTZ_X_DM_DIG_HIZ    High Impedance Digital 
*  PTZ_X_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PTZ_X_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PTZ_X_0, mode);
}


/*******************************************************************************
* Function Name: PTZ_X_Read
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
*  Macro PTZ_X_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PTZ_X_Read(void) 
{
    return (PTZ_X_PS & PTZ_X_MASK) >> PTZ_X_SHIFT;
}


/*******************************************************************************
* Function Name: PTZ_X_ReadDataReg
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
uint8 PTZ_X_ReadDataReg(void) 
{
    return (PTZ_X_DR & PTZ_X_MASK) >> PTZ_X_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PTZ_X_INTSTAT) 

    /*******************************************************************************
    * Function Name: PTZ_X_ClearInterrupt
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
    uint8 PTZ_X_ClearInterrupt(void) 
    {
        return (PTZ_X_INTSTAT & PTZ_X_MASK) >> PTZ_X_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
