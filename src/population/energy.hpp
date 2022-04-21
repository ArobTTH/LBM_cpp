#ifndef LBM_MULTI_FILE_ENERGY_HPP
#define LBM_MULTI_FILE_ENERGY_HPP

void Kt(double T_old[][NY+1],double T_new[][NY+1]);

void Rk() {
    int i,j;

    for(i = 0; i <= NX; i++) {
        for(j = 0; j<= NY; j++) {
            T_temp[i][j] =T[i][j];
        }
    }
    Kt(T_temp, h1);
    for(i = 0; i <= NX; i++) {
        for(j = 0; j <= NY; j++) {
            if(j == NY)
                h1[i][j]=0;
            T_temp[i][j] = T[i][j] + 0.5*h1[i][j];
        }
    }
    Kt(T_temp, h2);
    for(i = 0; i<= NX; i++) {
        for(j = 0; j <= NY; j++) {
            if(j == NY)
                h2[i][j]=0;
            T_temp[i][j] = T[i][j] + 0.5*h2[i][j];
        }
    }

    Kt(T_temp, h3);

    for(i = 0; i <= NX; i++) {
        for(j = 0; j <= NY; j++) {
            if(j == NY)
                h3[i][j]=0;

            T_temp[i][j] = T[i][j] + h3[i][j];
        }
    }
    Kt(T_temp, h4);
    for(i = 0; i <= NX; i++) {
        for(j = 0;j <= NY; j++) {
            if(j == NY)
                h4[i][j]=0;
        }
    }

    for(i = 0;i <= NX; i++) {
        for(j = 0;j <= NY; j++) {
            T[i][j] = T[i][j] + (h1[i][j] + 2*h2[i][j] + 2*h3[i][j] + h4[i][j])/6.0;
        }
    }
    for(i = 0;i <= NX; i++) {
        for(j = 0; j <= NY; j++) {
            h1[i][j] = 0;
            h2[i][j] = 0;
            h3[i][j] = 0;
            h4[i][j] = 0;
            T_temp[i][j] =0;
        }
    }
}

void Kt(double T_old[][NY+1],double T_new[][NY+1]) {

        int i,j,i1,j1,i2,j2;

        for (i=0;i<=NX;i++) {
            for (j=0;j<=NY;j++) {
                i1=i-1;
                j1=j-1;
                i2=i+1;
                j2=j+1;
                wrap(i1,j1);
                wrap(i2,j2);

                T_new[i][j] = - (u[i][j][0] * ((T_old[i2][j] - T_old[i1][j])/2.0)
                                 +  u[i][j][1] * ((T_old[i][j2] - T_old[i][j1])/2.0))
                              + ((lambda[i][j]+lambda[i2][j])/2.0*(T_old[i2][j] - T_old[i][j])
                                 - (lambda[i][j]+lambda[i1][j])/2.0*(T_old[i][j] - T_old[i1][j])
                                 + (lambda[i][j]+lambda[i][j2])/2.0*(T_old[i][j2] - T_old[i][j])
                                 - (lambda[i][j]+lambda[i][j1])/2.0*(T_old[i][j] - T_old[i][j1]))/rho[i][j]/cv
                              - ((u[i2][j][0] - u[i1][j][0])/2.0 + (u[i][j2][1] - u[i][j1][1])/2.0)
                                * T_old[i][j] * PR_R/cv/(1 - PR_b*rho[i][j]);

                if(j==0) {
                    if((i>= 0.5*( NX+1 - heating_section ))&&(i< 0.5*( NX+1 + heating_section))) {
                        T_new[i][j] =  ((lambda[i][j]+lambda[i2][j])/2.0*(T_old[i2][j] - T_old[i][j])
                                        - (lambda[i][j]+lambda[i1][j])/2.0*(T_old[i][j] - T_old[i1][j])
                                        + (lambda[i][j]+lambda[i][j2])/2.0*(T_old[i][j2] - T_old[i][j])
                                        - q)/rho[i][j]/cv;
                    } else {
                        T_new[i][j] =  ((lambda[i][j]+lambda[i2][j])/2.0*(T_old[i2][j] - T_old[i][j])
                                        - (lambda[i][j]+lambda[i1][j])/2.0*(T_old[i][j] - T_old[i1][j])
                                        + (lambda[i][j]+lambda[i][j2])/2.0*(T_old[i][j2] - T_old[i][j])
                                        - 0)/rho[i][j]/cv;
                    }
                }


            }
        }
}

#endif //LBM_MULTI_FILE_ENERGY_HPP
