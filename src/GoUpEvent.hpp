#include "MouseEvent.hpp"

class GoUpEvent : public MouseEvent
{
public:
  GoUpEvent(int key);
  static MouseEvent *create(int key);

  void pressed(int value);
  virtual ~GoUpEvent();
  static string KEYWORD;
};
