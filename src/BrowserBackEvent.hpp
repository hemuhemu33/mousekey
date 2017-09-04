#ifndef BROWSER_BACK_EVENT_HPP_6772215E_211A_46A1_84BA_C4E8B3045C5F_
#define BROWSER_BACK_EVENT_HPP_6772215E_211A_46A1_84BA_C4E8B3045C5F_
#include "MouseEvent.hpp"
class BrowserBackEvent : public MouseEvent
{
public:
  BrowserBackEvent(int key);
  virtual ~BrowserBackEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};
#endif  // BROWSER_BACK_EVENT_HPP_6772215E_211A_46A1_84BA_C4E8B3045C5F_
