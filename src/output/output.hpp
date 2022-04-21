#ifndef LBM_MULTI_FILE_OUTPUT_HPP
#define LBM_MULTI_FILE_OUTPUT_HPP

#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <sstream>

#include "../../src/parameter.hpp"
#include "../../src/global_variable.hpp"
#include "../../src/option.hpp"
#include "output_CA_test.hpp"
#include "output_boiling_simple.hpp"

using namespace std;

void output(int n) {

    int i,j;

    ostringstream filename;

    if (CA_test_flag) {
        filename = CATest();
    }

    if (boiling_simple_flag) {
        filename = boilingSimple(n);
    }

    string output_name = "../data/" + filename.str();
    ofstream out (output_name);
    //ofstream out (filename.str().c_str());
    out << "TITLE = \"Tecplot Data\"" << "\n"
        << "VARIABLES = \"X\",\"Y\",\"rho\",\"P\",\"T\",\"AREA\",\"u\",\"v\",\"fx\",\"fy\"\n"
        << "ZONE T= \"Zone " << n / 1000 << "\", J=" << NX+1 << ", I=" << NY+1 << ", F=POINT\n";
    for(i=0; i<=NX; i++)
    {
        for(j=0; j<=NY; j++)
        {

            if (area[i][j] == 1) {
                rho[i][j] = rho_s;
            }

            out
                    << i << "\t"
                    << j << "\t"
                    << rho[i][j] << "\t"
                    << P[i][j] << "\t"
                    << T[i][j] << "\t"
                    << area[i][j] << "\t"
                    << u[i][j][0] << "\t"
                    << u[i][j][1] << "\t"
                    << f_total[i][j][0] << "\t"
                    << f_total[i][j][1] << "\t"
                    << endl;

        }
    }

}

#endif //LBM_MULTI_FILE_OUTPUT_HPP
