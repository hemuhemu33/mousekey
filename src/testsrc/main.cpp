#include "../Keyboard.hpp"
//#include "../MouseEvent.hpp"

int main(int argc, char *argv[])
{
  //  std::cout << MouseEvent::getKeyword() << "\n";
  Keyboard::create(argc, argv);
  Keyboard::active();
  
  return 0;
}
