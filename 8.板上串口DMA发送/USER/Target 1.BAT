SET PATH=F:\Keil_v5\ARM\ARMCC\bin\;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\Java\jdk1.8.0_121\bin;C:\Program Files\Java\jdk1.8.0_121\jre\bin;F:\eclipse\platform-tools;F:\eclipse\tools;C:\Program Files\MySQL\MySQL Utilities 1.6\;F:\MATLAB\runtime\win64;F:\MATLAB\bin;C:\Users\ว๏สต\AppData\Local\Programs\Python\Python36-32\Scripts\;C:\Users\ว๏สต\AppData\Local\Programs\Python\Python36-32\;C:\Users\ว๏สต\AppData\Local\Microsoft\WindowsApps;
SET CPU_TYPE=STM32F103C8
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x044AA200
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\main.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\stm32f10x_it.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\system_stm32f10x.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\dma.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\delay.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\sys.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\usart.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\misc.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\stm32f10x_dma.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\stm32f10x_gpio.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\stm32f10x_rcc.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmCC" --Via "..\obj\stm32f10x_usart.__i"
"F:\Keil_v5\ARM\ARMCC\bin\ArmAsm" --Via "..\obj\startup_stm32f10x_md._ia"
"F:\Keil_v5\ARM\ARMCC\bin\ArmLink" --Via "..\OBJ\PROJECT1.lnp"
"F:\Keil_v5\ARM\ARMCC\bin\fromelf.exe" "..\OBJ\PROJECT1.axf" --i32combined --output "..\OBJ\PROJECT1.hex"
