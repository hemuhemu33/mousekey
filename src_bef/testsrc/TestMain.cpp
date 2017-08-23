#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/uinput.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/inotify.h>
#include "../ControllMouse.hpp"
#define MOUSE_EVENT "/dev/input/event5"
#define KEYBOARD_EVENT "/dev/input/event14"
#define VIRTUAL_EVENT "/dev/uinput"
int keyboardfd; 
int mousefd;
int virtualfd;




void writeKeyEvent(int code,int value,int fd){
  struct input_event keyEvent;
  gettimeofday(&keyEvent.time,NULL);
  keyEvent.type = EV_KEY;
  keyEvent.code = code;
  keyEvent.value = value;
  write(fd,&keyEvent,sizeof(keyEvent));
}
void test1(){
    //  mousefd=open(MOUSE_EVENT,O_RDWR);
  mousefd=open("/dev/input/event9",O_RDWR);
  keyboardfd=open(KEYBOARD_EVENT,O_RDWR);
  printf("%d",mousefd);
  printf("%d",keyboardfd);
  while (true) {
    struct input_event event;
    struct input_event keyevent;
    if (read(mousefd,&event,sizeof(event))!=sizeof(event)) {
      exit(EXIT_FAILURE);
    }
    if (read(keyboardfd,&keyevent,sizeof(keyevent))!=sizeof(keyevent)) {
      exit(EXIT_FAILURE);
    }
    switch (keyevent.type) {

    case EV_KEY: {

      switch(keyevent.code){
      case KEY_HENKAN: {
	std::cout << "aaa" << "\n";
	break;
      }
      default:
	std::cout << keyevent.code << "\n";
	break;
      }

      break;
    }
    default:
      break;
    }
    // switch (event.type) {
    // case EV_KEY: {
    //   printf("code:%x value:%x\n",event.code,event.value);
    //   break;
    // }
    // case EV_REL: {
    //   printf("code:%x value:%x\n",event.code,event.value);
    //   break;
    // }
    // case EV_ABS: {
    //   printf("code:%x value:%x\n",event.code,event.value);
    //   break;
    // }

    // default:
    //   break;
    // }
    fflush(stdout);
  }
  close(keyboardfd);
  close(mousefd);
}



void create_uinput_device(int fd){
  struct uinput_user_dev uidev;
  memset(&uidev,0,sizeof(uidev));
  snprintf(uidev.name,UINPUT_MAX_NAME_SIZE,"TESTKEY");
  uidev.id.bustype = BUS_USB;
  uidev.id.vendor = 0xAAAA;
  uidev.id.product = 0xBBBB;
  uidev.id.version = 1;
  if(write(fd,&uidev,sizeof(uidev)) < 0){
    std::cout << "ii" << "\n";
    exit(0);
  }
  if (ioctl(fd,UI_DEV_CREATE) < 0) {
    std::cout << "uu" << "\n";
    exit(0);
  }
    
}
bool isPressed(input_event ev){
  if (ev.value > 0) {
    return true;
  }else {
    return false;
  }
}
void test2(){
  //変換+Fの同時押しを確認
  bool pressHenkanKey = false;
  bool pressF = false;

  mousefd = open(MOUSE_EVENT,O_RDWR);
  keyboardfd = open(KEYBOARD_EVENT,O_RDWR);
  virtualfd = open("/dev/uinput",O_WRONLY | O_NONBLOCK); //マウスであるべき
  std::cout << keyboardfd << "\n";
  
  // ioctl(keyboardfd,UI_SET_KEYBIT,KEY_HENKAN);
  // ioctl(keyboardfd,UI_SET_KEYBIT,KEY_F);

  while (true) {
    struct input_event event;
    if(read(keyboardfd,&event,sizeof(event)) != sizeof(event)){
      exit(EXIT_FAILURE);
    }
    
    switch (event.type) {

    case EV_KEY: {
      switch(event.code){

      case KEY_HENKAN: {
	//	pressHenkanKey = isPressed(event);
	pressHenkanKey = isPressed(event);

	break;
      }
      case KEY_F: {
	pressF = isPressed(event);
	if (pressHenkanKey == true) {
	  std::cout << "Henkan + f" << "\n";
	}
	break;
      }

      }
      
      break;
    }
    default:
      break;
    }
    fflush(stdout);
  }
 BREAK:  
  // ioctl(keyboardfd,EVIOCGRAB,0);
  close(keyboardfd);
  close(mousefd);
  close(virtualfd);
}
void test3(){
  struct input_event event1,event2;
  int fd1 = open("/dev/input/event3",O_RDWR | O_NONBLOCK); //マウスであるべき
  //O_NONBLOCKを指定することによってreadで入力待ちを行わなければならない。
  int fd2 = open("/dev/input/event7",O_RDWR | O_NONBLOCK); //マウスであるべき
  int i;
  while (true) {
    i = read(fd1,&event1,sizeof(event1));
    if (i < 0) {
      
    }else {
      std::cout << "fd1" <<i << "\n";
    }
    i = read(fd2,&event2,sizeof(event2));
    if (i < 0) {
      
    }else {
      std::cout << "fd2"<<i << "\n";
    }    
  }
  
}

int main(int argc, char *argv[])
{

  //  test2();
  ControllMouse *cm = new ControllMouse(KEYBOARD_EVENT,VIRTUAL_EVENT,MOUSE_EVENT);
  std::cout << cm->isOpen() << "\n";
  cm->active();
  //  test3();
  return 0;
}



