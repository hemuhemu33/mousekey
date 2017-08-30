/*
  get from http://www.nakatayuki.com/archives/1061180296.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

int keyboardfd;
int mousefd;
void printEvent10(input_event input);
void printEvent16(input_event input);
int main(void)
{
  mousefd = open("/dev/input/event5", O_RDWR);
  //  keyboardfd = open("/dev/input/event1", O_RDWR);
	
  for (;;) {
    struct input_event event;

    if (read(mousefd, &event, sizeof(event)) != sizeof(event)) {
      exit(EXIT_FAILURE);
    }
    printEvent16(event);
  }
  
  close(keyboardfd);
  close(mousefd);
}

void printEvent10(input_event input){
  std::cout << "time"<<" | type"<<" | code"<< " | value"<< "\n";
  printf("%lud | %d | %d | %d\n", input.time.tv_sec,input.type,input.code,input.value);
}
void printEvent16(input_event input){
  std::cout << "time"<<" | type"<<" | code"<< " | value"<< "\n";
  printf("%lx | %x | %x | %x\n", input.time.tv_sec,input.type,input.code,input.value);
}
