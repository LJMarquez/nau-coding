#include "towerOfHanoi_lib.h"

int main()
{
    int sourceTower[TOWER_SIZE] = {EMPTY_VALUE};
    int auxTower[TOWER_SIZE] = {EMPTY_VALUE};
    int destinationTower[TOWER_SIZE] = {EMPTY_VALUE};

    int nDisksSource = 0;
    int nDisksAux = 0;
    int nDisksDest = 0;

    printf("Welcome to Tower of Hanoi!\n");
    printf("===============================\n");

    initializeTower(sourceTower, &nDisksSource);
    printTower(sourceTower, auxTower, destinationTower,
        nDisksSource, nDisksAux, nDisksDest);

    towerOfHanoi(sourceTower, auxTower, destinationTower,
        &nDisksSource, &nDisksAux, &nDisksDest);

    printf("\nSimulation ended.\n");

    return 0;
}