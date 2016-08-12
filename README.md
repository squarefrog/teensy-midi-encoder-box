# Teensy MIDI Encoder Box

This project uses 16 rotary encoders to generate relative MIDI CC messages. It uses a [Teensy 3.2](https://www.pjrc.com/teensy/teensy31.html), which features 34 digital input pins, each with the ability to use interrupts.

## Dependencies

The only non-standard Arduino library used is:

- [Encoder](https://github.com/PaulStoffregen/Encoder)

## Building the software

First download the latest [Arduino Software](https://www.arduino.cc/en/Main/OldSoftwareReleases#previous) that is compatible with [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html). At the time of writing, this is [Arduino](https://www.arduino.cc/en/Main/OldSoftwareReleases#previous) `1.6.9`, and [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) `1.29`.

Ensure you install the `Encoder` library when installing [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html).

Now open up `RotaryController.ino` located in the `RotaryController` directory.

At the top of the file you can customise the number of encoders in use, MIDI channel and CC numbers to suit your project.

Verify the sketch, which will open [Teensy Loader](https://www.pjrc.com/teensy/loader.html). Now press the button on the Teensy to load the firmware.

Now connect up all your encoders, following the schematic.

Finally, test each encoder using a MIDI monitor. I recommend [Snoize MIDI Monitor](https://www.snoize.com/MIDIMonitor/) on macOS, and [MIDI-OX](http://www.midiox.com) on Windows. If you know of a Linux MIDI monitor, I'd welcome a [Pull Request](https://github.com/squarefrog/teensy-midi-encoder-box/compare)!

Speaking of which...

## Pull Requests

Pull Requests are most welcome! Do you have a suggestion for code improvement? Or just spot a spelling mistake in this `README` file? Send me a [Pull Request](https://github.com/squarefrog/teensy-midi-encoder-box/compare).

## To do list

- [x] Write sketch code
- [x] Test on bread board
- [ ] Create schematic
- [ ] Design breakout PCB
- [ ] Design 3D enclosure
- [ ] Ableton Instant Mapping files

## Bill of Materials

Work in progress...

| Quantity | Part Number  | Description                                             | Line Price £ | Supplier  |
|----------|--------------|---------------------------------------------------------|--------------|---|
| 16       | EC12E2420802 | ALPS Incremental Rotary Encoder, 24 Pulses, 24 Detents  | 14.24        | [Farnell](http://uk.farnell.com/alps/ec12e2420802/encoder-vertical-12mm-24det-24ppr/dp/2065067) |
| 16       | CR-BAB-6-D   | MULTICOMP,CR-BAB-6-D,Knob, Round, 6 mm,                 | 6.50         | [Farnell](http://uk.farnell.com/multicomp/cr-bab-6-d/knob-15-7mm-black-no-line/dp/1441143)  |
| 1        |              | Teensy 3.2                                              | 18.00        | [Pimoroni](https://shop.pimoroni.com/products/teensy-3-1)  |
| 1        | N/A          | 40-pin 0.1" Pin Headers (Male)                          |              |   |
| 1        | N/A          | 2x7 SMD pin headers                                     |              |   |
| 16       | N/A          | M8 nuts                                                 |              |   |
| 16       | N/A          | M8 nuts                                                 |              |   |
| 16       | N/A          | Washers                                                 |              |   |
| 1        | N/A          | Breakout PCB (optional)                                 |              | [Ragworm.eu](http://ragworm.eu) |

## References

- [MIDI Control Change Messages](https://www.midi.org/specifications/item/table-3-control-change-messages-data-bytes-2)
- A more readable [MIDI Control Change Messages](http://nickfever.com/music/midi-cc-list) table
- [Encoder Library](https://www.pjrc.com/teensy/td_libs_Encoder.html)
- [Relative MIDI Mapping](http://tutorials.renoise.com/wiki/MIDI_Mapping)

