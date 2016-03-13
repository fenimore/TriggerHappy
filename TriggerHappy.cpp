/*
  TriggerHappy.cpp - Library for the HC SR04 Ping.
  Created by Fenimore, 2016.
  Released into the public domain.
  http://www.cascologix.com/blog/hc-sr04-ping-sensor-hardware-mod
*/

#include "Arduino.h"
#include "TriggerHappy.h"

TriggerHappy::TriggerHappy(int trig, int echo){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  _trig = trig;
  _echo = echo;
}


// returns duration of distance in microseconds
long TriggerHappy::PingDuration(){
  // initialize the HC-SR04
  //pinMode(PING_TRIG_PIN, OUTPUT);
  //pinMode(PING_ECHO_PIN, INPUT);
  
  long _duration;
  // The PING is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig, LOW);

  // The same pin is used to read the signal from the PING: a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  _duration = pulseIn(_echo, HIGH);
  // convert returned  the time into distance
  // cm = microsecondsToCentimeters(duration);
  return _duration;
}

long TriggerHappy::PingCentimeters(){
  long _duration;
  // See PingDuration for comments
  digitalWrite(_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig, LOW);
  _duration = pulseIn(_echo, HIGH);
  return _duration / 29 / 2;
}

long TriggerHappy::CalcCentimeters(long duration){
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return duration / 29 / 2;
}

long TriggerHappy::CalcInches(long duration){
  // According to Parallax's datasheet for the PING, there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second)
  return duration / 74 / 2;
}



