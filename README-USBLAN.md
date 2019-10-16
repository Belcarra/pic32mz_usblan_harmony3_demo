# Belcarra PIC32MZ USBLAN Driver Integration


The **Belcarra PIC32MZ USBLAN Driver** is a TCPIP NIC driver that uses the PIC32MZ USB High Speed Device Driver
to connect to another system. It uses CDC-EEM to transfer network packets to and from the other system.

Integrating the driver into a Harmony 2 project is not difficult.

    * Creating a second network interface and linking it to the USBLAN tcpipMACUSBLANInitData object.
    * Adding the high speed USB Device driver and USB layer device support
    * Intializing the USB DEVICE layer with the USBLAN USB Function usblanDevInitData


## Modifications to the project

    1. The application needs to enable the USBLAN driver.
    2. The System Configuration needs to define the Network Configuration for the USBLAN network interface.
    3. The System Definitions needs to add drvUSBObject and usbDevObject0 to the system objects structure.
    4. The System Initialization needs to:
        1. define and add support for the USB High Speed driver
        2. to have a network configuration for the USBLAN interface.
        3. Setup the USB interrupt vectors
        4. Link in the USBLAN driver to the USB Device driver
    6. The System Task must add calls the USB High Driver and the USB Device Driver.





## Additional Project Files

The following files need to be added to the project:

    1. Source Files / framework / driver usb / usbhs /src / dynamic 
        1. drv_usbhs.c
        2. drv_usbhs_device.c
    2. Source Files / framework / usb / src / dynamic
        1. usb_device.c
    3. Source Files / framework / usblan / src 
        * all .c files




## Application Layer diffs

````
diff --git b/tcpip_server/src/app.c a/tcpip_server/src/app.c
index 353c9f3..c4e8389 100644
--- b/tcpip_server/src/app.c
+++ a/tcpip_server/src/app.c
@@ -322,6 +322,14 @@ void _APP_ServerTasks()
 
 }
 
+/* Enable USBLAN, returns true if OK, or false for retry
+ */
+extern bool APP_Tasks_USBLAN_Enable(void);
+
 
 /******************************************************************************
   Function:
@@ -344,10 +352,23 @@ void APP_Tasks ( void )
             if(SYS_FS_Mount(SYS_FS_NVM_VOL, LOCAL_WEBSITE_PATH_FS, MPFS2, 0, NULL) == 0)
             {
                 SYS_CONSOLE_PRINT("SYS_Initialize: The %s File System is mounted\r\n", SYS_FS_MPFS_STRING);
-				appData.state = APP_TCPIP_WAIT_INIT;
+                appData.state = APP_USB_ENABLE;
             }
             break;
 
+            /* This will enable USBLAN */
+    case APP_USB_ENABLE:
+            SYS_PRINT("%s: APP_USB_ENABLE\r\n", __FUNCTION__);
+            appData.state = APP_Tasks_USBLAN_Enable() ? APP_TCPIP_WAIT_INIT : APP_USB_ENABLE; 
+            #else /* USBLAN */
+            appData.state = APP_TCPIP_WAIT_INIT;
+            break;
+
     case APP_TCPIP_WAIT_INIT:
             tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
             if(tcpipStat < 0)
diff --git b/tcpip_server/src/app.h a/tcpip_server/src/app.h
index 0dddbfb..254044a 100644
--- b/tcpip_server/src/app.h
+++ a/tcpip_server/src/app.h
@@ -97,6 +97,13 @@ typedef enum
 	/* Application's state machine's initial state. */
 	APP_MOUNT_DISK = 0,
 
+    /* This will enable USBLAN */
+    APP_USB_ENABLE,
+
     /* In this state, the application waits for a IP Address */
     APP_TCPIP_WAIT_INIT,
 
````


## pic32mz system config diffs

