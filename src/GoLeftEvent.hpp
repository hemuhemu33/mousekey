#ifndef GO_LEFT_EVENT_HPP_8B136492_2B62_453D_9831_6848367B56C7_
#define GO_LEFT_EVENT_HPP_8B136492_2B62_453D_9831_6848367B56C7_
#include "MouseEvent.hpp"
class GoLeftEvent : public MouseEvent
{
public:
  GoLeftEvent(int key);
  virtual ~GoLeftEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};
#endif  // GO_LEFT_EVENT_HPP_8B136492_2B62_453D_9831_6848367B56C7_
