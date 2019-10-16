# Web Net Server Demo

This is a Microchip demonstration for the **Belcarra PIC32MZ USBLAN Driver**. 
It demonstrates how **Networking over USB** can be used instead of **Ethernet** or
**WiFi** to provide networking to a Microchip PIC32MZ based board.

It is based on the **Microchip Harmony 3 Framework demonstration project**:

    - **apps/tcpip/web_net_server_nvm_mpfs**

The project was developed using **MPLAB X IDE v5.20** 

There are two projects available:

    * pic32mz_ef_sk.X - support for the PIC32MZ_EF_SK Ethernet Starter Kit
    * pic32mz_ef_curiosity.X - support of the PIC32MZ_EF_CURIOSITY Board


The project has been modified to add the following Harmony 3 components:

    * net Telnet
    * net Iperf
    * net Zeroconf
    * USB High Speed Driver
    * USB Device Driver

This demonstration can be used with or without the Belcarra USBLAN Driver:

    * The **Belcarra PIC32MZ USBLAN Driver** can be used if installed in the Harmony 3 Framework drivers directory.


## Supported Microchip Evaluation Boards

    - **PIC32MZ EF Ethernet Starter Kit** (pic32mz_ef_sk)
    - **PIC32MZ EF Curiosity Board Bundle **(pic32mz_ef_curiosity)

## Networking Over USB - CDC-EEM

**Networking over USB** uses a USB connection to transfer TCP IP Frames (aka packets) between the USB Device (in this case a Microchip Evaluation Board) and a
USB Host (typically a Windows, Mac or Linux system.)

There are various protocols defined by USB.org:

    * CDC-ECM
    * CDC-EEM
    * CDC-NCM

The **Belcarra PIC32MZ USBLAN Driver** implements **CDC-EEM**. The **CDC-EEM** protocol allows for simple point to point transfer of frames between the USB
Host and the USB Device. It supports frame aggregation and his very little overhead.

The **USBLAN** driver supports zero-copy received frames. I.e. the data is received into a receive buffer by the USB High Speed driver and that buffer is given
to the TCPIP layer for processing.

The **USBLAN** driver also supports zero-copy transmit frames or can aggregate multiple frames depending on how the data is formatted by the TCPIP lyaer.


## Performance

Using iperf the pic32mz_ef_sk board can source TCP data at about **70-80 Mbits/second with Ethernet** and about **60-70 Mbits/second using USBLAN**.

## Belcarra PIC32MZ USBLAN Driver

The _usblan_ configurations require the **Belcarra PIC32MZ USBLAN Driver**. That driver is available under license from Belcarra Technologies.

Contact Email: [info@belcarra.com](mailto://info@belcarra.com)


## Microchip Eval Boards 

### PIC32MZ_EF_SK - Ethernet Starter Kit PIC32MZ2048EFM144 - [DM320007-C](https://www.digikey.ca/product-detail/en/microchip-technology/DM320007-C/DM320007-C-ND/5401235)

Configurations:

    - pic32mz_ef_sk_usblan - USBLAN and Ethernet
    - pic32mz_ef_sk - Ethernet only 

![pic32mz_ef_sk][pic32mz_ef_sk]


### PIC32MZ_EF_CURIOSITY - Curiosity Board PIC32MZ2048EFM100 - [DM320104-BNDL](https://www.digikey.ca/product-detail/en/microchip-technology/DM320104-BNDL/DM320104-BNDL-ND/9094799a)

**N.B. the USB UART is shown plugged into Mikro Bus #1. The project configuration requires it to be in Mikro Bus #2.**

Configurations:

    - pic32mz_ef_sk_curiosity_usblan - USBLAN and Ethernet
    - pic32mz_ef_sk_curiosity - Ethernet only

![pic32mz_ef_curiosity][pic32mz_ef_curiosity] 



[pic32mz_ef_sk]: /img/pic32mz_ef_sk.png
[pic32mz_ef_curiosity]: /img/pic32mz_ef_curiosity.png

## Configurations

    - pic32mz_ef_sk_usblan - USBLAN and Ethernet
    - pic32mz_ef_sk_curiosity_usblan - USBLAN and Ethernet
    - pic32mz_ec_sk_usblan - USBLAN and Ethernet
    - pic32mz_ef_sk - Ethernet only
    - pic32mz_ef_sk_curiosity - Ethernet only
    - pic32mz_ec_sk - Ethernet only


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

![Web Server Screen](/img/demo-webserver.png "web server")

For the non _usblan_ configurations you will only see the webpage on the Ethernet IP address. 

IP address:

    - Ethernet is assigned by DHCP from your local DHCP server, see it's DHCP Lease table
    - USBLAN will be at 192.168.188.2


On the Starter Kits only buttons 1 and 2 work. Button 3 functionality is lost because the MPU pin it is on is used for the USB2UART Tx line.

On the Curiosity board, there is only one button. 



## PIC32MZ EF Curiosity - Enabling Rx/Tx to Mikro Bus slots

The base configuration for the pic32mz_ef_sk_curiosity did not have USART #1 and #2 pins on the MPU enabled.

The following pins were added to the pin configuration:

| PIC32MZ EF Curiosity Tx/RX Pins | |
| Pin | Signal |
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

### 2019-10-16 
    - moved to mplab x ide v5.20
    - moved to web_net_server_nvm_mpfs from Harmony 3
    - added support for USB 
    - added support for pic32mz ef Curiosity board


