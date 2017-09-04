#include "SeveralMouseEvent.hpp"

void SeveralMouseEvent::pressed(int key){
  key = 1;
}

SeveralMouseEvent::SeveralMouseEvent(vector<int> *keyfd){
  this->keyfd = keyfd;
  for (auto itr = keyfd->begin(); itr != keyfd->end(); itr++) {
    ioctlmake((*itr));
  }
}

void SeveralMouseEvent::pressed(int key,int value,FDManage fd){
  std::cout << Uinput::getfd().fd << "\n";
  if (writeKeyEvent(key,value,EV_KEY,Uinput::getfd()) == false) {
    std::cerr << "Can't write key" << "\n";
    exit(1);
  }
  if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
    std::cerr << "Can't write key" << "\n";
    exit(1);
  }
}

void SeveralMouseEvent::ioctlmake(int fd){
  result.push_back(ioctl(fd,EVIOCGRAB,1));

  // result.push_back(ioctl(fd, UI_SET_EVBIT,EV_KEY));
  // std::cout << fd << "\n";
  
  // for (int i = 1; i <=120; i++) {
  //   result.push_back(ioctl(fd,UI_SET_KEYBIT,i));
  // }

  for (auto itr = result.begin(); itr != result.end() ; itr++) {
    std::cout << (*itr) << "\n";
    if ((*itr) < 0) {
      std::cout << "can't set bits" << "\n";
      exit(1);
    }
    
  }
  
}

void SeveralMouseEvent::destroy(){
  for (auto itr = keyfd->begin(); itr != keyfd->end(); itr++) {
    ioctl((*itr),EVIOCGRAB,0);
  }
}

SeveralMouseEvent *SeveralMouseEvent::create(vector<int> *key){
  SeveralMouseEvent *sme = new SeveralMouseEvent(key);
  return sme;
}

