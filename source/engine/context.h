#ifndef COMMENT_DELETER_ENGINE_CONTEXT_H_
#define COMMENT_DELETER_ENGINE_CONTEXT_H_

#include <iostream>

namespace comment_deleter {

class State;

class Context {
public:
  Context(std::istream& inputStream,
          std::ostream& outputStream);

  Context(const Context&) = delete;
  Context& operator=(const Context&) = delete;

  void process();

  std::istream& getInputStream();
  std::ostream& getOutputStream();

private:
  friend class State;
  void setState_(State*);

private:
  std::istream& inputStream_;
  std::ostream& outputStream_;

  State* state_;
};

class State {
public:
  virtual void process(Context*) = 0;

protected:
  void setState_(Context* context, State* state);
};

class ProgramText : public State {
public:
  static State* instance();
  virtual void process(Context*);
};

class MultipleLineComment : public State {
public:
  static State* instance();
  virtual void process(Context*);
};

class SingleLineComment : public State {
public:
  static State* instance();
  virtual void process(Context*);
};

class StringLitheral : public State {
public:
  static State* instance();
  virtual void process(Context*);
};

class CharLitheral : public State {
public:
  static State* instance();
  virtual void process(Context*);
};

} // comment_deleter

#endif // COMMENT_DELETER_ENGINE_CONTEXT_H_
