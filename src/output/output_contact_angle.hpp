#ifndef LBM_MULTI_FILE_OUTPUT_CONTACT_ANGLE_HPP
#define LBM_MULTI_FILE_OUTPUT_CONTACT_ANGLE_HPP

#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <sstream>


ostringstream CATest() {

    ostringstream name;

    if(virtual_density_flag) {
        // virtual density model
        if(wet_flag) {
            name << "CA_test_"
                 << "phi_" << phi
                 << ".dat";

        } else {
            name << "CA_test_"
                 << "delta_rho_" << delta_rho
                 << ".dat";
        }
    }
    else {
        // Gw model
        name <<"CA_test_"
             <<"Gw_"
             <<Gw
             <<".dat";

    }

    return name;
}

#endif //LBM_MULTI_FILE_OUTPUT_CONTACT_ANGLE_HPP
