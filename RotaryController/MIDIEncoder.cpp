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

#include "MIDIEncoder.h"

/*
  Ableton Relative signed bit: Increase at [1-63], decrease at [65 - 127].
  Values are +1, as setting to minimum means you have to turn two clicks to
  register 1 jump in Ableton
 */
const byte incrementValue = 2;   // A constant for the start of increment values
const byte decrementValue = 66;  // A constant for the start of decrement values

MIDIEncoder::MIDIEncoder(byte pin1, byte pin2, byte midiChannel, byte midiCCNumber) : _enc(pin1, pin2)
{
  channel = midiChannel;
  ccNumber = midiCCNumber;
  _oldPosition = -999;
  _lastTurnedTime = millis();
}

byte MIDIEncoder::read()
{
  long newPosition = _enc.read();

  // If position hasn't changed, ignore.
  if (newPosition == _oldPosition) {
    return 0;
  }

  // The Encoder library counts 4 steps per detent.
  // If position is not divisible by 4, ignore.
  if (newPosition % 4 != 0) {
    return 0;
  }

  // Fetch the acceleration offset
  byte offset = accelerationOffset();

  // Create the MIDI CC value, adding any offset required.
  byte value = 0;
  if (newPosition > _oldPosition) {
    value = incrementValue + offset;
  } else {
    value = decrementValue + offset;
  }

  // Store the new position
  _oldPosition = newPosition;

  // Return the MIDI CC value
  return value;
}

byte MIDIEncoder::accelerationOffset()
{
  // Calculate the time since last change
  unsigned long currTime = millis();
  unsigned long delta = currTime - _lastTurnedTime;
//  Serial.println(delta);

  // Apply crude acceleration
  // Warning: here be magic numbers...
  byte offset = 0;
  if (delta < 100) {
    offset = 4;
  } else if (delta > 99 && delta < 180) {
    offset = 2;
  } else if (delta > 179 && delta <= 250) {
    offset = 1;
  }

  // Update lastTurnedTime variable
  _lastTurnedTime = currTime;

  return offset;
}


