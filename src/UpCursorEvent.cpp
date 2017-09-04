#include "UpCursorEvent.hpp"

string UpCursorEvent::KEYWORD = "UPCURSOREVENT";
UpCursorEvent::~UpCursorEvent(){
  
}

UpCursorEvent::UpCursorEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string UpCursorEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *UpCursorEvent::create(int key){
  MouseEvent *gue = new UpCursorEvent(key);
  return gue;
}

void UpCursorEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(KEY_UP,value,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(KEY_UP,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
