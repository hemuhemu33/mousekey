#ifndef KEYBOARD_MODE_HPP_62081ABC_41A7_45F9_9C9D_410129848630_
#define KEYBOARD_MODE_HPP_62081ABC_41A7_45F9_9C9D_410129848630_
#include "Mode.hpp"
#include "MouseEvent.hpp"
#include <vector>

#include "./Uinput.hpp"

#include "./MouseEvent.hpp"
#include "GoLeftEvent.hpp"
#include "GoRightEvent.hpp"
#include "GoDownEvent.hpp"
#include <iostream>
#include <fstream>

#include "./KeyboardMap.hpp"

#include "./HyperKeyEvent.hpp"
#include "./GoUpEvent.hpp"
#include "ReadConfig.hpp"
#include "./RightKeyEvent.hpp"

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

class KeyboardMode
{
public:
  static void _create();
  static vector<MouseEvent *> *_getMouseEventVector();
  static void _setMouseEvent(string mode,MouseEvent *event);
  static bool _setMode(int mode);
  static void _nextMode();
  static Mode* _getMode();

  //for debug
  //  static void printmodeList();

private:
  static vector<vector<MouseEvent *> > _keyboard;
  static Mode *_mode;
  static vector<Mode> _modeList;
  static vector<MouseEvent *> keyboardListMode1;
};
#endif  // KEYBOARD_MODE_HPP_62081ABC_41A7_45F9_9C9D_410129848630_
