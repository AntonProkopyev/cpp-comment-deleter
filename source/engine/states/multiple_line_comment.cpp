#include "../context.h"

namespace comment_deleter {

State* MultipleLineComment::instance() {
  static MultipleLineComment state;
  return &state;
}

// virtual
void MultipleLineComment::process(Context* context) {
  auto& inputStream = context->getInputStream();
  auto& outputStream = context->getOutputStream();
  char c = ' ';
  while((c = inputStream.get()) && inputStream) {
    switch(c) {
      case '*': {
        char c2 = inputStream.get();
        if (inputStream) {
          switch(c2) {
            case '/':
              setState_(context, ProgramText::instance());
              outputStream.put(' ');
              break;
          }
          return;
        }
        break;
      }

      default:
        break;
    }
  }
  setState_(context, nullptr);
}

} // comment_deleter
