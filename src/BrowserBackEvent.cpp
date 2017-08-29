#include "BrowserBackEvent.hpp"

string BrowserBackEvent::KEYWORD = "BROWSERBACKEVENT";
BrowserBackEvent::~BrowserBackEvent(){
  
}

BrowserBackEvent::BrowserBackEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string BrowserBackEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *BrowserBackEvent::create(int key){
  MouseEvent *gue = new BrowserBackEvent(key);
  return gue;
}

void BrowserBackEvent::pressed(int value){
  if (value == 1) {
    //    std::cout << "is Pressed 1" << "\n";
    if (writeKeyEvent(BTN_SIDE,1,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(BTN_SIDE,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
