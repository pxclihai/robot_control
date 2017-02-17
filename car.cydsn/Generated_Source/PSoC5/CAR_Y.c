/*******************************************************************************
* File Name: CAR_Y.c  
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
#include "CAR_Y.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 CAR_Y__PORT == 15 && ((CAR_Y__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: CAR_Y_Write
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
void CAR_Y_Write(uint8 value) 
{
    uint8 staticBits = (CAR_Y_DR & (uint8)(~CAR_Y_MASK));
    CAR_Y_DR = staticBits | ((uint8)(value << CAR_Y_SHIFT) & CAR_Y_MASK);
}


/*******************************************************************************
* Function Name: CAR_Y_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  CAR_Y_DM_STRONG     Strong Drive 
*  CAR_Y_DM_OD_HI      Open Drain, Drives High 
*  CAR_Y_DM_OD_LO      Open Drain, Drives Low 
*  CAR_Y_DM_RES_UP     Resistive Pull Up 
*  CAR_Y_DM_RES_DWN    Resistive Pull Down 
*  CAR_Y_DM_RES_UPDWN  Resistive Pull Up/Down 
*  CAR_Y_DM_DIG_HIZ    High Impedance Digital 
*  CAR_Y_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void CAR_Y_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(CAR_Y_0, mode);
}


/*******************************************************************************
* Function Name: CAR_Y_Read
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
*  Macro CAR_Y_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CAR_Y_Read(void) 
{
    return (CAR_Y_PS & CAR_Y_MASK) >> CAR_Y_SHIFT;
}


/*******************************************************************************
* Function Name: CAR_Y_ReadDataReg
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
uint8 CAR_Y_ReadDataReg(void) 
{
    return (CAR_Y_DR & CAR_Y_MASK) >> CAR_Y_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CAR_Y_INTSTAT) 

    /*******************************************************************************
    * Function Name: CAR_Y_ClearInterrupt
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
    uint8 CAR_Y_ClearInterrupt(void) 
    {
        return (CAR_Y_INTSTAT & CAR_Y_MASK) >> CAR_Y_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
