#include "../include/guylib.h"

namespace guylib {

OutputHelper::OutputHelper() {}

OutputHelper::~OutputHelper() {
  std::cout << out.str();
  if (!out.str().empty() && out.str().back() != '\n') {
    std::cout << '\n';
  }
  std::cout << std::flush;
}

void OutputHelper::throw_message() const { throw std::runtime_error(out.str()); }

}  // namespace guylib
