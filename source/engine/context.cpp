#include "context.h"

namespace comment_deleter {

void State::setState_(Context* context, State* state) {
  context->setState_(state);
}

Context::Context(std::istream& inputStream,
                 std::ostream& outputStream)
  : inputStream_{inputStream}
  , outputStream_{outputStream}
  , state_{ProgramText::instance()}
{}

void Context::process() {
  while (state_ != nullptr) {
    state_->process(this);
  }
}

void Context::setState_(State* state) {
  state_ = state;
}

std::istream& Context::getInputStream() {
  return inputStream_;
}

std::ostream& Context::getOutputStream() {
  return outputStream_;
}

} // comment_deleter
