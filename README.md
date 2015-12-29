#ASSISTANCE BUZZER
Two pairs of [Teensy 3.1 XBee Adapters](https://learn.sparkfun.com/tutorials/teensy-xbee-adapter-hookup-guide). 
One adapter has a button attached to it and is responsible for sending a signal to the other board. The other
adapter has a buzzer attached to it. When the button is depressed on the signaler, it begins sending 0's and 1's
over serial. The buzzer buzzes when it receives 1's and does nothing otherwise. 

##Signaler/Button
The signaler uses a 12V power supply which is regulated down to 3.3V using a linear regulator. A 2N3904 NPN 
transistor is toggled at pin 13. This controls the power supply to the powerful LED connected to the button. 
Additionally, the signaler is programmed to emit 'a' and 'b' keypresses when the button is switched on and off. 
A raspberry pi has been set up to listen to these keypresses and log timestamps to a file.

#Buzzer
The buzzer runs of a 800mAh lipo battery which provides 3.7V. Because this power source is supplied via the 
VIN pin of the Teensy, it is not possible to upgrade the XBee radio. This is because all other models require
more current than the Teensy can safely provide. 

#Raspberry Pi
A script is included which can be loaded on the PI. The script has been designed to only capture 'a' and 'b' keypresses
and will exit if it receives any other input. Timestamps are logged to output.txt on /media/PI. There is a fat32
partition loaded at this point so the SD card can be loaded on a windows or mac computer. 
