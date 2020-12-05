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
int first[] = {
    NOTE_A4, NOTE_D5, 0, 0, NOTE_A4, NOTE_D5, 0, 0
 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int firstDurations[] = {
    4, 4, 2, 2, 4, 4, 2, 2   
};

int second[] = {
    NOTE_AS4, NOTE_D5, NOTE_AS4, NOTE_F5, 0, NOTE_AS4, 0, NOTE_FS5, NOTE_AS4, NOTE_D5, NOTE_AS4, NOTE_F5, 0, NOTE_AS4, NOTE_FS5,
    NOTE_AS4, NOTE_G5, NOTE_AS4, NOTE_E5, 0, NOTE_FS5, NOTE_C5, NOTE_AS4, NOTE_G5, NOTE_AS4, NOTE_E5, 0, NOTE_FS5, NOTE_D5
 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int secondDurations[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4   
};

int third[] = {
    NOTE_E5, NOTE_CS5, NOTE_AS4, NOTE_FS4, NOTE_DS5, NOTE_C5, NOTE_GS4, NOTE_F4, NOTE_D5, NOTE_B4, NOTE_G4, NOTE_E4, NOTE_CS5, NOTE_AS4, NOTE_FS4,
    NOTE_DS4
 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int thirdDurations[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4   
};

int fourth[] = {
    NOTE_E3, NOTE_E3, NOTE_F3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_F3, NOTE_E3, NOTE_E3, NOTE_F3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_F3,
    NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3,
    NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3,
    NOTE_DS4
 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int fourthDurations[] = {
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 
};

int fifth[] = {
    NOTE_D5, NOTE_B5, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_FS5, NOTE_E5
 };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int fifthDurations[] = {
    2, 2, 2, 4, 4, 2, 2, 2, 2 
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
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], LOW);
    digitalWrite(ledPins[4], LOW); 
//    play_firstRoom();
  }
  if (buttonPushCounter == 2) {  
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], LOW);
    digitalWrite(ledPins[4], LOW);
    play_secondRoom();
    }
  if (buttonPushCounter == 3) { 
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], LOW);
    digitalWrite(ledPins[4], LOW);
    play_thirdRoom();
    }
  if (buttonPushCounter == 4) {  
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], HIGH);
    digitalWrite(ledPins[4], LOW);
    play_fourthRoom();
    }
  if (buttonPushCounter == 5) { 
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], HIGH);
    digitalWrite(ledPins[4], HIGH);
    play_fifthRoom();
   }
   
  else{
    noTone(9);
    digitalWrite(ledPins, LOW);
  }
  
 Serial.println(buttonState);
}

void play_firstRoom(){
    for (int thisNote = 0; thisNote < (sizeof(firstDurations)/2); thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int firstDuration = 1000/firstDurations[thisNote];
    tone(speakerPin, first[thisNote], firstDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = firstDuration * 1.20;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }   }

  void play_secondRoom(){
    for (int thisNote = 0; thisNote < (sizeof(secondDurations)/2); thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int secondDuration = 1000/secondDurations[thisNote];
    tone(speakerPin, second[thisNote], secondDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = secondDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }   }

  void play_thirdRoom(){
    for (int thisNote = 0; thisNote < (sizeof(thirdDurations)/2); thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int thirdDuration = 1000/thirdDurations[thisNote];
    tone(speakerPin, third[thisNote], thirdDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = thirdDuration * 1.40;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }   }

  void play_fourthRoom(){
    for (int thisNote = 0; thisNote < (sizeof(fourthDurations)/2); thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int fourthDuration = 1000/fourthDurations[thisNote];
    tone(speakerPin, fourth[thisNote], fourthDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = fourthDuration * 1.10;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }   }

  void play_fifthRoom(){
    for (int thisNote = 0; thisNote < (sizeof(fifthDurations)/2); thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int fifthDuration = 1000/fifthDurations[thisNote];
    tone(speakerPin, fifth[thisNote], fifthDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = fifthDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(speakerPin);
  }   }
