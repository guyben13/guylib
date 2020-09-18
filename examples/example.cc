#include <guylib.h>

#include <iostream>

int main() {
  int a = 10;
  double b = 3.14;
  DEB << OUT(a, b, a + b);
  DEB << "A line without newline";

  try {
    CHECK(a < b);
  } catch (std::exception& e) {
    DEB << OUT(e.what());
  }
  return 0;
}
