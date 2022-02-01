# RPi Pico Test Input

This is a repo for testing different inputs on the Raspberry Pi Pico. Each input is polled every second.

It's intended as only a personal project, but feel free to use it (See [LICENSE](LICENSE) for details).


## Flashing

1. Download the latest release
1. Hold the bootsel button while plugging in the RPi pico
1. Copy the UF2 file to it


## View the serial output

1. Connect the RPi pico to your PC
1. Open a serial terminal app on the serial port that it is connected to at a baud rate of 115200
    1. For linux users, one option is to install minicom and run `minicom -b 115200 -o -D /dev/ttyACM0`
1. A new log should be printed to your terminal every second


## Inputs

Currently there are only 2 inputs:

Type    | Name   | Connection                    | Description
--------|--------|-------------------------------|---------------------------------------------------------------------------------------------------
Digital | Switch | Pin 20 (GP15), any ground pin | Any external switch connected across the pins listed. States open and closed.
ADC     | Temp   | ADC4 (internal)               | The temperature sensor built into the RP2040. Read as potential in mV, output in degrees Celsius.

## Output

This application is not intended for testing output, but logs are sent to the USB serial debugger for feedback.