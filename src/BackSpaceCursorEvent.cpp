#include "BackSpaceCursorEvent.hpp"

string BackSpaceCursorEvent::KEYWORD = "BACKSPACECURSOREVENT";
BackSpaceCursorEvent::~BackSpaceCursorEvent(){
  
}

BackSpaceCursorEvent::BackSpaceCursorEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string BackSpaceCursorEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *BackSpaceCursorEvent::create(int key){
  MouseEvent *gue = new BackSpaceCursorEvent(key);
  return gue;
}

void BackSpaceCursorEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(KEY_BACKSPACE,1,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(KEY_BACKSPACE,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
