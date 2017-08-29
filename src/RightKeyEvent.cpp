#include "RightKeyEvent.hpp"

string RightKeyEvent::KEYWORD = "RIGHTKEYEVENT";
RightKeyEvent::~RightKeyEvent(){
  
}

RightKeyEvent::RightKeyEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string RightKeyEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *RightKeyEvent::create(int key){
  MouseEvent *gue = new RightKeyEvent(key);
  return gue;
}

void RightKeyEvent::pressed(int value){
  if (value == 1) {
    //    std::cout << "is Pressed 1" << "\n";
    if (writeKeyEvent(BTN_RIGHT,1,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(BTN_RIGHT,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
