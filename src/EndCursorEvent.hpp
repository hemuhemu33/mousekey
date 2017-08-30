#ifndef END_CURSOR_EVENT_HPP_579CA9F3_4332_4E7D_AC48_750104C52FA9_
#define END_CURSOR_EVENT_HPP_579CA9F3_4332_4E7D_AC48_750104C52FA9_
#include "MouseEvent.hpp"
class EndCursorEvent : public MouseEvent
{
public:
  EndCursorEvent(int key);
  virtual ~EndCursorEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};

#endif  // END_CURSOR_EVENT_HPP_579CA9F3_4332_4E7D_AC48_750104C52FA9_
