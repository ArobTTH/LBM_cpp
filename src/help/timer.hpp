#ifndef LBM_MULTI_FILE_TIMER_HPP
#define LBM_MULTI_FILE_TIMER_HPP

#include <ctime>
#include <string>
#include <chrono>
#include <random>

#define TI_GPU(tag) \
    cudaEvent_t _event_start_GPU_ ##tag; \
    cudaEvent_t _event_end_GPU_ ##tag; \
    float _event_time_GPU_ ##tag; \
    cudaEventCreate(& _event_start_GPU_ ##tag); \
    cudaEventCreate(& _event_end_GPU_ ##tag); \
    cudaEventRecord(_event_start_GPU_ ##tag);

#define TO_GPU(tag, str, times) \
    cudaEventRecord(_event_end_GPU_ ##tag); \
    cudaEventSynchronize(_event_end_GPU_ ##tag); \
    cudaEventElapsedTime(&_event_time_GPU_ ##tag, _event_start_GPU_ ##tag, _event_end_GPU_ ##tag); \
    float _event_time_once_GPU_ ##tag = _event_time_GPU_ ##tag / times; \
    printf("GPU:   %10s:\t %10.3fus\t", str, _event_time_once_GPU_ ##tag * 1000); \
    cudaDeviceSynchronize(); \
    printf("%10s string: %s\n\n",str, cudaGetErrorString(cudaGetLastError()));

#define TI_CPU(tag) \
    auto _event_time_CPU_start_ ##tag = chrono::high_resolution_clock::now();

#define TO_CPU(tag, str, times) \
    auto _event_time_CPU_end_ ##tag = chrono::high_resolution_clock::now(); \
    auto _duartion_CPU_ ##tag = chrono::duration_cast<chrono::microseconds>(_event_time_CPU_end_ ##tag - _event_time_CPU_start_ ##tag);\
    float _event_time_CPU_ ##tag = float(_duartion_CPU_ ##tag.count()); \
    printf("CPU:   %10s:\t %10.3fus\t \n", str, _event_time_CPU_ ##tag );

#endif //LBM_MULTI_FILE_TIMER_HPP
