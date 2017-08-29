#ifndef MIDDLE_KEY_EVENT_HPP_C5E07737_767F_4D1E_AE81_B3DC3CE7DA7D_
#define MIDDLE_KEY_EVENT_HPP_C5E07737_767F_4D1E_AE81_B3DC3CE7DA7D_
#include "MouseEvent.hpp"

class MiddleKeyEvent : public MouseEvent
{

public:
  MiddleKeyEvent(int key);
  virtual ~MiddleKeyEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();
private:
  static string KEYWORD;
};
#endif  // MIDDLE_KEY_EVENT_HPP_C5E07737_767F_4D1E_AE81_B3DC3CE7DA7D_
