#ifndef LEFT_CURSOR_EVENT_HPP_5818E10A_1438_4B52_8103_ABDC486DBE1B_
#define LEFT_CURSOR_EVENT_HPP_5818E10A_1438_4B52_8103_ABDC486DBE1B_

#include "MouseEvent.hpp"
class LeftCursorEvent : public MouseEvent
{
public:
  LeftCursorEvent(int key);
  virtual ~LeftCursorEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};
#endif  // LEFT_CURSOR_EVENT_HPP_5818E10A_1438_4B52_8103_ABDC486DBE1B_
