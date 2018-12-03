#include<avr/io.h> 
#include<util/delay.h> 
#include "SPI/spi_driver.h"
#include "LCD/lcd44780.h"




int main() 
{ 

SPI_SlaveInit();
lcd_init();

uint8_t bajt=10;
lcd_cls();
lcd_char( 's' );
while(1) 
{ 
	bajt = SPI_SlaveRecive();
	
	lcd_cls();

	lcd_int( bajt );
	lcd_char( 'a' );
	bajt = SPI_SlaveRecive();
	lcd_int( bajt );
	lcd_char( 'b' );	
	bajt = SPI_SlaveRecive();
	lcd_int( bajt );
	lcd_char( 'c' );
	bajt = SPI_SlaveRecive();
	lcd_int( bajt );
	lcd_char( 'd' );




}						
return 0; 
}



