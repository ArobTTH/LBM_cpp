#ifndef LBM_MULTI_FILE_OPTION_HPP
#define LBM_MULTI_FILE_OPTION_HPP

// case setting
bool    CA_test_flag            = false;
bool    boiling_simple_flag     = false;
bool    porous_media_flag       = true;

// energy equation setting
bool    RK_flag                 =  true;

// force setting
bool    F_b_flag                = false;

// wettability model setting
bool    wet_flag                = false;
bool    virtual_density_flag    = true;


#endif //LBM_MULTI_FILE_OPTION_HPP
