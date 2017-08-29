#ifndef RIGHT_KEY_EVENT_HPP_5A1F9281_998D_4032_9441_339FB9E09237_
#define RIGHT_KEY_EVENT_HPP_5A1F9281_998D_4032_9441_339FB9E09237_
#include "MouseEvent.hpp"
class RightKeyEvent : public MouseEvent
{
public:
  RightKeyEvent(int key);
  virtual ~RightKeyEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};
#endif  // RIGHT_KEY_EVENT_HPP_5A1F9281_998D_4032_9441_339FB9E09237_
