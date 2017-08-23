#include "../HyperKeyEvent.hpp"

int main(int argc, char *argv[])
{
  MouseEvent *me = HyperKeyEvent::create(112);

  std::cout <<   me->getKey() << "\n";


  return 0;
}
