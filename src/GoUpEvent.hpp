#ifndef GO_UP_EVENT_HPP_E631D29A_4995_4D5E_BBF3_C9A9D976E6BB_
#define GO_UP_EVENT_HPP_E631D29A_4995_4D5E_BBF3_C9A9D976E6BB_
#include "MouseEvent.hpp"

class GoUpEvent : public MouseEvent
{
public:
  GoUpEvent(int key);
  virtual ~GoUpEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();
private:

  static string KEYWORD;
};
#endif  // GO_UP_EVENT_HPP_E631D29A_4995_4D5E_BBF3_C9A9D976E6BB_
