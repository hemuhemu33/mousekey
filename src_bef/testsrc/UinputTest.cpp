#include "../Uinput.hpp"
#include <iostream>
/*ControllMouse.cppから持ってきて変えた。ただ、統合後はControllMouce.cppの方を使う
 */
bool writeKeyEvent(int code,int value,int type, int fdkind ){
  struct input_event keyEvent;
  gettimeofday(&keyEvent.time,NULL);
  keyEvent.type = type;
  keyEvent.code = code;
  keyEvent.value = value;
  if (write(fdkind, &keyEvent, sizeof(keyEvent)) < 0) {
    return false;
  }
  return true;
    
}

int main(int argc, char *argv[])
{
  //  std::cout << Uinput::create() << "\n";
  if (Uinput::create() < 0) {
    exit(0);
  }
  if (Uinput::getfd() < 0) {
    exit(0);
  }
  std::cout << Uinput::getfd() << "\n";
  while (1) {
    int ret = writeKeyEvent(REL_X, 3, EV_REL,Uinput::getfd());
    writeKeyEvent(EV_SYN, 0,SYN_REPORT ,Uinput::getfd());
    std::cout << "aaa"<< ret << "\n";
    sleep(1);
  }
  return 0;
}

