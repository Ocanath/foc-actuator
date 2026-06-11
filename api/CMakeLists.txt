add_library(motor_controller STATIC
    motor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../foc-code/Core/Src/trig_fixed.c
)

if(NOT TARGET dartt_audio)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/dartt_audio)
endif()

if(NOT TARGET serial)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/serial-cross-platform)
endif()

target_include_directories(motor_controller PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../foc-code/Core/Inc
)

target_link_libraries(motor_controller PUBLIC
    dartt_serial
    dartt_audio
)
