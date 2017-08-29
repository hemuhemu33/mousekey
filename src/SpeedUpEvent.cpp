#include "SpeedUpEvent.hpp"

string SpeedUpEvent::KEYWORD = "SPEEDUPEVENT";

SpeedUpEvent::~SpeedUpEvent(){
  
}
string SpeedUpEvent::getKeyword(){
  return KEYWORD;
}

SpeedUpEvent::SpeedUpEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

MouseEvent *SpeedUpEvent::create(int key){
  MouseEvent *gue = new SpeedUpEvent(key);
  return gue;
}

void SpeedUpEvent::pressed(int value){
  if (value == 1) {
    int speed = getIncrementSpeed()+getSpeed();
    setSpeed(speed);
  }else if(value == 0){
    
  }
}
