#include <stdio.h>

int main() {
    int password = 1234;
    int attempts = 1;

    for(int i = 0; i <= 9999; i++) {
        if(i == password) {
            printf("Password found: %d\n", i);
            break;
        }
        attempts++;
    }
    printf("Total attempts: %d\n", attempts);
    if(attempts > 9999) {
        printf("Password not found\n");
    }
}