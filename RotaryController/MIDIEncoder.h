/*
  MIDIEncoder
  A library for creating relative MIDI CC messages from a rotary encoder.

  Project source available at:
  http://github.com/squarefrog/teensy-midi-encoder-box

  Uses Paul Stoffregen's Teensy Encoder library
  https://github.com/PaulStoffregen/Encoder

  Copyright (c) 2016 Paul Williamson

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef MIDIEncoder_h
#define MIDIEncoder_h

#include "Arduino.h"
#include <Encoder.h>

class MIDIEncoder
{
  public:
    MIDIEncoder(byte pin1, byte pin2, byte midiChannel, byte midiCCNumber);
    byte channel;
    byte ccNumber;
    byte read();

  private:
    unsigned long _lastTurnedTime;
    long _oldPosition;
    Encoder _enc;
    byte accelerationOffset();
};

#endif

