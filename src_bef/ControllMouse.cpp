#include "ControllMouse.hpp"

int ControllKey::forward;
int ControllKey::back;
int ControllKey::up;
int ControllKey::down;
int ControllKey::mouseSpeed;

ControllMouse::ControllMouse(string keyboardEvent,string virtualEvent ,string mouseEvent ,int mouseSpeed){
  pressHyperKey=false;
  pressF=false;
  pressB=false;
  pressP=false;
  pressN=false;
  pressM=false;
  
  keyboardfd.path = keyboardEvent;
  //  virtualfd.path = virtualEvent;
  mousefd.path = mouseEvent;
  
  keyboardfd.fd = open(keyboardfd.path.c_str(),O_RDWR);
  //  virtualfd.fd = open(virtualfd.path.c_str(),O_WRONLY | O_NONBLOCK); //マウスであるべき
  mousefd.fd = open(mousefd.path.c_str(),O_RDWR);

  ControllKey::mouseSpeed = mouseSpeed;

}


int ControllMouse::isOpen(){
  int ret = 0;
  if (keyboardfd.fd > 0) {
    ret = ret + 1;
  }
  if (mousefd.fd > 0 ) {
    ret = ret + 2;
  }
  if (virtualfd.fd > 0) {
    ret = ret + 4;
  }
  return ret;

}

bool ControllMouse::writeKeyEvent(int code,int value,int type, FDManage fdkind ){
  struct input_event keyEvent;
  gettimeofday(&keyEvent.time,NULL);
  keyEvent.type = type;
  keyEvent.code = code;
  keyEvent.value = value;
  if (write(fdkind.fd, &keyEvent, sizeof(keyEvent)) < 0) {
    return false;
  }
  return true;
    
}

bool ControllMouse::isPressed(input_event ev){
  if (ev.value > 0) {
    return true;
  }else {
    return false;
  }
}

//デバッグ用終わり次第消す
void printdebug(bool henkankey,bool yobikey ,char in){
  if (henkankey == true && yobikey == true) {
    std::cout << "Henkan" << " + "   << in << "\n";
  }
}

