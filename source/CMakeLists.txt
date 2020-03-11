include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

set(driver_src
  driver/driver.cpp
)

add_library(driver_lib ${driver_src})

set(engine_src
  engine/engine.cpp

  engine/context.h
  engine/context.cpp

  engine/states/char_litheral.cpp
  engine/states/multiple_line_comment.cpp
  engine/states/program_text.cpp
  engine/states/single_line_comment.cpp
  engine/states/string_litheral.cpp
)

add_library(engine_lib ${engine_src})

set(comment_deleter_src
  main.cpp
)

add_executable(comment_deleter ${comment_deleter_src})
target_link_libraries(comment_deleter engine_lib driver_lib)
