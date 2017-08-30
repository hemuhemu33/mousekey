#ifndef HOME_CURSOR_EVENT_HPP_6ABA040D_AB21_42AC_8CBB_ECD3A2264EEE_
#define HOME_CURSOR_EVENT_HPP_6ABA040D_AB21_42AC_8CBB_ECD3A2264EEE_

#include "MouseEvent.hpp"
class HomeCursorEvent : public MouseEvent
{
public:
  HomeCursorEvent(int key);
  virtual ~HomeCursorEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};


#endif  // HOME_CURSOR_EVENT_HPP_6ABA040D_AB21_42AC_8CBB_ECD3A2264EEE_
