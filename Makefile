default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega2560 -c -o led.o led.c
	avr-gcc -o led.bin led.o -mmcu=avr6
	avr-objcopy -O ihex -R .eeprom led.bin led.hex

load: default
	sudo avrdude -cstk500v2 -pm2560 -D -P /dev/tty.usbmodem1301 -Uflash:w:led.hex
