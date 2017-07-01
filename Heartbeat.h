#ifndef HEARTBEAT_h
#define HEARTBEAT_h

class HeartBeat{
 public: 
  void update();
  void turnOff();
  void turnOn();
  void setFrequency(long t); 
  HeartBeat(int p, long t);
  HeartBeat(int p, long timeOn, long timeOff);  
 private:
  long lastPoint; 
  bool curState; 
  bool shouldBeOn; 
  long frequency;
  long timeOn;  
  int pin; 
  void setState(bool state); 
}; 



#endif 