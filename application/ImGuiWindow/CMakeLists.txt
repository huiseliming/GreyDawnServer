
include_directories(../../third_party/gl3w/include)
FILE(GLOB IMGUI_SRC_FILES "imgui/*.cpp" "imgui/*.h")
FILE(GLOB IMGUI_WINDOW_SRC_FILES "*.cpp" "*.h")
message(${IMGUI_WINDOW_SRC_FILES})
add_executable(ImGuiWindow ${IMGUI_SRC_FILES} ${IMGUI_WINDOW_SRC_FILES})
target_link_libraries(ImGuiWindow glfw gl3w)









