#ifndef LBM_MULTI_FILE_POPULATION_GPU_HPP
#define LBM_MULTI_FILE_POPULATION_GPU_HPP

#include "../../src/parameter.hpp"
#include "../../src/global_variable.hpp"
#include "../../src/function.hpp"
#include "../../src/option.hpp"

#include "boundary_gpu.hpp"
#include "collision_gpu.hpp"
#include "energy_gpu.hpp"
#include "force_gpu.hpp"
#include "macro_gpu.hpp"
#include "streaming_gpu.hpp"

#include "../../src/help/help.hpp"
#include "../../src/help/params.hpp"


template<int NX, int NY, int Q, typename DataTp>
void populationGPU(Params<DataTp> params) {

//    macroGPU_launcher< NX, NY, Q, DataTp> (
//            param.tensor_f_total,
//            param.tensor_f,
//            param.tensor_T,
//            param.tensor_area,
//            param.tensor_e,
//            param.tensor_rho,
//            param.tensor_lambda,
//            param.tensor_P,
//            param.tensor_Psi,
//            param.tensor_u,
//            param.tensor_rho_average_gpu
//    );

    forceGPU();

    collisionGPU();

    streamingGPU();

    boundaryGPU();

    //RKGPU();
}

#endif //LBM_MULTI_FILE_POPULATION_GPU_HPP
