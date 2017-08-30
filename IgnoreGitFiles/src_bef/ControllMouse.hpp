/*
 *マウスをキーボードで自動的に操ろうとするプログラム
 *テストでは Henkan-f 右　Henkan-b 左 Henkan-p 上 Henkan-n 下　の予定
 *ゆくゆくはconfigファイルで設定できたら…
 *
 *config memo
 *BasicKey=Henkan
 *Right=f
 *Left=l
 *Up=p
 *Under=n
 *Enter=m
 *MouseSpeed=10
 *
 *
 *memo キー配置の番号を受け取るプログラムが必要かもしれない
 *keyの番号input-event-codes.h
 *
 *@author taka
 *@version 0.1
*/
#ifndef CONTROLL_MOUSE_CPP_3DA66962_1275_44D1_904E_CBDEDF8D3C31_
#define CONTROLL_MOUSE_CPP_3DA66962_1275_44D1_904E_CBDEDF8D3C31_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

#include "MouseConfig.hpp"


using namespace std;


class ControllMouse
{
public:

  //テスト用のコンストラクタ
  //@param keyboardEvent キーボードのイベントの絶対パス(例"/dev/input/event9")
  //@param virtualEvent バーチャルのイベントの絶対パス(例"/dev/uinput")
  //@param mouseEvent マウスのイベントの絶対パス(例"/dev/input/event6")
  //@param mouseSpeed マウスのスピード
  ControllMouse(string keyboardEvent,string virtualEvent = "",string mouseEvent = "",int mouseSpeed = 1);

  //実際に使うコンストラクタコンフィグファイルからキー配置を決定する
  //@param configPath コンフィグファイルの絶対パス
  ControllMouse(string configPath="");

  //全てのファイルが開いているかチェックする
  //@keyboardfd 0b001
  //@mousefd 0b010
  //@virtualfd 0b100
  //開いていたら加算する
  //@return (ex)7 全てのファイルが開いている
  int isOpen();

  //開始する関数
  void active();
  
  //ボタンが押されたかどうかを判定
  //@param ev 判定させたいボタンのイベント
  bool isPressed(input_event ev);

  //全てのファイルディスクリプタを閉じる
  void closeFd();
  
private:
  FDManage virtualfd;
  FDManage keyboardfd;
  FDManage mousefd;

  //@param code イベントに送るコード
  //@param value イベントに送る内容
  //@param type イベントに送るタイプ
  //@param fd どこに送るか指定する
  //@return true 送るのに失敗した
  //@return false 送るのに成功した
  bool writeKeyEvent(int code,int value,int type ,FDManage fdkind );

  //FDkindクラスをFDManageに変換するファイル
  //@param fk 変換したい変数
  FDManage FDkindtoFDManage(FDkind fk);

  //FDManageクラスのダミーを作るクラス
  //@param &in 作りたいダミーの変数のアドレス
  void makeDummyFDManage(FDManage &in);


  //virtualdeviceをつくる関数
  //@param fd virtualのドライバを作る関数　基本的には、virtualfdでok
  void create_uinput_device(FDManage fd);

  //どのキーボードが同時押されたかを監視する
  //@param event 監視するキーボードのイベント
  void recogKey(input_event event);
  
  //keyが押されたかどうかを保持
  bool pressHyperKey;
  bool pressF;
  bool pressB;
  bool pressP;
  bool pressN;
  bool pressM;

  //初期化処理
  void init();
  
};

#endif  // CONTROLL_MOUSE_CPP_3DA66962_1275_44D1_904E_CBDEDF8D3C31_

