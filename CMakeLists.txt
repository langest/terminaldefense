cmake_minimum_required(VERSION 3.18.5)

#set(CMAKE_CXX_COMPILER "/usr/lib/llvm/11/bin/clang")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(TerminalDefense)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-g)
add_compile_options(-Werror)
add_compile_options(-Wpedantic)

add_subdirectory(source)
add_subdirectory(application)
