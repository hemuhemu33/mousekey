#include "Keyboard.hpp"

vector<MouseEvent *> *Keyboard::keyboardList;
vector<EventEnum> *Keyboard::eventList;
vector<int> Keyboard::fds;
SeveralMouseEvent *Keyboard::sme;


void Keyboard::create(int argc, char **argv){
  sme = SeveralMouseEvent::create(&fds);
  MouseEventList::create(argc, argv);
  keyboardList = MouseEventList::getMouseEventVector();

  eventList = SearchDevEvent::getFileEventToVector();
  // for (auto itr = eventList->begin(); itr != eventList->end(); itr++) {
  //   std::cout << (*itr).devicename << "\n";

  // }
  for (auto itr = eventList->begin(); itr != eventList->end(); itr++) {
    //デバイスをopenしていく
    //  std::cout << (*itr).deviceevent << "\n";
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
  auto itr = fds.begin();


  while (true) {
  BREAK:
    keyboardList = MouseEventList::getMouseEventVector();

    usleep(10000);
    for (itr = fds.begin(); itr != fds.end(); itr++) {
      if(read((*itr),&event,sizeof(event)) != sizeof(event)){
	// nonblockを指定しているため、exitをすると一瞬で終わってしまう。
	//	exit(EXIT_FAILURE);
	//	goto BREAK;
      }else {

	for (auto itr2 = keyboardList->begin(); itr2 != keyboardList->end(); itr2++) {
	  //	  std::cout << "getcode is "<<event.code << "\n";	  
	  if (event.code == MouseEventList::getHyperKeyEvent()->getKey()) {
	    //	    std::cout << "aaa" << "\n";
	    MouseEventList::getHyperKeyEvent()->pressed(event.value);
	    goto BREAK;

	  }else {
	    if (MouseEventList::getHyperKeyEvent()->getHyperKey() == true && (*itr2)->getKey() == event.code) {
	      //	      std::cout << "aaa" << "\n";
	      (*itr2)->pressed(event.value);
	      goto BREAK;
	    }else{}
	  }

	}
	
      }
    }

    //      sme->pressed(event.code, event.value);
    sme->pressed(event);
    // while ((read((*itr),&event, sizeof(struct input_event)) >= 0)) {
    //   if (event.code == EV_SYN) {
    // 	break;
    //   }else {
    // 	std::cout << event.code << "\n";
    //   }
    // }
  }
}
