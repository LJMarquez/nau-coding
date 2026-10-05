#include <stdio.h>
#include <math.h>

int main() {
    int years = 3;
    int weeks = 6;
    int days = 5;
    int hours = 2;
    int minutes = 5;

    int totalSeconds = (years * 365 * 24 * 60 * 60) + (weeks * 7 * 24 * 60 * 60) + (days * 24 * 60 * 60) + (hours * 60 * 60) + (minutes * 60);

    printf("The total number of seconds in %d years, %d weeks, %d days, %d hours, and %d minutes is %d.\n", years, weeks, days, hours, minutes, totalSeconds);

    return 0;
}