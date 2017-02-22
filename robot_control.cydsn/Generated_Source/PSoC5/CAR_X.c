/*******************************************************************************
* File Name: CAR_X.c  
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
#include "CAR_X.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 CAR_X__PORT == 15 && ((CAR_X__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: CAR_X_Write
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
void CAR_X_Write(uint8 value) 
{
    uint8 staticBits = (CAR_X_DR & (uint8)(~CAR_X_MASK));
    CAR_X_DR = staticBits | ((uint8)(value << CAR_X_SHIFT) & CAR_X_MASK);
}


/*******************************************************************************
* Function Name: CAR_X_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  CAR_X_DM_STRONG     Strong Drive 
*  CAR_X_DM_OD_HI      Open Drain, Drives High 
*  CAR_X_DM_OD_LO      Open Drain, Drives Low 
*  CAR_X_DM_RES_UP     Resistive Pull Up 
*  CAR_X_DM_RES_DWN    Resistive Pull Down 
*  CAR_X_DM_RES_UPDWN  Resistive Pull Up/Down 
*  CAR_X_DM_DIG_HIZ    High Impedance Digital 
*  CAR_X_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void CAR_X_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(CAR_X_0, mode);
}


/*******************************************************************************
* Function Name: CAR_X_Read
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
*  Macro CAR_X_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CAR_X_Read(void) 
{
    return (CAR_X_PS & CAR_X_MASK) >> CAR_X_SHIFT;
}


/*******************************************************************************
* Function Name: CAR_X_ReadDataReg
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
uint8 CAR_X_ReadDataReg(void) 
{
    return (CAR_X_DR & CAR_X_MASK) >> CAR_X_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CAR_X_INTSTAT) 

    /*******************************************************************************
    * Function Name: CAR_X_ClearInterrupt
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
    uint8 CAR_X_ClearInterrupt(void) 
    {
        return (CAR_X_INTSTAT & CAR_X_MASK) >> CAR_X_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
