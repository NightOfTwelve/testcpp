# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("testcpp")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#
# In this top level CMakeLists.txt, ${CMAKE_PROJECT_NAME} is used to define
# the target library name; in the sub-module's CMakeLists.txt, ${PROJECT_NAME}
# is preferred for the same purpose.
#
# In order to load a library into your app from Java/Kotlin, you must call
# System.loadLibrary() and pass the name of the library defined here;
# for GameActivity/NativeActivity derived applications, the same library name must be
# used in the AndroidManifest.xml file.
add_library(${CMAKE_PROJECT_NAME} SHARED
        # List C/C++ source files with relative paths to this CMakeLists.txt.
        native-lib.cpp
)

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
        # List libraries link to the target library
        android
        log)


#add_subdirectory(test2)
#add_subdirectory(test3)
#add_executable(test0 test2.cpp)
#add_executable(test1 test1.cpp)
#
add_subdirectory(insideObject)

##SET(CMAKE_BUILD_TYPE "Debug/Release/...”)
#
###* C++ 编译
##SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
##SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -DNODEBUG -O3 -Wall")
###* C 编译
##SET(CMAKE_C_FILAGS "$ENV{CFLAGS} -O0 -Wall -g -ggdb")
##SET(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -DNODEBUG -O3 -Wall")
#
#SET(CMAKE_BUILD_TYPE Release)
##set(CMAKE_BUILD_TYPE Debug)
#message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
#add_executable(${CMAKE_PROJECT_NAME} test2.cpp)
