project(source-c C)

set(SOURCES
  src/some-source-code.c
  src/some-source-code.h src/main.c)

add_executable(source-c ${SOURCES})
target_include_directories(source-c PRIVATE src)
set_target_properties(source-c PROPERTIES
  C_STANDARD 17
  C_STANDARD_REQUIRED ON
  C_EXTENSIONS ON)
