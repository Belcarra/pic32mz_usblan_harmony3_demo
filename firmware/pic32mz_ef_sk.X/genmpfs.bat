
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

