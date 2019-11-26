#include <iostream>
#include "circle_class.h"

int main(int argc, char const *argv[]) {
  // defining circles
  Circle a(2.0, 1.0, 3.0);
  Circle b(5.0, 6.0, 4.0);
  Circle c = a + b;
  Circle circle1 = a;
  Circle circle2 = a;

  // printing circles
  std::cout << "circle a: " << a << '\n';
  std::cout << "circle b: " << b << '\n';
  std::cout << "circle c: " << c << '\n';

  // comparing circles
  if (c > a) {
    std::cout << "true" << '\n';
  }
  else {
    std::cout << "false" << '\n';
  }

  // checking if circles are equal
  if ((circle1 > circle2) || (circle2 > circle1)) {
    std::cout << "circles are not equal" << '\n';
  }
  else {
    std::cout << "circles are equal" << '\n';
  }

  return 0;
}
