/*
   Created by Valery Smith
   March 2017
   for a dancing robot that dances to the music of a speaker that is
   placed obnoxiusly close to the sound sensor
   good for when you don't have friends to dance with
*/
//the includes
#include <CurieBLE.h>
#include "CurieIMU.h"
#include <SPI.h>
#include <SD.h>
#include <ASCII.h>
//the constants
const int motorR = 9;
const int motorL = 3;
const int beepPin = 8;
const int freq = 2000; //the base frrequency for the beeps
const int ledPin = 13;

const int numMoves = 3;

//normal variables
int dMove; //the current dance move being preformed
int velo = 100; // the speed at which the motors are going
int space; //space between activations of the sound
int oSpace;
bool sense;
void setup() {
  Serial.begin(9600);
  // set the pin modes !!
  pinMode(beepPin, OUTPUT);
  pinMode(motorR, OUTPUT);
  pinMode(motorL, OUTPUT);
  pinMode(ledPin, OUTPUT);
  //pinMode(soundPin, INPUT);
  attachInterrupt(0, inter0, RISING);
  //so to use the program you need to hook the sound sensor
  //into arduino pin 0
}
int t1;
int t2;
bool oldSound = LOW;
bool sound = LOW;

void inter0() {
  noInterrupts();
 dMove++;
      dMove %= (numMoves + 1);
  interrupts();
  Serial.println(dMove);
}
int oldMove;

void loop() {
  
      switch (dMove) {
        case 0:
          t1 = millis();
          if ((t1 - t2) >= 150) {
            noInterrupts();
            analogWrite(motorR, 0);
            analogWrite(motorL, 0);
            digitalWrite(ledPin, LOW);
            //dMove++;
            interrupts();
            oldMove = dMove;
            t2 = t1;
          }

          break;
        case 1:
          t1 = millis();
          if ((t1 - t2) >= 150) {
            noInterrupts();
            analogWrite(motorR, speedmothafucker);
            analogWrite(motorL, speedmothafucker);
            digitalWrite(ledPin, HIGH);
            oldMove = dMove;
            interrupts();
            t2 = t1;
          }
          break;
        case 2:
          t1 = millis();
          if ((t1 - t2) >= 150) {
            noInterrupts();
            analogWrite(motorR, speedmothafucker);
            analogWrite(motorL, 0);
            digitalWrite(ledPin, HIGH);
            oldMove = dMove;
            interrupts();
            t2 = t1;
          }
          break;
        case 3:
          t1 = millis();
          if((t1-t2)>=150){
          noInterrupts();
          analogWrite(motorR, 0);
          analogWrite(motorL, speedmothafucker);
          digitalWrite(ledPin, HIGH);
          oldMove = dMove;
          interrupts();
          t2=t1;}
          break;
      }

    }

