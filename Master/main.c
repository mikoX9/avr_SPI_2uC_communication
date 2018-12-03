#include<avr/io.h> 
#include<util/delay.h> 
#include "SPI/spi_driver.h"








int main() 
{ 


SPI_MasterInit();

uint8_t X= 2;

while(1)			
{ 
	SPI_MasterSend( X );
	_delay_ms(1000);
} 
return 0; 
}


