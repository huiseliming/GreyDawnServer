
#获取HelloWorld下的源文件
FILE(GLOB HELLOWORLD_SRC_FILES "HelloWorld/*.cpp" "HelloWorld/*.h")
message(${HELLOWORLD_SRC_FILES})
add_executable(HelloWorld ${HELLOWORLD_SRC_FILES})
target_link_libraries(HelloWorld drogon trantor jsoncpp uuid mariadbclient ssl crypto pthread dl z)

FILE(GLOB MYSQL_SRC_FILES "MySQL/*.cpp" "MySQL/*.h")
FILE(GLOB MODEL_SRC_FILES "MySQL/Model/*.cc" "MySQL/Model/*.h")

add_executable(MySQL ${MYSQL_SRC_FILES} ${MODEL_SRC_FILES}) 
target_link_libraries(MySQL drogon trantor jsoncpp uuid mariadbclient ssl crypto pthread dl z)


add_subdirectory(ImGuiWindow)

