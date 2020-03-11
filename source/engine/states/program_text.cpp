#include "../context.h"

namespace comment_deleter {

State* ProgramText::instance() {
  static ProgramText state;
  return &state;
}

// virtual
void ProgramText::process(Context* context) {
  auto& inputStream = context->getInputStream();
  auto& outputStream = context->getOutputStream();
  char c = ' ';
  while((c = inputStream.get()) && inputStream) {
    switch(c) {
      case '\"':
        setState_(context, StringLitheral::instance());
        outputStream.put(c);
        return;

      case '\'':
        setState_(context, CharLitheral::instance());
        outputStream.put(c);
        return;

      // FIXME: investigate that '\' affecting comments?
      // case '\\':

      case '/': {
        char c2 = inputStream.get();
        if (inputStream) {
          switch(c2) {
            case '/':
              setState_(context, SingleLineComment::instance());
              return;
            case '*':
              setState_(context, MultipleLineComment::instance());
              return;
            default:
              outputStream.put(c);
              outputStream.put(c2);
              break;
          }
          return;
        }
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
