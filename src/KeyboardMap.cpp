#include "KeyboardMap.hpp"

int KeyboardMap::isCreated = false;
vector<MapCode> KeyboardMap::vec;

void KeyboardMap::create(){
  vec.push_back(MapCode( "KEY_RESERVED" ,0));
  
  vec.push_back(MapCode( "KEY_ESC", 1));
  vec.push_back(MapCode( "KEY_1",2));
  vec.push_back(MapCode( "KEY_2",3));
  vec.push_back(MapCode( "KEY_3",4));
  vec.push_back(MapCode( "KEY_4",5));
  vec.push_back(MapCode( "KEY_5",6));
  vec.push_back(MapCode( "KEY_6",7));
  vec.push_back(MapCode( "KEY_7",8));
  vec.push_back(MapCode( "KEY_8",9));
  vec.push_back(MapCode( "KEY_9",10));
  vec.push_back(MapCode( "KEY_0",11));
  vec.push_back(MapCode( "KEY_MINUS",12));
  vec.push_back(MapCode( "KEY_EQUAL",13));
  vec.push_back(MapCode( "KEY_BACKSPACE",14));
  vec.push_back(MapCode( "KEY_TAB",15));
  vec.push_back(MapCode( "KEY_Q",16));
  vec.push_back(MapCode( "KEY_W",17));
  vec.push_back(MapCode( "KEY_E",18));
  vec.push_back(MapCode( "KEY_R",19));
  vec.push_back(MapCode( "KEY_T",20));
  vec.push_back(MapCode( "KEY_Y",21));
  vec.push_back(MapCode( "KEY_U",22));
  vec.push_back(MapCode( "KEY_I",23));
  vec.push_back(MapCode( "KEY_O",24));
  vec.push_back(MapCode( "KEY_P",25));
  vec.push_back(MapCode( "KEY_LEFTBRACE",26));
  vec.push_back(MapCode( "KEY_RIGHTBRACE",27));
  vec.push_back(MapCode( "KEY_ENTER",28));
  vec.push_back(MapCode( "KEY_LEFTCTRL",29));
  vec.push_back(MapCode( "KEY_A",30));
  vec.push_back(MapCode( "KEY_S",31));
  vec.push_back(MapCode( "KEY_D",32));
  vec.push_back(MapCode( "KEY_F",33));
  vec.push_back(MapCode( "KEY_G",34));
  vec.push_back(MapCode( "KEY_H",35));
  vec.push_back(MapCode( "KEY_J",36));
  vec.push_back(MapCode( "KEY_K",37));
  vec.push_back(MapCode( "KEY_L",38));
  vec.push_back(MapCode( "KEY_SEMICOLON",39));
  vec.push_back(MapCode( "KEY_APOSTROPHE",40));
  vec.push_back(MapCode( "KEY_GRAVE",41));
  vec.push_back(MapCode( "KEY_LEFTSHIFT",42));
  vec.push_back(MapCode( "KEY_BACKSLASH",43));
  vec.push_back(MapCode( "KEY_Z",44));
  vec.push_back(MapCode( "KEY_X",45));
  vec.push_back(MapCode( "KEY_C",46));
  vec.push_back(MapCode( "KEY_V",47));
  vec.push_back(MapCode( "KEY_B",48));
  vec.push_back(MapCode( "KEY_N",49));
  vec.push_back(MapCode( "KEY_M",50));
  vec.push_back(MapCode( "KEY_COMMA",51));
  vec.push_back(MapCode( "KEY_DOT",52));
  vec.push_back(MapCode( "KEY_SLASH",53));
  vec.push_back(MapCode( "KEY_RIGHTSHIFT",54));
  vec.push_back(MapCode( "KEY_KPASTERISK",55));
  vec.push_back(MapCode( "KEY_LEFTALT",56));
  vec.push_back(MapCode( "KEY_SPACE",57));
  vec.push_back(MapCode( "KEY_CAPSLOCK",58));
  vec.push_back(MapCode( "KEY_F1",59));
  vec.push_back(MapCode( "KEY_F2",60));
  vec.push_back(MapCode( "KEY_F3",61));
  vec.push_back(MapCode( "KEY_F4",62));
  vec.push_back(MapCode( "KEY_F5",63));
  vec.push_back(MapCode( "KEY_F6",64));
  vec.push_back(MapCode( "KEY_F7",65));
  vec.push_back(MapCode( "KEY_F8",66));
  vec.push_back(MapCode( "KEY_F9",67));
  vec.push_back(MapCode( "KEY_F10",68));
  vec.push_back(MapCode( "KEY_NUMLOCK",69));
  vec.push_back(MapCode( "KEY_SCROLLLOCK",70));
  vec.push_back(MapCode( "KEY_KP7",71));
  vec.push_back(MapCode( "KEY_KP8",72));
  vec.push_back(MapCode( "KEY_KP9",73));
  vec.push_back(MapCode( "KEY_KPMINUS",74));
  vec.push_back(MapCode( "KEY_KP4",75));
  vec.push_back(MapCode( "KEY_KP5",76));
  vec.push_back(MapCode( "KEY_KP6",77));
  vec.push_back(MapCode( "KEY_KPPLUS",78));
  vec.push_back(MapCode( "KEY_KP1",79));
  vec.push_back(MapCode( "KEY_KP2",80));
  vec.push_back(MapCode( "KEY_KP3",81));
  vec.push_back(MapCode( "KEY_KP0",82));
  vec.push_back(MapCode( "KEY_KPDOT",83));

  vec.push_back(MapCode( "KEY_ZENKAKUHANKAKU",85));
  vec.push_back(MapCode( "KEY_102ND",86));
  vec.push_back(MapCode( "KEY_F11",87));
  vec.push_back(MapCode( "KEY_F12",88));
  vec.push_back(MapCode( "KEY_RO",89));
  vec.push_back(MapCode( "KEY_KATAKANA",90));
  vec.push_back(MapCode( "KEY_HIRAGANA",91));
  vec.push_back(MapCode( "KEY_HENKAN",92));
  vec.push_back(MapCode( "KEY_KATAKANAHIRAGANA",93));
  vec.push_back(MapCode( "KEY_MUHENKAN",94));
  vec.push_back(MapCode( "KEY_KPJPCOMMA",95));
  vec.push_back(MapCode( "KEY_KPENTER",96));
  vec.push_back(MapCode( "KEY_RIGHTCTRL",97));
  vec.push_back(MapCode( "KEY_KPSLASH",98));
  vec.push_back(MapCode( "KEY_SYSRQ",99));
  vec.push_back(MapCode( "KEY_RIGHTALT",100));
  vec.push_back(MapCode( "KEY_LINEFEED",101));
  vec.push_back(MapCode( "KEY_HOME",102));
  vec.push_back(MapCode( "KEY_UP",103));
  vec.push_back(MapCode( "KEY_PAGEUP",104));
  vec.push_back(MapCode( "KEY_LEFT",105));
  vec.push_back(MapCode( "KEY_RIGHT",106));
  vec.push_back(MapCode( "KEY_END",107));
  vec.push_back(MapCode( "KEY_DOWN",108));
  vec.push_back(MapCode( "KEY_PAGEDOWN",109));
  vec.push_back(MapCode( "KEY_INSERT",110));
  vec.push_back(MapCode( "KEY_DELETE",111));
  vec.push_back(MapCode( "KEY_MACRO",112));
  vec.push_back(MapCode( "KEY_MUTE",113));
  vec.push_back(MapCode( "KEY_VOLUMEDOWN",114));
  vec.push_back(MapCode( "KEY_VOLUMEUP",115));
  vec.push_back(MapCode( "KEY_POWER",116));/* SC System Power Down */
  vec.push_back(MapCode( "KEY_KPEQUAL",117));
  vec.push_back(MapCode( "KEY_KPPLUSMINUS",118));
  vec.push_back(MapCode( "KEY_PAUSE",119));
  vec.push_back(MapCode( "KEY_SCALE",120));/* AL Compiz Scale (Expose) */
  
}

int KeyboardMap::stringToKey(string str){
  
  if (isCreated == false) {
    //createが一度も呼び出されていないなら、呼び出す。
    //    std::cout << "aaa" << "\n";
    create();
    isCreated = true;
  }else{}
  for (auto itr = vec.begin(); itr != vec.end(); itr++) {
    // std::cout << str << ":" << (*(itr)).str << "\n";
    if ((*(itr)).str == str) {
      return (*(itr)).code;
    }else{}
  }
  std::cerr << "err:in KeyBoardMap.cpp can't find code" << "\n";
  return -1;
}
