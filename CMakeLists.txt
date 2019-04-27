cmake_minimum_required (VERSION 3.5)

project (HCSR04)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (HCSR04 ${source_files})
target_link_libraries(HCSR04 wiringPi) 
