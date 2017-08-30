#include "DeleteCursorEvent.hpp"

string DeleteCursorEvent::KEYWORD = "DELETECURSOREVENT";
DeleteCursorEvent::~DeleteCursorEvent(){
  
}

DeleteCursorEvent::DeleteCursorEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string DeleteCursorEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *DeleteCursorEvent::create(int key){
  MouseEvent *gue = new DeleteCursorEvent(key);
  return gue;
}

void DeleteCursorEvent::pressed(int value){
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(KEY_DELETE,1,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(KEY_DELETE,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
