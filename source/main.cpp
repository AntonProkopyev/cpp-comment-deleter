#include <driver.h>
#include <engine.h>

#include <exception>
#include <iostream>

int main(int argc, char* argv[]) {
  using namespace comment_deleter;
  try {
    Driver driver{argc, argv};

    std::istream& inputStream = driver.getInputStream();
    std::ostream& outputStream = driver.getOutputStream();

    Engine engine{};
    engine.deleteComments(inputStream,
                          outputStream);

    return 0;
  } catch(std::exception& e) {
    std::cerr << "Unhandled exception: " << e.what() << std::endl;
    return -1;
  }
}