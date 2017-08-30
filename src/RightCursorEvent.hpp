#ifndef RIGHT_CURSOR_EVENT_HPP_7E73AA4B_3F07_4199_83C2_4192FF624E30_
#define RIGHT_CURSOR_EVENT_HPP_7E73AA4B_3F07_4199_83C2_4192FF624E30_

#include "MouseEvent.hpp"
class RightCursorEvent : public MouseEvent
{
public:
  RightCursorEvent(int key);
  virtual ~RightCursorEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};


#endif  // RIGHT_CURSOR_EVENT_HPP_7E73AA4B_3F07_4199_83C2_4192FF624E30_
