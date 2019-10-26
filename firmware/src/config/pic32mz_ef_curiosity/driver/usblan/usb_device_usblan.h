/* 
 * File Name:
 *  usb_config.h
 *
 * Copyright (c) 2019 Belcarra Technologies 2005
 * stuart.lynne@belcarra.com
 *
 *  Summary:
 *    USBLAN USB Function device driver USB configuration.
 *
 *  Description:
 *    USBLAN MAC Device Driver Interface
 *    
 *
 * This is used to set the USB Device configuration. Typically this will be included
 * in the project definitions.h file:
 *
 *
 *      #include "driver/usblan/usb_config.h"
 *      ...
 *      #include "usb/usb_chapter_9.h"
 *      #include "usb/usb_device.h"
 *      ...
 *      #include "driver/usb/usbhs/drv_usbhs.h"
 *      ...
 *      #include "driver/usblan/drv_usblan.h"
 *      #include "driver/usblan/usb_device_usblan.h"
 *
 */

#ifndef _USB_DEVICE_USBLAN_H_
#define _USB_DEVICE_USBLAN_H_

#include "usb/src/usb_device_function_driver.h"

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif

extern const USB_DEVICE_INIT usblanDevInitData;

#ifdef __cplusplus
}
#endif


#endif /* _USB_DEVICE_USBLAN_H_ */
