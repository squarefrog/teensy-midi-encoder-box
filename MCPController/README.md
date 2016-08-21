# MCP Controller

This project uses 16 Bourns PEC16 encoders, with 3 `MCP23S17` GPIO expanders. This means we can connect up 16 encoders and buttons, using as little as 4 Teensy pins.

One of the biggest advantages of the Teensy over an Arduino is any digital input can be used as an interrupt pin. Each `MCP23S17` offers two interrupts - one for `GPIOA` one for `GPIOB`. Therefore, we can use 6 Teensy input pins to monitor interrupts from the `MCP23S17` chips.

## Work in progress...

