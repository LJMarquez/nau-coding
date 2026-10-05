#include <stdio.h>
#include <math.h>

int main() {
    int seconds = 8675309;
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;
    int hours = minutes / 60;
    int remainingMinutes = minutes % 60;
    int days = hours / 24;
    int remainingHours = hours % 24;

    printf("There are %d days, %d hours, %d minutes, and %d seconds in %d seconds.\n", days, remainingHours, remainingMinutes, remainingSeconds, seconds);

    return 0;
}