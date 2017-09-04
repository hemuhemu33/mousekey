#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Uinput.hpp"
#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>

static int do_terminate = 0;

#define die(str, args...) do { perror(str); exit(EXIT_FAILURE); } while(0)

void send_event (int fd, int type, int code, int value) {
  struct input_event ev;
  memset(&ev, 0, sizeof(ev));

  gettimeofday(&ev.time, NULL);

  ev.type = type;
  ev.code = code;
  ev.value = value;

  if (write(fd, &ev, sizeof(ev)) < 0)
    die("error: write");
}

void ioctl_set (int fd, int set, int value) {
  if (ioctl(fd, set, value) < 0)
    die("error: ioctl set");
}

void create_uinput_device (int fd) {
  struct uinput_user_dev uidev;
  memset(&uidev, 0, sizeof(uidev));

  snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "NiseFootPedal");
  uidev.id.bustype = BUS_USB;
  uidev.id.vendor  = 0xDEAD;
  uidev.id.product = 0xBEEF;
  uidev.id.version = 1;

  if (write(fd, &uidev, sizeof(uidev)) < 0)
    die("create_uinput_device: write");

  if (ioctl(fd, UI_DEV_CREATE) < 0)
    die("create_uinput_device: ioctl");
}

void destroy_uinput_device (int fd) {
  if (ioctl(fd, UI_DEV_DESTROY) < 0)
    die("destroy_uinput_device: ioctl");
}

void on_term (int signal)
{
  printf("TERM\n");
  do_terminate = 1;
}

void set_signal_handler ()
{
  sigset_t mask;
  sigemptyset(&mask);
  signal(SIGTERM, on_term);
  signal(SIGINT, on_term);
  sigaddset(&mask, SIGTERM);
  sigaddset(&mask, SIGINT);
  sigprocmask(SIG_UNBLOCK, &mask, NULL);
}


int main (int argc, char** argv) {
  int outkb, inkb, ret;
  Uinput::create();
  printf("%s\n", argv[1]);
  if (argc != 2)
    die("Usage: footpedal <INPUT_DEVICE_EVENT>");

  inkb = open(argv[1], O_RDONLY | O_NONBLOCK);
  if (inkb < 0)
    die("error: open (in)");

  outkb = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
  if (outkb < 0)
    die("error: open (out)");

  ioctl_set(outkb, UI_SET_EVBIT, EV_KEY);
  ioctl_set(outkb, UI_SET_KEYBIT, KEY_ESC);

  create_uinput_device(outkb);

  struct input_event ev;
  int sz;

  //ioctlする前にsleepを入れる必要がある。
  sleep(1);
  //keyboard削除
  ioctl(inkb, EVIOCGRAB, 1);


  //これをいれとかないとずっとenterを押した状態になる。
  send_event(Uinput::getfd().fd, EV_KEY, KEY_LEFTCTRL, 1);
  send_event(Uinput::getfd().fd, EV_KEY, KEY_LEFTCTRL, 0);
  send_event(Uinput::getfd().fd, EV_SYN, SYN_REPORT, 0);


  
  while ((sz = read(inkb, &ev, sizeof(struct input_event)))) {

    if (sz < 0)
      continue;
    if (ev.type != EV_KEY)
      continue;
    if (!((ev.value == 1) || (ev.value == 0)))
      continue;

    send_event(Uinput::getfd().fd, EV_KEY, ev.code, ev.value);
    send_event(Uinput::getfd().fd, EV_SYN, SYN_REPORT, 0);
  }

  ioctl(inkb, EVIOCGRAB, 0);

  destroy_uinput_device(outkb);

  close(outkb);
  close(inkb);

  exit(EXIT_SUCCESS);
}
