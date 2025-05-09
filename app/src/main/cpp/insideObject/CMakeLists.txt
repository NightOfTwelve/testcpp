cmake_minimum_required(VERSION 3.22.1)

project("insideObject")

#SET(CMAKE_BUILD_TYPE "Debug/Release/...”)

##* C++ 编译
#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -DNODEBUG -O3 -Wall")
##* C 编译
#SET(CMAKE_C_FILAGS "$ENV{CFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -DNODEBUG -O3 -Wall")

#SET(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

# https://www.cnblogs.com/QG-whz/p/4909359.html
add_executable(insideObject_5_1 5.1.cpp)
add_executable(insideObject_5_2_1 5.2.1.cpp)
add_executable(insideObject_5_2_2 5.2.2.cpp)
add_executable(insideObject_6_2 6.2.cpp)
add_executable(insideObject_6_3 6.3.cpp)
add_executable(insideObject_7_1 7.1.cpp)
add_executable(insideObject_7_2 7.2.cpp)
