#include "MouseEventList.hpp"
#include "MiddleKeyEvent.hpp"

bool MouseEventList::isCreated;
vector<MouseEvent *> MouseEventList::keyboardList;
string MouseEventList::filepath = "./test.conf";
HyperKeyEvent *MouseEventList::hp;



void MouseEventList::create(int argc, char **argv){
  int opt;
  KeyboardMap::create();
  Uinput::create();
  
  //引数が増えたらここに追加する。
  while ((opt = getopt(argc,argv,"c")!=-1)) {
    switch (opt) {
    case 'c': {
      if (optarg == NULL) {
	std::cout << "-cの後の引数が不正です。" << "\n";
      }else {
	filepath = optarg;
      }
      break;
    }
default:
      break;
    }
  }
  parseConfig(filepath);
  if (MouseEventList::getHyperKeyEvent() ==NULL) {
    std::cout << "error:hyperKeyがセットされていません" << "\n";
    exit(0);
  }
}

void MouseEventList::parseConfig(string filepath){
  ReadConfig *rc = new ReadConfig(filepath,"=");
  vector<Node> vec = rc->getResult();
  for (auto itr = vec.begin(); itr != vec.end(); itr++) {
    //    int key = KeyboardMap::stringToKey((*(itr)).key);
    
    for (auto itr2 = (*(itr)).data.begin(); itr2 != (*(itr)).data.end(); itr2++) {
      int key = KeyboardMap::stringToKey((*(itr2)));
      checkAllEvents((*(itr)).key, key);
    }
  }
  //  std::cout << vec.size() << "\n";
  // for (auto itr = vec.begin(); itr != vec.end(); itr++) {
  //   std::cout << "key :" << (*(itr)).key << "\n";
  //   for (auto itr2 = (*(itr)).data.begin(); itr2 != (*(itr)).data.end(); itr2++) {
  //     std::cout << (*(itr2)) << "\n";
  //   }
    
  // }
}



void MouseEventList::checkAllEvents(string keyword,int key){
  MouseEvent *me;
  //  std::cout << HyperKeyEvent::getKeyword() << "\n";
  if (keyword == HyperKeyEvent::getKeyword()) {
    hp = new HyperKeyEvent(key);
    //    me = HyperKeyEvent::create(key);
    return;
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
  }else{
    std::cout << "can't find event[" << keyword << "]" << "\n";
    return;
  }
  
  keyboardList.push_back(me);
}


HyperKeyEvent *MouseEventList::getHyperKeyEvent(){
  return hp;
}

vector<MouseEvent *> MouseEventList::getMouseEventVector(){
  return keyboardList;
}
