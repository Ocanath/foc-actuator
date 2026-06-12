if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.22)
    project(foc_motor_controller C CXX)
endif()

add_library(motor_controller STATIC
    motor.cpp
    motor_serial_callbacks.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../foc-code/Core/Src/trig_fixed.c
)

if(NOT TARGET dartt_audio)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/dartt_audio)
endif()

target_include_directories(motor_controller PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../foc-code/Core/Inc
)

target_link_libraries(motor_controller PUBLIC
    dartt_audio
    dartt_protocol
    serial
    cobs
)
