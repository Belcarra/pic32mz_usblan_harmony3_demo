/* 
 * File Name:
 *  usb_device_usblah.h
 *
 * Copyright (c) 2019 Belcarra Technologies 2005
 * stuart.lynne@belcarra.com
 *
 *  Summary:
 *    USBLAN USB Function device driver interface file
 *
 *  Description:
 *    USBLAN MAC Device Driver Interface
 *
 *
 *  This needs to be added to the project configuration.h file:
 *
 *      ...
 *      #include "driver/usblan/usb_config.h"
 *      ...
 *
 */

#ifndef _USB_CONFIG_H_
#define _USB_CONFIG_H_


#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif


/* Number of Endpoints used */
#define DRV_USBHS_ENDPOINTS_NUMBER                        3

/* The USB Device Layer will not initialize the USB Driver */
#define USB_DEVICE_DRIVER_INITIALIZE_EXPLICIT

/* Maximum device layer instances */
#define USB_DEVICE_INSTANCES_NUMBER                         1

/* EP0 size in bytes */
#define USB_DEVICE_EP0_BUFFER_SIZE                          64



#ifdef __cplusplus
}
#endif


#endif /* _USB_DEVICE_USBLAN_H_ */
