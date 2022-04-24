#ifndef LBM_MULTI_FILE_PARAMS_HPP
#define LBM_MULTI_FILE_PARAMS_HPP

template<typename DataTp>
struct Params{
    // params for Streaming and Boundary
    DataTp * tensor_F;
    DataTp * tensor_f;
    int * tensor_area;
    int * tensor_e;
    int * tensor_bb;
    // Additional params for Temperature
    DataTp * tensor_T;
    DataTp * tensor_Temp;
    DataTp * tensor_h1;
    DataTp * tensor_h2;
    DataTp * tensor_h3;
    DataTp * tensor_h4;
    DataTp * tensor_lambda;
    DataTp * tensor_u;
    DataTp * tensor_rho;
    // Additional params for DensityPressureVelocityLambda
    DataTp * tensor_f_total;
    DataTp * tensor_P;
    DataTp * tensor_Psi;
    // Additional params for VisualDensity
    DataTp * tensor_w2;
    DataTp * tensor_rhow;
    // Additional params for Force update
    DataTp * tensor_mf;
    DataTp * tensor_s1;
    DataTp * tensor_s2;
    DataTp * tensor_Mre;
    DataTp * tensor_M0;
    int      cnt;
    DataTp * tensor_rho_average_gpu;
    DataTp * tensor_fb;
    DataTp * tensor_fm;
};

#endif //LBM_MULTI_FILE_PARAMS_HPP
