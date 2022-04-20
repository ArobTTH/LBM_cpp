#ifndef LBM_MULTI_FILE_STREAMING_HPP
#define LBM_MULTI_FILE_STREAMING_HPP


void streaming () {

    int i,j,k,ip,jp;

    for (i=0;i<=NX;i++)
    {
        for (j=0;j<=NY;j++)
        {
            for (k=0;k<Q;k++)
            {
                ip=i-e[k][0];
                jp=j-e[k][1];
                wrap(ip,jp);
                /*if(area[i][j]!=1 && area[ip][jp]!=1)*/
                f[i][j][k]=F[ip][jp][k];
            }
        }
    }

}

#endif //LBM_MULTI_FILE_STREAMING_HPP
