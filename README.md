# MIDI-LED-Strip-Controller
Control 4 LED strips with MIDI notes

## Description
Control up to 4 LED strips with MIDI Input.  
I trully recommend to read this whole guide from Adafruit about LED Strips first : https://learn.adafruit.com/rgb-led-strips/overview  

For controlling a LED strip color, we need a IRLB8721 transistor and a PWM output on the Arduino.  
That's why I use Arduino MEGA, because it has 12 PWM output.  
There's cheaper solutions, but I was looking for the most efficient in terms of conception time.  

Pin 2,3,4 of the Arduino are controlling the 3 colors of the first LED strip.  
5,6,7 the second LED strip ... and so on.  

## MIDI TABLE

### Channel
I use MIDI Channel 10, but you can change it by modifying  

#define MIDI_CHANNEL 10  

in the .ino file  

### Color control

Each note control a color. You can use velocity to control the brightness of the color.

| Note | Color | Strip |
|------|-------|-------|
| 60   | RED   | 1     |
| 61   | GREEN | 1     |
| 62   | BLUE  | 1     |
| 63   | WHITE | 1     |
| 64   | RED   | 2     |
| 65   | GREEN | 2     |
| 66   | BLUE  | 2     |
| 67   | WHITE | 2     |
| 68   | RED   | 3     |
| 69   | GREEN | 3     |
| 70   | BLUE  | 3     |
| 71   | WHITE | 3     |
| 72   | RED   | 4     |
| 73   | GREEN | 4     |
| 74   | BLUE  | 4     |
| 75   | WHITE | 4     |

The WHITE color is just a shortcut for sending value to RED, GREEN and BLUE at the same time.  

### Special Mode

58 -> RAINBOW MODE : because Rainbows are awesome  
59 -> EXPLODE MODE : each LED strip will blink in white independently  

### Control Changes

CC 3 -> Decay : control the decay level of the color. 0 - 127  
CC 4 -> Rainbow speed : control the speed of the Rainbow Mode. 0 - 127  
CC 5 -> Explode speed : control the speed of the Explode Mode. 0 - 127  



![alt text](https://raw.githubusercontent.com/alexiszbik/MIDI-LED-Strip-Controller/refs/heads/main/schema.png)

## Component List
* 1x Arduino MEGA (if you need to control only 1 or 2 strips, UNO is enough)
* 1x 1N4148
* 1x 10k
* 1x 470R
* 1x 220R
* 1x 6n138 optocoupler
* 1x MIDI IN socket
* 3x IRLB8721 transistors per Strip
