#include "../Keyboard.hpp"

int main(int argc, char *argv[])
{
  Keyboard::create(argc, argv);
  Keyboard::active();
  return 0;
}
