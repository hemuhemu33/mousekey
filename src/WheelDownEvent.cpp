#include "WheelDownEvent.hpp"

string WheelDownEvent::KEYWORD = "WHEELDOWNEVENT";

WheelDownEvent::~WheelDownEvent(){
  
}
string WheelDownEvent::getKeyword(){
  return KEYWORD;
}

WheelDownEvent::WheelDownEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

MouseEvent *WheelDownEvent::create(int key){
  MouseEvent *gue = new WheelDownEvent(key);
  return gue;
}

void WheelDownEvent::pressed(int value){
  if (value >= 1) {
    //    std::cout << "is Pressed 1" << "\n";
    if (writeKeyEvent(REL_WHEEL,-1,EV_REL,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }

  }
}


