cmake_minimum_required(VERSION 3.12)

set(This asio)
project(${This})

find_package(OpenSSL REQUIRED)


FILE(GLOB_RECURSE HeaderFiles  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h) #获取当前目录头文件
FILE(GLOB_RECURSE SourceFiles  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp) #获取当前目录源文件
add_library(${This} STATIC ${SourceFiles} ${HeaderFiles}) #编译静态库

target_include_directories(${This} PUBLIC include)

target_link_libraries(${This} PRIVATE OpenSSL::SSL OpenSSL::Crypto)

set_target_properties(${This} PROPERTIES
    FOLDER Libraries
)

add_definitions(-DASIO_SEPARATE_COMPILATION)