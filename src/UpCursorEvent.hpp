#ifndef UP_CURSOR_EVENT_HPP_F23E7B28_BE5E_410B_A411_D2219E656EAF_
#define UP_CURSOR_EVENT_HPP_F23E7B28_BE5E_410B_A411_D2219E656EAF_

#include "MouseEvent.hpp"
class UpCursorEvent : public MouseEvent
{
public:
  UpCursorEvent(int key);
  virtual ~UpCursorEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};

#endif  // UP_CURSOR_EVENT_HPP_F23E7B28_BE5E_410B_A411_D2219E656EAF_
