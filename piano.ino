/*
Piano glove

Using piezo sensors to sense "knock" signals, 
transmit them to another piezo to play notes.

*/
#include "notes.h"

const int led = 13;
//piezo sensors
const int piez0 = A0;
const int piez1 = A1;
const int piez2 = A2;
const int piez3 = A3;
const int piez4 = A4;
//speaker
const int playback = 8;
//threshold for piezo knock signal
const int threshold = 30;

//the piezo sensors on the 5 fingers
int sensor0 = 0;
int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;
int sensor4 = 0;
int ledState = LOW;

void setup(){
  pinMode(led, OUTPUT); //LED set to output
  Serial.begin(9600); //initialize serial communication
}

void loop() {

  //recieve "knock" signals from piezos
  sensor0 = analogRead(piez0);
  sensor1 = analogRead(piez1);
  sensor2 = analogRead(piez2);
  sensor3 = analogRead(piez3);
  sensor4 = analogRead(piez4);; 
  Serial.println("Read all");
  
  if (sensor0 >= threshold) {
    tone(playback, NOTE_C4, 250);
    delay(325);
    noTone(playback);
    Serial.println("C-note");
  } else if (sensor1 >= threshold) {
    tone(playback, NOTE_D4, 250);
    delay(325);
    noTone(playback);
    Serial.println("D-note");
  } else if (sensor2 >= threshold) {
    tone(playback, NOTE_E4, 250);
    delay(325);
    noTone(playback);
    Serial.println("E-note");
  } else if (sensor3 >= threshold) {
    tone(playback, NOTE_F4, 250);
    delay(325);
    noTone(playback);
    Serial.println("F-note");
  } else if (sensor4 >= threshold) {
    tone(playback, NOTE_G4, 250);
    delay(325);
    noTone(playback);
    Serial.println("D-note");
  }
}
