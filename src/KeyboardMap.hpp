#ifndef KEYBOARD_MAP_HPP_5B4F7270_39C1_4EC7_8CDD_B48DEBD0AF9F_
#define KEYBOARD_MAP_HPP_5B4F7270_39C1_4EC7_8CDD_B48DEBD0AF9F_
#include <string>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
class MapCode
{
public:
  MapCode(string str, int code){
    this->str = str;
    this->code = code;
  }
  string str;
  int code;
};



class KeyboardMap
{
public:
  static void create();
  static int stringToKey(string str);
private:
  static int isCreated;
  static vector<MapCode> vec;

};
#endif  // KEYBOARD_MAP_HPP_5B4F7270_39C1_4EC7_8CDD_B48DEBD0AF9F_
