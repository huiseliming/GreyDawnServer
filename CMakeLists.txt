cmake_minimum_required(VERSION 3.12)

set(This GreyDawnServer)
project(${This})

message(STATUS "compiler: " ${CMAKE_CXX_COMPILER_ID})

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # MSVC链接静态库(/MT),替换/MD为/MT来进行链接静态库,使用RUNTIME_STATIC_LINK控制链接静态库还是动态库
    if(MSVC AND RUNTIME_STATIC_LINK)
        foreach(flag
            CMAKE_C_FLAGS
            CMAKE_CXX_FLAGS
            CMAKE_C_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_C_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL
            CMAKE_CXX_FLAGS_MINSIZEREL
            CMAKE_C_FLAGS_RELWITHDEBINFO
            CMAKE_CXX_FLAGS_RELWITHDEBINFO
        )
            if(${flag} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
            endif()
        endforeach()
    endif()
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(-Wformat=0)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message( FATAL_ERROR "未配置Clang")
endif()

#googletest
enable_testing()
find_package(GTest CONFIG REQUIRED)


add_subdirectory(third_party)

add_subdirectory(grey_dawn_server)

























