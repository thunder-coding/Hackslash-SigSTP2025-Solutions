cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(Hackslash-SigSTP
  LANGUAGES CXX
  VERSION 0.1
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CXXFLAGS
  -Wall
  -Wextra
  -Werror
  -Wpedantic
  )

# Compile the actual logic of the task into a static library so that we can write test cases for them easily

add_library(Task1Lib STATIC
  Task-1/ATM.cc
)
add_executable(Task-1
  Task-1/main.cc
)
add_executable(Task-1-Tests
  Task-1/tests/main.cc
)

add_library(Task2Lib STATIC
  Task-2/TaskManager.cc
)
add_executable(Task-2
  Task-2/main.cc
)
add_executable(Task-2-Tests
  Task-2/tests/main.cc
)

add_library(Task3Lib STATIC
  Task-3/parser.cc
  Task-3/partOne.cc
  Task-3/partTwo.cc
)
add_executable(Task-3
  Task-3/main.cc
)
add_executable(Task-3-Tests
  Task-3/tests/main.cc
)

foreach(task 1;2;3)
  target_compile_options(Task-${task} PRIVATE ${CXXFLAGS})
  target_compile_options(Task${task}Lib PRIVATE ${CXXFLAGS})
  target_link_libraries(Task-${task} PRIVATE Task${task}Lib)
  target_link_libraries(Task-${task}-Tests PRIVATE Task${task}Lib)
endforeach()