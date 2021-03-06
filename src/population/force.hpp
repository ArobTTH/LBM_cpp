#ifndef LBM_MULTI_FILE_FORCE_HPP
#define LBM_MULTI_FILE_FORCE_HPP

#include "src/option.hpp"

void force () {
    int i,j,k,m,ip,jp;

    //clean force
    for (i=0;i<=NX;i++) {
        for (j=0;j<=NY;j++) {
            for(m=0;m<2;m++) {
                f_m[i][j][m]=0;
                f_ads[i][j][m]=0;
                f_b[i][j][m]=0;
                f_total[i][j][m]=0;
            }
        }
    }

    // virtual density model
    if (virtual_density_flag) {
        // virtual density
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                cc[i][j] = 0;
                cc_flag[i][j] = 0;
                rho_ave[i][j] = 0;
                for (k = 1; k < Q; k++) {
                    // solid node
                    if (area[i][j] == 1) {
                        ip = i + e[k][0];
                        jp = j + e[k][1];
                        wrap(ip, jp);

                        // touch fluid node
                        if (area[ip][jp] != 1){
                            cc[i][j] += w2[k];
                            cc_flag[i][j] =1;
                            rho_ave[i][j] += w2[k] * rho[ip][jp];
                        }
                    }
                }
            }
        }
        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                rhow[i][j] = 0;
                // solid node
                if (area[i][j] == 1 && cc_flag[i][j] == 1) {
                    rho_ave[i][j] = rho_ave[i][j] / cc[i][j];

                    if (wet_flag) {
                        rhow[i][j] = phi * rho_ave[i][j];

                    } else {
                        rhow[i][j] = rho_ave[i][j] - delta_rho;
                    }

                    rhow[i][j] = rhow[i][j] > rho_l ? rho_l : rhow[i][j];
                    rhow[i][j] = rhow[i][j] < rho_v ? rho_v : rhow[i][j];
                }
            }
        }
        // fm
        for (i=0;i<=NX;i++) {
            for (j=0;j<=NY;j++) {
                for (k=1;k<Q;k++) {
                    if(area[i][j]!=1) {
                        ip=i+e[k][0];
                        jp=j+e[k][1];
                        wrap(ip,jp);
                        //fluid intermolecular interaction force
                        if(area[ip][jp]!=1) {
                            for (m=0;m<2;m++) {
                                f_m[i][j][m]-=Psi[i][j]*G*w2[k]*
                                              Psi[ip][jp]*e[k][m];
                            }
                        }
                        //solid-fluid interaction force
                        if(area[ip][jp]==1) {
                            for (m=0;m<2;m++) {
                                f_m[i][j][m]-=Psi[i][j]*G*w2[k]*
                                              psi(rhow[ip][jp], P[i][j])*e[k][m];

                            }
                        }
                    }
                }
            }
        }
    }

    // fads model
    else {
        for (i=0;i<=NX;i++) {
            for (j=0;j<=NY;j++) {
                for (k=1;k<Q;k++) {
                    if(area[i][j]!=1) {
                        ip=i+e[k][0];
                        jp=j+e[k][1];
                        wrap(ip,jp);
                        //fluid intermolecular interaction force
                        if(area[ip][jp]!=1) {
                            for (m=0;m<2;m++) {
                                f_m[i][j][m]-=Psi[i][j]*G*w2[k]*
                                              Psi[ip][jp]*e[k][m];
                            }
                        }
                        //solid-fluid interaction force
                        if(area[ip][jp]==1) {
                            for (m=0;m<2;m++) {
                                f_m[i][j][m]-=Psi[i][j]*G*w2[k]*
                                              Psi[i][j]*e[k][m];

                                f_ads[i][j][m]-=Psi[i][j]*Gw*ww[k]*
                                    Psi[i][j]*e[k][m];
                            }
                        }
                    }
                }
            }
        }
    }

    // fb
    if (F_b_flag) {

        for (i = 0; i <= NX; i++) {
            for (j = 0; j <= NY; j++) {
                if (area[i][j] != 1) {
                    f_b[i][j][1] = (rho[i][j] - rho_average) * (-g);
                }
            }
        }
    }

    //total force
    for (i=0;i<=NX;i++) {
        for (j=0;j<=NY;j++) {
            for (m=0;m<2;m++) {
                f_total[i][j][m] = f_m[i][j][m] + f_ads[i][j][m] + f_b[i][j][m];
            }
        }
    }

}

#endif //LBM_MULTI_FILE_FORCE_HPP
