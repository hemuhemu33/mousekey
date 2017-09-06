#ifndef SEVERAL_MOUSE_EVENT_HPP_19173FDB_6C9A_41D6_98B9_A53074B1DE26_
#define SEVERAL_MOUSE_EVENT_HPP_19173FDB_6C9A_41D6_98B9_A53074B1DE26_
#include <vector>
#include <string>

#include "Uinput.hpp"
#include "MouseEvent.hpp"
#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
using std::vector;
using std::string;


class SeveralMouseEvent : MouseEvent
{
public:
  static SeveralMouseEvent *create(vector<int> *key);
  SeveralMouseEvent(vector<int> *keyfd);
  void destroy();
  void pressed(int key,int value);

private:
  void ioctlmake(int fd);
  void pressed(int key);
  string filepath;
  vector<int> result;
  vector<int> *keyfd;
};
#endif  // SEVERAL_MOUSE_EVENT_HPP_19173FDB_6C9A_41D6_98B9_A53074B1DE26_
