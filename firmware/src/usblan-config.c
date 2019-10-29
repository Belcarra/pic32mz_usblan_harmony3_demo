/*
 * USB USBLAN Function Driver Configuration
 */

#include "system_definitions.h"
#include "driver/usb/usbhs/drv_usbhs.h"

#define USBVENDORID 0x15ec
#define USBPRODUCTIO 0xf101

/*****************************************
 * USB Device Layer Descriptors for USBLAN
 *****************************************/
/************************************
 *  USB Device Descriptor  for USBLAN
 *************************************/
const USB_DEVICE_DESCRIPTOR usblandeviceDescriptor =
{
    0x12,                           /* Size of this descriptor in bytes */
    USB_DESCRIPTOR_DEVICE,          /* DEVICE descriptor type */
    0x0200,                         /* USB Spec Release Number in BCD format */
    0x02,                           /* Class Code */
    0x0c,                           /* Subclass code */
    0x07,                           /* Protocol code */
    USB_DEVICE_EP0_BUFFER_SIZE,     /* Max packet size for EP0, see system_config.h */
    USBVENDORID,                    /* Belcarra Vendor ID */
    USBPRODUCTIO,                   /* Belcarra Product ID */
    0x0100,                         /* Device release number in BCD format */
    0x01,                           /* Manufacturer string index */
    0x02,                           /* Product string index */
    0x00,                           /* Device serial number string index */
    0x01                            /* Number of possible configurations */
};

/*********************************************************
 *  USB Device Qualifier Descriptor for the USBLAN demo.
 *********************************************************/
const USB_DEVICE_QUALIFIER usblanDeviceQualifierDescriptor1 =
{
    0x0A,                               /* Size of this descriptor in bytes */
    USB_DESCRIPTOR_DEVICE_QUALIFIER,    /* Device Qualifier Type */
    0x0200,                             /* USB Specification Release number */
    0x0c,                               /* Class Code */
    0x07,                               /* Subclass code */
    0x07,                               /* Protocol code */
    USB_DEVICE_EP0_BUFFER_SIZE,         /* Maximum packet size for endpoint 0 */
    0x01,                               /* Number of possible configurations */
    0x00                                /* Reserved for future use. */
};

/*USB High Speed Configuration Descriptor for USBLAN
 */
const uint8_t usblanHighSpeedConfigurationDescriptor[]=
{   
    /* Configuration Descriptor for USBLAN */
    
    0x09,                                               /* Size of this descriptor in bytes */
    USB_DESCRIPTOR_CONFIGURATION,                       /* Descriptor Type */
    40,0,                                               /*(106 Bytes)Size of the Config descriptor */
    1,                                                  /* Number of interfaces in this cfg */
    0x01,                                               /* Index value of this configuration */
    0x00,                                               /* Configuration string index */
    USB_ATTRIBUTE_DEFAULT | USB_ATTRIBUTE_SELF_POWERED, /* Attributes */
    50,                                                 /* Max power consumption (2X mA) */
    // 9
    
    /* Descriptor for Function 1 - USBLAN Itsy protocol    */ 
    /* Interface Association Descriptor: USBLAN Itsy Function 1*/
    0x08,                                               /* Size of this descriptor in bytes */
    0x0B,                                               /* Interface association descriptor type */
    0,                                                  /* The first associated interface */
    0x02,                                               /* Number of contiguous associated interface */
    0x0c,                                               /* bInterfaceClass of the first interface */
    0x07,                                               /* bInterfaceSubclass of the first interface */
    0x00,                                               /* bInterfaceProtocol of the first interface */
    0x00,                                               /* Interface string index */
    // 17
    
    /* Interface Descriptor for USBLAN*/
    9,//sizeof(USB_INTF_DSC),                           /* Size of this descriptor in bytes */
    USB_DESCRIPTOR_INTERFACE,                           /* INTERFACE descriptor type */
    0,                                                  /* Interface Number */
    0,                                                  /* Alternate Setting Number */
    2,                                                  /* Number of endpoints in this intf */
    0x02,                                               /* Number of endpoints in this intf */
    0x0c,                                               /* Vendor Class code */
    0x07,                                               /* Subclass code */
    0,                                                  /* Interface string index */
    // 26
    
    /* Bulk IN Endpoint Descriptor */                   
    0x07,/*sizeof(USB_EP_DSC)*/                         
    USB_DESCRIPTOR_ENDPOINT,                            /* Endpoint Descriptor */
    1 | USB_EP_DIRECTION_IN,                            /* EndpointAddress ( EP2 IN ) */
    USB_TRANSFER_TYPE_BULK,                             /* Attributes */
    0x00, 0x02,                                         /* Max packet size of this EP */
    0x00,                                               /* Interval */
    // 33
    
    /* Bulk OUT Endpoint Descriptor */                  
    0x07,/*sizeof(USB_EP_DSC)*/                         
    USB_DESCRIPTOR_ENDPOINT,                            /* Endpoint Descriptor */
    1 | USB_EP_DIRECTION_OUT,                           /*  EndpointAddress ( EP2 OUT ) */
    USB_TRANSFER_TYPE_BULK,                             /* Attributes */
    0x00, 0x02,                                         /*  Max packet size of this EP */
    //0x40,0x00,                                        /* size */
    0x00,                                               /* Interval */
    // 40
}; /* End of high speed config */


USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE usblanHighSpeedConfigDescSet[1] =
{ usblanHighSpeedConfigurationDescriptor };

/* USB Full Speed Configuration Descriptor for USBLAN
 */
const uint8_t usblanFullSpeedConfigurationDescriptor[]=
{
    /* Configuration Descriptor for USBLAN */

    0x09,                                               /* Size of this descriptor in bytes */
    USB_DESCRIPTOR_CONFIGURATION,                       /* Descriptor Type */
    40,0,                                               /* (106 Bytes)Size of the Config descriptor */
    1,                                                  /* Number of interfaces in this cfg */
    0x01,                                               /* Index value of this configuration */
    0x00,                                               /* Configuration string index */
    USB_ATTRIBUTE_DEFAULT | USB_ATTRIBUTE_SELF_POWERED, /* Attributes */
    50,                                                 /* Max power consumption (2X mA) */
    // 9

    /* Descriptor for Function 1 - USBLAN Itsy Protocol    */
    /* Interface Association Descriptor: USBLAN Itsy Function 1*/
    0x08,                                               /* Size of this descriptor in bytes */
    0x0B,                                               /* Interface association descriptor type */
    0,                                                  /* The first associated interface */
    0x01,                                               /* Number of contiguous associated interface */
    0x02,                                               /* bInterfaceClass of the first interface */
    0x0c,                                               /* bInterfaceSubclass of the first interface */
    0x07,                                               /* bInterfaceProtocol of the first interface */
    0x00,                                               /* Interface string index */
    // 17

    /* Interface Descriptor for USBLAN */
    9,//sizeof(USB_INTF_DSC),                           /* Size of this descriptor in bytes */
    USB_DESCRIPTOR_INTERFACE,                           /* INTERFACE descriptor type */
    0,                                                  /* Interface Number */
    0,                                                  /* Alternate Setting Number */
    0x02,                                               /* Number of endpoints in this intf */
    0x0c,                                               /* Vendor Class code */
    0x07,                                               /* Subclass code */
    0, /*NO_PROTOCOL */                                 /* Protocol code */
    0,                                                  /* Interface string index */
    // 26

    /* BULK IN Endpoint Descriptor */
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT,                            /* Endpoint Descriptor */
    1 | USB_EP_DIRECTION_IN,                            /* EndpointAddress ( EP2 IN ) */
    USB_TRANSFER_TYPE_BULK,                             /* Attributes */
    0x40, 0x00,                                         /* size */
    0x00,                                               /* Interval */
    // 33

    /* BULK OUT Endpoint Descriptor */
    0x07,/*sizeof(USB_EP_DSC)*/
    USB_DESCRIPTOR_ENDPOINT,                            /* Endpoint Descriptor */
    1 | USB_EP_DIRECTION_OUT,                           /* EndpointAddress ( EP2 OUT ) */
    USB_TRANSFER_TYPE_BULK,                             /* Attributes */
    0x40,0x00,                                          /* size */
    0x00,                                               /* Interval */
    // 40
}; /* end of full speed configuration */

/** Array of Full speed config descriptors for USBLAN
 */
USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE usblanFullSpeedConfigDescSet[1] =
{ usblanFullSpeedConfigurationDescriptor };


/************************************                                      
 *  String descriptors. for USBLAN
 ***************************************/                                  
 /********************************************                             
 *  Language code string descriptor for USBLAN                             
 ********************************************/                             
    const struct { uint8_t bLength; uint8_t bDscType; uint16_t string[1];     }
    usblansd000 = {
        sizeof(usblansd000),          /* Size of this descriptor in bytes */
        USB_DESCRIPTOR_STRING,  /* STRING descriptor type */
        {0x0409}                /* Language ID */
    };  
