/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_H
#define _APP_H

#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif





// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"
#include "definitions.h" 
#include "tcpip/tcpip.h"

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

/* This section is highly customizable based on application's specific needs. */

#ifndef SWITCH2_PIN
#define SWITCH2_Get()      (0)
#endif /* SWITCH2_GET() */

#ifndef SWITCH3_PIN
#define SWITCH3_Get()      (0)
#endif /* SWITCH3_GET() */

#ifndef LED2_PIN
#define LED2_Set()
#define LED2_Get()  (0)
#define LED2_Clear()
#define LED2_Toggle()
#endif /* LED2_Set */

#ifndef LED3_PIN
#define LED3_Set()
#define LED3_Get()  (0)
#define LED3_Clear()
#define LED3_Toggle()
#endif /* LED3_Set */

#define APP_SWITCH_1StateGet()      SWITCH1_Get()
#define APP_SWITCH_2StateGet()      SWITCH2_Get()
#define APP_SWITCH_3StateGet()      SWITCH3_Get()

#define APP_LED_1StateSet()         LED1_Set()
#define APP_LED_1StateGet()         LED1_Get()
#define APP_LED_1StateClear()       LED1_Clear()
#define APP_LED_1StateToggle()      LED1_Toggle()

#define APP_LED_2StateSet()         LED2_Set()
#define APP_LED_2StateGet()         LED2_Get()
#define APP_LED_2StateClear()       LED2_Clear()
#define APP_LED_2StateToggle()      LED2_Toggle()

#define APP_LED_3StateSet()         LED3_Set()
#define APP_LED_3StateGet()         LED3_Get()
#define APP_LED_3StateClear()       LED3_Clear()
#define APP_LED_3StateToggle()      LED3_Toggle()

#ifndef RGB_LED_BLUE_PIN
#define RGB_LED_BLUE_Set()
#define RGB_LED_RED_Set()
#define RGB_LED_GREEN_Set()
#define RGB_LED_GREEN_Clear()
#define RGB_LED_BLUE_Clear()
#define RGB_LED_RED_Clear()
#endif /* RGB_LED_BLUE_PIN */


#if 0
#ifdef RGBLED
/* BSP LED and Switch Re-directs */
/* This section is highly customizable based on application's specific needs. */

#define APP_RGB_LED_RED_OC_FUNCTION     OUTPUT_FUNC_OC3
#define APP_RGB_LED_RED_OC_PIN          OUTPUT_PIN_RPB5
#define APP_RGB_LED_GREEN_OC_FUNCTION   OUTPUT_FUNC_OC4
#define APP_RGB_LED_GREEN_OC_PIN        OUTPUT_PIN_RPB1
#define APP_RGB_LED_BLUE_OC_FUNCTION    OUTPUT_FUNC_OC5
#define APP_RGB_LED_BLUE_OC_PIN         OUTPUT_PIN_RPB0

/* ID's for RGB LED */
#define APP_TMR_ID_FOR_OC       TMR_ID_3
#define APP_RGB_LED_RED_OC_ID   OC_ID_3
#define APP_RGB_LED_GREEN_OC_ID OC_ID_4
#define APP_RGB_LED_BLUE_OC_ID  OC_ID_5


void LEDinit(void);
void LEDColorSet(int Red, int Green, int Blue);
#endif /* RGBLED */
#endif


// *****************************************************************************
/* Application States

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* The application mounts the disk. */
    APP_MOUNT_DISK = 0,

    /* DO NOT REMOVE DURING MERGE */
    /* This will enable USBLAN */
    APP_USB_ENABLE,
    /* DO NOT REMOVE DURING MERGE */

    /* In this state, the application waits for the initialization of the TCP/IP stack
       to complete. */
    APP_TCPIP_WAIT_INIT,

    /* The application configures the Wi-Fi settings. */
    APP_WIFI_CONFIG,

    /* In this state, the application runs the Wi-Fi prescan. */
    APP_WIFI_PRESCAN,

    /* In this state, the application enables TCP/IP modules such as DHCP, NBNS and mDNS
       in all available interfaces. */
    APP_TCPIP_MODULES_ENABLE,

    /* In this state, the application can do TCP/IP transactions. */
    APP_TCPIP_TRANSACT,

    /* In this state, the application performs module FW update over the air. */
    APP_FW_OTA_UPDATE,

    /* In this state, the application waits till FW update gets completed. */
    APP_WAIT_FOR_FW_UPDATE,

    APP_TCPIP_ERROR,
} APP_STATES;

// *****************************************************************************
/* LED State

  Summary:
    Enumerates the supported LED states.

  Description:
    This enumeration defines the supported LED states.

  Remarks:
    None.
*/
typedef enum
{
    /* LED State is on */
    APP_LED_STATE_OFF = 0,
   /* LED State is off */
    APP_LED_STATE_ON = 1,
} APP_LED_STATE;


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* SYS_FS file handle */
    SYS_FS_HANDLE fileHandle;
    /* The application's current state */
    APP_STATES state;

    /* Device layer handle returned by device layer open function */
    USB_DEVICE_HANDLE  usbDevHandle;

    /* Device configured */
    bool deviceConfigured;


    /* Configuration value selected by the host*/
    uint8_t configurationValue;


    TCP_SOCKET              socket;

} APP_DATA;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

	
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the 
    application in its initial state and prepares it to run so that its 
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Tasks ( void );


extern const USB_DEVICE_FUNCTION_REGISTRATION_TABLE funcRegistrationTable[1];
extern const USB_DEVICE_MASTER_DESCRIPTOR usbMasterDescriptor;

// *****************************************************************************
// *****************************************************************************
// Section: External Declarations
// *****************************************************************************
// *****************************************************************************

// HTTP application processing
#if defined(TCPIP_STACK_USE_HTTP_NET_SERVER)
extern void HTTP_APP_Initialize(void);
#endif // defined(TCPIP_STACK_USE_HTTP_NET_SERVER)


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_H */

/*******************************************************************************
 End of File
 */

