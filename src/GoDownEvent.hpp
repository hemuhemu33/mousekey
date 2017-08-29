#ifndef GO_DOWN_EVENT_HPP_38A30DFE_DCA5_4059_813F_951DA65FADD6_
#define GO_DOWN_EVENT_HPP_38A30DFE_DCA5_4059_813F_951DA65FADD6_
#include "MouseEvent.hpp"
class GoDownEvent : public MouseEvent
{
public:
  GoDownEvent(int key);
  virtual ~GoDownEvent();
  static MouseEvent *create(int key);
  void pressed(int value);
  static string getKeyword();

private:
  static string KEYWORD;
};
#endif  // GO_DOWN_EVENT_HPP_38A30DFE_DCA5_4059_813F_951DA65FADD6_
