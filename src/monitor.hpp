#ifndef LBM_MULTI_FILE_MONITOR_HPP
#define LBM_MULTI_FILE_MONITOR_HPP

#include <iostream>

#include "option.hpp"
#include "global_variable.hpp"
using namespace std;

#include "parameter.hpp"

void monitor (int n) {

    //system("cls");

    if (CA_test_flag) {
        cout
                << "calculate:  "
                << double(n) / double(Nloop) * 100
                << " %" << endl;
    }

    if (boiling_simple_flag) {
        cout
            << "computation: "<< n << "\t"
            << "average density: "<< rho_average <<"\t"
            << endl;
    }

}

#endif //LBM_MULTI_FILE_MONITOR_HPP
