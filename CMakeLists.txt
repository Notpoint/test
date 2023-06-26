cmake_minimum_required(VERSION 3.22.1)

project(learncmake VERSION 2)

configure_file(learncmake.h.in learncmake.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(adder)

add_subdirectory(external/glfw)

target_link_libraries(${PROJECT_NAME} adder glfw)

link_directories(${PROJECT_NAME} PUBLIC external/glfw/src PUBLIC adder/src )

target_include_directories(${PROJECT_NAME} PUBLIC external/glfw/include PUBLIC adder/include) 
