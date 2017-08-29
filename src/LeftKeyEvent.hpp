#ifndef LEFT_KEY_EVENT_HPP_69313748_6E5B_4FA9_9A31_F60A2450833C_
#define LEFT_KEY_EVENT_HPP_69313748_6E5B_4FA9_9A31_F60A2450833C_
#include "MouseEvent.hpp"

class LeftKeyEvent : public MouseEvent
{
public:
  LeftKeyEvent(int key);
  virtual ~LeftKeyEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();
private:

  static string KEYWORD;
};

#endif  // LEFT_KEY_EVENT_HPP_69313748_6E5B_4FA9_9A31_F60A2450833C_
