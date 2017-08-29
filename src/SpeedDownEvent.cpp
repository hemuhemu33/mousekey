#include "SpeedDownEvent.hpp"

string SpeedDownEvent::KEYWORD = "SPEEDDOWNEVENT";

SpeedDownEvent::~SpeedDownEvent(){
  
}
string SpeedDownEvent::getKeyword(){
  return KEYWORD;
}

SpeedDownEvent::SpeedDownEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

MouseEvent *SpeedDownEvent::create(int key){
  MouseEvent *gue = new SpeedDownEvent(key);
  return gue;
}

void SpeedDownEvent::pressed(int value){
  if (value == 1) {
    int speed = getSpeed()-getDecrementSpeed();
    if (speed <= 0) {
      speed = 1;
    }
    setSpeed(speed);
  }else if(value == 0){
    
  }
}
