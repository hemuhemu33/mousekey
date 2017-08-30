#ifndef DOWN_CURSOR_EVENT_HPP_3E33A820_F6E4_4A5D_9187_372C0DFA39CA_
#define DOWN_CURSOR_EVENT_HPP_3E33A820_F6E4_4A5D_9187_372C0DFA39CA_


#include "MouseEvent.hpp"
class DownCursorEvent : public MouseEvent
{
public:
  DownCursorEvent(int key);
  virtual ~DownCursorEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};



#endif  // DOWN_CURSOR_EVENT_HPP_3E33A820_F6E4_4A5D_9187_372C0DFA39CA_
