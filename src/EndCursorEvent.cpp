#include "EndCursorEvent.hpp"

string EndCursorEvent::KEYWORD = "ENDCURSOREVENT";
EndCursorEvent::~EndCursorEvent(){
  
}

EndCursorEvent::EndCursorEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string EndCursorEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *EndCursorEvent::create(int key){
  MouseEvent *gue = new EndCursorEvent(key);
  return gue;
}

void EndCursorEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(KEY_END,value,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(KEY_END,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
