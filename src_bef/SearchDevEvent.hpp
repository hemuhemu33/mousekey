#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

#include "EventEnum.hpp"


using namespace std;
#ifndef SEARCH_DEV_EVENT_HPP_307DBC7D_2568_4DD1_9AD4_19203E418E13_
#define SEARCH_DEV_EVENT_HPP_307DBC7D_2568_4DD1_9AD4_19203E418E13_



class SearchDevEvent
{
private:
  static string handlerName;
  static string devicesFile;
  static vector<EventEnum> *eventList;
  static ifstream readfile;
  static vector<string> split(const string &str,char sep);

public:
  /*
    デバイスファイルを読み込んでキーボードのイベントのみをベクターに追加して返す。
    @return キーボードのイベント一覧
   */
  static vector<EventEnum> *getFileEventToVector();
  
  
  /*
    getFIleEventToVectorで取得したイベント一覧をプリントする。
   */
  static void printEventsPath();
  
  /*
    lineの中から"sysrq kbd"の文字列があるかどうか探索する。
    @param eventline devicesファイルの中の"H: ..."の文字列
    @return "sysrq kbd"の文字列があれば"event?"を、なければ""を返す。
   */
  static string keyBoardEventString(string eventline);
};


#endif  // SEARCH_DEV_EVENT_HPP_307DBC7D_2568_4DD1_9AD4_19203E418E13_
