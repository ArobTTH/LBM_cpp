#ifndef LBM_MULTI_FILE_INIT_POROUS_MEDIA_HPP
#define LBM_MULTI_FILE_INIT_POROUS_MEDIA_HPP

#include "../../src/help/qsgs.hpp"

void porousMediaInit() {
    int i,j,k,m;

    RK_flag = false;
        cout<< "Porous media start! "<<endl;

        //fluid & solid
    quartetStructureGenerationSet();

    for (i = 0; i<= NX; i++) {
        for (j = 0; j <= NY; j++) {
            if (j == 0 || j== NY) {
                area[i][j] = 1;
            }
        }
    }

    fluid_count = 0;
    for(i=0; i<=NX; i++)//buoyancy force
    {
        for(j=0; j<=NY; j++)
        {
            if(area[i][j]!=1)
            {
                fluid_count++;
            }
        }
    }

        //init density
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                if (area[i][j] == 1) {
                    rho[i][j] = rho_s;
                } else if (j <= NY/2) {
                    rho[i][j] = rho_l;
                } else {
                    rho[i][j] = rho_v;
                }
            }
        }
        //init temperature
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                T[i][j] = T_s;
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



#endif //LBM_MULTI_FILE_INIT_POROUS_MEDIA_HPP
