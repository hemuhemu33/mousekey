#include "GoLeftEvent.hpp"

string GoLeftEvent::KEYWORD = "GOLEFTEVENT";
GoLeftEvent::~GoLeftEvent(){
  
}

GoLeftEvent::GoLeftEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string GoLeftEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *GoLeftEvent::create(int key){
  MouseEvent *gue = new GoLeftEvent(key);
  return gue;
}

void GoLeftEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(REL_X,-1*MouseEvent::getSpeed(),EV_REL,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }

}
