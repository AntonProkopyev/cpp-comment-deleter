#include <driver.h>

#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

TEST_CASE("Default init", "[Driver]") {
  comment_deleter::Driver driver{};

  REQUIRE(&driver.getInputStream() == &std::cin);
  REQUIRE(&driver.getOutputStream() == &std::cout);
}
