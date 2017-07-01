#include "Arduino.h"
#include "Heartbeat.h"

HeartBeat::HeartBeat(int p, long t){
  frequency = t; 
  timeOn = t; 
  pin = p;
  pinMode(pin,OUTPUT); 
  lastPoint = millis(); 
  curState = true; 
  shouldBeOn = true; 
  setState(true); 
}

HeartBeat::HeartBeat(int p, long timeOn, long timeOff){
  frequency = timeOff;
  this->timeOn = timeOn;  
  pin = p;
  pinMode(pin,OUTPUT); 
  lastPoint = millis(); 
  curState = true; 
  shouldBeOn = true; 
  setState(true); 
}

void HeartBeat::turnOff(){
  shouldBeOn = false;
}

void HeartBeat::turnOn(){
  shouldBeOn = true; 
}

void HeartBeat::setFrequency(long t){
  frequency = t; 
}

void HeartBeat::update(){
  if(curState == false || timeOn == frequency){
    if(millis() - lastPoint > frequency){
      //Serial.println("\nTime: " + String(millis() - lastPoint));
      setState(!curState); 
      curState = !curState; 
      lastPoint = millis();  
    }
  }
  else{
    if(millis() - lastPoint > timeOn){
      setState(false);
      if(millis() - lastPoint > frequency){
        setState(!curState); 
        curState = false; 
        lastPoint = millis(); 
      }
    }
  }
}

void HeartBeat::setState(bool state){
  //Serial.println(state);
  if(state && shouldBeOn) digitalWrite(pin,HIGH);
  else digitalWrite(pin,LOW); 
}