#include "HyperKeyEvent.hpp"
string HyperKeyEvent::KEYWORD = "HYPERKEYEVENT";

// HyperKeyEvent::HyperKeyEvent(){
  
// }
HyperKeyEvent::HyperKeyEvent(int key) : MouseEvent(key){
  //  setKey(key);
  setKeyword(KEYWORD);
  hyperKey = false;
}
HyperKeyEvent::~HyperKeyEvent(){
  
}

bool HyperKeyEvent::getHyperKey(){
  return hyperKey;
}

void HyperKeyEvent::setHyperKey(bool isPressed){
  hyperKey = isPressed;
}

void HyperKeyEvent::pressed(int value){
  if(value > 0){
    setHyperKey(true);
  }else {
    setHyperKey(false);
  }
}

MouseEvent *HyperKeyEvent::create(int keycode){
  
  MouseEvent *ms = new HyperKeyEvent(keycode);
  //  std::cout << ms->getKey() << "\n";

  
  return ms;
}

// int main(int argc, char *argv[])
// {
//   MouseEvent *hke = HyperKeyEvent::create(123);
//   hke->getKeyword();
//   return 0;
// }

