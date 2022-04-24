#ifndef LBM_MULTI_FILE_CUDA_HELP_HPP
#define LBM_MULTI_FILE_CUDA_HELP_HPP


#include <random>

template<typename T>
struct memory_unit{
    T* host_ptr;
    T* device_ptr;
    int size_bytes;
    int elements;
    void h2d(){
        cudaMemcpy(device_ptr, host_ptr, size_bytes, cudaMemcpyHostToDevice);
    }
    void d2h(){
        cudaMemcpy(host_ptr, device_ptr, size_bytes, cudaMemcpyDeviceToHost);
    }
    void free_all(){
        free(host_ptr);
        cudaFree(device_ptr);
    }
    explicit memory_unit(int elements_): size_bytes(elements_ * sizeof(T)), elements(elements_){
        host_ptr = (T*) malloc(elements_ * sizeof(T));
        cudaMalloc((void**)&device_ptr, elements_ * sizeof(T));
    }
    void init(){

        std::random_device randomDevice;
        std::mt19937 mt(randomDevice());
        std::uniform_real_distribution<float> distribution(-1.0,1.0);
        for(int i = 0; i < elements; i++){
            host_ptr[i] = T(distribution(mt));
        }
        h2d();
    }

    void init(T value){

        for(int i = 0; i < elements; i++){
            host_ptr[i] = value;
        }
        h2d();
    }

    void clear(){
        cudaMemset(device_ptr, 0, size_bytes);
    }
    void init(T * ptr){
        memcpy(host_ptr, ptr, elements * sizeof(T));
        h2d();
    }
    void init(T value, T value2){
        for(int i = 0; i < elements; i++){
            host_ptr[i] = T(float(value) * float (i) + float(value2));//T(rand() % 100 / float(100)  * 2 * abs_range - abs_range);
            // __half value_fp16 = __half(3e-5)* __half(i) + __half(-1);
            if(isinf(float(host_ptr[i])))
                printf("%f i: %d,", float(host_ptr[i]), i);
        }
        h2d();
    }
};

#endif //LBM_MULTI_FILE_CUDA_HELP_HPP
