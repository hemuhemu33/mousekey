#ifndef ENTER_CURSOR_EVENT_HPP_4D8E814B_AA94_4492_B5BE_6F0B3C3E58ED_
#define ENTER_CURSOR_EVENT_HPP_4D8E814B_AA94_4492_B5BE_6F0B3C3E58ED_

#include "MouseEvent.hpp"
class EnterCursorEvent : public MouseEvent
{
public:
  EnterCursorEvent(int key);
  virtual ~EnterCursorEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};

#endif  // ENTER_CURSOR_EVENT_HPP_4D8E814B_AA94_4492_B5BE_6F0B3C3E58ED_
