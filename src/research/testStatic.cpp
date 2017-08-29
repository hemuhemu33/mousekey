//結果　実体を作っても静的関数を呼び出すことができる。
#include <iostream>
class A
{
public:
  static int x;
  virtual ~A(){}
  static  void create(){
    x++;

    std::cout << x<<"A is created" << "\n";
  }
  A(){
    
  }
};
int A::x = 0;


int main(int argc, char *argv[])
{
  A a;
  A *b  = new A();
  b->create();
  a.create();
  return 0;
}
