cmake_minimum_required(VERSION 3.12)

project(
  Concat
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVS)
  add_compile_options(/W4 /Wx)
else()
  add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

find_program(
  CLANG_TIDY_EXE
  NAMES "clang-tidy-10"
)

if(CLANG_TIDY_EXE)
  set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
endif()

add_subdirectory(concat)
