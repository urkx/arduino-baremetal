default:
	avr-gcc -shared -DF_CPU=16000000UL -mmcu=atmega2560 -c -o embed_led.o embed_led/embed_led.c
	avr-gcc -DF_CPU=16000000UL -mmcu=atmega2560 -I./embed_led -c -o led.o led.c
	avr-gcc -o led.bin led.o embed_led.o -mmcu=avr6
	#avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega2560 -c -o led.o led.c
	#avr-gcc -o led.bin led.o -mmcu=avr6
	avr-objcopy -O ihex -R .eeprom led.bin led.hex

load: default
	sudo avrdude -cstk500v2 -pm2560 -D -P /dev/tty.usbmodem1301 -Uflash:w:led.hex

disassemble:
	avr-objdump -d -m avr6 led.bin