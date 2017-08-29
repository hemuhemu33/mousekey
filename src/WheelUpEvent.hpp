#ifndef WHEEL_UP_EVENT_HPP_8D1F0567_2DFE_4ACA_8F2B_152D204E92B1_
#define WHEEL_UP_EVENT_HPP_8D1F0567_2DFE_4ACA_8F2B_152D204E92B1_
#include "MouseEvent.hpp"

class WheelUpEvent : public MouseEvent
{

public:
  WheelUpEvent(int key);
  virtual ~WheelUpEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();
private:
  static string KEYWORD;
};
#endif  // WHEEL_UP_EVENT_HPP_8D1F0567_2DFE_4ACA_8F2B_152D204E92B1_
