#ifndef SPEED_DOWN_EVENT_HPP_C0DF3982_F4AC_454B_90A5_5B7919941593_
#define SPEED_DOWN_EVENT_HPP_C0DF3982_F4AC_454B_90A5_5B7919941593_
#include "MouseEvent.hpp"

class SpeedDownEvent : public MouseEvent
{

public:
  SpeedDownEvent(int key);
  virtual ~SpeedDownEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();
private:
  static string KEYWORD;
};
#endif  // SPEED_DOWN_EVENT_HPP_C0DF3982_F4AC_454B_90A5_5B7919941593_
