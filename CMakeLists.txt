cmake_minimum_required(VERSION 3.19)

project(GLbasic)

set(CMAKE_CXX_STANDARD 20)

# ---- Add executable ----
add_executable(GLbasic
    src/main.cpp
    libs/glad/src/glad.c
    src/graphic/Shader.cpp
)

# ---- Include directories ----
target_include_directories(GLbasic PRIVATE
    libs/glad/include
    libs/glfw/include
    libs/glm
)

# ---- Link directories ----
link_directories(
    libs/glfw/lib
)

# ---- Link libraries ----
target_link_libraries(GLbasic
    ${CMAKE_SOURCE_DIR}/libs/glfw/lib/libglfw3.a
    opengl32
    gdi32
    user32
    shell32
)

target_link_directories(GLbasic PRIVATE libs/glfw/lib)