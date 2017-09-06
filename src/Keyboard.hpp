#ifndef KEYBOARD_HPP_43DF8AE8_9CD3_42FE_95CE_D89AB5A95BDF_
#define KEYBOARD_HPP_43DF8AE8_9CD3_42FE_95CE_D89AB5A95BDF_
#include "MouseEventList.hpp"
#include "SearchDevEvent.hpp"
#include <vector>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./SeveralMouseEvent.hpp"

class Keyboard
{
public:

  static void create(int argc ,char **argv);
  static void active();
private:
  static vector<MouseEvent *> *keyboardList;
  static vector<EventEnum> *eventList;
  static vector<int> fds;
  static SeveralMouseEvent *sme;

};
#endif  // KEYBOARD_HPP_43DF8AE8_9CD3_42FE_95CE_D89AB5A95BDF_
