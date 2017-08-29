#include "GoRightEvent.hpp"

string GoRightEvent::KEYWORD = "GORIGHTEVENT";
GoRightEvent::~GoRightEvent(){
  
}

GoRightEvent::GoRightEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string GoRightEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *GoRightEvent::create(int key){
  MouseEvent *gue = new GoRightEvent(key);
  return gue;
}

void GoRightEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(REL_X,MouseEvent::getSpeed(),EV_REL,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }

}
