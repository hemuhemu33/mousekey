#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/uinput.h>
#include <string.h>

//ここでマウスとキーボードのイベントを設定してください。
#define MOUSE_EVENT "/dev/input/event5"
#define KEYBOARD_EVENT "/dev/input/event14"


#define die(str, args...) do { perror(str); exit(EXIT_FAILURE); } while(0)

int keyboardfd;
int mousefd;
int virtualfd;

void create_uinput_device (int fd) {
  struct uinput_user_dev uidev;
  memset(&uidev, 0, sizeof(uidev));

  snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "YUKIMOUSE");
  uidev.id.bustype = BUS_USB;
  uidev.id.vendor  = 0xAAAA;
  uidev.id.product = 0xBBBB;
  uidev.id.version = 1;

  if (write(fd, &uidev, sizeof(uidev)) < 0)
    die("create_uinput_device: write");

  if (ioctl(fd, UI_DEV_CREATE) < 0)
    die("create_uinput_device: ioctl");
}

void send_event(int output, int type, int code, int value)
{
  struct input_event event;

  event.type = type;
  event.code = code;
  event.value = value;
  gettimeofday(&event.time, NULL);
	write(output, &event, sizeof(event));
}

int main(void)
{
  mousefd = open(MOUSE_EVENT, O_RDWR);
  keyboardfd = open(KEYBOARD_EVENT, O_RDWR);
  virtualfd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
	
  //マウス機能を登録し、User Inputデバイスを作成する
  //ここで左クリックを有効にするよーとか、マウス動かすよーとか登録
  ioctl(virtualfd, UI_SET_EVBIT, EV_REL);
  ioctl(virtualfd, UI_SET_RELBIT, REL_X);
  ioctl(virtualfd, UI_SET_RELBIT, REL_Y);
  ioctl(virtualfd, UI_SET_RELBIT, REL_WHEEL);
  ioctl(virtualfd, UI_SET_EVBIT, EV_KEY);
  ioctl(virtualfd, UI_SET_KEYBIT, BTN_LEFT);
  ioctl(virtualfd, UI_SET_KEYBIT, BTN_RIGHT);
  ioctl(virtualfd, UI_SET_KEYBIT, BTN_MIDDLE);
  create_uinput_device(virtualfd);
	
  //マウスを無効化
  ioctl(mousefd, EVIOCGRAB, 1);
	
  for (;;) {
    struct input_event event;

    if (read(mousefd, &event, sizeof(event)) != sizeof(event)) {
      exit(EXIT_FAILURE);
    }
    switch(event.type) {
    case EV_KEY:
				
      if(event.code == BTN_EXTRA && event.value == 1) {//EXTRAボタンを押したときCTRL + W
	send_event(keyboardfd, event.type, KEY_LEFTCTRL, 1);					
	send_event(keyboardfd, event.type, KEY_W, 1);
	send_event(keyboardfd, EV_SYN, SYN_REPORT, 0);
      }else if(event.code == BTN_EXTRA && event.value == 0) {//EXTRAボタンを離したとき
	send_event(keyboardfd, event.type, KEY_W, 0);
	send_event(keyboardfd, event.type, KEY_LEFTCTRL, 0);
	send_event(keyboardfd, EV_SYN, SYN_REPORT, 0);
      }else if(event.code == BTN_SIDE && event.value == 1) {//SIDEボタンを押したとき CTRL + TAB
	send_event(keyboardfd, event.type, KEY_LEFTCTRL, 1);	
	send_event(keyboardfd, event.type, KEY_TAB, 1);
	send_event(keyboardfd, EV_SYN, SYN_REPORT, 0);	
      }else if(event.code == BTN_SIDE && event.value == 0) {//SIDEボタンを離したとき
	send_event(keyboardfd, event.type, KEY_TAB, 0);
	send_event(keyboardfd, event.type, KEY_LEFTCTRL, 0);
	send_event(keyboardfd, EV_SYN, SYN_REPORT, 0);
					
      }else {
	send_event(mousefd, event.type, event.code, event.value);
      }
      break;
    case EV_REL:
      //printf("%x  ", event.code);
      send_event(mousefd, event.type, event.code, event.value);
      break;
    case EV_ABS:
      send_event(mousefd, event.type, event.code, event.value);
      break;
    default:
      send_event(mousefd, event.type, event.code, event.value);
      //printf("0");
      break;
    }
    fflush(stdout);
  }
  
  //マウスを有効に戻す
  ioctl(mousefd, EVIOCGRAB, 0);
  
  close(keyboardfd);
  close(mousefd);
  close(virtualfd);
}
