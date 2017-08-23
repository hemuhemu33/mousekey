class A
{
public:
  static int x;
  virtual ~A();
  A();
};

class B:public A
{
public:
  B(){

  }
  virtual ~B();
};
