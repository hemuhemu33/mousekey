#include "ChangeModeEvent.hpp"

string ChangeModeEvent::KEYWORD = "CHANGEMODEEVENT";
ChangeModeEvent::~ChangeModeEvent(){
  
}

ChangeModeEvent::ChangeModeEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string ChangeModeEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *ChangeModeEvent::create(int key){
  MouseEvent *gue = new ChangeModeEvent(key);
  return gue;
}

void ChangeModeEvent::pressed(int value){
  if (value == 1) {
    KeyboardMode::_nextMode();
    //    std::cout << "debug" << "\n";
    
    // if (getMode() == MOUSEMODE) {
    //   setMode(KEYBOARDMODE);
    // }else if (getMode() == KEYBOARDMODE) {
    //   setMode(MOUSEMODE);
    // }else {
    // }
    
  }else {
  }

  
}
