#include <guylib.h>

#include <thread>

int main() {
  TIMER(main);
  int a = 10;
  double b = 3.14;
  DEB << OUT(a, b, a + b);
  DEB << "A line without newline";

  {
    TIMER(sleep);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  try {
    TIMER(try);
    CHECK(a < b);
  } catch (std::exception& e) {
    DEB << OUT(e.what());
  }
  return 0;
}
