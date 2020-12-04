/*
 * 
 * What we want to do with the code 
 * - have a constant elevator tune when it is uploaded 
 *   - might be difficult plus how would that correspond 
 *   with LEDs/button stages? 
 * - when button is pressed, tune changes
 *      - there are (5) stages that the button cycles through
 *      - each stage gets more ominous (1-3), 
 *        (4) is an epic boss, (5) is the celebratory tune
 * - have 5 LEDs that turn on/off (whichever is easier) 
 *   depending on which stage you're on
 *   https://www.instructables.com/Controlling-Multiple-LEDs-With-an-Arduino-Uno/
  https://www.instructables.com/Musical-Snow-Globe/
  Melody
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int snowman[] = {
    NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_G4, NOTE_F4, NOTE_G4, 0, 0,
    0, 0, NOTE_DS4, NOTE_DS4,NOTE_AS3, NOTE_DS4, NOTE_G4, NOTE_F4, 0, 0, 0, 0, 0,
    NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_DS4, 0, NOTE_C4, NOTE_GS4, NOTE_G4, 
    NOTE_DS4, 0, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_G4, NOTE_B3, 0
 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int snowmanDurations[] = {
    8, 8, 8, 8, 8, 8, 4, 2, 4, 8,
    4, 8, 8, 8, 8, 8, 8, 2, 4, 4, 8, 4, 8,
    8, 8, 8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 
    4, 8, 8, 8, 8, 8, 8, 4, 4  
};
const int speakerPin = 9;
const int buttonPin = 2;
const int ledPins[] = {3,4,5,6,7};

// variables will change:
int buttonPushCounter = 0; //counter for the number of presses
int buttonState = 0; // variable for reading the pushbutton status
int lastButtonState = 0; //previous state of the button

// note durations: 4 = quarter note, 8 = eighth note, etc.:

void setup() {
Serial.begin(9600);

// initialize pin 9 as an output for the speaker:
  pinMode(speakerPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(ledPins, OUTPUT);

}

void loop() {
  // read the state of the pushbutton value:
  
  buttonState = digitalRead(buttonPin);
// compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  if (buttonPushCounter == 1) { 
//    play_snowmanMelody();
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], LOW);
    digitalWrite(ledPins[4], LOW); 
  }
  if (buttonPushCounter == 2) { 
//    play_snowmanMelody(); 
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], LOW);
    digitalWrite(ledPins[4], LOW);
    }
  if (buttonPushCounter == 3) { 
//    play_snowmanMelody(); 
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], LOW);
    digitalWrite(ledPins[4], LOW);
    }
  if (buttonPushCounter == 4) { 
//    play_snowmanMelody(); 
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], HIGH);
    digitalWrite(ledPins[4], LOW);
    }
  if (buttonPushCounter == 5) { 
//    play_snowmanMelody();
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], HIGH);
    digitalWrite(ledPins[4], HIGH);
   }
   
  else{
    noTone(9);
    digitalWrite(ledPins, LOW);
  }
  
 Serial.println(buttonState);
}

//void play_snowmanMelody(){
//    for (int thisNote = 0; thisNote < (sizeof(snowmanDurations)/2); thisNote++) {
//
//    // to calculate the note duration, take one second 
//    // divided by the note type.
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//    int snowmanDuration = 1500/snowmanDurations[thisNote];
//    tone(speakerPin, snowman[thisNote], snowmanDuration);
//
//    // to distinguish the notes, set a minimum time between them.
//    // the note's duration + 30% seems to work well:
//    int pauseBetweenNotes = snowmanDuration * 1.30;
//    delay(pauseBetweenNotes);
//    // stop the tone playing:
//    noTone(speakerPin);
//  }   }
