/*******************************************************************************
* File Name: BATTERY.c  
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
#include "BATTERY.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 BATTERY__PORT == 15 && ((BATTERY__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: BATTERY_Write
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
void BATTERY_Write(uint8 value) 
{
    uint8 staticBits = (BATTERY_DR & (uint8)(~BATTERY_MASK));
    BATTERY_DR = staticBits | ((uint8)(value << BATTERY_SHIFT) & BATTERY_MASK);
}


/*******************************************************************************
* Function Name: BATTERY_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  BATTERY_DM_STRONG     Strong Drive 
*  BATTERY_DM_OD_HI      Open Drain, Drives High 
*  BATTERY_DM_OD_LO      Open Drain, Drives Low 
*  BATTERY_DM_RES_UP     Resistive Pull Up 
*  BATTERY_DM_RES_DWN    Resistive Pull Down 
*  BATTERY_DM_RES_UPDWN  Resistive Pull Up/Down 
*  BATTERY_DM_DIG_HIZ    High Impedance Digital 
*  BATTERY_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void BATTERY_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(BATTERY_0, mode);
}


/*******************************************************************************
* Function Name: BATTERY_Read
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
*  Macro BATTERY_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 BATTERY_Read(void) 
{
    return (BATTERY_PS & BATTERY_MASK) >> BATTERY_SHIFT;
}


/*******************************************************************************
* Function Name: BATTERY_ReadDataReg
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
uint8 BATTERY_ReadDataReg(void) 
{
    return (BATTERY_DR & BATTERY_MASK) >> BATTERY_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(BATTERY_INTSTAT) 

    /*******************************************************************************
    * Function Name: BATTERY_ClearInterrupt
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
    uint8 BATTERY_ClearInterrupt(void) 
    {
        return (BATTERY_INTSTAT & BATTERY_MASK) >> BATTERY_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
