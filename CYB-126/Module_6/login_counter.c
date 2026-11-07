#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int total_logins = 0;
    for (int i = 1; i < argc; i++) {
        int attempts = atoi(argv[i]);
        if(attempts < 0) {
            printf("Error: Login attempts should be positive.");
            return 0;
        } else {
            total_logins += attempts;
        }
    }
    printf("Total login attempts: %d\n", total_logins);
    if (total_logins > 20) {
        printf("Alert: total exceeds the threshold of 20!");
    }
    return 0;
}