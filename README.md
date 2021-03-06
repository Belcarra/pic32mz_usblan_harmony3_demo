# Belcarra PIC32MZ USBLAN Harmony 3 Demonstration Project

This is a demonstration project for the **Belcarra PIC32MZ USBLAN Driver** using either of **Microchip's** 
**PIC32MZ EF Starter Kit** or **PIC32MZ EF Curiosity Board**.

It will demonstrate how **Networking over USB** can be used as an alternative to **Ethernet** or
**WiFi** to provide low cost networking to a Microchip PIC32MZ based board with performance that is close to Ethernet at over 80Mbps per second.

**Networking over USB** allows a point to point network connection to be used between
the PIC32MZ board and a Windows, Mac or Linux host.

This project is based on the [**Microchip Harmony 3 Framework demonstration project**](https://github.com/Microchip-MPLAB-Harmony):

    - net/apps/tcpip/web_net_server_nvm_mpfs

It was developed using:

- [**MPLAB X IDE v5.20**](https://www.microchip.com/mplab/mplab-x-ide)
- [**MPLAB XC32 Compiler**](https://www.microchip.com/mplab/compilers)

It is not necessary to have the **Harmony 3 Framework* or the **MPLAB Code Configurator** installed. 

There are two projects available in the kit:

- firmware/pic32mz_ef_sk.X - support for the PIC32MZ_EF_SK Ethernet Starter Kit
- firmware/pic32mz_ef_curiosity.X - support of the PIC32MZ_EF_CURIOSITY Board

The sample application was modified to add the following Harmony 3 components:

- net Telnet
- net Iperf
- net Zeroconf
- USB High Speed Driver
- USB Device Driver
- Belcarra PIC32MZ USBLAN Function Driver

The **Belcarra PIC32MZ USBLAN Function Driver** is a TCPIP NIC driver that uses the PIC32MZ USB High Speed Device Driver
to connect to another system. It uses CDC-EEM to transfer network packets to and from the other system. 
The driver is distributed in this project as a libary archive (libusblan.a)

## Testing

To test with this project you need:

- have MPLAB X IDE installed
- have the Microchip XC compiler installed
- have either the PIC32MZ EF SK or PIC32MZ EF Curiosity Board

The project has all of the files needed to compile and build the test application. It is not necessary to have the Harmony 3 Framework installed. 

## Belcarra Windows USBLAN 
A git archive containing Windows drivers that support this demonstration project is available here:

- [belcarra_usblan_iot_demo_drivers](https://github.com/Belcarra/belcarra_usblan_iot_demo_drivers.git)

For information on obtaining a licensed copy of the Belcarra driver contact Email: [info@belcarra.com](mailto://info@belcarra.com)
 
## Supported Microchip Evaluation Boards

- PIC32MZ EF Ethernet Starter Kit (pic32mz_ef_sk)
- PIC32MZ EF Curiosity Board Bundle (pic32mz_ef_curiosity)
- PIC32MZ EC Ethernet Starter Kit (pic32mz_ec_sk)

## CDC-EEM

**Networking over USB** uses a USB connection to transfer TCP IP Frames (aka packets) between the USB Device (in this case a Microchip Evaluation Board) and a
USB Host (typically a Windows, Mac or Linux system.)

The **Belcarra PIC32MZ USBLAN Driver** implements **CDC-EEM**. The **CDC-EEM** protocol allows for simple point to point transfer of frames between the USB
Host and the USB Device. It supports frame aggregation and his very little overhead.

The **USBLAN** driver supports zero-copy received frames. I.e. the data is received into a receive buffer by the USB High Speed driver and that buffer is given
to the TCPIP layer for processing.

The **USBLAN** driver also supports zero-copy transmit frames or can aggregate multiple frames depending on how the data is formatted by the TCPIP lyaer.


## Performance

Using iperf the pic32mz_ef_sk board can source TCP data at about **70-80 Mbits/second with Ethernet** and about **60-70 Mbits/second using USBLAN**.

## Microchip Eval Boards 

### PIC32MZ_EF_SK - Ethernet Starter Kit PIC32MZ2048EFM144 - [DM320007-C](https://www.digikey.ca/product-detail/en/microchip-technology/DM320007-C/DM320007-C-ND/5401235)

Configurations:

- pic32mz_ef_sk_usblan - USBLAN and Ethernet

There are two versions of this kit, you may to need to chnage the processor selection to match your kit:

- DM30007 - non-crypto PIC32MZ2048EFH144
- DM30007-C - crypto PIC32MZ2048EFM1444

![pic32mz_ef_sk][pic32mz_ef_sk]


### PIC32MZ_EF_CURIOSITY - Curiosity Board PIC32MZ2048EFM100 - [DM320104-BNDL](https://www.digikey.ca/product-detail/en/microchip-technology/DM320104-BNDL/DM320104-BNDL-ND/9094799a)

**N.B. the USB UART is shown plugged into Mikro Bus #1. The project configuration requires it to be in Mikro Bus #2.**

Configurations:

- pic32mz_ef_sk_curiosity_usblan - USBLAN and Ethernet

![pic32mz_ef_curiosity][pic32mz_ef_curiosity] 




### PIC32MZ_EC_SK - Ethernet Starter Kit PIC32MZ2048ECH144 

Configurations:

- pic32mz_ec_sk_usblan - USBLAN and Ethernet

N.B. The dev pack in *PIC32MZ-EC_DFP* for mplabx v5.30 is up to date with all of the required changes to support the EC version of the starter kit.
A set of fixes sufficient to allow the project to compile and work is provided in:
'''
src/packs/PIC32MZ2048ECH144_DFP/p32mz2048ech144-fixes.h
'''

N.B. The ECH chip does not support hardware float and as configured the project compiles with a warning that "soft float" is used.


![pic32mz_ec_sk][pic32mz_ec_sk]


[pic32mz_ef_sk]: /img/pic32mz_ef_sk.png
[pic32mz_ef_curiosity]: /img/pic32mz_ef_curiosity.png
[pic32mz_ec_sk]: /img/pic32mz_ec_sk.png

## Testing Setup

Use two systems:
    1. Linux development and testing for Ethernet
    2. Windows for testing USBLAN

Linux setup:
    - Chrome with two tabs open, for the two possible IP addresses that may be used for the Ethernet (depending if the Ethernet is the first or second interface). E.g.: http://192.168.40.145/ - Ethernet only configurations http://192.168.40.146/ - USBLAN and Ethernet configurations
    - Terminal window open running minicom pointing at appropriate serial port, configured to 460800 baud. Port names may vary, but on my system: /dev/ttyACM0 - PIC32MZ EF SK USB2UART port /dev/tty/USB0 - PIC32MZ EF Curiosity USBUART click board port

Windows setup:
    - Chrome with one tab open, set to the USBLAN IP address. E.g: http://192.168.188.2/
    - Terminal window (e.g. Cygwin mintty). Various tests, but typically: ping 192.168.188.2

The Chrome tabs should display the following screen, with the Random Number being updated rapidly:

![Web Server Screen](/img/demo-webserver.png)

For the non _usblan_ configurations you will only see the webpage on the Ethernet IP address. 

IP address:

- Ethernet is assigned by DHCP from your local DHCP server, see it's DHCP Lease table
- USBLAN will be at 192.168.188.2


On the Starter Kits only buttons 1 and 2 work. Button 3 functionality is lost because the MPU pin it is on is used for the USB2UART Tx line.

On the Curiosity board, there is only one button. 

## MPLAB X IDE Upgrading

If you have an newer version of MPLAB X you may see the following error:

![DFP Error](/img/dfp_error.png)


If you click on the highlighted link "Resolve DFP for project ..." 

You should see:

![DFP Property](/img/dfp_prop.png)

Select the next higher pack number (in this case 1.1.45), then click OK to save.

## PIC32MZ EF Curiosity 

The current (mid 2019) Harmony 3 framework does not have any PIC32MZ EF Curiosity board application samples. 
It does have the support so that the Harmony Configurator 3 can support the board. 

This was done by duplicating the pic32mz_ef_sk project to get a pic32mz_ef_curiosity project. After changing
the processor from PIC32MZ2048EFM144 to PIC32MZ2048EFM100 the MHC Pin configuration table was used
to setup of the correct pin configuration.

The following pins were added to the pin configuration:

PIC32MZ EF Curiosity Tx/RX Pins

| Pin | Signal |
| --- | ---------|
| 2 | BSP_STBY_RST |
| 7 | U2TX |
| 8 | U2RX |
| 11 | ERXCV |
| 16 | ERXCLK |
| 20 | RGB_LED_RED | 
| 24 | RGB_LED_GREEN |
| 25 | RGB_LED_BLUE |
| 35 | ERXERR |
| 39 | INT1 |
| 40 | INT2 |
| 41 | ERXD0 |
| 42 | ERXD1 |
| 48 | U1TX |
| 49 | CLKI |
| 64 | BSP_WIFI_INT |
| 69 | U1RX |
| 70 | EMDC |
| 71 | EMDIO |
| 76 | ETXEN |
| 85 | ETXD1 |
| 86 | ETXD0 |
| 96 | SWITCH1 |
| 99 | LED1 |
| 100 | LED2 |



## Release Notes

### 2019-11-06
    - update for mplab x ide v5.30

### 2019-10-16 
    - moved to mplab x ide v5.20
    - moved to web_net_server_nvm_mpfs from Harmony 3
    - added support for USB 
    - added support for pic32mz ef Curiosity board


