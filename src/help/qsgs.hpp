#ifndef LBM_MULTI_FILE_QSGS_HPP
#define LBM_MULTI_FILE_QSGS_HPP

#include <random>
#include <iostream>

#include "../../src/parameter.hpp"
#include "../../src/global_variable.hpp"
#include "../../src/option.hpp"

#define     cdd             0.0001
#define     targetPorosity  0.7
#define     totalPoint      ((NX+1)*(NY+1))
#define     d1              0.025
#define     d2              0.025
#define     d3              0.025
#define     d4              0.025
#define     d5              0.025
#define     d6              0.025
#define     d7              0.025
#define     d8              0.025

int solidCoo_x[totalPoint];
int solidCoo_y[totalPoint];

using namespace std;

double randNumGen()
{
    mt19937 rng(random_device{}());
    uniform_real_distribution<double> result(0.0, 1.0);
    return result(rng);
}

void quartetStructureGenerationSet() {
    int i,j,node;

    int currentSolidNum;
    int solidNum = 0;
//    int solidCoo_x[totalPoint];
//    int solidCoo_y[totalPoint];
    double solidNumMax =  (double)(1-targetPorosity)*(NX+1)*(NY+1);
    double currentPorosity;


    for (i=0;i<=NX;i++) {
        for (j=0;j<=NY;j++) {
            area[i][j]=0;
        }
    }

    for(i=0;i<totalPoint;i++) {
        solidCoo_x[i] = -1;
        solidCoo_y[i] = -1;
    }

    for (i=0;i<=NX;i++) {
        for (j=0;j<=NY;j++) {
            if(randNumGen()<cdd) {
                area[i][j] = 1;
                solidCoo_x[solidNum] = i;
                solidCoo_y[solidNum] = j;
                solidNum++;
            }
        }
    }


    currentSolidNum = solidNum;
    cout << "core number" <<currentSolidNum << endl;
    currentPorosity = 1 - (double)currentSolidNum / totalPoint;
    cout << "porosity" << currentPorosity << endl;


    while (currentSolidNum < solidNumMax) {
        for(node =0; node < currentSolidNum && currentSolidNum < solidNumMax; node++) {

            i = solidCoo_x[node];
            j = solidCoo_y[node];


            for(int k=1; k<=8;k++) {
                switch(k) {
                    case 1: {
                        if(i+1 <=NX && area[i+1][j]==0 && randNumGen()<d1) {
                            area[i+1][j] = 1;
                            solidNum++;
                            solidCoo_x[solidNum] = i+1;
                            solidCoo_y[solidNum] = j;
                        }
                    }

                    case 2: {
                        if(j+1 <=NY && area[i][j+1]==0 && randNumGen()<d2) {
                            area[i][j+1] = 1;
                            solidNum++;
                            solidCoo_x[solidNum] = i;
                            solidCoo_y[solidNum] = j+1;
                        }
                    }
                    case 3: {
                        if(i-1 >=0 && area[i-1][j]==0 && randNumGen()<d3) {
                            area[i-1][j] = 1;
                            solidNum++;
                            solidCoo_x[solidNum] = i-1;
                            solidCoo_y[solidNum] = j;
                        }
                    }
                    case 4: {
                        if(j-1 >=0 && area[i][j-1]==0 && randNumGen()<d4) {
                            area[i][j-1] = 1;
                            solidNum++;
                            solidCoo_x[solidNum] = i;
                            solidCoo_y[solidNum] = j-1;
                        }
                    }
                    case 5: {
                        if(i+1 <=NX && j+1<=NY && area[i][j+1]==0 && randNumGen()<d5) {
                            area[i+1][j+1] = 1;
                            solidNum++;
                            solidCoo_x[solidNum] = i+1;
                            solidCoo_y[solidNum] = j+1;
                        }
                    }
                    case 6: {
                        if(i-1 >=0 && j+1<=NY && area[i-1][j+1]==0 && randNumGen()<d6) {
                            area[i-1][j+1] = 1;
                            solidNum++;
                            solidCoo_x[solidNum] = i-1;
                            solidCoo_y[solidNum] = j+1;
                        }
                    }
                    case 7: {
                        if(i-1 >=0 && j-1>=0 && area[i-1][j-1]==0 && randNumGen()<d7) {
                            area[i-1][j-1] = 1;
                            solidNum++;
                            solidCoo_x[solidNum] = i-1;
                            solidCoo_y[solidNum] = j-1;
                        }
                    }
                    case 8: {
                        if(i+1 <=NX && j-1>=0 && area[i+1][j-1]==0 && randNumGen()<d8) {
                            area[i+1][j-1] = 1;
                            solidNum++;
                            solidCoo_x[solidNum] = i+1;
                            solidCoo_y[solidNum] = j-1;
                        }
                    }
                        break;

                    default: cout<<"qsgs error!"<<endl;
                }
            }

            currentSolidNum = solidNum;
        }
    }
    currentPorosity = 1- (double)currentSolidNum / totalPoint;
    cout << "current porosity" << currentPorosity << endl;
}

#endif //LBM_MULTI_FILE_QSGS_HPP
