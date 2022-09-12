#### RP2040 - C SDK SPI - 9/11/2022 
Controller and Peripheral mode implemented with simple readback.  
Operating in an inefficient single core blocking mode as of now,  
as such this should be used as a base or just for testing.  
  
  
#### Make, Compile, and Upload  
- Create a build directory within the accompanying folders
- `cd ./build`
- On Linux: `cmake ..`
- On Windows (mingw only) `cmake -G "MinGW Makefiles" ..`
- `make`
- Plug in RP2040 device with bootsel pressed (external flash !CS pulled low)
- copy `{project name}.uf2` into RP2040 directory
  
  
#### Debug
By default the use of VUSB and printf() will output messages over a COM port  
at 115200 8N1 standard UART communications standards.  
Use minicom/RealTerm/preffered serial port monitor to view sent and readback  
messages.
