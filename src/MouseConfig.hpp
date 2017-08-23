#ifndef MOUSE_CONFIG_HPP_603240EC_FFB2_42D8_A615_4367EE7FBEF6_
#define MOUSE_CONFIG_HPP_603240EC_FFB2_42D8_A615_4367EE7FBEF6_
#include <string>
#include <vector>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>

using std::string;
enum FDkind{
  VIRTUAL,
  MOUSE,
  KEYBOARD
};


/*
 *キー配置を設定するクラス
 *staticなので気をつけて
 */
class ControllKey
{
public:
  static int forward;
  static int back;
  static int up;
  static int down;
  static int mouseSpeed;
};


/*
 *fdの状態を見るクラス　
 */
class FDManage
{
public:
  int fd;
  string path;
};

#endif  // MOUSE_CONFIG_HPP_603240EC_FFB2_42D8_A615_4367EE7FBEF6_
