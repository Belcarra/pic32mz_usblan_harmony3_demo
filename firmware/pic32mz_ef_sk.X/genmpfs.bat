: #
: # Copyright (c) 2019 Belcarra Technologies
: # Stuart.Lynne@belcarra.com
: #
: # Linux/Mac sh / Windows bat file version of genmpfs
: # 
: # This is a hack that allows a single file to be used in mplabs x ide configuration to 
: # do prebuild actions for both Windows and systems with Posix Shells (Linux and MacOS).
: # 
: # This script is called before building. It will generate confname.h and
: # rebuild the web image .c files.
: #
: # We jump through some hoops to allow Posix Shell and Windows command.exe to 
: # work....
: #
: #	1. This file MUST BE in DOS CR/LF format
: #	2. BAT comments start with :
: #	3. BAT and Linux comment start with : #
: #	4. BAT Comment, Linux command, :; COMMAND HERE
: #	5. BAT will jump over anything with goto 
: # 	6. Linux shell will ignore anything in if [false] ;then ignore here ; fi
: #
: #
: # The defaults for H3PATH and JREPATH are dependent on the local
: # system configuration. Change as needed. 
: #
: # Only the mpfs generator from the Harmony 3 Framework is required. 
: # 
: # The contents of:
: # 	/HarmonyFramework3/net/utilties/mpfs_generator
: #	
: # 
: # Linux default:
: # 	H3PATH="/HarmonyFramework3"
: #	
: # Windows (mplab x ide v5.30):
: #	H3PATH="\HarmonyFramework3"
: #	JREPATH="\Program Files (x86)\Microchip\MPLABX\v5.30\sys\java\jre1.8.0_181\bin\"
: #
: #
: # This script should be called for the Pre Build operation. See properties / building.
: #
: #	genmpfs.bat ${ProjectDir} ${ProjectName} ${ConfName} ${Device}
: #
: # It will generate a config/${ConfName}/confname.h file containing:
: #
: #  	#define PROJDIR "pic32mz_usblan_harmony3_demo"
: #  	#define PROJNAME "usblan_demo_pic32mz_ef_sk"
: #  	#define CONFNAME "pic32mz_ef_sk"
: #  	#define DEVICE "PIC32MZ2048EFM144"
: # 

: # Shell will ignore @echo goto, Windows will ignore if and goto :WINDOWS
: #
:; if [ -z 0 ] ; then
    @echo off
    goto :WINDOWS
fi

: # Shell will start processing here, this is ignored by Windows

    :; Linux/Mac sh script
    :;
    echo SHELL

    # Set to installation path for HARMONY3
    # This is only required to be able to update the web pages
    #
    H3PATH="/HarmonyFramework3"

    if [ ! -d "${H3PATH}" ] ; then
	(
	sleep 2
	echo
	echo "Cannot see HarmonyFramework installed in: ${H3PATH}"
	echo "Install HarmonyFramework 3 and / or set location in firmware/src/genmpfs.bat file"
	echo "Web Pages will not be rebuilt"
	echo
	) 1>&2 
	exit 0
    fi

    PROJDIR=$(echo $1 | sed -e 's/.*\/\(.*\)\/firmware.*/\1/')
    PROJNAME=$2
    CONFNAME=$3
    DEVICE=$4

    printf '\r\nHarmony3: %s\r\nPROJDIR: %s CONFNAME: %s DEVICE: %s\r\n\r\n' ${H3PATH}  ${PROJDIR} ${CONFNAME} ${DEVICE} 

    (
    echo "/* DO NOT EDIT - see src/genmpfs.bat which is called from project properties building */"
    echo 
    echo '#define PROJDIR "'$PROJDIR'"' 
    echo '#define PROJNAME "'$PROJNAME'"' 
    echo '#define CONFNAME "'$CONFNAME'"' 
    echo '#define DEVICE "'$DEVICE'"' 
    ) > ../src/config/${CONFNAME}/confname.h

    set -x
    java -jar ${H3PATH}/net/utilities/mpfs_generator/mpfs.jar /c /z "snmp.bib" "../src/web_pages" "../src" "mpfs_net_img.c"

    exit

: # Windows will start here

:; Windows bat script
:;
:WINDOWS

    ECHO OFF
    ECHO WINDOWS

    if "%H3PATH%" == "" GOTO H3PATHNOTSET
	GOTO H3PATHSET
    :H3PATHNOTSET
    set H3PATH=\HarmonyFramework3
    
    :H3PATHSET


    if "%JREPATH%" == "" GOTO JREPATHNOTSET
	GOTO JREPATHSET
    :JREPATHNOTSET
    set JREPATH="\Program Files (x86)\Microchip\MPLABX\v5.30\sys\java\jre1.8.0_181\bin"

    :JREPATHSET

    echo %H3PATH%
    echo %JREPATH%

    if not exist %H3PATH% ( echo CANNOT FIND %H3PATH% && echo WEB PAGES NOT REBUILT && exit 0)
    if not exist %JREPATH% ( echo CANNOT FIND %JREPATH% && echo WEB PAGES NOT REBUILT && exit 0)

    rem Get the project dir the hard way!
    rem Format is ...\pic32mz_usblan_harmony3_demo\firmware\pic32mz_ef_sk.X 
    rem Need to remove the last two directory names to get the project directory,
    rem then remove everything above that.
    rem 
    set p0=%1
    :echo p0: %p0%
    for %%i in ( %p0% ) do set p1=%%~pi
    :echo p1: %p1%
    set p2=%p1:~0,-1%
    :echo p2: %p2%
    for %%j in ( %p2% ) do set p3=%%~pj
    :echo p3: %p3%
    set p4=%p3:~0,-1%
    :echo p4: %p4%
    for %%k in ( %p4% ) do set p5=%%~nk
    :echo p5: %p5%
    
    set PROJDIR=%p5%
    set PROJNAME=%2 
    set CONFNAME=%3
    set DEVICE=%4
    > ..\src\config\%CONFNAME%\confname.h (
	echo /* DO NOT EDIT - see src/genmpf.bats which is called from project properties building */
	echo #define PROJDIR "%PROJDIR%" 
	echo #define PROJNAME "%PROJNAME%" 
	echo #define CONFNAME "%CONFNAME%" 
	echo #define DEVICE "%DEVICE%"
    )

    ECHO ON
    %JREPATH%\java.exe -jar %H3PATH%\net\utilities\mpfs_generator\mpfs.jar /c /z "snmp.bib" "..\src\web_pages" "..\src" "mpfs_net_img.c"

    exit 0

