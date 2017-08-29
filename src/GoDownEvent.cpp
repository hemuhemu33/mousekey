#include "GoDownEvent.hpp"

string GoDownEvent::KEYWORD = "GODOWNEVENT";
GoDownEvent::~GoDownEvent(){
  
}

GoDownEvent::GoDownEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string GoDownEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *GoDownEvent::create(int key){
  MouseEvent *gue = new GoDownEvent(key);
  return gue;
}

void GoDownEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(REL_Y,MouseEvent::getSpeed(),EV_REL,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }

}
