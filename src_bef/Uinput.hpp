#ifndef UINPUT_HPP_EB745667_4D68_48AB_9CE6_F432E2B93C1A_
#define UINPUT_HPP_EB745667_4D68_48AB_9CE6_F432E2B93C1A_

#include "MouseConfig.hpp"
#include <iostream>

using std::string;
using std::vector;
class Uinput
{
public:
  /*
    uinputを作るプログラム
    @return -2 ioctlの失敗
    @return -1 uinputを開くことの失敗
    @return 1  成功
   */
  static int create(string devicepath="/dev/uinput");
  
  /*
    return fd uinputの値を返す。
   */
  static int getfd();
private:
  static vector<int> result;
  static void createDevice(FDManage fd);
  static FDManage virtualfd;
  /*
    ioctlをする。結果をvectorのresultに代入する
   */
  static void registIoctl();


};
#endif  // UINPUT_HPP_EB745667_4D68_48AB_9CE6_F432E2B93C1A_
