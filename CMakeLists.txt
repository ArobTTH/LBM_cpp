cmake_minimum_required(VERSION 3.22)
project(lbm_multi_file)

set(CMAKE_CXX_STANDARD 14)

add_executable(lbm_multi_file
        main.cpp
        src/parameter.hpp
        src/global_variable.hpp
        src/function.hpp
        src/monitor.hpp
        src/population/population.hpp
        src/population/streaming.hpp
        src/population/boundary.hpp
        src/population/collision.hpp
        src/population/macro.hpp
        src/population/force.hpp
        src/option.hpp
        src/initialization/init_CA_test.hpp
        src/initialization/initialization.hpp
        src/output/output.hpp
        src/output/output_CA_test.hpp src/population/energy.hpp src/initialization/init_boiling_simple.hpp src/output/output_boiling_simple.hpp)
