cmake_minimum_required(VERSION 4.2)
project(hypercube LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SOURCES src/main.cpp src/grid.cpp src/renderer.cpp)

find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wextra -Wpedantic)
