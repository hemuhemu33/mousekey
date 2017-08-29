#include "../KeyboardMap.hpp"
#include <linux/input.h>
int main(int argc, char *argv[])
{
  string y = "KEY_F";
  std::cout << y << "\n";
  int x = KeyboardMap::stringToKey("KEY_U");
  std::cout << x <<" " << KEY_U << "\n";
  x = KeyboardMap::stringToKey("KEY_HENKAN");
  std::cout << x <<" "<< KEY_HENKAN << "\n";
  return 0;
}
