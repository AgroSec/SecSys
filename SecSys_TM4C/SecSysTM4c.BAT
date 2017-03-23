SET PATH=C:\Keil_v5\ARM\ARMCC\Bin;C:\Python27\;C:\Python27\Scripts;C:\ProgramData\Oracle\Java\javapath;C:\Tool\Common\Perl32\site\bin;C:\Tool\Common\Perl32\bin;C:\Tool\Common\Perl64\site\bin;C:\Tool\Common\Perl64\bin;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;c:\Tool\Common\CMake_2.8\bin;C:\Program Files\OpenVPN\bin;C:\Program Files (x86)\Java\jre1.8.0_71\bin;C:\Program Files (x86)\Integrity\IntegrityClient10.5\bin;C:\Tool\Common\TDM-GCC-32\bin;C:\Program Files (x86)\Windows Kits\8.1\Windows Performance Toolkit\;C:\Program Files\Microsoft SQL Server\110\Tools\Binn\;C:\Program Files (x86)\Microsoft SDKs\TypeScript\1.0\;C:\Program Files\Microsoft SQL Server\120\Tools\Binn\;C:\Tool\Common\Git\cmd;C:\Program Files (x86)\Gource\cmd;C:\Program Files (x86)\Skype\Phone\
SET CPU_TYPE=TM4C123GH6PM
SET CPU_VENDOR=Texas Instruments
SET UV2_TARGET=SecSysTM4C
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\os_core._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\os_core.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\generated\objects\osasm._ia"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\os_hw._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\os_hw.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\main._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\main.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\profile._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\profile.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\GSM_HA~1._IP"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\gsm_handler.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\PIR_HA~1._IP"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\pir_handler.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\generated\objects\startup_tm4c123._ia"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\SYSTEM~1._IP"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\system_tm4c123.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via ".\generated\Objects\ssOS.lnp"
"C:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" ".\generated\Objects\ssOS.axf" --i32combined --output ".\generated\Objects\ssOS.hex"
