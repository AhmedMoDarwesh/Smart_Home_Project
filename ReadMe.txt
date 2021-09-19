§◄Smart Home Application►§


Describtion:
• An application to toggle devices by turning them off or on, or to turn all the devices off.


Construction:
1- UART Module
	- Transmitting data to be received by SPI to switch devices.
2- ECU1 (Master ECU)
	- Receives the data from the UART (Bluetooth module).
	- Storing the data received from the UART module then using it to be transmitted through SPI Master
3- ECU2 (Slave ECU)
	- Reveives the data in the SPI Slave which is transmitted by the SPI Master.
	- Controlling the devices that needs to be switched on/off depending on the data received from UART.
	- Switching all devices off if needed.


System Operation:
--> UART & ECU1
	- The microcontroller will receive the data sent by the user to decide which device needs to be driven.

--> ECU2
	- The microntroller will toggle devices or turn all of them off:
		• By sending '1' the user chooses to drive the 1st device either by toggling it on or off.
		• By sending '2' the user chooses to drive the 2nd device either by toggling it on or off.
		• By sending '3' the user chooses to drive the 3rd device either by toggling it on or off.
		• By sending '0' the user can then turn all the devices off.