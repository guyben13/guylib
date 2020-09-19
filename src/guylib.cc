#include "../include/guylib.h"

#include <iomanip>
#include <string_view>

namespace guylib {

std::string OutputHelper::indentation;

OutputHelper::OutputHelper() {}

OutputHelper::~OutputHelper() {
  std::cout << indentation << "==========================\n";
  size_t location = 0;
  std::string s = out.str();
  std::string_view str(s);
  for (size_t next_loc = str.find('\n'); next_loc != std::string::npos && next_loc + 1 < str.size();
       next_loc = str.find('\n', next_loc + 1)) {
    std::cout << indentation << "  " << str.substr(location, next_loc + 1 - location);
    location = next_loc + 1;
  }
  std::cout << indentation << "  " << str.substr(location);
  if (!str.empty() && str.back() != '\n') {
    std::cout << '\n';
  }
  std::cout << indentation << "==========================\n";
  std::cout << std::flush;
}

void OutputHelper::throw_message() const { throw std::runtime_error(out.str()); }

TimerHelper::TimerHelper(std::string name) : name(std::move(name)) {
  OutputHelper().out << "TIMER " << this->name << " STARTED";
  OutputHelper::indentation.push_back(' ');
  OutputHelper::indentation.push_back(' ');
  start_time = std::chrono::high_resolution_clock::now();
}

TimerHelper::~TimerHelper() {
  double duration =
      std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start_time).count();
  OutputHelper::indentation.pop_back();
  OutputHelper::indentation.pop_back();
  OutputHelper().out << "TIMER " << name << " TOOK " << sec_to_string(duration);
}

std::string sec_to_string(double seconds) {
  std::ostringstream out;
  int iseconds = seconds;
  seconds -= iseconds;
  int hours = iseconds / 3600;
  iseconds %= 3600;
  int minutes = iseconds / 60;
  iseconds %= 60;
  int imilliseconds = seconds * 1000;
  out << hours << ':' << std::setw(2) << std::setfill('0') << minutes << ':' << std::setw(2)
      << std::setfill('0') << iseconds << '.' << std::setw(3) << std::setfill('0') << imilliseconds;
  return out.str();
}

}  // namespace guylib
