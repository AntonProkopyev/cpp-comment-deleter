#ifndef COMMENT_DELETER_DRIVER_H
#define COMMENT_DELETER_DRIVER_H

#include <iostream>
#include <memory>

namespace comment_deleter {

class Driver {
public:
  Driver();
  Driver(int argc, char* argv[]);

  Driver(const Driver&) = delete;
  Driver& operator=(const Driver&) = delete;

  std::istream& getInputStream();
  std::ostream& getOutputStream();
private:
  std::unique_ptr<std::istream> inputStream_ = nullptr;
  std::unique_ptr<std::ostream> outputStream_ = nullptr;
};

} // comment_deleter

#endif // COMMENT_DELETER_DRIVER_H
