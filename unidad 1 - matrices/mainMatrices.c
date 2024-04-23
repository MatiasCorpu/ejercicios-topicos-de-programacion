#include <stdio.h>
#include <stdlib.h>

#include "matrices.h"
#include "matrices.c"

int main()
{   
    int rows = MAX_COLUMNS;
    int columns = MAX_COLUMNS;
    
    const int squareMatrix[][MAX_COLUMNS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
    };

    const int diagonalMatrix[][MAX_COLUMNS] = {
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1},
    };

    const int simetricalMatrix[][MAX_COLUMNS] = {
        {1, 2, 3, 4, 5},
        {2, 7, 8, 9, 10},
        {3, 8, 13, 14, 15},
        {4, 9, 14, 19, 20},
        {5, 10, 15, 20, 25},
    };

    int matrixEmpty[MAX_COLUMNS][MAX_COLUMNS] = {{0}};

    //showMatrix(squareMatrix, 5, 5);

    //printf("\nLa sumatoria de los numeros por encima de la diagonal principal con esta excluida: %d\n", sumMainDiagonal(squareMatrix, MAX_COLUMNS, MAX_COLUMNS));

    //printf("\nLa sumatoria de los numeros por encima de la diagonal principal con esta excluida: %d\n", sumAboveMainDiagonal(squareMatrix, MAX_COLUMNS, MAX_COLUMNS));

    //printf("\nLa sumatoria de los numeros por encima de la diagonal principal con esta excluida: %d\n", sumBelowMainDiagonal(squareMatrix, MAX_COLUMNS, MAX_COLUMNS));

    //printf("\nLa sumatoria de los numeros por encima de la diagonal principal con esta excluida: %d\n", sumSecondaryDiagonal(squareMatrix, MAX_COLUMNS));

    //if(isDiagonalMatrix(diagonalMatrix, MAX_COLUMNS, MAX_COLUMNS)) printf("\nEs una matriz diagonal"); else printf("\nNo es una matriz diagonal");

    //if(isIdentityMatrix(diagonalMatrix , MAX_COLUMNS, MAX_COLUMNS)) printf("\nEs una matriz identidad"); else printf("\nNo es una matriz identidad");

    //if(isSymmetricMatrix(simetricalMatrix , MAX_COLUMNS)) printf("\nEs una matriz simetrica"); else printf("\nNo es una matriz simetrica");

    //transposeMatrixInSitu(squareMatrix, MAX_COLUMNS); showMatrix(squareMatrix, MAX_COLUMNS, MAX_COLUMNS);

    //transposeMatrix(squareMatrix, matrixEmpty, MAX_COLUMNS); showMatrix(matrixEmpty , MAX_COLUMNS, MAX_COLUMNS);
    
    
    const int matrixA[4][3] = {
        {1, 2, 3},
        {6, 7, 8},
        {11, 12, 13},
        {16, 17, 18},
    };

    const int matrixB[3][2] = {
        {1, 2},
        {6, 7},
        {11, 12},
    };
   
    int matResult[4][2]; 
    
    //multiplyMatrices(matrixA, 4, 3, matrixB, 3, 2, matResult); para mostrar la matriz tendria que hacer las matrices con memoria dinamica


    const int matrixPoints[][MAX_COLUMNS] = {
        {0,0,0,3,0},
        {0,0,1,0,0},
        {1,1,0,0,0},
        {3,0,1,0,1},
        {0,3,0,3,0},
    };

    //if(validateScoreMatrix(matrixPoints, MAX_COLUMNS, MAX_COLUMNS)) printf("Es una matriz valida\n"); else printf("No es una matriz valida\n");

    return 0;
}