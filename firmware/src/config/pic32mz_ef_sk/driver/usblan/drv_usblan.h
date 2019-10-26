/*
 * File Name:
 *   drv_usblan.h
 *
 * Copyright (c) 2019 Belcarra Technologies 2005
 * stuart.lynne@belcarra.com
 *
 *  Summary:
 *    USBLAN MAC device driver interface file
 *
 *  Description:
 *    USBLAN MAC Device Driver Interface
 *    
 * The USBLAN MAC device driver provides a simple interface to manage
 * the USBLAN peripheral. This file defines the interface definitions
 *  and prototypes for the USBLAN MAC driver.                         
 *
 * This file defines the name of the USBLAN MAC driver object and TCPIP 
 * stack configuration structure:
 *
 *      extern const TCPIP_MAC_OBJECT DRV_USBLAN_MACObject;
 *      extern const TCPIP_MODULE_MAC_PIC32INT_CONFIG tcpipMACUSBLANInitData;
 *
 * These are used to initialize the USBLAN MAC driver.
 *
 * E.g. configuration.h
 *
 *      #define TCPIP_NETWORK_DEFAULT_MAC_DRIVER_IDX1           DRV_USBLAN_MACObject
 *
 * Typically this is done in the initialization.c:
 *
 *
 *      const TCPIP_NETWORK_CONFIG __attribute__((unused))  TCPIP_HOSTS_CONFIGURATION[] =
 *      {
 *          {
 *              TCPIP_NETWORK_DEFAULT_INTERFACE_NAME_IDX1,       // interface
 *              TCPIP_NETWORK_DEFAULT_HOST_NAME_IDX1,            // hostName
 *              TCPIP_NETWORK_DEFAULT_MAC_ADDR_IDX1,             // macAddr
 *              TCPIP_NETWORK_DEFAULT_IP_ADDRESS_IDX1,           // ipAddr
 *              TCPIP_NETWORK_DEFAULT_IP_MASK_IDX1,              // ipMask
 *              TCPIP_NETWORK_DEFAULT_GATEWAY_IDX1,              // gateway
 *              TCPIP_NETWORK_DEFAULT_DNS_IDX1,                  // priDNS
 *              TCPIP_NETWORK_DEFAULT_SECOND_DNS_IDX1,           // secondDNS
 *              TCPIP_NETWORK_DEFAULT_POWER_MODE_IDX1,           // powerMode
 *              TCPIP_NETWORK_DEFAULT_INTERFACE_FLAGS_IDX1,      // startFlags
 *             &TCPIP_NETWORK_DEFAULT_MAC_DRIVER_IDX1,           // pMacObject
 *          },
 *       ...
 *       };
 *
 *      const TCPIP_STACK_MODULE_CONFIG TCPIP_STACK_MODULE_CONFIG_TBL [] =
 *      {
 *          ...
 *          // MAC modules
 *          {TCPIP_MODULE_MAC_EXTERNAL,       &tcpipMACUSBLANInitData},
 *           ....
 *      };
 *
 *
 */ 

#ifndef _DRV_USBLAN_H
#define _DRV_USBLAN_H

#include "tcpip/tcpip_mac.h"
#include "tcpip/tcpip_mac_object.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

extern const TCPIP_MAC_OBJECT DRV_USBLAN_MACObject;
extern const TCPIP_MODULE_MAC_PIC32INT_CONFIG tcpipMACUSBLANInitData;


#endif // #ifndef _DRV_USBLAN_H

/*******************************************************************************
 End of File
*/

