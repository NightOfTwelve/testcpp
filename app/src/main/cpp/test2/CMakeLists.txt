# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("test")

#SET(CMAKE_BUILD_TYPE "Debug/Release/...”)

##* C++ 编译
#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -DNODEBUG -O3 -Wall")
##* C 编译
#SET(CMAKE_C_FILAGS "$ENV{CFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -DNODEBUG -O3 -Wall")

SET(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
add_executable(test test2.cpp)
