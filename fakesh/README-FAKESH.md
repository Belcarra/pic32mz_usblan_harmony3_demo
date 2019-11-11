# README-Fakesh

MPLAB X IDE supports calling a script prior to building. 

Unfortunately this how this script is run depends on what system you are running on:

- Windows - command.exe
- Linux / MacOS - /bin/sh

The default for the serverdemo project runs java with arguements that java understands in both a Windows Command execution or Posix Shell environment.

```
java.exe -jar %H3PATH%\net\utilities\mpfs_generator\mpfs.jar /c /z "snmp.bib" "..\src\web_pages" "..\src" "mpfs_net_img.c"
```

Using a script we can do a lot more. E.g. generate a build specific confname.h file containing interesting information:

```
/* DO NOT EDIT - see src/genmpf.bats which is called from project properties building */
#define PROJDIR "pic32mz_usblan_harmony3_demo"
#define PROJNAME "usblan_demo_pic32mz_ef_sk "
#define CONFNAME "pic32mz_ef_sk"
#define DEVICE "PIC32MZ2048EFM144'"
```

But generating that requires running a shell script for Posix shell systems (Linux and MacOS) or a bat file for Windows.

Worse the requirements for formatting the command to be run is differnt for both systems.

- Posix shell - requires a full or relative path for the script (if not something that can be found in $PATH)
- Windows - does not understand a relative path or a path with forward slashes


To work around this the fakesh.s program takes a command string formated correctly for Posix shell, assumes that the path is relative to the calling directory, 
and calls the without the relative file path. 

I.e. ./genmpfs becomes simply genmpfs. If genmpfs.bat exists then Windows command.exe will run it with the supplied arguments.


This allows us to have two scripts:

1. genmpfs - Posix shell script
2. genmpfs.bat - Windows command bat file

Both scripts do the same, and can be invoked with the same arguements. 

The following is the command as seen in the configuration.xml file (see Properties / Building / Pre and Post build options.)


```
<makeCustomizationType>
<makeCustomizationPreStepEnabled>true</makeCustomizationPreStepEnabled>
<makeCustomizationPreStep>sh -c ''./genmpfs ${ProjectDir} ${ProjectName} ${ConfName} ${Device}'</makeCustomizationPreStep>
<makeCustomizationPostStepEnabled>false</makeCustomizationPostStepEnabled>
			        
```

