#ifndef SPEED_UP_EVENT_HPP_4075AB5D_4B7C_40C6_BBCC_6EB9540BB6C7_
#define SPEED_UP_EVENT_HPP_4075AB5D_4B7C_40C6_BBCC_6EB9540BB6C7_
#include "MouseEvent.hpp"

class SpeedUpEvent : public MouseEvent
{

public:
  SpeedUpEvent(int key);
  virtual ~SpeedUpEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();
private:
  static string KEYWORD;
};
#endif  // SPEED_UP_EVENT_HPP_4075AB5D_4B7C_40C6_BBCC_6EB9540BB6C7_
