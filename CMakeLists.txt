cmake_minimum_required(VERSION 3.8)

project(streamview LANGUAGES CXX)

if (MSVC)
  add_compile_options("/W4" "/std:c++latest")
  add_definitions("-D_WIN32_WINNT=0x0601")
else()
  add_compile_options("-std=c++17")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tests)
