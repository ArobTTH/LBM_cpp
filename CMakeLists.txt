cmake_minimum_required(VERSION 3.22)
project(lbm_multi_file CUDA)

find_package(CUDA 11.5 REQUIRED)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. HPP_LIST)

MATH(EXPR stack_size "128*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(lbm_multi_file
        main.cu src/help/cuda_help.hpp src/help/timer.hpp src/help/help.hpp src/help/params.hpp src/initialization/get_corner.hpp)

set_target_properties(lbm_multi_file PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
