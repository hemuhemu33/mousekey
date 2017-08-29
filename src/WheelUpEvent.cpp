#include "WheelUpEvent.hpp"

string WheelUpEvent::KEYWORD = "WHEELUPEVENT";

WheelUpEvent::~WheelUpEvent(){
  
}
string WheelUpEvent::getKeyword(){
  return KEYWORD;
}

WheelUpEvent::WheelUpEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

MouseEvent *WheelUpEvent::create(int key){
  MouseEvent *gue = new WheelUpEvent(key);
  return gue;
}

void WheelUpEvent::pressed(int value){
  if (value >= 1) {
    //    std::cout << "is Pressed 1" << "\n";
    if (writeKeyEvent(REL_WHEEL,1,EV_REL,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }
}


