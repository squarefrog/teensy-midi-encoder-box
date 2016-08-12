/*
  RotaryController

  This project sends relative signed bit MIDI CC messages when an encoder
  is turned.

  Project source available at:
  http://github.com/squarefrog/teensy-midi-encoder-box

  For more information about relative MIDI mapping, see:
  http://tutorials.renoise.com/wiki/MIDI_Mapping
  Ableton Relative signed bit: Increase at [1-63], decrease at [65 - 127].
*/

#include "MIDIEncoder.h"

// Constants
const byte midiChannel = 1;       // The MIDI Channel to send the commands over
const byte numberEncoders = 16;   // The number of encoders in the project

// Encoder Variables - Avoid Pin 13! Encoder constructer as follows:
// MIDIEncoder(byte pin1, byte pin2, byte midiChannel, byte midiCCNumber);
MIDIEncoder enc1(0, 1, midiChannel, 16);
MIDIEncoder enc2(2, 3, midiChannel, 17);
MIDIEncoder enc3(4, 5, midiChannel, 18);
MIDIEncoder enc4(6, 7, midiChannel, 19);
MIDIEncoder enc5(8, 9, midiChannel, 20);
MIDIEncoder enc6(10, 11, midiChannel, 21);
MIDIEncoder enc7(14, 15, midiChannel, 22);
MIDIEncoder enc8(16, 17, midiChannel, 23);
MIDIEncoder enc9(18, 19, midiChannel, 24);
MIDIEncoder enc10(20, 21, midiChannel, 25);
MIDIEncoder enc11(22, 23, midiChannel, 26);
MIDIEncoder enc12(24, 25, midiChannel, 27);
MIDIEncoder enc13(26, 27, midiChannel, 28);
MIDIEncoder enc14(28, 29, midiChannel, 29);
MIDIEncoder enc15(30, 31, midiChannel, 30);
MIDIEncoder enc16(32, 33, midiChannel, 31);

// Store encoder pointers for easier lookups
MIDIEncoder *encoders[numberEncoders] {
  &enc1,  &enc2,  &enc3,  &enc4,
  &enc5,  &enc6,  &enc7,  &enc8,
  &enc9,  &enc10, &enc11, &enc12,
  &enc13, &enc14, &enc15, &enc16
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  readEncoders();
}

void readEncoders() {
  // Loop through each encoder and read the value
  for (byte i = 0; i < numberEncoders; i++) {
    byte value = encoders[i]->read();
    if (value > 0) {
      Serial.print("Encoder changed: ");
      Serial.println(i, DEC);
      byte cc = encoders[i]->ccNumber;
      byte channel = encoders[i]->channel;
      usbMIDI.sendControlChange(cc, value, channel);
    }
  }
}

