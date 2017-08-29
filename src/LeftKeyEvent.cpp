#include "./LeftKeyEvent.hpp"

string LeftKeyEvent::KEYWORD = "LEFTKEYEVENT";

LeftKeyEvent::~LeftKeyEvent(){
  
}
string LeftKeyEvent::getKeyword(){
  return KEYWORD;
}

LeftKeyEvent::LeftKeyEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

MouseEvent *LeftKeyEvent::create(int key){
  MouseEvent *gue = new LeftKeyEvent(key);
  return gue;
}

void LeftKeyEvent::pressed(int value){
  if (value == 1) {
    //    std::cout << "is Pressed 1" << "\n";
    if (writeKeyEvent(BTN_LEFT,1,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(BTN_LEFT,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }
}


