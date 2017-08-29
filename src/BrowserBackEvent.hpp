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
