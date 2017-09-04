#include "./MouseEvent.hpp"
#include "GoLeftEvent.hpp"
#include "GoRightEvent.hpp"
#include "GoDownEvent.hpp"
#include "./HyperKeyEvent.hpp"
#include "./GoUpEvent.hpp"
#include "ReadConfig.hpp"
#include "./RightKeyEvent.hpp"
#include "LeftKeyEvent.hpp"
#include "WheelUpEvent.hpp"
#include "WheelDownEvent.hpp"
#include "SpeedUpEvent.hpp"
#include "QuitEvent.hpp"
#include "SpeedDownEvent.hpp"
#include "BrowserNextEvent.hpp"
#include "BrowserBackEvent.hpp"
#include "MiddleKeyEvent.hpp"
#include "ChangeModeEvent.hpp"
#include "BackSpaceCursorEvent.hpp"
#include "HomeCursorEvent.hpp"
#include "EnterCursorEvent.hpp"
#include "UpCursorEvent.hpp"
#include "DownCursorEvent.hpp"
#include "RightCursorEvent.hpp"
#include "LeftCursorEvent.hpp"
#include "DeleteCursorEvent.hpp"
#include "EndCursorEvent.hpp"
#include "KeyboardMode.hpp"
//#include "ReadConfig.hpp"
#include "KeyboardMap.hpp"
#include "Mode.hpp"

void checkAllEvents(string keyword,int key,string mode);

int main(int argc, char *argv[])
{
  ReadConfig *rc = new ReadConfig("./test.conf","=");
  vector<Node> vec = rc->getResult();
  //  std::cout << vec.size() << "\n";
  for (auto itr = vec.begin(); itr != vec.end(); itr++) {
    //    int key = KeyboardMap::stringToKey((*(itr)).key);

    // for (auto itr2 = (*(itr)).data.begin(); itr2 != (*(itr)).data.end(); itr2++) {

    //    std::cout << (*itr).key << "\n";
    int key = KeyboardMap::stringToKey((*itr).data.at(0));

    // string mode = (*itr).data.at(1);p
    // checkAllEvents((*(itr)).key, key,mode);
    if ((*itr).data.size() > 0) {
      try {
	string mode = (*itr).data.at(1);
	checkAllEvents((*(itr)).key, key,mode);
      } catch (std::out_of_range) {
	//	std::cout << (*itr).key << "\n";
	checkAllEvents((*(itr)).key, key,"");
      }      
    }else{}
  }

  KeyboardMode::printmodeList();
  std::cout << KeyboardMode::_getMode()->getModeKeyword() << "\n";
  KeyboardMode::_nextMode();
  std::cout << KeyboardMode::_getMode()->getModeKeyword() << "\n";
  KeyboardMode::_nextMode();
  std::cout << KeyboardMode::_getMode()->getModeKeyword() << "\n";
  return 0;
}


void checkAllEvents(string keyword,int key,string mode){
  MouseEvent *me = NULL;
  //  std::cout << HyperKeyEvent::getKeyword() << "\n";
  if (keyword == HyperKeyEvent::getKeyword()) {
    //    HyperKeyEvent *hp = new HyperKeyEvent(key);
    //    me = HyperKeyEvent::create(key);
  }else if (keyword == GoUpEvent::getKeyword()) {
    //    std::cout << GoUpEvent::getKeyword() << "\n";
    me = GoUpEvent::create(key);
  }else if(keyword == GoLeftEvent::getKeyword()){
    me = GoLeftEvent::create(key);
  }else if(keyword == GoRightEvent::getKeyword()){
    me = GoRightEvent::create(key);
  }else if (keyword == GoDownEvent::getKeyword()) {
    me = GoDownEvent::create(key);
  }else if (keyword == RightKeyEvent::getKeyword()) {
    me = RightKeyEvent::create(key);
  }else if (keyword == LeftKeyEvent::getKeyword()) {
    me = LeftKeyEvent::create(key);
  }else if (keyword == MiddleKeyEvent::getKeyword()) {
    me = MiddleKeyEvent::create(key);
  }else if (keyword == WheelUpEvent::getKeyword()) {
    me = WheelUpEvent::create(key);
  }else if(keyword == WheelDownEvent::getKeyword()){
    me = WheelDownEvent::create(key);
  }else if (keyword == QuitEvent::getKeyword()) {
    me = QuitEvent::create(key);
  }else if (keyword == SpeedUpEvent::getKeyword()) {
    me = SpeedUpEvent::create(key);
  }else if (keyword == SpeedDownEvent::getKeyword()) {
    me = SpeedDownEvent::create(key);
  }else if (keyword == BrowserBackEvent::getKeyword()) {
    me = BrowserBackEvent::create(key);
  }else if(keyword == BrowserNextEvent::getKeyword()){
    me = BrowserNextEvent::create(key);
  }else if (keyword == BackSpaceCursorEvent::getKeyword()){
    me = BackSpaceCursorEvent::create(key);
  }else if (keyword == HomeCursorEvent::getKeyword()) {
    me = HomeCursorEvent::create(key);
  }else if (keyword == EnterCursorEvent::getKeyword()) {
    me = EnterCursorEvent::create(key);
  }else if (keyword == UpCursorEvent::getKeyword()) {
    me = UpCursorEvent::create(key);
  }else if (keyword == DownCursorEvent::getKeyword()) {
    me = DownCursorEvent::create(key);
  }else if (keyword == RightCursorEvent::getKeyword()) {
    me = RightCursorEvent::create(key);
  }else if (keyword == LeftCursorEvent::getKeyword()) {
    me = LeftCursorEvent::create(key);
  }else if (keyword == DeleteCursorEvent::getKeyword()) {
    me = DeleteCursorEvent::create(key);
  }else if (keyword == EndCursorEvent::getKeyword()) {
    me = EndCursorEvent::create(key);
  }else if (keyword == "DEFAULTSPEED") {
    if (key < 0) {
      std::cout << "DEFAULTSPEEDの引数にエラーがあります" << "\n";
      key = 1;
    }
    MouseEvent::setSpeed(key);
  }else{

    std::cout << "can't find event[" << keyword << "]" << "\n";
    return;
  }
  if (me != NULL) {
    KeyboardMode::_setMouseEvent(mode, me);    
  }

  // std::cout << KeyboardMode::_getMode()->getModeKeyword() << "\n";
  // KeyboardMode::_nextMode();
  // std::cout << KeyboardMode::_getMode()->getModeKeyword() << "\n";


}
