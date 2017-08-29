#include "MiddleKeyEvent.hpp"

string MiddleKeyEvent::KEYWORD = "MIDDLEKEYEVENT";

MiddleKeyEvent::~MiddleKeyEvent(){
  
}
string MiddleKeyEvent::getKeyword(){
  return KEYWORD;
}

MiddleKeyEvent::MiddleKeyEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

MouseEvent *MiddleKeyEvent::create(int key){
  MouseEvent *gue = new MiddleKeyEvent(key);
  return gue;
}

void MiddleKeyEvent::pressed(int value){
  if (value == 1) {
    //    std::cout << "is Pressed 1" << "\n";
    if (writeKeyEvent(BTN_MIDDLE,1,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(BTN_MIDDLE,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }
}


