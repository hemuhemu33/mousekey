#ifndef MOUSE_EVENT_LIST_HPP_AD7AE39E_D213_42EF_9F8A_10AC2C37E5BC_
#define MOUSE_EVENT_LIST_HPP_AD7AE39E_D213_42EF_9F8A_10AC2C37E5BC_
#include <vector>
#include <unistd.h>
#include "./MouseEvent.hpp"
#include "GoLeftEvent.hpp"
#include "GoRightEvent.hpp"
#include "GoDownEvent.hpp"
#include "./Uinput.hpp"
#include "./HyperKeyEvent.hpp"
#include "./GoUpEvent.hpp"
#include "ReadConfig.hpp"
#include <iostream>
#include <fstream>
#include "./RightKeyEvent.hpp"
#include "./KeyboardMap.hpp"
#include "LeftKeyEvent.hpp"
#include "WheelUpEvent.hpp"
#include "WheelDownEvent.hpp"
#include "SpeedUpEvent.hpp"
#include "QuitEvent.hpp"
#include "SpeedDownEvent.hpp"
#include "BrowserNextEvent.hpp"
#include "BrowserBackEvent.hpp"
#include "MiddleKeyEvent.hpp"
#include "ChangeModeEvent.hpp"
#include "BackSpaceCursorEvent.hpp"
#include "HomeCursorEvent.hpp"

#include "EnterCursorEvent.hpp"
#include "UpCursorEvent.hpp"
#include "DownCursorEvent.hpp"
#include "RightCursorEvent.hpp"
#include "LeftCursorEvent.hpp"
#include "DeleteCursorEvent.hpp"
#include "EndCursorEvent.hpp"

using std::vector;
class MouseEventList
{
private:
  static bool isCreated;
  static vector<MouseEvent *> keyboardListMode1;
  static vector<MouseEvent *> keyboardListMode2;
  
  static vector<vector<MouseEvent*>> mode;
  static HyperKeyEvent *hp;
  //  static void sameTextandMouseEv(string keyword,MouseEvent *ms);
  static void checkAllEvents(string keyword,int key,string mode);
  static string filepath;
public:
  //parseConfig テストのためpublicへ
  static void parseConfig(string filepath);
  static void create(int argc,char **argv);
  static HyperKeyEvent *getHyperKeyEvent();
  static vector<MouseEvent *>getMouseEventVector();

};
#endif  // MOUSE_EVENT_LIST_HPP_AD7AE39E_D213_42EF_9F8A_10AC2C37E5BC_
