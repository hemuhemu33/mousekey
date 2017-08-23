#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include "MouseConfig.hpp"
#include "Uinput.hpp"

using std::string;
#ifndef MOSUE_EVENT_HPP_C47A4E75_F621_420C_AFD7_C61E2089AFDE_
#define MOSUE_EVENT_HPP_C47A4E75_F621_420C_AFD7_C61E2089AFDE_
class MouseEvent
{
private:
  static int speed;
  int key;
  static string KEYWORD;
public:
  MouseEvent();
  MouseEvent(int key);
  virtual ~MouseEvent(){}
  static void setSpeed(int speed);
  static int getSpeed();
  int getKey();
  void setKeyword(string KEYWORD);
  void setKey(int key);
  static string getKeyword();
  static MouseEvent *create();
  bool writeKeyEvent(int code, int value, int type,FDManage fd);
  virtual void pressed(int value) = 0;
  
  
};
#endif  // MOSUE_EVENT_HPP_C47A4E75_F621_420C_AFD7_C61E2089AFDE_
