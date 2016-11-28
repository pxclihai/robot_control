/*******************************************************************************
* File Name: PTZ_RIGHT.c  
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
#include "PTZ_RIGHT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PTZ_RIGHT__PORT == 15 && ((PTZ_RIGHT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PTZ_RIGHT_Write
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
void PTZ_RIGHT_Write(uint8 value) 
{
    uint8 staticBits = (PTZ_RIGHT_DR & (uint8)(~PTZ_RIGHT_MASK));
    PTZ_RIGHT_DR = staticBits | ((uint8)(value << PTZ_RIGHT_SHIFT) & PTZ_RIGHT_MASK);
}


/*******************************************************************************
* Function Name: PTZ_RIGHT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PTZ_RIGHT_DM_STRONG     Strong Drive 
*  PTZ_RIGHT_DM_OD_HI      Open Drain, Drives High 
*  PTZ_RIGHT_DM_OD_LO      Open Drain, Drives Low 
*  PTZ_RIGHT_DM_RES_UP     Resistive Pull Up 
*  PTZ_RIGHT_DM_RES_DWN    Resistive Pull Down 
*  PTZ_RIGHT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PTZ_RIGHT_DM_DIG_HIZ    High Impedance Digital 
*  PTZ_RIGHT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PTZ_RIGHT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PTZ_RIGHT_0, mode);
}


/*******************************************************************************
* Function Name: PTZ_RIGHT_Read
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
*  Macro PTZ_RIGHT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PTZ_RIGHT_Read(void) 
{
    return (PTZ_RIGHT_PS & PTZ_RIGHT_MASK) >> PTZ_RIGHT_SHIFT;
}


/*******************************************************************************
* Function Name: PTZ_RIGHT_ReadDataReg
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
uint8 PTZ_RIGHT_ReadDataReg(void) 
{
    return (PTZ_RIGHT_DR & PTZ_RIGHT_MASK) >> PTZ_RIGHT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PTZ_RIGHT_INTSTAT) 

    /*******************************************************************************
    * Function Name: PTZ_RIGHT_ClearInterrupt
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
    uint8 PTZ_RIGHT_ClearInterrupt(void) 
    {
        return (PTZ_RIGHT_INTSTAT & PTZ_RIGHT_MASK) >> PTZ_RIGHT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
