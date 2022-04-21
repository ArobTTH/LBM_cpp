#ifndef LBM_MULTI_FILE_MACRO_HPP
#define LBM_MULTI_FILE_MACRO_HPP

void macro () {

    int i,j,k,m;

    for (i=0;i<=NX;i++) {
        for (j=0;j<=NY;j++) {
            if(area[i][j]!=1) {
                rho[i][j] = 0;
                P[i][j] = 0;
                Psi[i][j] = 0;

                for (m=0;m<2;m++)
                    u[i][j][m] = 0.5*f_total[i][j][m];
                for (k=0;k<Q;k++) {
                    rho[i][j] += f[i][j][k];
                    for (m=0;m<2;m++)
                        u[i][j][m] += f[i][j][k]*e[k][m];
                }
                for (m=0;m<2;m++)
                    u[i][j][m] /= rho[i][j];

                P[i][j] = peos( rho[i][j], T[i][j]);
                Psi[i][j] = psi( rho[i][j],P[i][j]);
                lambda[i][j] = 0.028 * rho[i][j];
            } else {
                lambda[i][j] = lambda_s;
                rho[i][j] = rho_s;
            }
        }
    }

    // average density
    double rho_sum = 0;
    for (i = 0; i <= NX; i++) {
        for (j = 0; j <= NY; j++) {
            if (area[i][j] != 1) {
                rho_sum += rho[i][j];
            }
        }
    }
    rho_average = rho_sum / fluid_count;
    //rho_average = rho_sum;

}

#endif //LBM_MULTI_FILE_MACRO_HPP
