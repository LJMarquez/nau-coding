#include <stdio.h>

int main() {
    int packet_count = 5;
    double total_size = 0.0;

    printf("Enter the sizes of five packets in bytes:\n");
    for (int index = 0; index < packet_count; index++) {
        double packet_size;
        printf("Packet %d: ", index + 1);
        scanf("%lf", &packet_size);
        total_size += packet_size;
    }

    printf("\nAverage packet size: %.2f bytes\n", total_size / packet_count);
    return 0;
}