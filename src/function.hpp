#ifndef LBM_MULTI_FILE_FUNCTION_HPP
#define LBM_MULTI_FILE_FUNCTION_HPP

#include <cmath>
#include <iostream>
#include "global_variable.hpp"
#include "parameter.hpp"

void wrap(int &ip, int &jp)
{
    if (ip==NX+1)
        ip=0;
    if (ip==NX+2)
        ip=1;
    if (ip==-1)
        ip=NX;
    if (ip==-2)
        ip=NX-1;

    if (jp==NY+1)
        jp=0;
    if (jp==NY+2)
        jp=1;
    if (jp==-1)
        jp=NY;
    if (jp==-2)
        jp=NY-1;
}

double feq(int k, double Rho, const double U[2])
{
    double eu, uv, feq;
    eu= (e[k][0]*U[0]+e[k][1]*U[1]);
    uv= (U[0]*U[0]+U[1]*U[1]);
    feq=w[k]*Rho*(1.0+3.0*eu+4.5*eu*eu-1.5*uv);
    return feq;
}

double meq(int k, double Rho, const double U[2])
{
    double meq;
    if (k==0)
        meq=1;
    if (k==1)
        meq=-2.+3*(U[1]*U[1]+U[0]*U[0]);
    if (k==2)
        meq=1.-3*(U[1]*U[1]+U[0]*U[0]);
    if (k==3)
        meq=U[0];
    if (k==4)
        meq=-U[0];
    if (k==5)
        meq=U[1];
    if (k==6)
        meq=-U[1];
    if (k==7)
        meq=(U[0]*U[0]-U[1]*U[1]);
    if (k==8)
        meq=U[0]*U[1];
    return Rho*meq;
}

double forceeq(int k, const double force[2], const double U[2], double psi)
{
    double feq;
    double f2 = (force[0]*force[0])+(force[1]*force[1]);

    if (k==0)
        feq=0;
    if (k==1)
        feq=(6.0*(U[0]*force[0]+U[1]*force[1]))
            +(12*sigma*f2/((psi * psi)*(tau_e-0.5)));
    if (k==2)
        feq=(-6.0*(U[0]*force[0]+U[1]*force[1]))
            -(12*sigma*f2/((psi * psi))*(tau_t-0.5));
    if (k==3)
        feq=force[0];
    if (k==4)
        feq=-force[0];
    if (k==5)
        feq=force[1];
    if (k==6)
        feq=-force[1];
    if (k==7)
        feq=2.0*(U[0]*force[0]-U[1]*force[1]);
    if (k==8)
        feq=U[0]*force[1]+U[1]*force[0];

    return feq;
}

double psi(double Rho, double Pressure)
{
//    if ((Rho/3-Pressure)<0)
//		printf("warning: check psi!\n");

    double psi = sqrt(2*(Pressure-Rho/3)/G);
    return psi;
}

double peos(double Rho, double Temper)
{
    double phiT = pow( 1 + (0.37464 + 1.54226 *PR_omega -
                            0.26992 * PR_omega*PR_omega)*(1-sqrt(Temper/Tc)),2);

    double p = (Rho*PR_R*Temper)/(1-PR_b*Rho)
               - (PR_a*phiT*Rho*Rho)/(1+2*PR_b*Rho-PR_b*PR_b*Rho*Rho);
    return p;
}

#endif //LBM_MULTI_FILE_FUNCTION_HPP
