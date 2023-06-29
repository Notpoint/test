cmake_minimum_required(VERSION 3.22.1)

project(learncmake VERSION 2)

option(USE_ADDER "add adder into project" ON)

if(USE_ADDER)
    add_subdirectory(adder)
    list(APPEND EXTRA_DIRS "adder/src")
    list(APPEND EXTRA_INCLUDE_DIRS "adder/include")
    list(APPEND EXTRA_LINKS adder)
endif()

configure_file(learncmake.h.in learncmake.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(external/glfw)

target_link_libraries(${PROJECT_NAME} adder glfw)

link_directories(${PROJECT_NAME} PUBLIC external/glfw/src ${EXTRA_DIRS})

target_include_directories(${PROJECT_NAME} PUBLIC external/glfw/include ${EXTRA_INCLUDE_DIRS}) 
