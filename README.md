# BLE-jammer
BLE (Bluetooth low energy) jammer using nRF2401+ modules and Maple Mini (STM32)

## Brief overview
BLE uses 40 channels, 3 of which are used for advertising and the other 37 are used for data transmission.
Data transmission on the other 37 channels are usually done with adaptive frequency hopping to minimize interference.

On the other hand, BLE discovery is made possible by 3 advertising channels (2402MHz, 2426MHz and 2480MHz).
These 3 advertising channels transmit the characteristics and Mac Address of the device.
On newer BLE devices, advertising uses all 3 channels, hence the need to generate noise on all
3 channels in order to achieve maximum effectiveness in jamming BLE discoverability.

This is far more feasible than jamming all 40 channels with a wideband jammer as it risks affecting other network such as WiFi.

## nRF2401+
The nRF2401+ (by Nordic Semiconductor) is a highly integrated, 
ultra low power (ULP) 2Mbps RF transceiver for the 2.4GHz ISM (Industrial, 
Scientific and Medical) band. 

### Features:
* Power supply : 1.9~3.6V
* ~520m Range at 2Mbit Data Rate
* Auto Acknowledge
* Auto Re-Transmit
* Multiceiver - 6 Data Pipes
* 32 Byte separate TX and RX FIFOs
* Software selectable channel: 2400MHz to 2525MHz (125 Selectable channels)
* Minimum number of external components
* Pins broken out : VCC, CE, CSN, SCK, MOSI, MISO, IRQ, GND

nRF2401+ is a narrowband tranceiver (~2MHz) but that works to our advantage as BLE is also narrowband by design (~2MHz).
