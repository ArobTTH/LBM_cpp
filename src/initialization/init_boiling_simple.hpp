#ifndef LBM_MULTI_FILE_INIT_BOILING_SIMPLE_HPP
#define LBM_MULTI_FILE_INIT_BOILING_SIMPLE_HPP

void boilingSimpleInit() {

    cout<< "Boiling simple case start! "<<endl;

    RK_flag = true;
    int i,j,k,m;

    //fluid & solid
    for (i=0;i<=NX;i++) {
        for (j=0;j<=NY;j++) {

            if(j < thick_down || j > NY - thick_up) {
                area[i][j] = 1;
            } else {
                area[i][j] = 0; //fluid
            }
        }
    }


//  fluid & solid count
    for (i = 0; i <= NX; i++) {
        for (j = 0; j <= NY; j++) {
            if (area[i][j] != 1) {
                fluid_count++;
            }

            if( area [i][j] ==1 && j<= (NY/2)) {
                base_down_count++;
            }

            if( area [i][j] ==1 && j> (NY/2)) {
                base_up_count++;
            }
        }
    }

    //init density & lambda
    for (i=0;i<=NX;i++) {
        for (j=0;j<=NY;j++) {
            if(area[i][j]==1) {
                rho[i][j] = rho_s;
                lambda[i][j] = lambda_s;
            }
            else {

                if( j >= (NY+1 -thick_up - thick_down) * charging_ratio + thick_down) {
                    rho[i][j] = rho_v;
                }else{
                    rho[i][j] = rho_l;
                }
                lambda[i][j] = 0.028*rho[i][j];
            }
        }
    }
    //init temperature

    if(RK_flag) {
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
            for (j = 0; j <= NY; j++){
                T[i][j] = T_s;
            }
        }
    }
    //init pressure
    for (i=0;i<=NX;i++)
    {
        for (j = 0; j <= NY; j++)
            if (area[i][j]!=1)
            {
                P[i][j] = peos(rho[i][j], T_s);
            }
    }
    //init distribution function
    for (i = 0; i <= NX; i++) {
        for (j = 0;j <= NY; j++) {
            for (m = 0; m < 2; m++) {
                u[i][j][m]=0;
                f_m[i][j][m]=0;
                f_ads[i][j][m]=0;
                f_b[i][j][m]=0;
                f_total[i][j][m]=0;
            }
            for (k = 0; k < Q; k++) {
                if(area[i][j] != 1) {
                    f[i][j][k]=feq(k,rho[i][j],u[i][j]);
                    F[i][j][k]=f[i][j][k];
                }else {
                    f[i][j][k]=0;
                    F[i][j][k]=0;
                }
            }
        }
    }
}

#endif //LBM_MULTI_FILE_INIT_BOILING_SIMPLE_HPP
