#include "BrowserNextEvent.hpp"

string BrowserNextEvent::KEYWORD = "BROWSERNEXTEVENT";
BrowserNextEvent::~BrowserNextEvent(){
  
}

BrowserNextEvent::BrowserNextEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

string BrowserNextEvent::getKeyword(){
  return KEYWORD;
}

MouseEvent *BrowserNextEvent::create(int key){
  MouseEvent *gue = new BrowserNextEvent(key);
  return gue;
}

void BrowserNextEvent::pressed(int value){
  if (value == 1) {
    //    std::cout << "is Pressed 1" << "\n";
    if (writeKeyEvent(BTN_EXTRA,1,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }else if(value == 0){
    //    std::cout << "is Pressed 0" << "\n";
    if (writeKeyEvent(BTN_EXTRA,0,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      return;
    }
  }

}
