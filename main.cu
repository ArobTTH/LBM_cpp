#include "src/monitor.hpp"
#include "src/population/population.hpp"
//#include "src/population_gpu/population_gpu.hpp"
#include "src/initialization/initialization.hpp"
#include "src/output/output.hpp"

using DataTp = double;

int main() {

    initialization();

    for (int n = 0; n <= Nloop; n++) {

        if (!GPU_flag) {
            population();

            if (n % Nmonitor == 0) {
                monitor(n);
            }

            if (n % Noutput == 0) {
                output(n);
            }
        }
    }
    return 0;
}