#include <stdio.h>
#include <math.h>

int main() {
    int a = 2;
    int b = 4;
    int c = 3;
    double discriminant = pow(b, 2) - 4 * a * c;

    if (discriminant < 0) {
        printf("The equation %dx^2 + %dx + %d has no real roots.\n", a, b, c);
    } else {
        double result1 = (-b + sqrt(discriminant)) / (2 * a);
        double result2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The roots of the equation %dx^2 + %dx + %d are %.2lf and %.2lf.\n", a, b, c, result1, result2);
    }

    return 0;
}