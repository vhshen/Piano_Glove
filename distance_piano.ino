/*
Piano glove

Using piezo sensors to sense "knock" signals, 
transmit them to another piezo to play notes.

*/
#include "notes.h"

const int led = 13;
//the pins for the ping sensor
const int trigPin = 2;
const int echoPin = 4;
//piezo sensors
const int piez1 = A1;
const int piez2 = A2;
const int piez3 = A3;
const int piez4 = A4;
const int piez5 = A5;
//speaker
const int playback = 8;
//threshold for piezo knock signal
const int threshold = 20;
//keyboard toggler
const int button = A0;
const int butthresh = 80;
int regular = 0;
int butinit = 0;

//the piezo sensors on the 5 fingers
int sensor0 = 0;
int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;
int sensor4 = 0;
int ledState = LOW;

//variables for wooden "piano" surface
int endPiano = 381;
int interval = 85;

void setup(){
  pinMode(led, OUTPUT); //LED set to output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); //initialize serial communication
}

void loop() {
  long duration, mm; //duration of echo and distance in mm
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //Read signal from sensor, duration is time from sending ping
  // to recieving echo off object
  duration = pulseIn(echoPin, HIGH);
  //convert this into distance
  mm = microsecondsToMillimeters(duration);
  
  Serial.print("dist: ");
  Serial.println(mm);
  
  //recieve "knock" signals from piezos
  sensor0 = analogRead(piez1);
  sensor1 = analogRead(piez2);
  sensor2 = analogRead(piez3);
  sensor3 = analogRead(piez4);
  sensor4 = analogRead(piez5);
  butinit = analogRead(button);
  //Serial.println("Read all");
  
  if(butinit > butthresh){
    regular = !regular;
    if(regular){
      Serial.print("Regular keyboard!");
    } else {
      Serial.print("White Keys Only!");
    }
    
    tone(playback, NOTE_F4, 250);
    delay(330);
    tone(playback, NOTE_D4, 250);
    delay(330);
    tone(playback, NOTE_C4, 250);
    delay(330);
    
  }
  
  if(!regular){
    if (mm < endPiano && mm > (endPiano - interval)){
      if (sensor0 >= threshold) {
        tone(playback, NOTE_E3, 250);
        delay(300);
        noTone(playback);
        Serial.println("E-note");
        Serial.println("INTERVAL ONE 1 ONE 1 ONE 1 ONE 1 ONE 1");
      } else if (sensor1 >= threshold) {
        tone(playback, NOTE_F3, 250);
        delay(300);
        noTone(playback);
        //Serial.println("F-note");
        //Serial.println("INTERVAL ONE 1 ONE 1 ONE 1 ONE 1 ONE 1");
      } else if (sensor2 >= threshold) {
        tone(playback, NOTE_G3, 250);
        delay(300);
        noTone(playback);
        //Serial.println("G-note");
        //Serial.println("INTERVAL ONE 1 ONE 1 ONE 1 ONE 1 ONE 1");
      } else if (sensor3 >= threshold) {
        tone(playback, NOTE_A3, 250);
        delay(300);
        noTone(playback);
        //Serial.println("A-note");
        //Serial.println("INTERVAL ONE 1 ONE 1 ONE 1 ONE 1 ONE 1");
      } else if (sensor4 >= threshold) {
        tone(playback, NOTE_B3, 250);
        delay(300);
        noTone(playback);
        //Serial.println("B-note");
        //Serial.println("INTERVAL ONE 1 ONE 1 ONE 1 ONE 1 ONE 1");
      }
    } else if (mm < (endPiano - interval) && mm > (endPiano - 2*interval)){
      if (sensor0 >= threshold) {
        tone(playback, NOTE_C4, 250);
        delay(300);
        noTone(playback);
        Serial.println("C-note");
        Serial.println("INTERVAL TWO 2 TWO 2 TWO 2 TWO 2 TWO 2");
      } else if (sensor1 >= threshold) {
        tone(playback, NOTE_D4, 250);
        delay(300);
        noTone(playback);
        //Serial.println("D-note");
        //Serial.println("INTERVAL TWO 2 TWO 2 TWO 2 TWO 2 TWO 2");
      } else if (sensor2 >= threshold) {
        tone(playback, NOTE_E4, 250);
        delay(300);
        noTone(playback);
        //Serial.println("E-note");
        //Serial.println("INTERVAL TWO 2 TWO 2 TWO 2 TWO 2 TWO 2");
      } else if (sensor3 >= threshold) {
        tone(playback, NOTE_F4, 250);
        delay(300);
        noTone(playback);
        //Serial.println("F-note");
        //Serial.println("INTERVAL TWO 2 TWO 2 TWO 2 TWO 2 TWO 2");
      } else if (sensor4 >= threshold) {
        tone(playback, NOTE_G4, 250);
        delay(300);
        noTone(playback);
        //Serial.println("G-note");
        //Serial.println("INTERVAL TWO 2 TWO 2 TWO 2 TWO 2 TWO 2");
      }
    } else if (mm < (endPiano - 2*interval) && mm > (endPiano - 3*interval)){
      if (sensor0 >= threshold) {
        tone(playback, NOTE_A4, 250);
        delay(300);
        noTone(playback);
        //Serial.println("A-note");
        //Serial.println("INTERVAL THREE 3 THREE 3 THREE 3 THREE 3");
      } else if (sensor1 >= threshold) {
        tone(playback, NOTE_B4, 250);
        delay(300);
        noTone(playback);
        //Serial.println("B-note");
        //Serial.println("INTERVAL THREE 3 THREE 3 THREE 3 THREE 3");
      } else if (sensor2 >= threshold) {
        tone(playback, NOTE_C5, 250);
        delay(300);
        noTone(playback);
        //Serial.println("C-note");
        //Serial.println("INTERVAL THREE 3 THREE 3 THREE 3 THREE 3");
      } else if (sensor3 >= threshold) {
        tone(playback, NOTE_D5, 250);
        delay(300);
        noTone(playback);
        //Serial.println("D-note");
        //Serial.println("INTERVAL THREE 3 THREE 3 THREE 3 THREE 3");
      } else if (sensor4 >= threshold) {
        tone(playback, NOTE_E5, 250);
        delay(300);
        noTone(playback);
        //Serial.println("E-note");
        //Serial.println("INTERVAL THREE 3 THREE 3 THREE 3 THREE 3");
      }
    } else {
      if (sensor0 >= threshold) {
        tone(playback, NOTE_F5, 250);
        delay(300);
        noTone(playback);
        //Serial.println("F-note");
        //Serial.println("INTERVAL FOUR 4 FOUR 4 FOUR 4 FOUR 4");
      } else if (sensor1 >= threshold) {
        tone(playback, NOTE_G5, 250);
        delay(300);
        noTone(playback);
        //Serial.println("G-note");
        //Serial.println("INTERVAL FOUR 4 FOUR 4 FOUR 4 FOUR 4");
      } else if (sensor2 >= threshold) {
        tone(playback, NOTE_A5, 250);
        delay(300);
        noTone(playback);
        //Serial.println("A-note");
        //Serial.println("INTERVAL FOUR 4 FOUR 4 FOUR 4 FOUR 4");
      } else if (sensor3 >= threshold) {
        tone(playback, NOTE_B5, 250);
        delay(300);
        noTone(playback);
        //Serial.println("B-note");
        //Serial.println("INTERVAL FOUR 4 FOUR 4 FOUR 4 FOUR 4");
      } else if (sensor4 >= threshold) {
        tone(playback, NOTE_C6, 250);
        delay(300);
        noTone(playback);
        //Serial.println("C-note");
        //Serial.println("INTERVAL FOUR 4 FOUR 4 FOUR 4 FOUR 4");
      }
    }
  } else {
    if (mm < endPiano && mm > (endPiano - interval)){
      if (sensor0 >= threshold) {
        tone(playback, NOTE_G3, 250);
        delay(300);
        noTone(playback);
      } else if (sensor1 >= threshold) {
        tone(playback, NOTE_GS3, 250);
        delay(300);
        noTone(playback);
      } else if (sensor2 >= threshold) {
        tone(playback, NOTE_A3, 250);
        delay(300);
        noTone(playback);
      } else if (sensor3 >= threshold) {
        tone(playback, NOTE_AS3, 250);
        delay(300);
        noTone(playback);
      } else if (sensor4 >= threshold) {
        tone(playback, NOTE_B3, 250);
        delay(300);
        noTone(playback);
      }
    } else if (mm < (endPiano - interval) && mm > (endPiano - 2*interval)){
      if (sensor0 >= threshold) {
        tone(playback, NOTE_C4, 250);
        delay(300);
        noTone(playback);
      } else if (sensor1 >= threshold) {
        tone(playback, NOTE_CS4, 250);
        delay(300);
        noTone(playback);
      } else if (sensor2 >= threshold) {
        tone(playback, NOTE_D4, 250);
        delay(300);
        noTone(playback);
      } else if (sensor3 >= threshold) {
        tone(playback, NOTE_DS4, 250);
        delay(300);
        noTone(playback);
      } else if (sensor4 >= threshold) {
        tone(playback, NOTE_E4, 250);
        delay(300);
        noTone(playback);
      }
    } else if (mm < (endPiano - 2*interval) && mm > (endPiano - 3*interval)){
      if (sensor0 >= threshold) {
        tone(playback, NOTE_F4, 250);
        delay(300);
        noTone(playback);
      } else if (sensor1 >= threshold) {
        tone(playback, NOTE_FS4, 250);
        delay(300);
        noTone(playback);
      } else if (sensor2 >= threshold) {
        tone(playback, NOTE_G4, 250);
        delay(300);
        noTone(playback);
      } else if (sensor3 >= threshold) {
        tone(playback, NOTE_GS4, 250);
        delay(300);
        noTone(playback);
      } else if (sensor4 >= threshold) {
        tone(playback, NOTE_A4, 250);
        delay(300);
        noTone(playback);
      }
    } else {
      if (sensor0 >= threshold) {
        tone(playback, NOTE_AS4, 250);
        delay(300);
        noTone(playback);
      } else if (sensor1 >= threshold) {
        tone(playback, NOTE_B4, 250);
        delay(300);
        noTone(playback);
      } else if (sensor2 >= threshold) {
        tone(playback, NOTE_C5, 250);
        delay(300);
        noTone(playback);
      } else if (sensor3 >= threshold) {
        tone(playback, NOTE_CS5, 250);
        delay(300);
        noTone(playback);
      } else if (sensor4 >= threshold) {
        tone(playback, NOTE_D5, 250);
        delay(300);
        noTone(playback);
      }
    }
  }

  delay(100);

}

long microsecondsToMillimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 2.94 / 2;
}

