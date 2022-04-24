#ifndef LBM_MULTI_FILE_POPULATION_HPP
#define LBM_MULTI_FILE_POPULATION_HPP

#include "../../src/parameter.hpp"
#include "../../src/global_variable.hpp"
#include "../../src/function.hpp"
#include "../../src/option.hpp"
#include "streaming.hpp"
#include "boundary.hpp"
#include "collision.hpp"
#include "macro.hpp"
#include "force.hpp"
#include "energy.hpp"

void population () {

//    streaming();
//
//    boundary();
//
//    if (RK_flag) {
//        Rk();
//    }
//
//    macro();
//
//    force();
//
//    collision();

    macro();

    force();

    collision();

    streaming();

    boundary();
//
//    if (RK_flag) {
//        Rk();
//    }



}

#endif //LBM_MULTI_FILE_POPULATION_HPP
