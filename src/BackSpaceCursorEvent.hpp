#ifndef BACK_SPACE_CURSOR_EVENT_HPP_67E6974F_AB2E_41C7_BD45_3AE1E8A52375_
#define BACK_SPACE_CURSOR_EVENT_HPP_67E6974F_AB2E_41C7_BD45_3AE1E8A52375_


#include "MouseEvent.hpp"
class BackSpaceCursorEvent : public MouseEvent
{
public:
  BackSpaceCursorEvent(int key);
  virtual ~BackSpaceCursorEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};


#endif  // BACK_SPACE_CURSOR_EVENT_HPP_67E6974F_AB2E_41C7_BD45_3AE1E8A52375_
