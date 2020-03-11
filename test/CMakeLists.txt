add_subdirectory(3pc)

include_directories("${PROJECT_SOURCE_DIR}/source/include")

add_executable(driver_test driver_test.cpp)
target_link_libraries(driver_test driver_lib Catch2::Catch2)

add_executable(engine_test engine_test.cpp)
target_link_libraries(engine_test engine_lib Catch2::Catch2)

add_test(NAME DriverTest COMMAND driver_test)
add_test(NAME EngineTest COMMAND engine_test)
