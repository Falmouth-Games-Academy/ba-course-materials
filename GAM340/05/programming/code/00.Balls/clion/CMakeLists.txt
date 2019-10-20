cmake_minimum_required(VERSION 3.15)
project(clion)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

add_executable(clion
        simplesdl.cpp)

target_link_libraries(clion
        ${SDL2_LIBRARY}
        ${SDL2_MIXER_LIBRARY}
        ${OPENGL_LIBRARIES}
        ${SDL2_IMAGE_LIBRARY}
        )

add_custom_command(TARGET clion PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources)