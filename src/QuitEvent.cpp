#include "QuitEvent.hpp"

string QuitEvent::KEYWORD = "QUITEVENT";

QuitEvent::~QuitEvent(){
  
}
string QuitEvent::getKeyword(){
  return KEYWORD;
}

QuitEvent::QuitEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

MouseEvent *QuitEvent::create(int key){
  MouseEvent *gue = new QuitEvent(key);
  return gue;
}

void QuitEvent::pressed(int value){
  if (value >= 1) {
    exit(0);
  }else if(value == 0){
    
  }
}


