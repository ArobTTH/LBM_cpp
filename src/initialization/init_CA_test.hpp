#ifndef LBM_MULTI_FILE_INIT_CA_TEST_HPP
#define LBM_MULTI_FILE_INIT_CA_TEST_HPP

#include <iostream>

#include "../../src/parameter.hpp"
#include "../../src/global_variable.hpp"
#include "../../src/function.hpp"
#include "../../src/option.hpp"

void CaTestInit() {
    int i,j,k,m;
    if (CA_test_flag) {

        cout<< "Contact Angle Test start! "<<endl;

        double RR = 40.0;
        double R0 = int(NX / 2);
        double T0 = T_rate * Tc;
        //fluid & solid
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                //solid
                if (j == 0 || j == NY) {
                    area[i][j] = 1;
                } else
                    //fluid
                {
                    area[i][j] = 0;
                }
            }
        }
        //init density
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                if (area[i][j] == 1) {
                    rho[i][j] = rho_s;
                } else {
                    rho[i][j] = (rho_l + rho_v) * 0.5 - (rho_l - rho_v) * 0.5 *
                                                        tanh((sqrt((i - R0) * (i - R0) + (j - 1) * (j - 1)) - RR) / 5);
                }
            }
        }
        //init temperature
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                T[i][j] = T0;
            }
        }
        //init pressure
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++)
                if (area[i][j] != 1) {
                    P[i][j] = peos(rho[i][j], T[i][j]);
                }
        }
        //init distribution function
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                for (m = 0; m < 2; m++) {
                    u[i][j][m] = 0;
                    f_m[i][j][m] = 0;
                    f_ads[i][j][m] = 0;
                    f_b[i][j][m] = 0;
                    f_total[i][j][m] = 0;
                }
                for (k = 0; k < Q; k++) {
                    if (area[i][j] != 1) {
                        f[i][j][k] = feq(k, rho[i][j], u[i][j]);
                        F[i][j][k] = f[i][j][k];
                    } else {
                        f[i][j][k] = 0;
                        F[i][j][k] = 0;
                    }
                }
            }
        }
    }
}

#endif //LBM_MULTI_FILE_INIT_CA_TEST_HPP
