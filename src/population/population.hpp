#ifndef LBM_MULTI_FILE_POPULATION_HPP
#define LBM_MULTI_FILE_POPULATION_HPP

#include "../../src/parameter.hpp"
#include "../../src/global_variable.hpp"
#include "../../src/function.hpp"
#include "streaming.hpp"
#include "boundary.hpp"
#include "collision.hpp"
#include "macro.hpp"
#include "force.hpp"

void population () {

    streaming();

    boundary();

    macro();

    force();

    collision();

}

#endif //LBM_MULTI_FILE_POPULATION_HPP
