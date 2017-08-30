#ifndef DELETE_CURSOR_EVENT_HPP_12E979F8_4149_409A_875E_286A86150CA1_
#define DELETE_CURSOR_EVENT_HPP_12E979F8_4149_409A_875E_286A86150CA1_

#include "MouseEvent.hpp"
class DeleteCursorEvent : public MouseEvent
{
public:
  DeleteCursorEvent(int key);
  virtual ~DeleteCursorEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};

#endif  // DELETE_CURSOR_EVENT_HPP_12E979F8_4149_409A_875E_286A86150CA1_
