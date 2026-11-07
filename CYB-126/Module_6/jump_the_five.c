#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 11 && argc !=8) {
        printf("Please enter 10 or 7 digits individually seperated with spaces\n");
    } else {
        for (int i = 1; i < argc; i++) {
            int digit = atoi(argv[i]);
            if (digit < 0 || digit > 9) {
                printf("\nPlease make sure your digits are between 0 and 9\n");
                return 0;
            }
            if (digit == 0) {
                digit = 5;
            } else if (digit == 5) {
                digit = 0;
            } else {
                digit = 10 - digit;
            }
            printf("%d", digit);
        }
        printf("\n");
    }
    return 0;
}