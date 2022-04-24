#ifndef LBM_MULTI_FILE_MACRO_GPU_HPP
#define LBM_MULTI_FILE_MACRO_GPU_HPP



template<
        int NX, int NY, int Q, typename DataTp, int NY_stride = NY + 1>
__global__ void macroGPU_launcher(
        const DataTp *f_total,
        const DataTp *f,
        const DataTp *T,
        const int *area,
        const int *e,
        DataTp *rho,
        DataTp *lambda,
        DataTp *P,
        DataTp *Psi,
        DataTp *u,
        DataTp *rho_average
) {
    constexpr int threadNY = 32;
    constexpr int threadNX = 4;
    dim3 block(threadNY, threadNX);
    int Nx_blocks = (NX + 1 + threadNX - 1) / threadNX;
    int Ny_blocks = (NY + 1 + threadNY - 1) / threadNY;
    dim3 grid(Ny_blocks, Nx_blocks);

    macroGPU < NX, NY, Q, DataTp ><<<grid, block, 0, 0>>>(
            f_total, f, T, area, e, rho, lambda, P, Psi, u, rho_average);
}

template<
        int NX, int NY, int Q, typename DataTp, int NY_stride = NY + 1>
__device__ void macroGPU(
        const DataTp * f_total,
        const DataTp * f,
        const DataTp * T,
        const int * area,
        const int * e,
        DataTp * rho,
        DataTp * lambda,
        DataTp * P,
        DataTp * Psi,
        DataTp * u,
        DataTp * rho_average,
        int Nx_id, int Ny_id)
{
    if(Nx_id > NX || Ny_id > NY)
        return;
    bool area_flag = area[Nx_id * NY_stride + Ny_id] != 1;
    DataTp rho_reg = rho_s;
    DataTp lambda_reg = lambda_s;
    if(area_flag){
        rho_reg = DataTp(0);
        DataTp P_reg = DataTp(0);
        DataTp Psi_reg = DataTp(0);

        DataTp u_reg[2];
        for(int m = 0; m < 2; m++){
            // FIXME: need to transpose to MxNXxNY
            u_reg[m] = DataTp(0.5f) * f_total[Nx_id * NY_stride * 2 + Ny_id * 2 + m];
        }
        for(int k = 0; k < Q; k++){
            DataTp f_reg = f[Nx_id * NY_stride * Q + Ny_id * Q + k];
            rho_reg += f_reg;
            for(int m = 0; m < 2; m++){
                u_reg[m] += f_reg * e[k * 2 + m];
            }
        }
        for(int m = 0; m < 2; m++){
            u_reg[m] /= rho_reg;

            u[Nx_id * NY_stride *2 + Ny_id * 2 + m] = u_reg[m];
        }

        P_reg = peos_cuda<DataTp>(rho_reg, T[Nx_id * NY_stride + Ny_id]);
        Psi[Nx_id * NY_stride + Ny_id] = psi_cuda<DataTp>(rho_reg, P_reg);
        P[Nx_id * NY_stride + Ny_id] = P_reg;

        lambda_reg = 0.028 * rho_reg;
        atomicAdd(rho_average, rho_reg);


    }
    rho[Nx_id * NY_stride + Ny_id] = rho_reg;
    lambda[Nx_id * NY_stride + Ny_id] = lambda_reg;
}



#endif //LBM_MULTI_FILE_MACRO_GPU_HPP
