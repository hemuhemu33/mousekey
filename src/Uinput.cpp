#include "Uinput.hpp"
#include <errno.h>

FDManage Uinput::virtualfd;
vector<int> Uinput::result;

int Uinput::create(string devicepath){
  virtualfd.path = devicepath;
  virtualfd.fd = open(devicepath.c_str(),O_WRONLY | O_NONBLOCK);
  if (virtualfd.fd == -1) {
    return -1;
  }
  

  registIoctl();
  //  std::cout << "size is " << result.size() << "\n";
  for (auto itr = result.begin(); itr != result.end(); itr++) {
    // std::cout << "itr" << *itr << "\n";
    if ((*itr) < 0) {

      return -2;
    }
  }

  createDevice(virtualfd);
  return 1;
}

void Uinput::registIoctl(){
  //イベント事を増やす場合はここに追加する。
  
  result.push_back(ioctl(virtualfd.fd,UI_SET_EVBIT,EV_REL));
  result.push_back(ioctl(virtualfd.fd,UI_SET_RELBIT,REL_X));
  result.push_back(ioctl(virtualfd.fd, UI_SET_RELBIT, REL_Y));
  result.push_back(ioctl(virtualfd.fd,UI_SET_RELBIT,REL_WHEEL));
  
  result.push_back(ioctl(virtualfd.fd, UI_SET_EVBIT,EV_KEY));
  result.push_back(ioctl(virtualfd.fd, UI_SET_KEYBIT,BTN_RIGHT));
  result.push_back(ioctl(virtualfd.fd, UI_SET_KEYBIT,BTN_LEFT));
  result.push_back(ioctl(virtualfd.fd, UI_SET_KEYBIT,BTN_MIDDLE));
  result.push_back(ioctl(virtualfd.fd, UI_SET_KEYBIT,BTN_SIDE));
  result.push_back(ioctl(virtualfd.fd, UI_SET_KEYBIT,BTN_EXTRA));

  

}  



FDManage Uinput::getfd(){
  return virtualfd;
}

void Uinput::createDevice(FDManage fd){
  struct uinput_user_dev uidev;
  memset(&uidev,0,sizeof(uidev));
  snprintf(uidev.name,UINPUT_MAX_NAME_SIZE,"MOUSE_VIRTUAL_DEVICE");
  uidev.id.bustype = BUS_USB;
  uidev.id.vendor = 0xAAAA;
  uidev.id.product = 0xBBBB;
  uidev.id.version = 1;
  if(write(fd.fd,&uidev,sizeof(uidev)) < 0){
    exit(0);
  }
  if (ioctl(fd.fd,UI_DEV_CREATE) < 0) {
    exit(0);
  }
}

