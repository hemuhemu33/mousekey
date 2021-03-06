#ifndef READ_CONFIG_HPP_D4C58CEC_3226_4FAF_ADA3_16BD2F032C95_
#define READ_CONFIG_HPP_D4C58CEC_3226_4FAF_ADA3_16BD2F032C95_
#include "Node.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

class ReadConfig
{
private:
  vector<Node> result;
  
  //jumpWordがchを含んでいるか確認
  //@param jumpWord 検索対象
  //@param ch 文字列
  //@return true jumpWordの中にchを含んでいる
  //@return false umpWordの中にchを含んでいない
  bool isInclude(string jumpWord,char ch);

  //readlineを探索する。jumpWordで指定された文字列を読み飛ばしたり、読み飛ばさなかったり
  //@param jumpWord 読み飛ばしたり読み飛ばさなかったりするワードを設定。
  //@param readline 検索対象「　　A」ならAの直前の空白を返す。
  //@param mode true jumpWordで指定された文字が出てこなくなるまでreadlineを読み飛ばす
  //@param mode false　jumpWordで指定された文字が出てくるまでreadlineを読み飛ばす
  //@return 読み飛ばされた文字列
  string jumpToNext(string jumpWord,char **readline,bool mode);

public:
  //コンストラクタ区切りは「=」となっている。
  //@param fileName コンフィグファイルを指定
  ReadConfig(string fileName);

  //コンストラクタ区切りはseparateにて指定
  //空白とタブは使えないと思われ
  //@param fileName コンフィグファイルを指定
  //@param separate 区切る文字を指定複数でもいい
  ReadConfig(string fileName,string separate);

  //コンストラクタ区切りはseparateにて指定
  //@param fileName コンフィグファイルを指定
  //@param separate 区切る文字を指定複数でもいい
  bool addConfigFile(string fileName,string separate = "=");

  
  vector<Node> getResult();

};
#endif  // READ_CONFIG_HPP_D4C58CEC_3226_4FAF_ADA3_16BD2F032C95_
