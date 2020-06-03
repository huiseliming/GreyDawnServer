
#获取HelloWorld下的源文件
FILE(GLOB SC_FILES "HelloWorld/*.cpp" "HelloWorld/*.h")

add_executable(HelloWorld ${SC_FILES})

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

