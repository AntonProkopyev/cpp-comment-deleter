#include "../context.h"

namespace comment_deleter {

State* CharLitheral::instance() {
  static CharLitheral state;
  return &state;
}

// virtual
void CharLitheral::process(Context* context) {
  auto& inputStream = context->getInputStream();
  auto& outputStream = context->getOutputStream();
  char c = ' ';
  while((c = inputStream.get()) && inputStream) {
    switch (c) {
      case '\'':
        outputStream.put(c);
        setState_(context, ProgramText::instance());
        return;

      case '\\':
        outputStream.put(c);
        c = inputStream.get();
        if (!inputStream) {
          break;
        }
        // else fall thru

      default:
        outputStream.put(c);
        break;
    }
  }
  setState_(context, nullptr);
}

} // comment_deleter
