#include "./GoUpEvent.hpp"

string GoUpEvent::KEYWORD = "GOUPEVENT";

GoUpEvent::~GoUpEvent(){
  
}
string GoUpEvent::getKeyword(){
  return KEYWORD;
}

GoUpEvent::GoUpEvent(int key):MouseEvent(key){
  setKeyword(KEYWORD);
}

MouseEvent *GoUpEvent::create(int key){
  MouseEvent *gue = new GoUpEvent(key);
  return gue;
}

void GoUpEvent::pressed(int value){
  //  std::cout <<"aaa"  << "\n";
  if ((value == 1 || value == 2)) {
    if (writeKeyEvent(REL_Y,-1*MouseEvent::getSpeed(),EV_REL,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
  }
}


// int main(int argc, char *argv[])
// {
//   GoUpEvent ge = GoUpEvent::create(123);
//   return 0;
// }
