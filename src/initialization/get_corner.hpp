#ifndef LBM_MULTI_FILE_GET_CORNER_HPP
#define LBM_MULTI_FILE_GET_CORNER_HPP

#include "../../src/function.hpp"


void getCorner() {

    int i, j, k, ip, jp, ip2, jp2;

    for (i = 0; i <= NX; i++) {
        for (j = 0; j <= NY; j++) {
            for (k = 0; k < Q; k++)
                isCornerDir[i][j][k] = 0;

            ip = i - e[k][0];
            jp = j - e[k][1];
            ip2 = i + e[k][0];
            jp2 = j + e[k][1];

            wrap(ip, jp);
            wrap(ip2, jp2);

            if (area[i][j] == 0 && area[ip][jp] == 1 && area[ip2][jp2] == 1) {
                isCornerDir[i][j][k] = 1;
            }
        }
    }
}

#endif //LBM_MULTI_FILE_GET_CORNER_HPP
