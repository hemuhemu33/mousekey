#include "Keyboard.hpp"

//vector<MouseEvent *> Keyboard::keyboardList;
vector<MouseEvent *> *Keyboard::keyboardList;
vector<EventEnum> *Keyboard::eventList;
//vector<EventEnum> *Keyboard::eventList;
vector<int> Keyboard::fds;

void Keyboard::create(int argc, char **argv){

  MouseEventList::create(argc, argv);

  keyboardList = MouseEventList::getMouseEventVector();

  eventList = SearchDevEvent::getFileEventToVector();
  // for (auto itr = eventList->begin(); itr != eventList->end(); itr++) {
  //   std::cout << (*itr).deviceevent << "\n";

  // }
  for (auto itr = eventList->begin(); itr != eventList->end(); itr++) {
    //デバイスをopenしていく
    int fd = open((*itr).deviceevent.c_str(),O_RDWR| O_NONBLOCK);
    if (fd == -1) {
      std::cout << "err: ファイルが開けません。管理者権限がないかも" << "\n";
      exit(1);
    }
    fds.push_back(fd);
  }
  // for (auto itr = fds.begin(); itr != fds.end(); itr++) {
  //   std::cout << (*itr) << "\n";
  // }
  // for (auto itr2 = keyboardList.begin(); itr2 != keyboardList.end(); itr2++) {
  //   std::cout << (*itr2)->getKey() << "\n";
  // }
}

void Keyboard::active(){
  struct input_event event;
  while (true) {
    keyboardList = MouseEventList::getMouseEventVector();
    usleep(10000);
    for (auto itr = fds.begin(); itr != fds.end(); itr++) {
      if(read((*itr),&event,sizeof(event)) != sizeof(event)){
	//	exit(EXIT_FAILURE);
      }else {

	for (auto itr2 = keyboardList->begin(); itr2 != keyboardList->end(); itr2++) {
	  //	  std::cout << "getcode is "<<event.code << "\n";	  
	  if (event.code == MouseEventList::getHyperKeyEvent()->getKey()) {

	    MouseEventList::getHyperKeyEvent()->pressed(event.value);
	  }else {
	    if (MouseEventList::getHyperKeyEvent()->getHyperKey() == true && (*itr2)->getKey() == event.code) {
	      (*itr2)->pressed(event.value);
	    }else{}
	  }
	}
	
      }
    }

  }
}
