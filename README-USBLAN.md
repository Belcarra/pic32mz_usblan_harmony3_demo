# Belcarra PIC32MZ USBLAN Driver Integration


The **Belcarra PIC32MZ USBLAN Driver** is a TCPIP NIC driver that uses the PIC32MZ USB High Speed Device Driver
to connect to another system. It uses CDC-EEM to transfer network packets to and from the other system.


Integrating the driver into a Harmony 3 project is not difficult. 

Starting with an project that already has TCPIP enabled:

    * add USB Device support
    * add a vendor function
    * modify the configuration.h to define the network configuration for index 1, USBLAN.
    * add these includes to the definitions.h file:
        #include "driver/usblan/drv_usblan.h"
        #include "driver/usblan/usb_device_usblan.h"
    * in the initialization.c:
        * add a second network configuration to TCPIP_HOSTS_CONFIGURATION
        * add a tcpipMACUSBLANInitData to the TCPIP_STAC_MODULE_CONFIG_TBL
        * change the USB_DEVICE_Initialize to use &usblanDevInitData
    * add the usblan driver files or library to the project
   
The above modifications can be seen in this project. To find them use:


    egrep -rsI '#ifdef USBLAN'


