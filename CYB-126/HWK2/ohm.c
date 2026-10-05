#include <stdio.h>

int main() {
    double current = 15.0;
    double voltage = 120.0;
    printf("15 amps of current at 120 volts requires %.2f ohms of resistance.\n", voltage / current);
    return 0;
}