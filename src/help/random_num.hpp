#ifndef LBM_MULTI_FILE_RANDOM_NUM_HPP
#define LBM_MULTI_FILE_RANDOM_NUM_HPP

#include <random>

double randNumGen()
{
    mt19937 rng(random_device{}());
    uniform_real_distribution<double> result(0.0, 1.0);
    return result(rng);
}

#endif //LBM_MULTI_FILE_RANDOM_NUM_HPP
