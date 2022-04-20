#ifndef LBM_MULTI_FILE_INITIALIZATION_HPP
#define LBM_MULTI_FILE_INITIALIZATION_HPP

#include "../../src/parameter.hpp"
#include "../../src/global_variable.hpp"
#include "../../src/option.hpp"

#include "contact_angle_test.hpp"

void initialization() {

    if(CA_test) {
        CA_Test();
    }



}


#endif //LBM_MULTI_FILE_INITIALIZATION_HPP
