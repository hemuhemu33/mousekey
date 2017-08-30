#include "LeftCursorEvent.hpp"

string LeftCursorEvent::KEYWORD = "LEFTCURSOREVENT";
LeftCursorEvent::~LeftCursorEvent(){
  
}

LeftCursorEvent::LeftCursorEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string LeftCursorEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *LeftCursorEvent::create(int key){
  MouseEvent *gue = new LeftCursorEvent(key);
  return gue;
}

void LeftCursorEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(KEY_LEFT,1,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(KEY_LEFT,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
