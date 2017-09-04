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


// enum MODE{
//   MOUSEMODE=0,KEYBOARDMODE=1
// };



class MouseEvent
{
private:
  static int speed;
  int key;
  static string KEYWORD;
  static int incrementSpeed;
  static int declementSpeed;
  //  static MODE mode;

public:
  MouseEvent();
  MouseEvent(int key);
  virtual ~MouseEvent(){}
  static void setSpeed(int speed);
  static int getSpeed();
  static int getIncrementSpeed();
  static int getDecrementSpeed();
  static void setIncrementSpeed(int speed);
  static void setDecrementSpeed(int speed);
  int getKey();
  void setKeyword(string KEYWORD);
  void setKey(int key);
  static string getKeyword();
  static MouseEvent *create();
  bool writeKeyEvent(int code, int value, int type,FDManage fd);
  virtual void pressed(int value) = 0;
  //  static MODE getMode();
  //  static void setMode(MODE m);
  
};
#endif  // MOSUE_EVENT_HPP_C47A4E75_F621_420C_AFD7_C61E2089AFDE_
