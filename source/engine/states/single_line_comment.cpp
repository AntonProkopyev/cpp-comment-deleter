#include "../context.h"

namespace comment_deleter {

State* SingleLineComment::instance() {
  static SingleLineComment state;
  return &state;
}

// virtual
void SingleLineComment::process(Context* context) {
  auto& inputStream = context->getInputStream();
  auto& outputStream = context->getOutputStream();
  char c = ' ';
  while((c = inputStream.get()) && inputStream) {
    switch(c) {
      // FIXME: investigate that '\' affecting comments?
      // case '\\':

      case '\n':
        setState_(context, ProgramText::instance());
        outputStream.put(c);
        return;

      default:
        break;
    }
  }
  setState_(context, nullptr);
}

} // comment_deleter
