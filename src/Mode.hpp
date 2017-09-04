#ifndef MODE_HPP_399EF475_534B_495F_8455_CCDB7178FDA6_
#define MODE_HPP_399EF475_534B_495F_8455_CCDB7178FDA6_
#include <string>
using std::string;

class Mode
{
public:
  Mode(string modeKeyword,int keyboardMode);
  string getModeKeyword();
  int getKeyboardMode();
private:
  string modeKeyword;
  int keyboardMode;
};
#endif  // MODE_HPP_399EF475_534B_495F_8455_CCDB7178FDA6_
