#include <MIDI.h>

#include "StripeEngine.h"

#define MIDI_CHANNEL 10
#define CC_SPEED 3
#define CC_RAINBOWSPEED 4
#define CC_EXPLODE_LEVEL 5

//We use Serial1 for Mega
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

StripeEngine stripeEngine;

void setup() {
    
  Serial1.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  stripeEngine.setup();

  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  MIDI.read();


  stripeEngine.loop();
}

void handleNoteOn(byte channel, byte note, byte velocity) {
    stripeEngine.setNote(note, velocity);
    //digitalWrite(LED_BUILTIN, velocity > 0 ? HIGH : LOW);
}

void handleNoteOff(byte channel, byte note, byte velocity) {
    stripeEngine.setNote(note, 0);
    //digitalWrite(LED_BUILTIN, LOW);
}

void handleControlChange(byte channel, byte control, byte value) {
  if (control == CC_SPEED) {
    stripeEngine.setDecayTime(value);
  }
  if (control == CC_RAINBOWSPEED) {
    stripeEngine.setRainbowTime(value);
  }
  if (control == CC_EXPLODE_LEVEL) {
    stripeEngine.setExplodeLevel(value);
  }
}
