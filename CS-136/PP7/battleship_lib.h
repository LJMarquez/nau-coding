#ifndef BATTLESHIP_LIB_H
#define BATTLESHIP_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10
#define N_SHIPS 10
#define WATER_SOLUTION '0'
#define WATER_GAME 'W'
#define SHIP_GAME 'S'
#define HIDDEN_SHIP_GAME '_'
#define GIVE_UP -1
#define HORIZONTAL 0
#define VERTICAL 1
#define CRUISER 2
#define SUBMARINE 3
#define DESTROYER 3
#define BATTLESHIP 4
#define AIRCRAFT_CARRIER 5

void initializeRandom();

void printMatrix(const char matrix[SIZE][SIZE]);

void buildBoard(char board[SIZE][SIZE], char character);

bool isWater(const char solution[SIZE][SIZE], int row, int col);

void placeShipHorizontal(char solution[SIZE][SIZE], int shipLength);

void placeShipVertical(char solution[SIZE][SIZE], int shipLength);

void fillBoard(char solution[SIZE][SIZE]);

void shoot(const char solution[SIZE][SIZE], char game[SIZE][SIZE], int row, int col);

bool checkVictory(const char solution[SIZE][SIZE], const char game[SIZE][SIZE]);

#endif