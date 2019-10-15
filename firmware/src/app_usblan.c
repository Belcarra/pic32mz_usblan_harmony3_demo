 
#include "app.h"

extern APP_DATA appData;


//#include "tcpip/tcpip.h"

//#include "app_commands.h"
//#include "tcpip/tcpip_common_ports.h"

//#define SERVER_PORT 9760

#if 0
void USBDeviceEventHandler ( USB_DEVICE_EVENT event,
        void * eventData, uintptr_t context)
{
    uint8_t usbActiveConfiguration;
    switch ( event )
    {
        case USB_DEVICE_EVENT_RESET:

            consUsbData.isConfigured = false;
            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            usbActiveConfiguration = ((USB_DEVICE_EVENT_DATA_CONFIGURED *)eventData)->configurationValue;

            if (usbActiveConfiguration == 1)
            {
                /* Register the CDC Device application event handler here. */
                /USB_DEVICE_CDC_EventHandlerSet(USB_DEVICE_CDC_INDEX_0, USBDeviceCDCEventHandler, (uintptr_t)&consUsbData);
                //consUsbData.isConfigured = true;
            }
            break;

        case USB_DEVICE_EVENT_SUSPENDED:
        case USB_DEVICE_EVENT_RESUMED:
        case USB_DEVICE_EVENT_POWER_DETECTED:
        case USB_DEVICE_EVENT_POWER_REMOVED:
        case USB_DEVICE_EVENT_ERROR:
        default:
            break;

    }
}
#endif

#if 0
void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * eventData, uintptr_t context)
{   
    #if 0
    uint8_t * configurationValue;
    USB_SETUP_PACKET * setupPacket;
    switch(event)
    {
        case USB_DEVICE_EVENT_RESET:
        case USB_DEVICE_EVENT_DECONFIGURED:

            /* Device is reset or deconfigured. Provide LED indication.*/
            BSP_LEDOn  (APP_USB_LED_1);
            BSP_LEDOn (APP_USB_LED_2);
            BSP_LEDOff (APP_USB_LED_3);

            appData.deviceIsConfigured = false;

            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            /* Check the configuration */
            configurationValue = (uint8_t *)eventData;
            if(*configurationValue == 1 )
            {
                /* The device is in configured state. Update LED indication */
                BSP_LEDOff  (APP_USB_LED_1);
                BSP_LEDOff (APP_USB_LED_2);
                BSP_LEDOn (APP_USB_LED_3);

                /* Reset endpoint data send & receive flag  */
                appData.deviceIsConfigured = true;
            }
            break;

        case USB_DEVICE_EVENT_SUSPENDED:

            /* Device is suspended. Update LED indication */
            BSP_LEDOff  (APP_USB_LED_1);
            BSP_LEDOn (APP_USB_LED_2);
            BSP_LEDOn (APP_USB_LED_3);
            break;


        case USB_DEVICE_EVENT_POWER_DETECTED:

            /* VBUS is detected. Attach the device */
            //USB_DEVICE_Attach(usbDevHandle);
            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:

            /* VBUS is removed. Detach the device */
            //USB_DEVICE_Detach (usbDevHandle);
            break;


        /* These events are not used in this demo. */
        case USB_DEVICE_EVENT_CONTROL_TRANSFER_SETUP_REQUEST:
        case USB_DEVICE_EVENT_ENDPOINT_WRITE_COMPLETE:
        case USB_DEVICE_EVENT_RESUMED:
        case USB_DEVICE_EVENT_ERROR:
        default:
            break;
    }
    #endif
}
#endif

void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * eventData, uintptr_t context)
{   
    switch(event)
    {   
        case USB_DEVICE_EVENT_RESET:
        case USB_DEVICE_EVENT_DECONFIGURED:
            
            SYS_PRINT("%s: RESET\r\n", __func__);
            /* Host has de configured the device or a bus reset has happened.
             * Device layer is going to de-initialize all function drivers.
             * Hence close handles to all function drivers (Only if they are
             * opened previously. */
            
            LED_Off(); 
            appData.deviceConfigured = false;
            //appData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
            break;
        
        case USB_DEVICE_EVENT_CONFIGURED:
            SYS_PRINT("%s: CONFIGURED\r\n", __func__);
            LED_On(); 
            /* Set the flag indicating device is configured. */
            appData.deviceConfigured = true;
            
            /* Save the other details for later use. */
            appData.configurationValue = ((USB_DEVICE_EVENT_DATA_CONFIGURED*)eventData)->configurationValue;
            
            /* Register application HID event handler */
            //USB_DEVICE_HID_EventHandlerSet(USB_DEVICE_HID_INDEX_0, APP_USBDeviceHIDEventHandler, (uintptr_t)&appData);
            
            
            break;
        
        case USB_DEVICE_EVENT_SUSPENDED:
            SYS_PRINT("%s: SUSPENDED\r\n", __func__);
            break;
        
        case USB_DEVICE_EVENT_POWER_DETECTED:
            
            SYS_PRINT("%s: VBUS PowerDetected\r\n", __func__);

            /* VBUS was detected. We can attach the device */
            
            USB_DEVICE_Attach (appData.usbDevHandle);
            break;
        
        case USB_DEVICE_EVENT_POWER_REMOVED:
            SYS_PRINT("%s: VBUS lost\r\n", __func__);
            LED_Off(); 
            /* VBUS is not available */
            USB_DEVICE_Detach(appData.usbDevHandle);
            break;
        
        /* These events are not used in this demo */
        case USB_DEVICE_EVENT_RESUMED:
        case USB_DEVICE_EVENT_ERROR:
        default:
            break;
    }
}



//USB_DEVICE_HANDLE usbDevHandle;

bool APP_Tasks_USBLAN_Enable(void) 
{
    SYS_PRINT("%s:\r\n", __FUNCTION__);

    /* Open the device layer */
    appData.usbDevHandle = USB_DEVICE_Open( USB_DEVICE_INDEX_0, DRV_IO_INTENT_READWRITE );

    if(appData.usbDevHandle != USB_DEVICE_HANDLE_INVALID)
    {
        /* Register a callback with device layer to get event notification (for end point 0) */
        SYS_PRINT("%s: OK\r\n", __FUNCTION__);
        USB_DEVICE_EventHandlerSet(appData.usbDevHandle,  APP_USBDeviceEventHandler, 0);

        /* Attach the device */
        //SYS_PRINT("%s: Attach\r\n", __FUNCTION__);
        //USB_DEVICE_Attach (appData.usbDevHandle);
        return true;
    }
    /* The Device Layer is not ready to be opened. We should try
     * again later. 
     */
    SYS_PRINT("%s: FAILED\r\n", __FUNCTION__);
    return false;
}

/* End of File */

