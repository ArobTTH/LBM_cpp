#ifndef LBM_MULTI_FILE_INIT_POROUS_MEDIA_HPP
#define LBM_MULTI_FILE_INIT_POROUS_MEDIA_HPP

#include "../../src/help/qsgs.hpp"

void porousMediaInit() {
    int i, j, k, m;
    RK_flag = true;

    cout << "Porous media boiling start! " << endl;

    //fluid & solid
    quartetStructureGenerationSet();

    for (i = 0; i <= NX; i++) {
        for (j = 0; j <= NY; j++) {
            if (j == 0 || j == NY) {
                area[i][j] = 1;
//            }else {
//                area[i][j] = 0;
            }
        }
    }

//    int ox = NX/6;
//    int oy = NY/2;
//    int rr=10;
//
//    for (i = 1; i < NX; i++) {
//        for (j = 1; j < NY; j++) {
//
//            area[i][j] = 0;
//
//            if (i % ox ==  0 && j % oy == 0) {
//                for (int ii = 0; ii <=NX;ii++){
//                    for (int jj =0; jj<= NY; jj++){
//                        if ((ii < i + rr && ii > i-rr)&&
//                            (jj < j + rr && jj > j-rr)) {
//                            area[ii][jj] = 1;
//                        }
//                    }
//                }
//            }
//        }
//    }


//    //fluid & solid
//
//    for (i = 0; i <= NX; i++) {
//        for (j = 0; j <= NY; j++) {
//            if (j <  1 || j > NY-1) {
//                area[i][j] = 1;
//
//           }
//        }
//    }


//    for (i = 0; i <= NX; i++) {
//        for (j = 0; j <= NY; j++) {
//
//            if (i % ox ==  0 && j % oy == 0) {
//                for (int ii = 0; ii <=NX;ii++){
//                    for (int jj =0; jj<= NY; jj++){
//                        if ((i -ii)*(i-ii) + (j-jj)*(j-jj)<= rr*rr) {
//                         area[ii][jj] = 1;
//                        }
//                    }
//                }
//            }
//        }
//    }



//    for (i = 0; i <= NX; i++) {
//        for (j = 0; j <= NY; j++) {
//            if (j <  2*thick_down || j > NY -  2*thick_down) {
//                area[i][j] = 1;
//            }
//        }
//    }
//
//    for (i = 0; i <= NX; i++) {
//        for (j = 0; j <= NY; j++) {
//            if (i > 2 * thick_down && i < NX - 2 * thick_up) {
//                if (j > 4 * thick_down && j < NY - 4 * thick_down) {
//                    area[i][j] = 0;
//                }
//            }
//        }
//    }


//  fluid & solid count
    for (i = 0; i <= NX; i++) {
        for (j = 0; j <= NY; j++) {
            if (area[i][j] != 1) {
                fluid_count++;
            }

            if (area[i][j] == 1 && j <= (NY / 2)) {
                base_down_count++;
            }

            if (area[i][j] == 1 && j > (NY / 2)) {
                base_up_count++;
            }
        }
    }

    //init density & lambda
    for (i = 0; i <= NX; i++) {
        for (j = 0; j <= NY; j++) {
            if (area[i][j] == 1) {
                rho[i][j] = rho_s;
                rho0[i][j] = rho_s;
                lambda[i][j] = lambda_s;
            } else {

                if (j >= (NY + 1 - thick_up - thick_down) * charging_ratio + thick_down) {
                    rho[i][j] = rho_v;
                    rho0[i][j] = rho_v;
                } else {
                    rho[i][j] = rho_l;
                    rho0[i][j] = rho_l;
                }
                lambda[i][j] = 0.028 * rho[i][j];
            }
        }
    }
    //init temperature

    if (RK_flag) {
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                if (j == 0) {
                    T[i][j] = T_s;
                }

                if (j == NY) {
                    T[i][j] = T_u;
                }

                if (j > 0 && j < NY) {
                    T[i][j] = T_s;
                }
            }
        }
    } else {
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                T[i][j] = T_s;
            }
        }
    }
    //init pressure
    for (i = 0; i <= NX; i++) {
        for (j = 0; j <= NY; j++)
            if (area[i][j] != 1) {
                P[i][j] = peos(rho[i][j], T_s);
            }
    }
    //init distribution function
    for (i = 0; i <= NX; i++) {
        for (j = 0; j <= NY; j++) {
            for (m = 0; m < 2; m++) {
                u[i][j][m] = 0;
                u0[i][j][m] = 0;
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

#endif //LBM_MULTI_FILE_INIT_POROUS_MEDIA_HPP
