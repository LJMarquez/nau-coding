
// header files
#include "mosaic_lib.h"

using namespace std;

// main program
int main()
{
    // set seed for random number generation
        // functions: srand, time
    srand(time(nullptr));

    // declare and initialize the degraded mural data
    int unityData[SIZE][SIZE] =
    {
        {12, 3, 7, 14, 5, 8},
        {9, 16, 11, 0, 2, 18},
        {21, 4, 13, 22, 6, 19},
        {15, 10, 24, 20, 3, 17},
        {8, 26, 28, 1, 23, 30},
        {31, 0, 34, 33, 29, 25}
    };

    int victoryData[SIZE][SIZE] =
    {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };

    // create Mosaic objects using the constructor
    Mosaic muralOfUnity(unityData);
    Mosaic muralOfVictory(victoryData);

    // print an explanation to the problem
    cout << endl << "Dear Art Conservator, the Mural of Unity and the Mural of Victory" << endl;
    cout << " need your help! Please restore the murals, the stories of Azura" << endl;
    cout << "depend on you!" << endl << endl;
    cout << "=================================================================" << endl << endl;

    // print the degraded mural of unity
        // methods: cout, printMatrix
    cout << "Degraded Mural of Unity:" << endl;
    muralOfUnity.printMatrix();

    // Task 1: reordering the mosaic tiles to order them properly
        // method: transpose
    muralOfUnity.transpose();
    // print the semi-restored mural
        // methods: cout, printMatrix
    cout << endl << "Mural of Unity after reordering the titles:" << endl;
    muralOfUnity.printMatrix();

    // Task 2: rotating the tiles to reorder them
        // method: rotate
    muralOfUnity.rotate();
    // print the semi-restored mural
        // methods: cout, printMatrix
    cout << endl << "Mural of Unity after rotating titles:" << endl;
    muralOfUnity.printMatrix();

    // Task 3: where there is blank titles, clean its row and column
        // method: zeroMatrix
    muralOfUnity.zeroMatrix();
    // print the restored mural
        // methods: cout, printMatrix
    cout << endl << "Mural of Unity after cleaning dirty titles:" << endl;
    muralOfUnity.printMatrix();

    // print a congratulations message
        // function: cout
    cout << endl << "Congratulations! You restored the Mural of Unity!" << endl;
    cout << endl << "Now, let's work on the Mural of Victory!" << endl;

    // print the degraded murals
        // methods: cout, printMatrix
    cout << "Degraded Mural of Victory:" << endl;
    muralOfVictory.printMatrix();

    // Task 4: rotate a part of the mosaic by k steps
        // method: rotateRow
    muralOfVictory.rotateRow(STEPS);

    // print the restored mural
        // methods: cout, printMatrix
    cout << endl << "Mural after rotating a particular row:" << endl;
    muralOfVictory.printMatrix();

    // print a congratulations message
        // function: cout
    cout << endl << "Congratulations! You restored the Mural of Victory!" << endl;
    cout << "You can now unveil its secret by reading the spiral message!" << endl;

    // Task 5: generate the message of the tiles in spiral order
        // method: spiralOrder
    int* spiral = muralOfVictory.spiralOrder();

    // print the message
        // method: cout
    cout << endl << "The secret from the Mural of Victory:" << endl;
        // traverse the array
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        // print the message
            // method: cout
        cout << spiral[i] << " ";
    }
    // cosmetic
    cout << endl;

    // deallocate dynamically allocated memory
    delete[] spiral;
    return 0;
}