void ControllMouse::recogKey(input_event event){
  switch (event.type) {
  case EV_KEY: {
    switch(event.code){

    case KEY_HENKAN: {
      cout << event.code << endl;      
      pressHyperKey = isPressed(event);
      break;
    }
    case KEY_F: {
      if ((event.value == 1 || event.value == 2) && pressHyperKey == true) {
	std::cout << "F is Pressed"  << "\n";
	if (writeKeyEvent(REL_X, ControllKey::mouseSpeed, EV_REL, mousefd) == false) {
	  return;
	}
	if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, mousefd) == false) {

	  return;
	}
      }
      
      break;
    }
    case KEY_SPACE: {
      if (event.value == 1 && pressHyperKey == true) {
	if(writeKeyEvent(BTN_LEFT, 1, EV_KEY, mousefd) == false){
	  return;
	}

	if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, mousefd) == false) {
	  return;
	}
	std::cout << "M is Pressed"  << "\n";
      }else if (event.value == 0 && pressHyperKey == true) {
	if (writeKeyEvent(BTN_LEFT, 0, EV_KEY, mousefd) == false) {
	  return ;
	}
	
	if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, mousefd) == false) {
	  return;
	}
	
	std::cout << "M is Released"  << "\n";
      }
      break;
    }
    case KEY_L: {
      if (event.value == 1 && pressHyperKey == true) {
	if(writeKeyEvent(BTN_RIGHT, 1, EV_KEY, mousefd) == false){
	  return;
	}

	if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, mousefd) == false) {
	  return;
	}
	std::cout << "M is Pressed"  << "\n";
      }else if (event.value == 0 && pressHyperKey == true) {
	if (writeKeyEvent(BTN_RIGHT, 0, EV_KEY, mousefd) == false) {
	  return ;
	}
	
	if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, mousefd) == false) {
	  return;
	}
	
	std::cout << "M is Released"  << "\n";
      }
      break;
    }
    case KEY_I: {
      if ((event.value == 1 || event.value == 2)&& pressHyperKey == true) {
	if(writeKeyEvent(REL_WHEEL, 1, EV_REL, mousefd) == false){
	  return;
	}

	if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, mousefd) == false) {
	  return;
	}
	std::cout << "I is Pressed"  << "\n";
      }
      break;
    }
    case KEY_K: {
      if ((event.value == 1 || event.value == 2)&& pressHyperKey == true) {
	if(writeKeyEvent(REL_WHEEL, -1, EV_REL, mousefd) == false){
	  return;
	}

	if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, mousefd) == false) {
	  return;
	}
	std::cout << "K is Pressed"  << "\n";
      }
      break;
    }
   
    case KEY_B: {
      if ((event.value == 1 || event.value == 2) && pressHyperKey == true) {
	std::cout << "B is Pressed"  << "\n";
	if (writeKeyEvent(REL_X, -1*ControllKey::mouseSpeed, EV_REL, mousefd) == false) {
	  return;
	}
	if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, mousefd) == false) {
	  return;
	}
	std::cout << "K is Pressed"  << "\n";
      }
      break;
    }
    case KEY_N: {

      if ((event.value == 1 || event.value == 2) && pressHyperKey == true) {
	std::cout << "N is Pressed"  << "\n";
	if (writeKeyEvent(REL_Y, ControllKey::mouseSpeed, EV_REL, mousefd) == false) {
	  return;
	}
	if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, mousefd) == false) {

	  return;
	}
      }
      break;
    }
    case KEY_P: {
      if ((event.value == 1 || event.value == 2) && pressHyperKey == true) {
	std::cout << "P is Pressed"  << "\n";
	if (writeKeyEvent(REL_Y, -1*ControllKey::mouseSpeed, EV_REL, mousefd) == false) {
	  return;
	}
	if (writeKeyEvent(EV_SYN, 0, SYN_REPORT, mousefd) == false) {
	  return;
	}
      }
      break;
    }
    case KEY_U: {
      if ((event.value == 0) && pressHyperKey == true) {
	ControllKey::mouseSpeed = 10+ControllKey::mouseSpeed;
      }
      break;
    }
    case KEY_D: {
      if ((event.value == 0) && pressHyperKey == true) {
	int nowSpeed = ControllKey::mouseSpeed;
	nowSpeed = nowSpeed-10;
	std::cout <<" nowSpeed" << nowSpeed << "\n";
	if (nowSpeed > 0) {
	  ControllKey::mouseSpeed = nowSpeed;
	}
      }
      break;
    }
    }
      
  }
  default:
    break;
  }  
}

  void ControllMouse::init(){
    ioctl(virtualfd.fd,UI_SET_KEYBIT,BTN_LEFT);
    create_uinput_device(virtualfd);
  }

  void ControllMouse::active(){
  
    while (true) {
    
      struct input_event event;
      if(read(keyboardfd.fd,&event,sizeof(event)) != sizeof(event)){
	exit(EXIT_FAILURE);
      }
      usleep(10000);
      recogKey(event);
      fflush(stdout);
    }

  }

  void ControllMouse::closeFd(){
    close(keyboardfd.fd);
    close(mousefd.fd);
    close(virtualfd.fd);
  }
  void ControllMouse::create_uinput_device(FDManage fd){
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



  FDManage ControllMouse::FDkindtoFDManage(FDkind fk){
    FDManage ret;
    makeDummyFDManage(ret);
    if (fk == VIRTUAL) {
      ret = virtualfd;
    }
    
    if (fk == MOUSE) {
      ret = mousefd;
    }
    if (fk ==KEYBOARD) {
      ret = keyboardfd;
    }
    return ret;
  }

  void ControllMouse::makeDummyFDManage(FDManage &in){
    in.fd = -1;
    in.path = "";
  
  }

