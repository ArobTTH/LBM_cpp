#ifndef LBM_MULTI_FILE_INITIALIZATION_HPP
#define LBM_MULTI_FILE_INITIALIZATION_HPP

#include <iostream>

#include "../../src/parameter.hpp"
#include "../../src/global_variable.hpp"
#include "../../src/option.hpp"

#include "init_CA_test.hpp"
#include "init_boiling_simple.hpp"
#include "init_porous_media.hpp"

void initialization() {

    if(CA_test_flag) {
        caTestInit();
    }

    if(boiling_simple_flag) {
        boilingSimpleInit();
    }

    if(porous_media_flag) {
        porousMediaInit();
    }


}


#endif //LBM_MULTI_FILE_INITIALIZATION_HPP
