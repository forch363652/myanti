# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("ndkanti")

#设置变量路径
set(CMAKE_CURRENT_SOURCE_DIR .)

# 编译器堆栈保护 设置此项会增大so包体积
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector-all")

# 开启汇编
set(can_use_assembler TRUE)
enable_language(ASM)

# 编译警告
add_definitions(-w) #忽略所有警告

# 查找当前目录下的所有源文件，并保存到 DIR_LIB_SRCS 变量
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}  DIR_LIB_SRCS)
aux_source_directory(include  DIR_LIB_SRCS)
aux_source_directory(base/call DIR_LIB_SRCS)
aux_source_directory(base/Env DIR_LIB_SRCS)



# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        ndkanti

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${DIR_LIB_SRCS})

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
target_include_directories(ndkanti PUBLIC arch/${ANDROID_ABI}) # cpp文件直接 #include "syscall_arch.h" 即可使用

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log
        android # 链接下面的库
        #include "android/asset_manager.h"
        #include "android/asset_manager_jni.h"

        )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        ndkanti
        android
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})