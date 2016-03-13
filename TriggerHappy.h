#ifndef TriggerHappy_h
#define TriggerHappy_h

#include "Arduino.h"

class TriggerHappy {
  public:
    TriggerHappy(int trig, int echo);
    long PingDuration();
    long PingCentimeters();
    long CalcCentimeters(long duration);
    long CalcInches(long duration);
  private:
    int _trig, _echo;
};


#endif
