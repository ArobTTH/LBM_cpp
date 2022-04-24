#ifndef LBM_MULTI_FILE_STREAMING_HPP
#define LBM_MULTI_FILE_STREAMING_HPP


void streaming() {

    int i, j, k, ip, jp;

    for (i = 0; i <= NX; i++) {
        for (j = 0; j <= NY; j++) {
            for (k = 0; k < Q; k++) {
                ip = i - e[k][0];
                jp = j - e[k][1];
                wrap(ip, jp);
                f[i][j][k] = F[ip][jp][k];
            }
        }
    }

//    for (i=0;i<=NX;i++) {
//        for (j=0;j<=NY;j++) {
//            for (k=0;k<Q;k++) {
//                if(isCornerDir[i][j][k] == 1 ) {
//
//                    f[i][j][k] = feq(k,rho0[i][j],u0[i][j]);
//                    //f[i][j][bb[k]] = feq(k,rho0[i][j],u0[i][j]);
//
////                    for (k2=1;k2<Q;k2++) {
////                        f[i][j][k] += Mre[k][k2]* meq(k2, rho[i][j],u[i][j]);
////                    }
//                }
//            }
//        }
//    }

}


#endif //LBM_MULTI_FILE_STREAMING_HPP
