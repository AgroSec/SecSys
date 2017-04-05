SET PATH=C:\Keil_v5\ARM\ARMCC\Bin;C:\ProgramData\Oracle\Java\javapath;C:\Program Files (x86)\Integrity\IntegrityClient10.8\bin;C:\Tool\Common\CTC\v6.5.5;C:\Tool\Common\Perl_5.12.4\site\bin;C:\Tool\Common\Perl_5.12.4\bin;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\OpenVPN\bin;C:\Program Files (x86)\Skype\Phone\;C:\Program Files\Git\cmd;C:\Program Files (x86)\Windows Kits\8.1\Windows Performance Toolkit\;C:\Program Files\Microsoft SQL Server\110\Tools\Binn\;C:\Program Files (x86)\Microsoft SDKs\TypeScript\1.0\;C:\Tool\Common\TDM-GCC-64\bin;C:\Program Files\Microsoft SQL Server\120\Tools\Binn\
SET ARMCC5_ASMOPT=--diag_suppress=9931
SET ARMCC5_CCOPT=--diag_suppress=9931
SET ARMCC5_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=TM4C123GH6PM
SET CPU_VENDOR=Texas Instruments
SET UV2_TARGET=SecSysTM4C
SET CPU_CLOCK=0x00B71B00
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\main._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\main.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\os_core._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\os_core.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\generated\objects\osasm._ia"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\os_hw._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\os_hw.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\gsm._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\gsm.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\pir._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\pir.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\hx711._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\hx711.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\UART_H~1._IP"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\uart_handler.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\GPIO_H~1._IP"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\gpio_handler.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\CYCLIC~1._IP"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\cyclic_activity_handler.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\STARTU~1._IP"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\startup_handler.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\profile._ip"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\profile.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\generated\objects\startup_tm4c123._ia"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via "GENERA~1\listings\SYSTEM~1._IP"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\generated\objects\system_tm4c123.__i"
"C:\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via ".\generated\Objects\ssOS.lnp"
"C:\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" ".\generated\Objects\ssOS.axf" --i32combined --output ".\generated\Objects\ssOS.hex"
