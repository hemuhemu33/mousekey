#include "Mode.hpp"


Mode::Mode(string modeKeyword,int keyboardMode){
  this->modeKeyword = modeKeyword;
  this->keyboardMode = keyboardMode;
}

string Mode::getModeKeyword(){
  return modeKeyword;
}

int Mode::getKeyboardMode(){
  return  keyboardMode;
}
