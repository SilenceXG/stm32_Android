# stm32_Android
Repo contents:

LPC1768_mbed: 
Serial client based on LPC1768 using mbed platform. Exported as uVision project.
Instruction: 
Download Keil uVision 5 and open Test_usb_connection.uvprojx. Compile all and load program on LPC1768 board.

stm32_uart_send:
Serial client with transmit functionality. Receiving can be configured using interrupt.

UsbSerial:
Android App based on Android studio IDE.
Instruction:
Use Android studio and open UsbSerial project. Run example.
The example has been tested using Android VM.


USB_CDC_Virtual_Com_Port (Obsolete)
Serial client based on STM32. Board is configured through STM32CubeMX. 
Instruction:
To config pinout and STM32-related parameters, use STM32CubeMX to open USB_CDC_Virtual_Com_Port.ioc
To run the program, open ./MDK-ARM/USB_CDC_Virtual_Com_Port.uvprojx with Keil uVision 5