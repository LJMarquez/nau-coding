#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    double step = 1.0;
    if (argc < 3 || argc > 4) {
        printf("Please enter (in farenheit) a starting temp, and ending temp, and a step size (optional).");
    } else {
        double startTemp = atof(argv[1]);
        double endTemp = atof(argv[2]);
        if (argc == 4) {
            step = atof(argv[3]);
        }
        while (startTemp <= endTemp) {
            double celsius = (startTemp - 32.0) * (5.0/9.0);
            printf("%.1lf\t%.1lf\n", startTemp, celsius);
            startTemp += step;
        }
    }
    return 0;
}