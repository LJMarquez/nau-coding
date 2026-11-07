#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc == 2) {
        int previous1 = 0;
        int previous2 = 1;
        int result;
        int n = atoi(argv[1]);
        if (n < 0) {
            printf("Please enter a positive number.\n");
        } else if (n == 0) {
            printf("The %dth term of the fibonacci sequence is %d.\n", n, previous1);
        } else if (n == 1) {
            printf("The %dth term of the fibonacci sequence is %d.\n", n, previous2);
        } else {
            for (int i = 2; i <= n; i++) {
                result = previous1 + previous2;
                previous1 = previous2;
                previous2 = result;
            }
            printf("The %dth term of the fibonacci sequence is %d.\n", n, result);
        }
    } else {
        printf("Please enter only 1 argument into the command line.\n");
    }

    return 0;
}