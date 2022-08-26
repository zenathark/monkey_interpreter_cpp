cmake_minimum_required(VERSION 3.10)

project(MonkeyInterpreterCpp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Catch2 3 REQUIRED)
find_package(Boost REQUIRED)

set(BIN_SOURCES
  src/main.cpp
)

set(TEST_SOURCES
  test/test.cpp
  src/lexer.cpp
)


add_executable(tests ${TEST_SOURCES})
target_compile_features(tests PRIVATE cxx_std_17)
target_link_libraries(tests
  PRIVATE
    Catch2::Catch2WithMain
)
target_include_directories(tests
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)


# add_executable(monkeycpp main.cpp)
