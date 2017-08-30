#ifndef CHANGE_MODE_EVENT_HPP_5F76A8BB_361D_4BCF_BDF0_C7A272CF4BA4_
#define CHANGE_MODE_EVENT_HPP_5F76A8BB_361D_4BCF_BDF0_C7A272CF4BA4_
#include "MouseEvent.hpp"
class ChangeModeEvent : public MouseEvent
{
public:
  ChangeModeEvent(int key);
  virtual ~ChangeModeEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};
#endif  // CHANGE_MODE_EVENT_HPP_5F76A8BB_361D_4BCF_BDF0_C7A272CF4BA4_
