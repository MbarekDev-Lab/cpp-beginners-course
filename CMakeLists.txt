cmake_minimum_required(VERSION 3.10)
project(cpp_beginners_course)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable for main program
add_executable(main src/main.cpp)

# Optional: Add more executables for different exercises
# add_executable(exercise1 exercises/exercise1.cpp)
