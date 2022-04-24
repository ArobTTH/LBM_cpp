#ifndef LBM_MULTI_FILE_PARAMETER_HPP
#define LBM_MULTI_FILE_PARAMETER_HPP
//D2Q9
constexpr unsigned int    Q                      =  9;

// grid
constexpr unsigned int    NX                     =  800;
constexpr unsigned int    NY                     =  400;
constexpr unsigned int    thick_up               =  20;
constexpr unsigned int    thick_down             =  20;
constexpr unsigned int    heating_section        =  100;
constexpr double          charging_ratio         =  0.5;

//heat flux
constexpr double          q                      =  (-1.86*0.0001*25);

// output
constexpr unsigned int    Nloop       =  200000;
constexpr unsigned int    Noutput     =  1000;
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
constexpr double    Gw          =  0.4;
constexpr double    sigma       =  0.11;
constexpr double    phi         =  1.5;
constexpr double    delta_rho   =  0.8;

// PR
constexpr double    PR_omega    =  0.344;
constexpr double    PR_a        =  0.06122448;
constexpr double    PR_b        =  0.09523809;
constexpr double    PR_R        =  1.0;

// Temperature
constexpr double    Tc          =  0.109382994;
constexpr double    T_rate      =  0.86;
constexpr double    T_s         =  (T_rate*Tc);
constexpr double    T_b         =  (T_s + 0.0137);
constexpr double    T_u         =  (0.85*Tc);

// Physical parameters
constexpr double    cv          =  6.0;
constexpr double    lambda_s    =  (rho_l*0.028*1);
constexpr double    h_fg        =  (0.5702);
constexpr double    g           =  (3*0.00001);

#endif //LBM_MULTI_FILE_PARAMETER_HPP
