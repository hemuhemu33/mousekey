#include "DownCursorEvent.hpp"

string DownCursorEvent::KEYWORD = "DOWNCURSOREVENT";
DownCursorEvent::~DownCursorEvent(){
  
}

DownCursorEvent::DownCursorEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string DownCursorEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *DownCursorEvent::create(int key){
  MouseEvent *gue = new DownCursorEvent(key);
  return gue;
}

void DownCursorEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(KEY_DOWN,value,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(KEY_DOWN,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
