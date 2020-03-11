#include <engine.h>

#include <algorithm>
#include <iterator>

#include "context.h"

namespace comment_deleter {

void Engine::deleteComments(std::istream& input,
                            std::ostream& output) {
  static_assert(std::is_same<std::istream::char_type,
                             std::ostream::char_type>::value,
                "Input char type must be equal to output char type");

  using char_type = std::istream::char_type;

  Context context{input, output};

  context.process();
}

} // comment_deleter
