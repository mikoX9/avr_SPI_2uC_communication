#include <avr/io.h>
#include "spi_driver.h"




// Initialize SPI Master Device (with SPI interrupt)
void SPI_MasterInit(void) 
{
    // Set MOSI, SCKm, CS as Output
    DDR_SPI |= ( 1 << PIN_SCK ) | ( 1 << PIN_MOSI ) | ( 1 << PIN_CS );	          //MOSI, SCK, SS' jako wyjścia
 
    // Enable SPI, Set as Master
    // Prescaler: Fosc/16, Enable Interrupts
    SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPIE);
    //SPIR ->przerwanie zglaszane po zakończeniu transmisji 
 
    // Enable Global Interrupts
 //   sei();
}



void SPI_MasterSend(char bajt) 
{ 
SPDR = bajt;					//Wysyłamy zawartość zmiennej bajt	
while(!(SPSR & (1<<SPIF)));		//Oczekujemy na zakończenie transmisji ( do ustawienia SPIF ) przez sprzęt
}	



// Initialize SPI Slave Device
void SPI_SlaveInit(void) 
{
    DDR_SPI |= ( 1 << PIN_MISO );
    SPCR = (1<<SPE) | ( 1 << SPIE );   //Enable SPI
    //SPIE -> przerwanie zglaszane po zakończeniu transmisji
    
    // Enable Global Interrupts
 ////   sei();

}


uint8_t SPI_SlaveRecive(void) 
{							//Czekamy na koniec transmisji danych
while(!(SPSR & (1<<SPIF)));	 	// ( aż do ustawienie flagi SPIF	 ) 
return SPDR;					//Zwracamy to co dostaliśmy do SPDR
}	



//master inicjuje wysylanie danych, wiec z poziomy slave trzeba
//zrobic cos jesli sie chce aby dany wedrowaly w tym samym momencie

uint8_t SPI_Transfer(uint8_t bajt)
{
    // Load data into the buffer
    SPDR = bajt;
 
    //Wait until transmission complete
    while(!(SPSR & (1<<SPIF) ));
 
    // Return received data
    return bajt;
}