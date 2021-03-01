#include <iostream>
#include "Vector.h"
#include <algorithm>

int main() {
  Vector v;
  v.pushBack(2);
  v.pushBack(3);
  v.pushBack(0);
  std::sort(v.Begin(), v.End());
  v.print();
  int* s = std::min_element(v.Begin(), v.End());
  std::cout << *s;

  return 0;
}
