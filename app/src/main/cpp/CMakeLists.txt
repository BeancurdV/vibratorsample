# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name. The project name can be accessed via ${ PROJECT_NAME},
# Since this is the top level CMakeLists.txt, the project name is also accessible
# with ${CMAKE_PROJECT_NAME} (both CMake variables are in-sync within the top level
# build script scope).
project("vibrator_sample")

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
        native-lib.cpp)

include_directories(android)

# Specifies libraries CMake should link to your target library. You
# can link libraries from various origins, such as libraries defined in this
# build script, prebuilt third-party libraries, or Android system libraries.
target_link_libraries(${CMAKE_PROJECT_NAME}
        # List libraries link to the target library
        android
#        binder_ndk
        log)


# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VIBRATOR vibrator_main)
include_directories(include)
add_executable(${VIBRATOR}
        vibrator_main.cpp)

set_target_properties(${VIBRATOR} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out
        )

# 指定NDK的STL库
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++")

set(SHARED_LIB_DIR ${CMAKE_SOURCE_DIR}/so)
link_directories(${SHARED_LIB_DIR})

add_library(binder SHARED IMPORTED)
set_target_properties(binder PROPERTIES IMPORTED_LOCATION ${SHARED_LIB_DIR}/libbinder.so)

add_library(cutils SHARED IMPORTED)
set_target_properties(cutils PROPERTIES IMPORTED_LOCATION ${SHARED_LIB_DIR}/libcutils.so)

add_library(utils SHARED IMPORTED)
set_target_properties(utils PROPERTIES IMPORTED_LOCATION ${SHARED_LIB_DIR}/libutils.so)

add_library(log SHARED IMPORTED)
set_target_properties(log PROPERTIES IMPORTED_LOCATION ${SHARED_LIB_DIR}/liblog.so)


# 链接目标库
target_link_libraries(
        ${VIBRATOR}
        binder
        cutils
        utils
        log
)

#cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-21 ..