````
diff --git b/tcpip_server/src/system_config/pic32mz_ef_sk/system_config.h a/tcpip_server/src/system_config/pic32mz_ef_sk/system_config.h
index e50fd99..afb9432 100644
--- b/tcpip_server/src/system_config/pic32mz_ef_sk/system_config.h
+++ a/tcpip_server/src/system_config/pic32mz_ef_sk/system_config.h
@@ -663,6 +663,31 @@ extern "C" {
 #define TCPIP_NETWORK_DEFAULT_IPV6_PREFIX_LENGTH_IDX0	0
 #define TCPIP_NETWORK_DEFAULT_IPV6_GATEWAY_IDX0			0
 
+/*** Network Configuration Index 1 USBLAN ***/
+#define TCPIP_NETWORK_DEFAULT_INTERFACE_NAME_IDX1       "USBLAN"
+#define TCPIP_IF_USBLAN
+#define TCPIP_NETWORK_DEFAULT_HOST_NAME_IDX1            "USBLAN_E"
+#define TCPIP_NETWORK_DEFAULT_MAC_ADDR_IDX1             0
+#define TCPIP_NETWORK_DEFAULT_IP_ADDRESS_IDX1           "192.168.188.2"
+#define TCPIP_NETWORK_DEFAULT_IP_MASK_IDX1              "255.255.255.0"
+#define TCPIP_NETWORK_DEFAULT_GATEWAY_IDX1              "192.168.188.2"
+#define TCPIP_NETWORK_DEFAULT_DNS_IDX1                  "192.168.188.2"
+#define TCPIP_NETWORK_DEFAULT_SECOND_DNS_IDX1           "0.0.0.0"
+#define TCPIP_NETWORK_DEFAULT_POWER_MODE_IDX1           "full"
+#define TCPIP_NETWORK_DEFAULT_INTERFACE_FLAGS_IDX1          \
+                                                    TCPIP_NETWORK_CONFIG_DHCP_CLIENT_ON |\
+                                                    TCPIP_NETWORK_CONFIG_DNS_CLIENT_ON |\
+                                                    TCPIP_NETWORK_CONFIG_IP_STATIC 
+
+#define TCPIP_NETWORK_DEFAULT_MAC_DRIVER_IDX1           DRV_USBLAN_MACObject
+#define TCPIP_NETWORK_DEFAULT_IPV6_ADDRESS_IDX1         0
+#define TCPIP_NETWORK_DEFAULT_IPV6_PREFIX_LENGTH_IDX1   0
+#define TCPIP_NETWORK_DEFAULT_IPV6_GATEWAY_IDX1         0
+/*** end of Network Configuration Index 1 USBLAN ***/
 
 /*** TCPIP SYS FS Wrapper ***/
 #define SYS_FS_MAX_PATH						80
@@ -716,6 +741,13 @@ extern "C" {
 #define USB_DEVICE_EP0_BUFFER_SIZE      64
 
 
+/* Maximum instances of USBLAN function driver */
+#define USB_DEVICE_USBLAN_INSTANCES_NUMBER     1
 
 
 
diff --git b/tcpip_server/src/system_config/pic32mz_ef_sk/system_definitions.h a/tcpip_server/src/system_config/pic32mz_ef_sk/system_definitions.h
index 89feaf8..ba2dcf7 100644
--- b/tcpip_server/src/system_config/pic32mz_ef_sk/system_definitions.h
+++ a/tcpip_server/src/system_config/pic32mz_ef_sk/system_definitions.h
@@ -74,6 +74,11 @@ SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
 #include "net/pres/net_pres_encryptionproviderapi.h"
 #include "net/pres/net_pres_transportapi.h"
 #include "net/pres/net_pres_socketapi.h"
+#include "driver/usblan/usb_device_usblan.h"
 #include "app.h"
 
 
@@ -115,6 +120,14 @@ typedef struct
     SYS_MODULE_OBJ  drvNvm;
     SYS_MODULE_OBJ  sysDebug;
     SYS_MODULE_OBJ  sysConsole0;
+    SYS_MODULE_OBJ  drvUSBObject;
+    
+    SYS_MODULE_OBJ  usbDevObject0;
+
 
     SYS_MODULE_OBJ  tcpip;
     SYS_MODULE_OBJ  drvMiim;
diff --git b/tcpip_server/src/system_config/pic32mz_ef_sk/system_init.c a/tcpip_server/src/system_config/pic32mz_ef_sk/system_init.c
index 91185a3..063c8fd 100644
--- b/tcpip_server/src/system_config/pic32mz_ef_sk/system_init.c
+++ a/tcpip_server/src/system_config/pic32mz_ef_sk/system_init.c
@@ -206,6 +206,39 @@ const DRV_USART_INIT drvUsart0InitData =
 // </editor-fold>
 // <editor-fold defaultstate="collapsed" desc="DRV_USB Initialization Data">
+/******************************************************
+ * USB Driver Initialization
+ ******************************************************/
+const DRV_USBHS_INIT drvUSBHSInit =
+{
+    /* Interrupt Source for USB module */
+    .interruptSource = INT_SOURCE_USB_1,
+    
+    /* Interrupt Source for USB module */
+    .interruptSourceUSBDma = INT_SOURCE_USB_1_DMA,
+
+    /* System module initialization */
+    .moduleInit = {SYS_MODULE_POWER_RUN_FULL},
+
+    /* Operation Mode */
+    .operationMode = DRV_USBHS_OPMODE_DEVICE,
+
+    /* Operation Speed */ 
+    .operationSpeed = USB_SPEED_HIGH,
+    
+    /* Stop in idle */
+    .stopInIdle = false,
+
+    /* Suspend in sleep */
+    .suspendInSleep = false,
+
+    /* Identifies peripheral (PLIB-level) ID */
+    .usbID = USBHS_ID_0,
+    
+};
 // </editor-fold>
 
 // *****************************************************************************
@@ -522,6 +555,14 @@ const TCPIP_MODULE_MAC_PIC32INT_CONFIG tcpipMACPIC32INTInitData =
     .pPhyInit               = &tcpipPhyInitData,
 };
 
+/*** ETH MAC Initialization Data for USBLAN ***/
+extern const TCPIP_MODULE_MAC_PIC32INT_CONFIG tcpipMACUSBLANInitData;
+/*** end of ETH MAC Initialization Data for USBLAN ***/
+
 
 
 /*** Zeroconfig initialization data ***/
@@ -559,6 +600,29 @@ TCPIP_STACK_HEAP_INTERNAL_CONFIG tcpipHeapConfig =
  
 const TCPIP_NETWORK_CONFIG __attribute__((unused))  TCPIP_HOSTS_CONFIGURATION[] =
 {
+/*** Network Configuration Index 1 for USBLAN 
+ * IDX1 is used to avoid patching the ETHMAC driver config.
+ * This is placed first in the array to allow iperf to work. The tcpip iperf.c 
+ * does not correctly route to ip addresses in the second interface.
+ */
+    {
+        TCPIP_NETWORK_DEFAULT_INTERFACE_NAME_IDX1,       // interface
+        TCPIP_NETWORK_DEFAULT_HOST_NAME_IDX1,            // hostName
+        TCPIP_NETWORK_DEFAULT_MAC_ADDR_IDX1,             // macAddr
+        TCPIP_NETWORK_DEFAULT_IP_ADDRESS_IDX1,           // ipAddr
+        TCPIP_NETWORK_DEFAULT_IP_MASK_IDX1,              // ipMask
+        TCPIP_NETWORK_DEFAULT_GATEWAY_IDX1,              // gateway
+        TCPIP_NETWORK_DEFAULT_DNS_IDX1,                  // priDNS
+        TCPIP_NETWORK_DEFAULT_SECOND_DNS_IDX1,           // secondDNS
+        TCPIP_NETWORK_DEFAULT_POWER_MODE_IDX1,           // powerMode
+        TCPIP_NETWORK_DEFAULT_INTERFACE_FLAGS_IDX1,      // startFlags
+       &TCPIP_NETWORK_DEFAULT_MAC_DRIVER_IDX1,           // pMacObject
+    },
+/*** end of Network Configuration Index 1 for USBLAN ***/
 /*** Network Configuration Index 0 ***/
     {
         TCPIP_NETWORK_DEFAULT_INTERFACE_NAME_IDX0,       // interface
@@ -592,6 +656,11 @@ const TCPIP_STACK_MODULE_CONFIG TCPIP_STACK_MODULE_CONFIG_TBL [] =
     {TCPIP_MODULE_ZCLL,             0},                             // TCPIP_MODULE_ZCLL,
     { TCPIP_MODULE_MANAGER,         &tcpipHeapConfig },             // TCPIP_MODULE_MANAGER
     // MAC modules
+    {TCPIP_MODULE_MAC_USBLAN,       &tcpipMACUSBLANInitData},       // TCPIP_MODULE_MAC_USBLAN
     {TCPIP_MODULE_MAC_PIC32INT,     &tcpipMACPIC32INTInitData},     // TCPIP_MODULE_MAC_PIC32INT
 
 };
@@ -976,6 +1045,25 @@ void SYS_Initialize ( void* data )
     SYS_INT_VectorSubprioritySet(INT_VECTOR_UART2_RX, INT_SUBPRIORITY_LEVEL0);
     SYS_INT_VectorPrioritySet(INT_VECTOR_UART2_FAULT, INT_PRIORITY_LEVEL1);
     SYS_INT_VectorSubprioritySet(INT_VECTOR_UART2_FAULT, INT_SUBPRIORITY_LEVEL0);
+    /* Initialize USB Driver */ 
+    sysObj.drvUSBObject = DRV_USBHS_Initialize(DRV_USBHS_INDEX_0, (SYS_MODULE_INIT *) &drvUSBHSInit);
+    
+    /* Set priority of USB interrupt source */
+    SYS_INT_VectorPrioritySet(INT_VECTOR_USB1, INT_PRIORITY_LEVEL4);
+
+    /* Set Sub-priority of USB interrupt source */
+    SYS_INT_VectorSubprioritySet(INT_VECTOR_USB1, INT_SUBPRIORITY_LEVEL0);
+    
+    /* Set the priority of the USB DMA Interrupt */
+    SYS_INT_VectorPrioritySet(INT_VECTOR_USB1_DMA, INT_PRIORITY_LEVEL4);
+
+    /* Set Sub-priority of the USB DMA Interrupt */
+    SYS_INT_VectorSubprioritySet(INT_VECTOR_USB1_DMA, INT_SUBPRIORITY_LEVEL0);
+    
 
     /* Initialize System Services */
     SYS_PORTS_Initialize();
@@ -1012,6 +1100,13 @@ void SYS_Initialize ( void* data )
     sysObj.tcpip = TCPIP_STACK_Init();
     SYS_ASSERT(sysObj.tcpip != SYS_MODULE_OBJ_INVALID, "TCPIP_STACK_Init Failed" );
 
+    /* Initialize the USB device layer for USBLAN */
+    sysObj.usbDevObject0 = USB_DEVICE_Initialize (USB_DEVICE_INDEX_0 , ( SYS_MODULE_INIT* ) & usblanDevInitData);
+
     /* Enable Global Interrupts */
     SYS_INT_Enable();
 
diff --git b/tcpip_server/src/system_config/pic32mz_ef_sk/system_interrupt.c a/tcpip_server/src/system_config/pic32mz_ef_sk/system_interrupt.c
index db4e566..35c0ad1 100644
--- b/tcpip_server/src/system_config/pic32mz_ef_sk/system_interrupt.c
+++ a/tcpip_server/src/system_config/pic32mz_ef_sk/system_interrupt.c
@@ -106,6 +106,19 @@ void __ISR(_TIMER_2_VECTOR, ipl4AUTO) IntHandlerDrvTmrInstance0(void)
 
 }
 
+void __ISR(_USB_VECTOR, ipl4AUTO) _IntHandlerUSBInstance0(void)
+{
+    DRV_USBHS_Tasks_ISR(sysObj.drvUSBObject);
+}
+
+void __ISR ( _USB_DMA_VECTOR,ipl4AUTO) _IntHandlerUSBInstance0_USBDMA ( void )
+{
+    DRV_USBHS_Tasks_ISR_USBDMA(sysObj.drvUSBObject);
+}
 void __ISR(_ETHERNET_VECTOR, ipl5AUTO) _IntHandler_ETHMAC(void)
 {
     DRV_ETHMAC_Tasks_ISR((SYS_MODULE_OBJ)0);
diff --git b/tcpip_server/src/system_config/pic32mz_ef_sk/system_tasks.c a/tcpip_server/src/system_config/pic32mz_ef_sk/system_tasks.c
index a4bf163..a99e933 100644
--- b/tcpip_server/src/system_config/pic32mz_ef_sk/system_tasks.c
+++ a/tcpip_server/src/system_config/pic32mz_ef_sk/system_tasks.c
@@ -88,6 +88,17 @@ void SYS_Tasks ( void )
     /* Maintain the TCP/IP Stack*/
     TCPIP_STACK_Task(sysObj.tcpip);
 
+    /* USB HS Driver Task Routine */ 
+     DRV_USBHS_Tasks(sysObj.drvUSBObject);
+     
+ 
+    /* USB Device layer tasks routine */ 
+    USB_DEVICE_Tasks(sysObj.usbDevObject0);
+
     /* Maintain the application's state machine. */
     APP_Tasks();
 }
````



