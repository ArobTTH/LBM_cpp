#ifndef LBM_MULTI_FILE_OUTPUT_BOILING_SIMPLE_HPP
#define LBM_MULTI_FILE_OUTPUT_BOILING_SIMPLE_HPP

ostringstream boilingSimple(int n) {

    int i;

    ostringstream name;

    const int a[] = {10,100,1000,10000,100000,1000000,10000000,100000000};
    int b[8];
    for(i = 0; i < 8; i++)
    {
        b[i]=n % a[i] / (a[i] / 10);
    }
    name << "boiling_simple_"
         << b[7] << b[6] << b[5] << b[4] << b[3] << b[2] << b[1] << b[0]
         << ".dat";

    return name;
}

#endif //LBM_MULTI_FILE_OUTPUT_BOILING_SIMPLE_HPP
