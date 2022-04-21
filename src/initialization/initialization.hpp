#ifndef LBM_MULTI_FILE_INITIALIZATION_HPP
#define LBM_MULTI_FILE_INITIALIZATION_HPP

#include "../../src/parameter.hpp"
#include "../../src/global_variable.hpp"
#include "../../src/option.hpp"

#include "init_CA_test.hpp"
#include "init_boiling_simple.hpp"

void initialization() {

    if(CA_test_flag) {
        CaTestInit();
    }

    if(boiling_simple_flag) {
        boilingSimpleInit();
    }


}


#endif //LBM_MULTI_FILE_INITIALIZATION_HPP
