/*
RP2040 Peripheral SPI Side for Testing Peripheral Mode Operation


Good Docs on SPI SDK:
https://raspberrypi.github.io/pico-sdk-doxygen/group__hardware__spi.html
*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"


#define LED 25

int main(){
    
    const uint cs_pin   = 1;    // GPIO 1   CS
    const uint sck_pin  = 2;    // GPIO 2   SCK
    const uint mosi_pin = 3;    // GPIO 3   TX
    const uint miso_pin = 4;    // GPIO 4   RX

    spi_inst_t  *spi_Main = spi0;    // SPI0 Selected
    
    stdio_init_all();           // Enable UART/USB output

    // Enable SPI at 1MHz clk
    spi_init(spi_Main, 1000 * 1000);

    // Define as Peripheral Mode
    spi_set_slave(spi_Main, 1);             // 1 == Peripheral Mode, 0 (default init) == Controller Mode

    // Initialize SPI Format
    //      8 bit per frame, CPOL Polarity, CPHA Phase, Endianness
    spi_set_format(spi_Main, 8, 1, 1, SPI_MSB_FIRST);

    // Initialize SPI Port Pins
    gpio_set_function(sck_pin, GPIO_FUNC_SPI);
    gpio_set_function(mosi_pin, GPIO_FUNC_SPI);
    gpio_set_function(miso_pin, GPIO_FUNC_SPI);
    gpio_set_function(cs_pin, GPIO_FUNC_SPI);


    uint8_t inn_buff[5] = {0x00};                       // Test Input Array
    uint8_t out_buff[5] = {'H','i','!',' ','\0'};
    
    #ifdef USB_DEBUG_INIT
    printf("SPI%u Enabled at Baudrate: %u\n\n", spi_get_index(spi_Main), spi_get_baudrate(spi_Main));             // USB Debug Messages
    #endif

    sleep_ms(1000);                     // Wait to enter Loop

    

    while(1){
        // Test read, blocking
        if(spi_is_readable(spi_Main)){
            printf("SPI%u Recieved: %i bytes at %u baud\n", spi_get_index(spi_Main), spi_write_read_blocking(spi_Main, out_buff, inn_buff, 5), spi_get_baudrate(spi_Main));
            printf("\tRecieved: %s\n", inn_buff);
            printf("\tSent: %s\n\n", out_buff);
            for(int n = 0; n < 5; n++){
                inn_buff[n] = 0x00;
            }
            
        }
        

        //sleep_ms(1000);
    }    
}