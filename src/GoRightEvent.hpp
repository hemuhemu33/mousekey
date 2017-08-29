#ifndef GO_RIGHT_EVENT_HPP_29D32E8F_8B7D_42E8_9E15_8498FC5BB5BA_
#define GO_RIGHT_EVENT_HPP_29D32E8F_8B7D_42E8_9E15_8498FC5BB5BA_
#include "MouseEvent.hpp"
class GoRightEvent : public MouseEvent
{
public:
  GoRightEvent(int key);
  virtual ~GoRightEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};
#endif  // GO_RIGHT_EVENT_HPP_29D32E8F_8B7D_42E8_9E15_8498FC5BB5BA_
