# Blinking Christmas Tree
This is a program for a blinking Christmas tree coded onto an ATmega88 microchip. The Christmas tree offers four light patterns for eleven LEDs, controlled by a variator.

I built this Christmas tree for a friend. She later discovered a bug relating to switching between light patterns. Unfortunately, I couldn't fix it for her, because my design didn't include a USB port and I didn't want to tear apart the whole tree to get to the microchip. A lesson learned, to always design a way to update the code. It was so long ago she discovered the bug so I don't remember how to reproduce it.

## Table of contents
* [Who is this for?](#who-is-this-for)
* [Prerequisites](#prerequisites)
* [Installation instructions](#installation-instructions)
* [Usage](#usage)
* [Licensing](#licensing)
* [How to contribute](#how-to-contribute)
* [Versioning](#versioning)

## Who is this for?
For the tinkerer who wants to delve into hardware programming with a simple project to start with. This project has a lot of development potential, both on the software and the hardware side.

## Prerequisites
Since it was a long time ago I built this, I don't remember exactly which components I used. Here is a list of what I remember, though:

### Hardware
| Component | Count | Value | Comments
| --- | --- | --- | ---
| [ATmega88 microchip][1] | 1
| Battery | 1 | 9&nbsp;V | Will power both the ATmega88 and the LEDs.
Four-state variator | 1
| LED | 11 | | The colour(s) of your choice.
| Material in the form of a Christmas tree | | | Plastic or other non-conducting material on which to attach the LEDs and resistors
| [Perfboard][7] | | | To hold all the components except the LEDs and their resistors.
| Resistor | 1 | 1.4&nbsp;kΩ&ndash;2.6&nbsp;kΩ | For the ATmega88 microchip's power supply, since the maximum operating voltage is 2.7&nbsp;V&ndash;5.5&nbsp;V.
| Resistor | 11 | ? | Resistance dependent on the configuration; the goal is to not fry the LEDs.
| Wires | | | To connect the components.

Since microchips and LEDs are very sensitive things, please make sure that you do your own calculations and research for which resistors you need. Do not rely solely on what I have written here. That is from my hazy memory, after all. :wink:

In future updates to this project, I will probably take the time to design schematics detailing the exact values for all components and how to connect them.

### Software
* [Atmel Studio][5] (or any other compiler capable to write the C source code onto the ATmega88's EEPROM)
* [TinyCAD][6] (for reading the schematics; note that no schematics are available at this time)

## Installation instructions
Since it was a long time ago and my memory is vague around how I built it, this section has to remain empty until I have designed the schematics for the hardware.

However, I can say that the source code must be compiled into a HEX file (using [Atmel Studio][5] for example) and written to ATmega88's EEPROM.

## Usage
When the hardware is connected and the software has been written to ATmega88's EEPROM, the user can choose between light patterns on the LEDs, using the variator. To stop the Christmas tree from emitting light, the user has to remove or unplug the battery.

## Licensing
This application is licensed under the [MIT License][2]. For detailed license terms, please read [LICENSE][8].

## How to contribute
Thank you for wanting to contribute to this project. Open source is all about community. Go and read the document [CONTRIBUTING.md][9] for more information on with what you can contribute and how to go about it.

## Versioning
This project uses [Semantic Versioning 2.0.0][3] for version numbering. To see what's changed between versions, please read [CHANGELOG.md][10]. That file also has links to the download section of each release.


[1]: http://www.microchip.com/wwwproducts/en/ATmega88
[2]: https://opensource.org/licenses/MIT
[3]: https://semver.org/
[5]: https://www.microchip.com/mplab/avr-support/atmel-studio-7
[6]: https://sourceforge.net/projects/tinycad/
[7]: https://en.wikipedia.org/wiki/Perfboard
[8]: LICENSE
[9]: CONTRIBUTING.md
[10]: CHANGELOG.md
