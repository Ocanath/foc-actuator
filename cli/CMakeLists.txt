cmake_minimum_required(VERSION 3.22)
project(motor_cli C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT TARGET motor_controller)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../api motor_api_build)
endif()

add_executable(motor-cli main.cpp args.cpp)

target_link_libraries(motor-cli PRIVATE
    motor_controller
)
