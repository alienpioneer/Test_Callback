# CMakeList.txt : CMake project for Test_Callback, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Test_Callback")

# Add source to this project's executable.
add_executable (Test_Callback "main.cpp" "Caller.h" "Caller.cpp")

# TODO: Add tests and install targets if needed.
