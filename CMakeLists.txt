cmake_minimum_required(VERSION 3.10)

project(MonkeyInterpreterCpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Catch2 3 REQUIRED)

add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(monkeycpp main.cpp)
