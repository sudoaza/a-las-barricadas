/*
  
 circuit:
 * 8-ohm speaker on digital pin 4
 
 http://arduino.cc/en/Tutorial/Tone
  */
 #include "pitches.h"

int melody[] = {
  NOTE_A7, NOTE_A7, NOTE_G6, NOTE_F6, NOTE_F6, NOTE_E6,
  NOTE_D6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_F6,
  NOTE_E6, NOTE_A7, NOTE_A7, NOTE_A7, NOTE_G6, NOTE_F6, NOTE_E6,
  NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A7, 0,
  
  NOTE_A7, NOTE_A7, NOTE_A7, NOTE_D7, NOTE_A7, NOTE_G6,
  NOTE_F6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_F6,
  NOTE_E6, NOTE_A7, NOTE_A7, NOTE_A7, NOTE_G6, NOTE_F6, NOTE_E6,
  NOTE_D6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_C6,
  
  NOTE_F6, NOTE_F6, NOTE_F6, NOTE_C6, NOTE_F6,
  NOTE_G6, NOTE_G6, NOTE_G6, NOTE_C6, NOTE_F6,
  NOTE_G6, NOTE_C7, NOTE_G6, NOTE_B7, NOTE_A7, NOTE_G6,
  NOTE_A7, NOTE_A7, NOTE_A7, NOTE_A7, NOTE_A7, 
  
  NOTE_A7, NOTE_A7, NOTE_A7, NOTE_D7, NOTE_A7, NOTE_G6,
  NOTE_F6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_F6, NOTE_F6,
  NOTE_E6, NOTE_A7, NOTE_A7, NOTE_A7, NOTE_G6, NOTE_F6, NOTE_E6,
  NOTE_D6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_C6,
  
  NOTE_F6, NOTE_F6, NOTE_F6, NOTE_C6, NOTE_F6, NOTE_F6,
  NOTE_G6, NOTE_G6, NOTE_G6, NOTE_C6, NOTE_G6, NOTE_G6,
  NOTE_G6, NOTE_C6, NOTE_G6, NOTE_B7, NOTE_A7, NOTE_G6,
  NOTE_A7, NOTE_A7, NOTE_A7, NOTE_A7,
  
  NOTE_A7, NOTE_A7, NOTE_A7, NOTE_A7, NOTE_D7, NOTE_A7, NOTE_G6,
  NOTE_F6, NOTE_F6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_F6, NOTE_F6,
  NOTE_E6, NOTE_A7, NOTE_A7, NOTE_A7, NOTE_G6, NOTE_F6, NOTE_E6,
  NOTE_D6, NOTE_F6, NOTE_E6, NOTE_D6, 0
 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,7.9,16,4,7.9,16,
  4,7.9,16,4,4,
  4,7.9,16,8,8,8,8,
  8,8,8,8,2,16,
  
  4,7.9,16,4,7.9,16,
  4,7.9,16,4,4,
  4,7.9,16,8,8,8,8,
  4,7.9,16,4,4,
  
  4,7.9,16,4,4,
  4,7.9,16,4,4,
  4,7.9,16,4,7.9,16,
  4,7.9,16,3.9,8,
  
  4,7.9,16,4,7.9,16,
  4,7.9,16,4,7.9,16,
  4,8,8,8,8,8,8,
  4,7.9,16,4,4,
  
  4,7.9,16,4,7.9,16,
  4,7.9,16,4,7.9,16,
  4,7.9,16,4,7.9,16,
  4,7.9,16,2,
  
  7.9,16,7.9,16,4,8,8,
  7.9,16,7.9,16,4,7.9,16,
  4,7.9,16,8,8,8,8,
  4,7.9,16,4,2,
};

void setup() {
  float temp = 2;
  int g = 0;
  int pos = 0;
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 200; thisNote++) {
    
    
    if ( temp > 1 ) {
      temp = 0;
      pos = 0;
    }
    
    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(4, melody[thisNote],noteDuration);
    
   
    temp += 4 / melody[thisNote];
    pos++;

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(4);
  }
}

void loop() {
  // no need to repeat the melody.
}
