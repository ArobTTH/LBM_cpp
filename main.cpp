#include "src/monitor.hpp"
#include "src/population/population.hpp"
#include "src/initialization/initialization.hpp"
#include "src/output/output.hpp"

int main() {

    initialization();

    for (int n = 0; n <= Nloop; n++) {

        population();

        if (n % Nmonitor == 0) {
            monitor(n);
        }

        if (n % Noutput == 0) {
            output(n);
        }
    }

    return 0;
}
