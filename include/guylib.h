#include <iostream>
#include <sstream>

#define OUTN(x) #x << " = " << (x)
#define OUT9(x, ...) OUTN(x) __VA_OPT__(<< "; " << OUTN(__VA_ARGS__))
#define OUT8(x, ...) OUTN(x) __VA_OPT__(<< "; " << OUT9(__VA_ARGS__))
#define OUT7(x, ...) OUTN(x) __VA_OPT__(<< "; " << OUT8(__VA_ARGS__))
#define OUT6(x, ...) OUTN(x) __VA_OPT__(<< "; " << OUT7(__VA_ARGS__))
#define OUT5(x, ...) OUTN(x) __VA_OPT__(<< "; " << OUT6(__VA_ARGS__))
#define OUT4(x, ...) OUTN(x) __VA_OPT__(<< "; " << OUT5(__VA_ARGS__))
#define OUT3(x, ...) OUTN(x) __VA_OPT__(<< "; " << OUT4(__VA_ARGS__))
#define OUT2(x, ...) OUTN(x) __VA_OPT__(<< "; " << OUT3(__VA_ARGS__))
#define OUT1(x, ...) OUTN(x) __VA_OPT__(<< "; " << OUT2(__VA_ARGS__))
#define OUT(...) OUT1(__VA_ARGS__) << std::endl

#define DEB guylib::OutputHelper().out << __FILE__ << ":" << __LINE__ << ": "

#define CHECK(x)                                                             \
  if (x) {                                                                   \
  } else                                                                     \
    for (guylib::OutputHelper output_helper;; output_helper.throw_message()) \
    output_helper.out << __FILE__ << ":" << __LINE__ << ": CHECK(" << #x << ") failed!"

namespace guylib {

class OutputHelper {
 public:
  OutputHelper();
  ~OutputHelper();

  void throw_message() const;

  std::ostringstream out;
};

//

}  // namespace guylib
