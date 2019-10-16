/*********************************************************************
* File Name: http_net_print.h
*
* Provides callback headers and resolution for user's custom
* HTTP NET Application.
* 
* This file is automatically generated by the MPFS Utility
* ALL MODIFICATIONS WILL BE OVERWRITTEN BY THE MPFS GENERATOR
* 
*********************************************************************/

/*****************************************************************************
Copyright (C) 2012-2018 Microchip Technology Inc. and its subsidiaries.

Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software 
and any derivatives exclusively with Microchip products. It is your
responsibility to comply with third party license terms applicable to your
use of third party software (including open source software) that may
accompany Microchip software.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR
PURPOSE.

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*****************************************************************************/

#ifndef _HTTP_NET_PRINT_H
#define _HTTP_NET_PRINT_H

/****************************************************************************
Section:
	Dynamic Variables Function Prototypes

Remarks:
	There are no predefined functions that do the dynamic variables processing.
	The only interface between the application and the HTTP module is done using
	TCPIP_HTTP_NET_UserHandlerRegister() call.
	Therefore, whenever the HTTP module will encounter a dynamic variable it will
	simply call the "dynamicPrint" function that was registered!
	It is up to the application to detect what dynamic variable is processed by
	examining the TCPIP_HTTP_DYN_VAR_DCPT *parameter that's passed to the function
	and take appropriate action.

	The mpfs generator does not generate a list of dynamic variables functions anymore.
	All the dynamic variable processing happens at run time!
	Web pages could be changed at run time and the web server will work just fine
	(providing that the application properly processes the dynamic variables).

	These are just functions  belonging to the application.
	They can have any name the application uses to.
****************************************************************************/

TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_hellomsg(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_cookiename(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_cookiefav(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_builddate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_led(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_ledSelected(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_version(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_drive(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_fstype(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_btn(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_pot(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_uploadedmd5(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_snmp_en(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_read_comm(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_write_comm(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_status_fail(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_config_mac(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_config_hostname(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_config_dhcpchecked(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_config_ip(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_config_gw(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_config_subnet(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_config_dns1(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_config_dns2(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_reboot(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_rebootaddr(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_status_ok(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_ddns_status(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_ddns_status_msg(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_ddns_service(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_ddns_user(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_ddns_pass(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_Print_ddns_host(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);

/*****************************************************************************
  Function:
    TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionGetExecute(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)

  Internal:
    See documentation in the TCP/IP Stack APIs or http_net.h for details.
****************************************************************************/
TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionGetExecute(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack);

/*****************************************************************************
  Function:
    TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionPostExecute(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)

  Internal:
    See documentation in the TCP/IP Stack APIs or http_net.h for details.
****************************************************************************/
TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionPostExecute(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack);

/*****************************************************************************
  Function:
    uint8_t TCPIP_HTTP_NET_ConnectionFileAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, uint8_t *cFile, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)

  Internal:
    See documentation in the TCP/IP Stack APIs or http_net.h for details.
****************************************************************************/
#if defined(TCPIP_HTTP_NET_USE_AUTHENTICATION)
uint8_t TCPIP_HTTP_NET_ConnectionFileAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const char *cFile, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack);


/*****************************************************************************
  Function:
    uint8_t TCPIP_HTTP_NET_ConnectionUserAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const char *cUser, const char *cPass, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack)

  Internal:
    See documentation in the TCP/IP Stack APIs or http_net.h for details.
****************************************************************************/
uint8_t TCPIP_HTTP_NET_ConnectionUserAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const char *cUser, const char *cPass, const TCPIP_HTTP_NET_USER_CALLBACK *pCBack);
#endif

 // processing the HTTP buffer acknowledgment
void TCPIP_HTTP_NET_DynAcknowledge(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const void *buffer, const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK *pCBack);

// processing the HTTP reported events
void TCPIP_HTTP_NET_EventReport(TCPIP_HTTP_NET_CONN_HANDLE connHandle, TCPIP_HTTP_NET_EVENT_TYPE evType, const void *evInfo, const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK *pCBack);

// example of processing an SSI notification
// return false for standard processing of this SSI command by the HTTP module
// return true if the processing is done by you and HTTP need take no further action
bool TCPIP_HTTP_NET_SSINotification(TCPIP_HTTP_NET_CONN_HANDLE connHandle, TCPIP_HTTP_SSI_NOTIFY_DCPT *pSSINotifyDcpt, const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK *pCBack);

/****************************************************************************
  Section:
    Application Dynamic Variables processing functions.
    For easy processing and facilitating of the transfer from the old style of
    processing the dynamic variables with pre-defined functions,
    the new dynamic variables functions maintain the old name and
    a table showing the correspondence between the dynamic variable name
    and the function that processes that variable i smaintained in this
    coming HTTP_APP_DynVarTbl[].
    Note that this is just an example.
    The application could opt for any type of proccessing it needs to do at run time.

    See http_net.h for details regarding each of these functions.
****************************************************************************/

// application HTTP dynamic variables processing function
typedef TCPIP_HTTP_DYN_PRINT_RES (*HTTP_APP_DYNVAR_FNC)(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT *vDcpt);

// an entry for the application processing HTTP dynamic variables
typedef struct
{
    const char *varName;        // name of the dynamic variable
    HTTP_APP_DYNVAR_FNC varFnc; // processing function
}HTTP_APP_DYNVAR_ENTRY;

// Number of buffers to be used by the app for dynamic variable callbacks
#define HTTP_APP_DYNVAR_BUFFERS_NO      4

// size of an allocated dynamic variable call back buffer
#define HTTP_APP_DYNVAR_BUFFER_SIZE     100

//An entry for the dynamic variables which is used during the dynamic variable processing
typedef struct
{
    uint16_t    busy;           // buffer is currently in process
    uint16_t    bufferSize;     // size of the associated buffer
    char        data[HTTP_APP_DYNVAR_BUFFER_SIZE];  // buffer for writing the dynamic variable callback content
}HTTP_APP_DYNVAR_BUFFER;

/****************************************************************************
  Section:
    Application initialization and HTTP registration.
    Here the application registers with the HTTP module the functions
    that will process the HTTP events (dynamic variables, SSI events, Post, Get, etc.).
    Note that without registering the process functions with HTTP, there won't be any web page processing.
    There is no default processing for a web page!

    See http_net.h for details regarding each of these functions.
****************************************************************************/
void HTTP_APP_Initialize(void);

// helper to get one of the application's dynamic buffer that are used in the
// dynamic variables processing
HTTP_APP_DYNVAR_BUFFER *HTTP_APP_GetDynamicBuffer(void);


#endif /* _HTTP_NET_PRINT_H */
