#include <driver.h>

namespace comment_deleter {

Driver::Driver() {}

// FIXME : Implement command line args processing
Driver::Driver(int argc, char* argv[]) {}

std::istream& Driver::getInputStream() {
  if (inputStream_) {
    return *inputStream_;
  }

  return std::cin;
}

std::ostream& Driver::getOutputStream() {
  if (outputStream_) {
    return *outputStream_;
  }

  return std::cout;
}

} // comment_deleter
