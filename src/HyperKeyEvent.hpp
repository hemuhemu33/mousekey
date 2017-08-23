#ifndef HYPER_KEY_EVENT_HPP_6BD70F53_450E_4B75_97BF_35B527D7365A_
#define HYPER_KEY_EVENT_HPP_6BD70F53_450E_4B75_97BF_35B527D7365A_
#include "MouseEvent.hpp"

class HyperKeyEvent : public MouseEvent
{
public:
  //  HyperKeyEvent();
  virtual ~HyperKeyEvent();
  HyperKeyEvent(int key);
  bool getHyperKey();
  void setHyperKey(bool isPressed);
  static MouseEvent *create(int keycode);
  void pressed(int value);
private:
  bool hyperKey;
  static string KEYWORD;
};

#endif  // HYPER_KEY_EVENT_HPP_6BD70F53_450E_4B75_97BF_35B527D7365A_


  

