#include "ReadConfig.hpp"

ReadConfig::ReadConfig(string fileName){
  if (  addConfigFile(fileName)!= true) {
  }
}

ReadConfig::ReadConfig(string fileName,string separate){
  if (  addConfigFile(fileName,separate)!= true) {
  }
}

bool ReadConfig::addConfigFile(string fileName,string separate){
  ifstream readConf;
  string readline;
  bool leftIsSet = false;
  readConf.open(fileName.c_str());
  if (readConf.fail() == true) {
    std::cout << "no such file" << "\n";
    return false;
  }
  while (!readConf.eof()) {
    getline(readConf,readline);
    char *ptr = (char *)readline.c_str();

    //    std::cout << readline << "\n";
    Node node;
    leftIsSet = false;
    while (true) {
      jumpToNext(" \t", &ptr, true);
      if (*(ptr+1) == '\0') {

	if (leftIsSet == true) {
	  
	  result.push_back(node);
	}else {

	}
	break;
      }else {
	string ret = jumpToNext(" \n\t",&ptr,false);
	if (leftIsSet ==false) {

	  jumpToNext(separate, &ptr, false);
	  ptr = ptr+1;
	  node.key = ret;
	  leftIsSet = true;
	}else {
	  node.data.push_back(ret);
	}
      }      
    }

    
  }
  return true;
}

vector<Node> ReadConfig::getResult(){
  return result;
}

string ReadConfig::jumpToNext(string jumpWord,char **getline,bool mode){
  string ret;
  int i ;
  char *readline = *getline;
  //  int size = sizeof(*getline)/(sizeof(*getline[0]));
  int size = strlen(*getline);
  for (i = 0; i < size; i++) {
    char target = *(readline+i);
    
    if (mode == true) {
      if (isInclude(jumpWord,target) == false) {
	readline = readline+i;
	*getline = readline;
	//	std::cout << readline << "\n";
	return ret;
      }
    }else if(mode == false){
      if (isInclude(jumpWord,target) == true) {
	readline = readline+i;
	*getline = readline;
	//	std::cout << readline << "\n";
	return ret;
      }
    }else{}
    ret+=target;
  }
  readline = readline+i;
  *getline = readline-1;
  return ret;
}



bool ReadConfig::isInclude(string jumpWord,char ch){
  for (int i = 0; i < (int)jumpWord.size(); i++) {
    if (jumpWord[i] == ch) {
      return true;
    }
  }
  return false;
}
/*
 string ReadConfig::jumpToNext(string jumpWord,char *readline,bool mode){
  string ret;
  for (int i = 0; i < strlen(readline); i++) {
    char target = *(readline+i);
    
    if (mode == true) {
      if (isInclude(jumpWord,target) == false) {
	readline = readline+i;
	std::cout << readline << "\n";
	return ret;
      }
    }else if(mode == false){
      if (isInclude(jumpWord,target) == true) {
	readline = readline+i;
	std::cout << readline << "\n";
	return ret;
      }
    }else{}
    ret+=target;
  }

  return NULL;
}

bool ReadConfig::isInclude(string jumpWord,char ch){
  for (int i = 0; i < jumpWord.size(); i++) {
    if (jumpWord[i] == ch) {
      return true;
    }
  }
  return false;
}
*/
