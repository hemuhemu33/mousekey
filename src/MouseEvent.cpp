#include "MouseEvent.hpp"
#include <cstdlib>

string MouseEvent::KEYWORD = "";
int MouseEvent::speed = 1;
int MouseEvent::incrementSpeed = 10;
int MouseEvent::declementSpeed = 10;
MODE MouseEvent::mode = MOUSEMODE;


int MouseEvent::getIncrementSpeed(){
  return incrementSpeed;
}
int MouseEvent::getDecrementSpeed(){
  return declementSpeed;
}

void  MouseEvent::setDecrementSpeed(int speed){
  declementSpeed = speed;
}
void MouseEvent::setIncrementSpeed(int speed){
  incrementSpeed = speed;
}

MouseEvent::MouseEvent(){
  // speed = (int*)malloc(sizeof(int));
  // *(speed) = 1;
}
//abstructにコンストラクタは作れない
MouseEvent::MouseEvent(int key){
  this->key = key;
}

void MouseEvent::setSpeed(int speed){
  MouseEvent::speed = speed;
}

int MouseEvent::getSpeed(){
  return MouseEvent::speed;
}
int MouseEvent::getKey(){
  return key;
}
void MouseEvent::setKey(int key){
  this->key = key;
}
void MouseEvent::setKeyword(string KEYWORD){
  this->KEYWORD = KEYWORD;
}
string MouseEvent::getKeyword(){
  return KEYWORD;
}

bool MouseEvent::writeKeyEvent(int code,int value,int type, FDManage fdkind ){
  struct input_event keyEvent;
  gettimeofday(&keyEvent.time,NULL);
  keyEvent.type = type;
  keyEvent.code = code;
  keyEvent.value = value;
  if (write(fdkind.fd, &keyEvent, sizeof(keyEvent)) < 0) {
    return false;
  }
  return true;
}
MODE MouseEvent::getMode(){
  return mode;
  
}
void MouseEvent::setMode(MODE m){
  mode = m;
}

  //abstruct はやはりnewできない。
  //*MouseEvent::create(){
  //   //  return new MouseEvent();
  // }



