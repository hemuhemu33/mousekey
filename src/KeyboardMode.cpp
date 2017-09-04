#include "KeyboardMode.hpp"
vector<vector<MouseEvent *> > KeyboardMode::_keyboard;
Mode *KeyboardMode::_mode = NULL;
vector<Mode> KeyboardMode::_modeList;

void KeyboardMode::_create(){
  
}
vector<MouseEvent *> *KeyboardMode::_getMouseEventVector(){
  return &(_keyboard.at(_getMode()->getKeyboardMode()));
}


void KeyboardMode::_setMouseEvent(string mode,MouseEvent *event){
  MouseEvent *ev = event;
  //  std::cout << event->getKeyword() << "\n";
  //途中
  //  std::cout << "aaa" << "\n";
  for (auto itr = _modeList.begin(); itr != _modeList.end(); (itr++)) {
    if ((*itr).getModeKeyword() == mode) {
      //      printmodeList();
      _keyboard.at((*itr).getKeyboardMode()).push_back(ev);
      return;
    }else{}
  }

  Mode thismode(mode,_modeList.size());
  _modeList.push_back(thismode);
  vector<MouseEvent *>vec;
  vec.push_back(ev);
  _keyboard.push_back(vec);

  //  printmodeList();
}

bool KeyboardMode::_setMode(int mode){
  for (auto itr = _modeList.begin(); itr != _modeList.end(); itr++) {
    if ((*itr).getKeyboardMode() == mode) {
      _mode = &(*itr);
      return true;
    }
  }
  std::cerr << "can't find mode" << "\n";
  return false;
}

void KeyboardMode::_nextMode(){
  if (_setMode(_getMode()->getKeyboardMode()+1) == false) {
    _setMode(0);
  }else {}
}

Mode *KeyboardMode::_getMode(){
  if (_mode == NULL) {
    _mode = &_modeList.at(0);
  }
  //  std::cout << _mode->getKeyboardMode() << "\n";
  return _mode;
}

// void KeyboardMode::printmodeList(){
//   for (auto itr = _modeList.begin(); itr != _modeList.end(); itr++) {
//     std::cout << "mode" << (*itr).getKeyboardMode() << " " << (*itr).getModeKeyword() << "\n";
//     for (auto itr2 = _keyboard.at((*itr).getKeyboardMode()).begin(); itr2 != _keyboard.at((*itr).getKeyboardMode()).end(); itr2++) {
//       std::cout << (*itr2)->getKeyword() << "\n";
//     }
//   }
  
  
// }
