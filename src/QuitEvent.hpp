#ifndef QUIT_EVENT_HPP_015FD385_3999_499C_BAD3_80850290BD74_
#define QUIT_EVENT_HPP_015FD385_3999_499C_BAD3_80850290BD74_
#include "MouseEvent.hpp"

class QuitEvent : public MouseEvent
{

public:
  QuitEvent(int key);
  virtual ~QuitEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();
private:
  static string KEYWORD;
};
#endif  // QUIT_EVENT_HPP_015FD385_3999_499C_BAD3_80850290BD74_
