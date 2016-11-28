/*******************************************************************************
* File Name: KEY_SPEED_HIGH.c  
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
#include "KEY_SPEED_HIGH.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 KEY_SPEED_HIGH__PORT == 15 && ((KEY_SPEED_HIGH__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: KEY_SPEED_HIGH_Write
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
void KEY_SPEED_HIGH_Write(uint8 value) 
{
    uint8 staticBits = (KEY_SPEED_HIGH_DR & (uint8)(~KEY_SPEED_HIGH_MASK));
    KEY_SPEED_HIGH_DR = staticBits | ((uint8)(value << KEY_SPEED_HIGH_SHIFT) & KEY_SPEED_HIGH_MASK);
}


/*******************************************************************************
* Function Name: KEY_SPEED_HIGH_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  KEY_SPEED_HIGH_DM_STRONG     Strong Drive 
*  KEY_SPEED_HIGH_DM_OD_HI      Open Drain, Drives High 
*  KEY_SPEED_HIGH_DM_OD_LO      Open Drain, Drives Low 
*  KEY_SPEED_HIGH_DM_RES_UP     Resistive Pull Up 
*  KEY_SPEED_HIGH_DM_RES_DWN    Resistive Pull Down 
*  KEY_SPEED_HIGH_DM_RES_UPDWN  Resistive Pull Up/Down 
*  KEY_SPEED_HIGH_DM_DIG_HIZ    High Impedance Digital 
*  KEY_SPEED_HIGH_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void KEY_SPEED_HIGH_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(KEY_SPEED_HIGH_0, mode);
}


/*******************************************************************************
* Function Name: KEY_SPEED_HIGH_Read
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
*  Macro KEY_SPEED_HIGH_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 KEY_SPEED_HIGH_Read(void) 
{
    return (KEY_SPEED_HIGH_PS & KEY_SPEED_HIGH_MASK) >> KEY_SPEED_HIGH_SHIFT;
}


/*******************************************************************************
* Function Name: KEY_SPEED_HIGH_ReadDataReg
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
uint8 KEY_SPEED_HIGH_ReadDataReg(void) 
{
    return (KEY_SPEED_HIGH_DR & KEY_SPEED_HIGH_MASK) >> KEY_SPEED_HIGH_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(KEY_SPEED_HIGH_INTSTAT) 

    /*******************************************************************************
    * Function Name: KEY_SPEED_HIGH_ClearInterrupt
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
    uint8 KEY_SPEED_HIGH_ClearInterrupt(void) 
    {
        return (KEY_SPEED_HIGH_INTSTAT & KEY_SPEED_HIGH_MASK) >> KEY_SPEED_HIGH_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
