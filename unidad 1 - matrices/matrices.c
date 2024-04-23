/*
Ejercicio 1.12
Desarrollar una función para que, dada una matriz cuadrada de reales de orden N, obtenga la sumatoria de los elementos que están por encima de la diagonal principal (excluida ésta). Lo mismo para la diagonal secundaria. Lo mismo incluyendo la diagonal. Lo mismo, con los que están por debajo de la diagonal.

Ejercicio 1.13
Desarrollar una función para que, dada una matriz cuadrada de enteros de orden N, obtenga la traza de la misma (sumatoria de los elementos de la diagonal principal). Lo mismo, pero con la diagonal secundaria.

Ejercicio 1.14
Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es matriz diagonal (ceros en todos sus elementos excepto en la diagonal principal).

Ejercicio 1.15
Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es matriz identidad (matriz diagonal, con unos en la diagonal principal y ceros en los restantes).

Ejercicio 1.16
Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es simétrica.

Ejercicio 1.17
Desarrollar una función para trasponer, in situ, una matriz cuadrada.

Ejercicio 1.18
Desarrollar una función para obtener la traspuesta de una matriz dada.

Ejercicio 1.19
Desarrollar una función para obtener la matriz producto entre dos matrices de enteros.

Ejercicio 1.20
Se dispone de una matriz cuadrada de enteros de orden N, donde cada elemento [i][j] representa la cantidad de puntos que obtuvo el equipo i frente al equipo j al fin de un torneo de fútbol (partidos de ida y vuelta) en el que participaron N equipos. El sistema de puntuación es: 3 puntos para el ganador del partido y ninguno para el perdedor; 1 punto para cada equipo en caso de empate.
Desarrollar una función que determine si la matriz está correctamente generada.
Desarrollar una función que genere un arreglo de N elementos tal que cada elemento V[k] contenga
la cantidad de puntos obtenidos por el equipo k.
*/
#include "matrices.h"

void showMatrix( int matrix[][MAX_COLUMNS], const int rows , const int columns)
{
    for(int i = 0; i < rows; i++)
    {   
        printf("\n");
        for(int j = 0; j < columns; j++)
            printf("%5.d", matrix[i][j]);
    }
}

int sumMainDiagonal(const int matrix[][MAX_COLUMNS], const int rows , const int columns)
{
    int sum = 0;

    for(int i = 0; i < rows; i++)
        sum += matrix[i][i];

    return sum;
}

int sumAboveMainDiagonal(const int matrix[][MAX_COLUMNS], const int rows, const int columns)
{
    int sum = 0;

    for(int i = 0; i < rows; i++)
        for(int j = i + 1; j < columns; j++)
            sum += matrix[i][j];

    return sum;
}

int sumBelowMainDiagonal(const int matrix[][MAX_COLUMNS], const int rows, const int columns)
{
    int sum = 0;

    for(int i = 1 ; i < rows; i++)
        for(int j = 0 ; j < i ; j++)
            sum = matrix[i][j];

    return sum;
}

int sumSecondaryDiagonal(const int matrix[][MAX_COLUMNS], const int columns)
{
    int sum = 0;

    for(int i = 0 ; i < columns; i++)
    {
        printf("\nvoy a suma = %d\n",matrix[i][columns - i - 1]); 
        sum += matrix[i][columns - 1 - i];
    }
    return sum;
}

bool isDiagonalMatrix(const int matrix[][MAX_COLUMNS], const int rows , const int columns)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0 ; j < columns; j++)
            if( matrix[i][j] != 0 && i != j)
                return false;
    return true;
}

bool isIdentityMatrix(const int matrix[][MAX_COLUMNS], const int rows , const int columns)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0 ; j < columns; j++)
            if( (matrix[i][j] != 0 && i != j) || (i == j && matrix[i][j] != 1))
                return false;
    return true;
}

bool isSymmetricMatrix(const int matrix[][MAX_COLUMNS], const int columns)
{
    for(int i = 0; i < columns ; i++)
        for(int j = i + 1; j < columns; j++)
            if(matrix[i][j] != matrix[j][i] && i != j)
                return false;
    return true;
}

void transposeMatrixInSitu(int matrix[][MAX_COLUMNS], const int columns)
{
    int aux;

    for(int i = 0; i < columns; i++)
        for(int j = i + 1; j < columns; j++)
        {
            aux = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = aux;
        }
}

void transposeMatrix(const int matrix1[][MAX_COLUMNS], int matrix2[][MAX_COLUMNS], const int columns)
{
    int aux;
    for(int i = 0; i < columns; i++)
        for(int j = i ; j < columns; j++)
        {
            aux = matrix1[i][j];
            matrix2[i][j] = matrix1[j][i];
            matrix2[j][i] = aux;
        }
}

void multiplyMatrices(const int matrix1[4][3], const int rows1, const int columns1, const int matrix2[3][2], const int rows2, const int columns2, int matrixResult[4][2])
{
    
    for(int i = 0; i < rows1; i++)
        for(int j = 0; j < columns2; j++)
        {
            matrixResult[i][j] = 0;
            for(int k = 0; k < columns1; k++)
                matrixResult[i][j] += (matrix1[i][k] * matrix2[k][j]);
        }
}

bool validateScoreMatrix(const int matrix[][MAX_COLUMNS], const int rows, const int columns)
{
    for(int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if(i == j && matrix[i][j] != 0 || matrix[i][j] == 2 || matrix[i][j] > 3 || matrix[i][j] < 0)
                return false;
    return true;
}

