cmake_minimum_required(VERSION 3.12)
project(emu6502)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS "src/*.hpp" "src/*.cpp")

add_executable(emu6502
  ${srcs}
)
