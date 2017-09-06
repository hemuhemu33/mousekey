#include "SearchDevEvent.hpp"
#include <sstream>
#include <vector>

string SearchDevEvent::devicesFile = "/proc/bus/input/devices";
string SearchDevEvent::handlerName = "sysrq kbd";
vector<EventEnum> *SearchDevEvent::eventList = new vector<EventEnum>();
ifstream SearchDevEvent::readfile;

vector<EventEnum> *SearchDevEvent::getFileEventToVector(){
  string readline;
  string nameline;
  readfile.open(devicesFile.c_str(), std::ios::in);
  if (readfile.fail()) {
    std::cout << "cant open this file" << "\n";
    return eventList;
  }

  while (!readfile.eof()) {

    getline(readfile,readline);
    if (strncmp(readline.c_str(),"N:",2) == 0) {
      nameline = readline;
    }
    if (strncmp(readline.c_str(),"H:",2) == 0) {
      string eventNum;
      eventNum = keyBoardEventString(readline);
      //      std::cout << readline << "\n";
      if (eventNum.size() == 0 || (nameline.find("MOUSE_VIRTUAL_DEVICE") != std::string::npos)) {
	
      }else{
	EventEnum ee;
	//	std::cout << "eventNum:"<<eventNum << "\n";
	ee.devicename = nameline;
	ee.deviceevent = "/dev/input/"+eventNum;
	eventList->push_back(ee);
      }
    }
  }
  readfile.close();

  return eventList;
}


vector<string> SearchDevEvent::split(const string &str,char sep){
  vector<string> v;
  stringstream ss;
  string ret;
  ss << str;

  while (getline(ss,ret,sep)) {
    v.push_back(ret);
  }
  return v;
}

string SearchDevEvent::keyBoardEventString(string eventline){
  //  string testcase = "Handlers=sysrq kbd event3 leds";
  vector<string> v;
  string ret;
  v = split(eventline,'=');
  v = split(v.at(1),' ');
  if (v.size() >=2) {
    if (v.at(0) == "sysrq" && v.at(1) == "kbd") {
      for (int i = 2; i < v.size(); i++) {
	if (v.at(i).find("event") != std::string::npos) {

	  return v.at(i);	  
	}
      }

    }
  }

  return "";
  
}

void SearchDevEvent::printEventsPath(){
  if (eventList->size() == 0) {
    std::cout << "no event file" << "\n";
  }else {
    for (auto itr = eventList->begin(); itr != eventList->end(); itr++) {
      std::cout << (*itr).devicename << "\n";
      std::cout << "E: NUM=\""<<(*itr).deviceevent<< "\""<<"\n";
      
      std::cout << "---" << "\n";
    }
  }
  
    
}
