#ifndef LBM_MULTI_FILE_PARAMETER_HPP
#define LBM_MULTI_FILE_PARAMETER_HPP

// D2Q9
constexpr unsigned int    NX           =  300;
constexpr unsigned int    NY           =  100;
constexpr unsigned int    Q            =  9;

// output
constexpr unsigned int    Nloop       =  2000;
constexpr unsigned int    Noutput     =  2000;
constexpr unsigned int    Nmonitor    =  100;

// MRT
constexpr double    rho_l       =  6.4989;
constexpr double    rho_v       =  0.3797;
constexpr double    rho_a       =  ((rho_l + rho_v)/2);
constexpr double    rho_s       =  10;
constexpr double    nu_l        =  0.1;
constexpr double    nu_v        =  (0.5/3);
constexpr double    tau_l       =  (3*nu_l + 0.5);
constexpr double    tau_v       =  (3*nu_v + 0.5);
constexpr double    tau_e       =  (1.0/1.1);
constexpr double    tau_t       =  (1.0/1.1);

// SC model
constexpr double    G           =  (-1.0);
constexpr double    Gw          =  -0.3;
constexpr double    sigma       =  0.11;
constexpr double    phi         =  1.1;
constexpr double    delta_rho   =  0.3;


// PR
constexpr double    PR_omega    =  0.344;
constexpr double    PR_a        =  0.06122448;
constexpr double    PR_b        =  0.09523809;
constexpr double    PR_R        =  1.0;

// Temperature
constexpr double    Tc          =  0.109382994;
constexpr double    T_rate      =  0.86;

#endif //LBM_MULTI_FILE_PARAMETER_HPP
