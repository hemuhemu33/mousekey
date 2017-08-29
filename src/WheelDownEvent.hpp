#ifndef WHEEL_DOWN_EVENT_HPP_82958B96_E2FB_4A88_BF50_C9FA2A9AB027_
#define WHEEL_DOWN_EVENT_HPP_82958B96_E2FB_4A88_BF50_C9FA2A9AB027_
#include "MouseEvent.hpp"

class WheelDownEvent : public MouseEvent
{

public:
  WheelDownEvent(int key);
  virtual ~WheelDownEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();
private:
  static string KEYWORD;
};
#endif  // WHEEL_DOWN_EVENT_HPP_82958B96_E2FB_4A88_BF50_C9FA2A9AB027_
