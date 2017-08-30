#include "HomeCursorEvent.hpp"

string HomeCursorEvent::KEYWORD = "HOMECURSOREVENT";
HomeCursorEvent::~HomeCursorEvent(){
  
}

HomeCursorEvent::HomeCursorEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string HomeCursorEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *HomeCursorEvent::create(int key){
  MouseEvent *gue = new HomeCursorEvent(key);
  return gue;
}

void HomeCursorEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(KEY_HOME,1,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(KEY_HOME,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
