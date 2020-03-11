#ifndef COMMENT_DELETER_ENGINE_H
#define COMMENT_DELETER_ENGINE_H

#include <iostream>

namespace comment_deleter {

class Engine {
public:
  void deleteComments(std::istream& input = std::cin,
                      std::ostream& output = std::cout);
};

} // comment_deleter

#endif // COMMENT_DELETER_ENGINE_H
