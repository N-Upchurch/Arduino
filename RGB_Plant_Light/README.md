# Button Operated Plant Light Sketch

## Purpose
The light cycles between red, violet, purple, white, and off in order to shine different light wavelengths onto different types of plants and foliage.

## Usage
Pressing the button cycles through the light settings.

## Setup
This is designed to be used with an array of common-cathode RGB LEDs. The cathodes are connected in series to ground. I made use of three NPN transistors; one for each color.
The emitter of transistor no.1 is conected to all red LEDs, no.2 to all green LEDs, and no. 3 to all blue LEDs. Transistor collectors are connected to ground in parallel, and bases are connected to pins 9(red), 10(green), & 11(blue), in series
with a 1000 ohm resistor. The button is connected to pin 2, with a 10k ohm pull-down resistor. 
