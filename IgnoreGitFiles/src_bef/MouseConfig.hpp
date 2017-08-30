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

