 
#include "app.h"
#include "system/debug/sys_debug.h"

extern APP_DATA appData;
void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * eventData, uintptr_t context)
{   
    uint8_t * configurationValue;
    //USB_SETUP_PACKET * setupPacket;
    switch(event)
    {
        case USB_DEVICE_EVENT_RESET:
        case USB_DEVICE_EVENT_DECONFIGURED:

            SYS_PRINT("USB RESET\r\n");

            /* Device is reset or deconfigured. Provide LED indication.*/
            //LED1_Set();
            LED2_Clear();
            LED3_Clear();

            appData.deviceConfigured = false;

            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            SYS_PRINT("USB CONFIGURED\r\n");

            /* Check the configuration */
            configurationValue = (uint8_t *)eventData;
            if(*configurationValue == 1 )
            {
                /* The device is in configured state. Update LED indication */
                LED2_Set();
                LED3_Set();

                /* Reset endpoint data send & receive flag  */
                appData.deviceConfigured = true;
            }
            break;

        case USB_DEVICE_EVENT_SUSPENDED:

            SYS_PRINT("USB SUSPENDED\r\n");

            /* Device is suspended. Update LED indication */
            LED2_Set();
            LED3_Clear();
            break;


        case USB_DEVICE_EVENT_POWER_DETECTED:
            
            SYS_PRINT("USB VBUS\r\n");
            LED2_Set();
            LED3_Clear();

            /* VBUS is detected. Attach the device */
            USB_DEVICE_Attach(appData.usbDevHandle);
            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:

            SYS_PRINT("USB VBUS LOST\r\n");

            /* VBUS is removed. Detach the device */
            USB_DEVICE_Detach (appData.usbDevHandle);
            LED2_Clear();
            LED3_Clear();
            break;


        /* These events are not used in this demo. */
        case USB_DEVICE_EVENT_CONTROL_TRANSFER_SETUP_REQUEST:
        case USB_DEVICE_EVENT_ENDPOINT_WRITE_COMPLETE:
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

