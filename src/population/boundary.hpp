#ifndef LBM_MULTI_FILE_BOUNDARY_HPP
#define LBM_MULTI_FILE_BOUNDARY_HPP

void boundary() {
    int i, j, k, ip, jp;

    for (i = 0; i <= NX; i++) {
        for (j = 0; j <= NY; j++) {
            for (k = 0; k < Q; k++) {
                if (area[i][j] == 0)//fluid node
                {
                    ip = i + e[k][0];
                    jp = j + e[k][1];
                    wrap(ip, jp);
                    if (area[ip][jp] == 1 && isCornerDir[i][j][k] == 0)// solid node
                        f[i][j][bb[k]] = F[i][j][k];

                }

                if (k != 0 && isCornerDir[i][j][k] == 1) {

                    f[i][j][k] = feq(k, rho0[i][j], u0[i][j]);
                }
            }
        }
    }

//    for (i=0;i<=NX;i++) {
//        for (j=0;j<=NY;j++) {
//            for (k=1;k<Q;k++) {
//                if(isCornerDir[i][j][k] == 1 ) {
//
//                    f[i][j][k] = feq(k,rho0[i][j],u0[i][j]);
//
////                    for (k2=1;k2<Q;k2++) {
////                        f[i][j][k] += Mre[k][k2]* meq(k2, rho[i][j],u[i][j]);
////                    }
//                }
//            }
//        }
//    }


}

#endif //LBM_MULTI_FILE_BOUNDARY_HPP
