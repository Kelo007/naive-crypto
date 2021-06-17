cmake_minimum_required(VERSION 3.10)

project(naive-crypto)

set(CMAKE_CXX_STANDARD 20)

add_library(prime STATIC
  src/prime.cpp
  src/type.cpp
)

target_include_directories(prime PUBLIC
  include/
)

add_executable(rsa rsa.cpp)
add_executable(test test.cpp)
target_link_libraries(rsa PRIVATE prime)
target_link_libraries(test PRIVATE prime)
