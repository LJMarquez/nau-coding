#include "towerOfHanoi_lib.h"

void initializeTower(int *tower, int *nDisks)
{
    int index;

    for(index = 0; index < TOTAL_DISKS; index++)
    {
        tower[index] = index + 1;
    }

    *nDisks = TOTAL_DISKS;
}

void addDisk(int *tower, int *nDisks, int disk)
{
    int index;

    for(index = *nDisks; index > 0; index--)
    {
        tower[index] = tower[index - 1];
    }

    tower[0] = disk;
    *nDisks = *nDisks + 1;
}

int getDisk(int *tower, int *nDisks)
{
    int index;
    int topDisk;

    if(*nDisks == 0)
    {
        return EMPTY_VALUE;
    }

    topDisk = tower[0];

    for(index = 1; index < *nDisks; index++)
    {
        tower[index - 1] = tower[index];
    }

    tower[*nDisks - 1] = EMPTY_VALUE;
    *nDisks = *nDisks - 1;

    return topDisk;
}

void moveDisk(int *sourceTower, int *destinationTower, int *nDisksSource,
              int *nDisksDest)
{
    int disk;

    if(*nDisksSource == 0)
    {
        disk = getDisk(destinationTower, nDisksDest);
        addDisk(sourceTower, nDisksSource, disk);
    }
    else if(*nDisksDest == 0 || sourceTower[0] < destinationTower[0])
    {
        disk = getDisk(sourceTower, nDisksSource);
        addDisk(destinationTower, nDisksDest, disk);
    }
    else
    {
        disk = getDisk(destinationTower, nDisksDest);
        addDisk(sourceTower, nDisksSource, disk);
    }
}

int getTotalMoves()
{
    return (int)pow(2, TOTAL_DISKS) - 1;
}

void towerOfHanoi(int *sourceTower, int *auxTower, int *destinationTower, int *nDisksSource, int *nDisksAux, int *nDisksDest)
{
    int moveCount;
    int totalMoves = getTotalMoves();

    for(moveCount = 1; moveCount <= totalMoves; moveCount++)
    {
        if(moveCount % TOTAL_DISKS == 0)
        {
            moveDisk(auxTower, destinationTower, nDisksAux, nDisksDest);
        }
        else if(moveCount % TOTAL_DISKS == 1)
        {
            moveDisk(sourceTower, destinationTower, nDisksSource, nDisksDest);
        }
        else
        {
            moveDisk(sourceTower, auxTower, nDisksSource, nDisksAux);
        }

        printTower(sourceTower, auxTower, destinationTower, *nDisksSource, *nDisksAux, *nDisksDest);
    }
}

void printTower(const int *sourceTower, const int *auxTower, const int *destinationTower, const int nDisksSource, const int nDisksAux, const int nDisksDest)
{
    int index;

    printf("\nsrc   aux   dst\n");
    printf("===============\n");

    for(index = 0; index < TOWER_SIZE; index++)
    {
        if(index < nDisksSource)
        {
            printf(" %d ", sourceTower[index]);
        }
        else
        {
            printf("   ");
        }

        printf("| ");

        if(index < nDisksAux)
        {
            printf(" %d ", auxTower[index]);
        }
        else
        {
            printf("   ");
        }

        printf("| ");

        if(index < nDisksDest)
        {
            printf(" %d   ", destinationTower[index]);
        }
        else
        {
            printf("  ");
        }

        printf("\n");
    }

    printf("\n");
}
