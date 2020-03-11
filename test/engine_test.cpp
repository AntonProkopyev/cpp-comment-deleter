#include <engine.h>

#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <string>
#include <sstream>

SCENARIO("Text w/o comments", "[Engine]") {
  GIVEN("Engine and text w/o comments") {
    comment_deleter::Engine engine{};
    const std::string textWoComments = "abc\n"
                                       "abc abc\n"
                                       "\t\t abc\n";

    WHEN("Text w/o comments processed by engine") {
      std::istringstream inputStream{textWoComments};
      std::ostringstream outputStream{};

      engine.deleteComments(inputStream,
                            outputStream);

      THEN("Result is equal to source text") {
        const std::string result = outputStream.str();

        REQUIRE(textWoComments == result);
      }
    }
  }
}

TEST_CASE("Single line comment", "[Engine]") {
  comment_deleter::Engine engine{};

  std::vector<std::pair<std::string, std::string>> tests =
  {   // { plainText, expected }
    {"//abc\n", "\n"},
    {"// abc \n", "\n"},
    {"//\n", "\n"},
    {"//", ""},
  };

  for (auto& test : tests) {
    const std::string plainText = test.first;
    const std::string expected = test.second;

    std::istringstream inputStream{plainText};
    std::ostringstream outputStream{};

    engine.deleteComments(inputStream,
                          outputStream);

    const std::string result = outputStream.str();

    REQUIRE(expected == result);
  }
}

TEST_CASE("Multiple line comment", "[Engine]") {
  comment_deleter::Engine engine{};

  std::vector<std::pair<std::string, std::string>> tests =
  {   // { plainText, expected }
    {"/*abc*/\n", " \n"},
    {"/**/", " "},
    {"/* asbdbajfsbajdf */", " "},
    {"/*\n\n\n\n\n*/", " "},
  };

  for (auto& test : tests) {
    const std::string plainText = test.first;
    const std::string expected = test.second;

    std::istringstream inputStream{plainText};
    std::ostringstream outputStream{};

    engine.deleteComments(inputStream,
                          outputStream);

    const std::string result = outputStream.str();

    REQUIRE(expected == result);
  }
}