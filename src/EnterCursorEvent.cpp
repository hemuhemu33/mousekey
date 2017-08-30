#include "EnterCursorEvent.hpp"

string EnterCursorEvent::KEYWORD = "ENTERCURSOREVENT";
EnterCursorEvent::~EnterCursorEvent(){
  
}

EnterCursorEvent::EnterCursorEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string EnterCursorEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *EnterCursorEvent::create(int key){
  MouseEvent *gue = new EnterCursorEvent(key);
  return gue;
}

void EnterCursorEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(KEY_ENTER,1,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(KEY_ENTER,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
