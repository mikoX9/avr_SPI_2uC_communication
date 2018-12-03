#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H



#define DDR_SPI DDRB
#define PORT_SPI PORTB

#define PIN_MOSI PB5
#define PIN_MISO PB6
#define PIN_SCK	PB7
#define PIN_CS PB4


void SPI_MasterInit(void);
void SPI_MasterTransmit(char bajt);

void SPI_SlaveInit(void);
uint8_t SPI_SlaveRecive(void);

uint8_t SPI_Transfer(uint8_t bajt);

#endif