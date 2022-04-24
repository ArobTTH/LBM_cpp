#ifndef LBM_MULTI_FILE_OPTION_HPP
#define LBM_MULTI_FILE_OPTION_HPP

// solver setting
bool    GPU_flag                = false;

// case setting
bool    CA_test_flag            = false;
bool    boiling_simple_flag     = false;
bool    porous_media_flag       = true;

// energy equation setting
bool    RK_flag                 = false;

// force setting
bool    F_b_flag                = false;

// wettability model setting
bool    virtual_density_flag    = false;
bool    wet_flag                = true;



#endif //LBM_MULTI_FILE_OPTION_HPP
