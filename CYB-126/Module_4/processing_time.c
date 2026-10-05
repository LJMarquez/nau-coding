#include <stdio.h>

int main() {
    int packet_count = 5;
    double processing_speed = 0.5;
    double packet_sizes[packet_count];

    printf("Enter the sizes of five packets in bytes:\n");
    for (int i = 0; i < packet_count; i++) {
        double packet_size;
        printf("Packet %d: ", i + 1);
        scanf("%lf", &packet_size);
        packet_sizes[i] = packet_size;
    }
    printf("\n");

    for (int i = 0; i < packet_count; i++) {
        double processing_time = packet_sizes[i] * processing_speed;
        printf("Packet %d: %.2f milliseconds\n", i + 1, processing_time);
    }

    return 0;
}
