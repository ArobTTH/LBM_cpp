#ifndef LBM_MULTI_FILE_COLLISION_HPP
#define LBM_MULTI_FILE_COLLISION_HPP

void collision () {

    int i,j,k,k2;
    //f to m
    for (i=0;i<=NX;i++) {
        for (j=0;j<=NY;j++) {
            if(area[i][j]!=1) {
                for (k=0;k<Q;k++) {
                    mf[i][j][k]=0;
                    for (k2=0;k2<Q;k2++)
                        mf[i][j][k]+=M0[k][k2]*f[i][j][k2];
                }
            }
        }
    }
    //m collision
    for (i=0;i<=NX;i++) {
        for (j=0;j<=NY;j++) {
            if(area[i][j]!=1) {
                for (k=0;k<Q;k++) {

                    if(rho[i][j] >= rho_a) {
                        MF[i][j][k]=mf[i][j][k]+s1[k]*(meq(k, rho[i][j],u[i][j])-
                                                       mf[i][j][k])+(1-0.5*s1[k])*forceeq(k,f_total[i][j],u[i][j],Psi[i][j]);
                    } else {
                        MF[i][j][k]=mf[i][j][k]+s2[k]*(meq(k, rho[i][j],u[i][j])-
                                                       mf[i][j][k])+(1-0.5*s2[k])*forceeq(k,f_total[i][j],u[i][j],Psi[i][j]);
                    }
                }
            }
        }
    }
    //M to F
    for (i=0;i<=NX;i++) {
        for (j=0;j<=NY;j++) {
            if(area[i][j]!=1) {
                for (k=0;k<Q;k++) {
                    F[i][j][k]=0;
                    for (k2=0;k2<Q;k2++)
                        F[i][j][k]+=Mre[k][k2]*MF[i][j][k2];
                }
            }
        }
    }
}

#endif //LBM_MULTI_FILE_COLLISION_HPP
