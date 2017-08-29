#ifndef BROWSER_NEXT_EVENT_HPP_C7116A1F_0F73_4EC2_BFE7_97F871D44F07_
#define BROWSER_NEXT_EVENT_HPP_C7116A1F_0F73_4EC2_BFE7_97F871D44F07_
#include "MouseEvent.hpp"

class BrowserNextEvent : public MouseEvent
{
public:
  BrowserNextEvent(int key);
  virtual ~BrowserNextEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};

#endif  // BROWSER_NEXT_EVENT_HPP_C7116A1F_0F73_4EC2_BFE7_97F871D44F07_
