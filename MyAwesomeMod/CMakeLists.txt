cmake_minimum_required(VERSION 3.18)

set(TARGET MyAwesomeMod)
project(${TARGET})

set(${TARGET}_Sources
        "${CMAKE_CURRENT_SOURCE_DIR}/dllmain.cpp"

        # imgui
        "${CMAKE_CURRENT_SOURCE_DIR}/../RE-UE4SS/Dependencies/imgui/imgui.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../RE-UE4SS/Dependencies/imgui/imgui_draw.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../RE-UE4SS/Dependencies/imgui/imgui_tables.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../RE-UE4SS/Dependencies/imgui/imgui_widgets.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../RE-UE4SS/Dependencies/imgui/misc/cpp/imgui_stdlib.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../RE-UE4SS/Dependencies/imgui/backends/imgui_impl_win32.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../RE-UE4SS/Dependencies/imgui/backends/imgui_impl_dx11.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../RE-UE4SS/Dependencies/imgui/backends/imgui_impl_opengl3.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../RE-UE4SS/Dependencies/imgui/backends/imgui_impl_glfw.cpp"
        )

add_library(${TARGET} SHARED ${${TARGET}_Sources})
target_include_directories(${TARGET} PRIVATE .)
target_link_libraries(${TARGET} PUBLIC cppsdk xinput1_3)

