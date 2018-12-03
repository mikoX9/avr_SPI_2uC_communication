

#	CC=xyz	->definiowanie zmiennej
#	$(CC)	->uzywanie zmiennej

MCU = atmega328p
F_CPU = 8000000

FILE1 		= spi_driver
LOCATION1 	= SPI

FILE2 		= lcd44780
LOCATION2 	= LCD

all:	main.hex
	rm -f main.o
	rm -f main.elf
	rm -f $(FILE1).o
	rm -f $(FILE2).o

.c.o:
	avr-gcc -Wall -Os -DF_CPU=$(F_CPU) -c -mmcu=$(MCU) $(LOCATION1)/$(FILE1).c -o $(FILE1).o
	avr-gcc -Wall -Os -DF_CPU=$(F_CPU) -c -mmcu=$(MCU) $(LOCATION2)/$(FILE2).c -o $(FILE2).o
	avr-gcc -Wall -Os -DF_CPU=$(F_CPU) -c -mmcu=$(MCU) main.c -o main.o

main.elf: main.o $(FILE1).o $(FILE2).o
	avr-gcc -Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) main.o $(FILE1).o $(FILE2).o -o main.elf

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

clean:
	rm -f main.hex
	rm -f main.o
	rm -f main.elf
	rm -f $(FILE1).o
	rm -f $(FILE2).o