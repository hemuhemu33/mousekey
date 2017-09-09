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

void SeveralMouseEvent::pressed(input_event ev){
  if (ev.type ==  EV_KEY ) {
    //    std::cout << ev.code << "\n";
    if (writeKeyEvent(ev.code,ev.value,EV_KEY,Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, Uinput::getfd()) == false) {
      std::cerr << "Can't write key" << "\n";
      exit(1);
    }
    

    
  }
    



}

void SeveralMouseEvent::ioctlmake(int fd){
  //ioctlする前にsleepを入れる必要がある。
  //  sleep(1);
  //挙動がおかしかったら、usleepの中の値を大きくしてみる。あとでudevを作ることによってenterを認識させないようにした。
  //  usleep(100000);
  struct input_event ev;

  //   std::cout << "fd" << fd << "\n";
  result.push_back(ioctl(fd,EVIOCGRAB,1));
  while ((read(fd,&ev, sizeof(struct input_event)) >= 0)) {
    std::cout << ev.code << " " << ev.value << "\n";
  }
  //  std::cout << Uinput::getfd().fd << "\n";
  
  
  for (auto itr = result.begin(); itr != result.end() ; itr++) {
    //    std::cout << (*itr) << "\n";
    if ((*itr) < 0) {
      std::cout << "can't set bits" << "\n";
      exit(1);
    }
    
  }
  //  sleep(1);

  // if(writeKeyEvent(KEY_A,1,EV_KEY,Uinput::getfd())&&
  //    writeKeyEvent(KEY_A,0,EV_KEY,Uinput::getfd())&&
  //    writeKeyEvent(EV_SYN,0,SYN_REPORT,Uinput::getfd()) == false){
  //   std::cerr << "Can't write key" << "\n";
  //   exit(1);
  // }
  FDManage fds;
  fds.fd = fd;
  // if(writeKeyEvent(KEY_A,1,EV_KEY,fds)&&
  //    writeKeyEvent(KEY_A, 0, EV_KEY, fds) &&
  //    writeKeyEvent(EV_SYN,0,SYN_REPORT,fds) == false){
  //   std::cerr << "Can't write key" << "\n";
  //   exit(1);
  // }


  
}

void SeveralMouseEvent::destroy(){
  for (auto itr = keyfd->begin(); itr != keyfd->end(); itr++) {
    ioctl((*itr),EVIOCGRAB,0);
  }
}

SeveralMouseEvent *SeveralMouseEvent::create(vector<int> *key){
  // for (auto itr = key->begin(); itr!=key->end(); itr++) {
  //   std::cout << *(itr) << "\n";
  // }
  SeveralMouseEvent *sme = new SeveralMouseEvent(key);

  return sme;
}

