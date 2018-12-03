#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H



#define DDR_SPI DDRB
#define PORT_SPI PORTB

#define PIN_MOSI PB3
#define PIN_MISO PB4
#define PIN_SCK	PB5
#define PIN_CS PB2

void SPI_MasterInit(void);
void SPI_MasterTransmit(char bajt);

void SPI_SlaveInit(void);
uint8_t SPI_SlaveRecive(void);

uint8_t SPI_Transfer(uint8_t bajt);

#endif