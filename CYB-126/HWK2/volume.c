#include <stdio.h>
#include <math.h>

int main() {
    int edge = 5;
    double volume = ((5 * (3 + sqrt(5))) / 12) * pow(edge, 3);
    printf("The volume of a dodecahedron with edge length %d is %.2lf units cubed.\n", edge, volume);
    return 0;
}