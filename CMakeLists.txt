cmake_minimum_required(VERSION 3.17)
project(gxng)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(graphics)
add_subdirectory(math)
add_subdirectory(lib)

file(GLOB SOURCE "graphics/*.cpp" "math/*.cpp"  "input/*.cpp")

add_library(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC
        graphics
        input
        math
        )

target_link_libraries(${PROJECT_NAME} PUBLIC
        glad
        lodepng
        )