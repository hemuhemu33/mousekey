#include "RightCursorEvent.hpp"

string RightCursorEvent::KEYWORD = "RIGHTCURSOREVENT";
RightCursorEvent::~RightCursorEvent(){
  
}

RightCursorEvent::RightCursorEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string RightCursorEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *RightCursorEvent::create(int key){
  MouseEvent *gue = new RightCursorEvent(key);
  return gue;
}

void RightCursorEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(KEY_RIGHT,value,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(KEY_RIGHT,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
