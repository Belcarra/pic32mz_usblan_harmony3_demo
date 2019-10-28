# Belcarra LIBUSBLAN 

This directory contains a linkable library for the *Belcarra PIC32MZ USBLAN* driver.

The *Belcarra PIC32MZ USBLAN* driver implements *Networking Over USB* for PIC32MZ projects. It implements an 
*Ethernet MAC* driver that sends and receives network frames over *USB* using the *CDC-EEM* protocol.

The *libusblan_PROJNAME.a* file contains the Belcarra PIC32MZ USBLAN Driver for a specific Microchip PIC32MZ board..

    - pic32mz_ef_sk
    - pic32mz_ef_curiosity

There are three C include files and two C source files:

    - usb_config.h
    - drv_usblan.h
    - usb_device_usblan.h
    - app_usblan.c
    - usblan-config.c

These should be placed in your project drivers directory, e.g.:

    firmware/src/config/pic32mz_ef_sk/driver/usblan

The two *.c* files will need to be added to your project *Source Files* list in MPLab X IDE.

N.B. The following assume that your project has:
    
    - a USB Vendor Function driver 
    - TCPIP networking with an Ethernet MAC driver 


## usb_config.h - configuration.h 

The project *configuration.h* file needs to have Microchip *USB Device Function* configuration that is defined for the 
PIC32MZ USBLAN driver. This is done by including the usb_config.h file in the definitions.h file.

```
...
#include "driver/usblan/usb_config.h"
...
```


## drv_usblan.h - definitions.h 

This defines the TCPIP MAC information needed to add USBLAN as a MAC driver for sending and receiving network frames.

Add drv_usblan.h to the project definitions.h file.

In the project initialization.c file:

```
const TCPIP_NETWORK_CONFIG __attribute__((unused))  TCPIP_HOSTS_CONFIGURATION[] =
{
    {
        TCPIP_NETWORK_DEFAULT_INTERFACE_NAME_IDX1,       // interface
        TCPIP_NETWORK_DEFAULT_HOST_NAME_IDX1,            // hostName
        TCPIP_NETWORK_DEFAULT_MAC_ADDR_IDX1,             // macAddr
        TCPIP_NETWORK_DEFAULT_IP_ADDRESS_IDX1,           // ipAddr
        TCPIP_NETWORK_DEFAULT_IP_MASK_IDX1,              // ipMask
        TCPIP_NETWORK_DEFAULT_GATEWAY_IDX1,              // gateway
        TCPIP_NETWORK_DEFAULT_DNS_IDX1,                  // priDNS
        TCPIP_NETWORK_DEFAULT_SECOND_DNS_IDX1,           // secondDNS
        TCPIP_NETWORK_DEFAULT_POWER_MODE_IDX1,           // powerMode
        TCPIP_NETWORK_DEFAULT_INTERFACE_FLAGS_IDX1,      // startFlags
       &TCPIP_NETWORK_DEFAULT_MAC_DRIVER_IDX1,           // pMacObject
    },
 ...
 };

const TCPIP_STACK_MODULE_CONFIG TCPIP_STACK_MODULE_CONFIG_TBL [] =
{
    ...
    // MAC modules
    {TCPIP_MODULE_MAC_EXTERNAL,       &tcpipMACUSBLANInitData},
     ....
};



```

## usb_device_usblan.h - 

This defines the USBLAN Function driver information needed for the USB Device support to use USBLAN.

Defines:

```
extern const USB_DEVICE_INIT usblanDevInitData;
```


Add drv_usblan.h to the project definitions.h file and add a usbDevObject0 to the *SYSTEM_OBJECTS* structure.

```
typdef struct {

    ...

    SYS_MODULE_OBJ usbDevObject0;
    ...
    SYS_MODULE_OBJ drvUSBHSObject;

} SYSTEM_OBJECTS;
```

Add the following to the initialization.c file:

```
SYS_Initialize(void * data) {

    ...
    /* Initialize USB Driver */
    sysObj.usbDevObject0 = USB_DEVICE_Initialize (USB_DEVICE_INDEX_0 , ( SYS_MODULE_INIT* ) &usblanDevInitData);
    ...

}
```


## app_usblan.c

This defines *APP_Tasks_Enable()* which needs to be called from *app.c* in the *APP_Tasks* function.

...

typedef enum
{
    APP_MOUNT_DISK = 0,
    APP_USB_ENABLE,
    APP_TCPIP_WAIT_INIT,
    ...

} APP_STATES;


void APP_Tasks(void) {

    switch(appData.state) {

    case APP_MOUNT_DISK:
        ...
        appData.state = APP_USB_ENABLE;
        break;

    case APP_USB_ENABLE:
        appData.state = APP_Tasks_USBLAN_Enable() ? APP_TCPIP_WAIT_INIT : APP_USB_ENABLE;
        break;

    case APP_TCPIP_WAIT_INIT:
        ...

    }
}

...



## usblan.config.c

This contains the *USB Descriptor* definitions and the *USB_DEVICE_INIT* structure *usblanDevInitData*.

If necessary the USB Vendor and Product ID's can be modified here.

The default are:

    * 0x15ec - Belcarra Technologies
    * 0xf101 - Belcarra Demonstration kit driver








###Date: Sun Oct 27 23:35:44 PDT 2019
###ProjDir: pic32mzusblan
###ConfName: pic32mz_ef_sk
###Device: PIC32MZ2048EFM144
