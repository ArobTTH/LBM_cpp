#ifndef LBM_MULTI_FILE_MONITOR_HPP
#define LBM_MULTI_FILE_MONITOR_HPP

#include <iostream>
using namespace std;

#include "parameter.hpp"

void monitor (int n) {

    //system("cls");
    cout
    <<"calculate:  "
    <<double(n)/double(Nloop)*100
    <<" %" <<endl;

}

#endif //LBM_MULTI_FILE_MONITOR_HPP
