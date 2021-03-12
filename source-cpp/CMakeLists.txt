project(source-cpp CXX)

set(SOURCES
  src/some-source-code.cpp
  src/some-source-code.hpp)

add_executable(source-cpp ${SOURCES})
target_include_directories(source-cpp PRIVATE src)
set_target_properties(source-cpp PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF)