/********************************************
 *  Manufacturer string descriptor for USBLAN
 ********************************************/
    const struct { uint8_t bLength; uint8_t bDscType; uint16_t string[26]; }
    usblsd001 = {
        sizeof(usblsd001), USB_DESCRIPTOR_STRING,
        {'B','e','l','c','a','r','r','a',' ','T','e','c','h','n','o','l','o','g','i','e','s',' ','2','0', '0', '5'}
    }; //
/***************************************
 *  Product string descriptor for USBLAN
 ***************************************/
    const struct { uint8_t bLength; uint8_t bDscType; uint16_t string[16]; }
    usblsd002 = {
        sizeof(usblsd002), USB_DESCRIPTOR_STRING,
        {'U','S','B','L','A','N',' ','C','D','D','-','E', 'E','M'}
    };  //
/*******************************************
 * Array of string descriptors for USBLAN
 ******************************************/
USB_DEVICE_STRING_DESCRIPTORS_TABLE usblanStringDescriptors[3]= {
    (const uint8_t *const)&usblansd000,
    (const uint8_t *const)&usblsd001,
    (const uint8_t *const)&usblsd002
}; //



/**************************************************
 * USB Device Layer Function Driver Registration 
 * Table
 **************************************************/
extern const USB_DEVICE_FUNCTION_DRIVER usblanFunctionDriver;
const USB_DEVICE_FUNCTION_REGISTRATION_TABLE usblanfuncRegistrationTable[3] =
{   
    /* Function 1 */
    {   
        .configurationValue = 1,    /* Configuration value */
        .interfaceNumber = 0,       /* First interfaceNumber of this function */
        .speed = USB_SPEED_HIGH|USB_SPEED_FULL,    /* Function Speed */
        .numberOfInterfaces = 1,                /* Number of interfaces  */
        .funcDriverIndex = 0,                   /* Index of USBLAN Function Driver  */
        .driver = (void*)&usblanFunctionDriver,    /* USB USBLAN function data exposed to device layer  */
        .funcDriverInit = (void*)NULL,          /* Function driver init data  */
    },
};

/*****************************************
 * USB Device Layer Descriptors for USBLAN
 *****************************************/
const USB_DEVICE_DESCRIPTOR usblandeviceDescriptor;
const USB_DEVICE_QUALIFIER usblanDeviceQualifierDescriptor1;
USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE usblanHighSpeedConfigDescSet[1];
USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE usblanFullSpeedConfigDescSet[1];
USB_DEVICE_STRING_DESCRIPTORS_TABLE usblanStringDescriptors[3];
const USB_DEVICE_MASTER_DESCRIPTOR usblanMasterDescriptor = {
    &usblandeviceDescriptor,        /* Full speed descriptor */
    1,                          /* Total number of full speed configurations available */
    usblanFullSpeedConfigDescSet,   /* Pointer to array of full speed configurations descriptors*/
    &usblandeviceDescriptor,        /* High speed device descriptor*/
    1,                          /* Total number of high speed configurations available */
    usblanHighSpeedConfigDescSet,   /* Pointer to array of high speed configurations descriptors. */
    3,                              /* Total number of string descriptors available. */
    usblanStringDescriptors,              /* Pointer to array of string descriptors. */
    &usblanDeviceQualifierDescriptor1,// Pointer to full speed dev qualifier.
    &usblanDeviceQualifierDescriptor1 // Pointer to high speed dev qualifier.
};

/*************************************************
 * USB Device Layer Initialization Data for USBLAN
 *************************************************/
const USB_DEVICE_INIT usblanDevInitData = {
    /* System module initialization for USBLAN */
#ifdef HF2
    .moduleInit = {SYS_MODULE_POWER_RUN_FULL},      //
#else /* HF2 */
    .moduleInit = {0},      //
#endif /* HF2 */

    .registeredFuncCount = 1,                       /* number of function drivers */
    .registeredFunctions = (USB_DEVICE_FUNCTION_REGISTRATION_TABLE*)usblanfuncRegistrationTable,
    /* Pointer to USB Descriptor structure for USBLAN */
    .usbMasterDescriptor = (USB_DEVICE_MASTER_DESCRIPTOR*)&usblanMasterDescriptor, //
    .deviceSpeed = USB_SPEED_HIGH,                  //
    .driverIndex = DRV_USBHS_INDEX_0,               //
    .usbDriverInterface = DRV_USBHS_DEVICE_INTERFACE, //
};//





