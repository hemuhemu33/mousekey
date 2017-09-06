#include "MouseEventList.hpp"

bool MouseEventList::isCreated;
//vector<MouseEvent *> MouseEventList::keyboardListMode1;
//vector<MouseEvent *> MouseEventList::keyboardListMode2;

//vector<vector<MouseEvent*>> MouseEventList::mode;
string MouseEventList::filepath = "./test.conf";
HyperKeyEvent *MouseEventList::hp;



void MouseEventList::create(int argc, char *argv[]){
  int opt = 0;
  KeyboardMap::create();
  Uinput::create();
  
  //引数が増えたらここに追加する。
  while ((opt = getopt(argc,argv,"hc:"))!=-1) {
    switch (opt) {
    case 'c': {
      if (optarg == NULL) {
	std::cout << "-cの後の引数が不正です。" << "\n";
      }else {

	filepath = optarg;
      }
      break;
    }case 'h': {
       std::cout << "-h: ヘルプ" << "\n";
       std::cout << "-c ファイル名: コンフィグファイルを指定" << "\n";
       exit(0);
       break;
     }
default:
      break;
    }
  }
  parseConfig(filepath);
  if (MouseEventList::getHyperKeyEvent() ==NULL) {
    std::cout << "error:hyperKeyがセットされていません" << "\n";
    exit(1);
  }
}

void MouseEventList::parseConfig(string filepath){
  ReadConfig *rc = new ReadConfig(filepath,"=");
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
      } catch (...) {
	//	std::cout << (*itr).key << "\n";
	checkAllEvents((*(itr)).key, key,"");
      }      
    }else{}
  }
  //  mode.push_back(keyboardListMode1);
  //  mode.push_back(keyboardListMode2);
  
}



void MouseEventList::checkAllEvents(string keyword,int key,string mode){
  MouseEvent *me = NULL;
  //  std::cout << HyperKeyEvent::getKeyword() << "\n";
  if (keyword == HyperKeyEvent::getKeyword()) {
    hp = new HyperKeyEvent(key);
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
  }else if (keyword == ChangeModeEvent::getKeyword()) {
    me = ChangeModeEvent::create(key);
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

  
  // if (mode == "MODE1" || mode == "mode1") {
  //   keyboardListMode1.push_back(me);    
  // }else if(mode == "MODE2" || mode == "mode2"){
  //   keyboardListMode2.push_back(me);
  // }

}


HyperKeyEvent *MouseEventList::getHyperKeyEvent(){
  return hp;
}

vector<MouseEvent *> *MouseEventList::getMouseEventVector(){
  //  std::cout << MouseEvent::getMode() << "\n";
  //  return mode.at(MouseEvent::getMode());
  return KeyboardMode::_getMouseEventVector();
}
