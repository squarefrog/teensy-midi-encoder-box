/*
   MCP23S17 Test

   Enc1
   A - Green
   B - Red
   C - Yellow


   Enc2
   A - Green
   B - Blue
   C - Yellow

   SS - 10
   SCK - 13
   MOSI - 11
   MISO - 12

   MCP1 = 0
   MCP2 = 1

   ENC1A - MCP1GPA0
   ENC1B - MCP1GPA1
   ENC2A - MCP2GPA0
   ENC2B - MCP2GPA1

*/

#include <SPI.h>
#include "MCP23S17.h"

const byte chipSelect = 10;
byte oldValue = 0;

void setup() {
  // Set chip select to be output high
  pinMode(chipSelect, OUTPUT);
  digitalWrite(chipSelect, HIGH);

  // Set SS to be output high
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH);

  // Start SPI
  SPI.begin();

  // Set GPIOA to input
  Mcp23S17Write(chipSelect, IODIRA, 0xff);

  // Use weak pullup resistors
  Mcp23S17Write(chipSelect, GPPUA, 0xff);

  // Invert the polarity of the input
  Mcp23S17Write(chipSelect, IPOLA, 0xff);

  // Setup Serial
  Serial.begin(9600);
  delay(500);
  Serial.println("Begin");
}

void loop() {
  uint8_t value = Mcp23S17Read(chipSelect, GPIOA);
  if (oldValue != value) {
    Serial.print("Value changed: ");
    Serial.println(value, BIN);
    oldValue = value;
  }
}


void Mcp23S17Write(byte cs, byte reg, byte value) {
  digitalWrite(cs, LOW);
  SPI.transfer(0x40);
  SPI.transfer(reg);
  SPI.transfer(value);
  digitalWrite(cs, HIGH);
}

byte Mcp23S17Read(byte cs, byte reg) {
  byte value;
  digitalWrite(cs, LOW);
  SPI.transfer(0x41);
  SPI.transfer(reg);
  value = SPI.transfer(0);
  digitalWrite(cs, HIGH);
  return value;
}

