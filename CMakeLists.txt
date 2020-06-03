cmake_minimum_required(VERSION 3.12)

project(grey_dawn_server)
message(STATUS "compiler: " ${CMAKE_CXX_COMPILER_ID})

IF(NOT APPLE AND NOT MSVC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
ENDIF()

add_executable(HelloWorld application/HelloWorld.cpp)

target_link_libraries(HelloWorld 
    drogon
    trantor
    jsoncpp
    uuid
    ssl
    crypto
    pthread
    dl
    z
    )































