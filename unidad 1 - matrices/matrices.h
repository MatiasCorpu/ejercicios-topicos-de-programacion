#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLUMNS 5

//Secondary Diagonal
int sumSecondaryDiagonal(const int matrix[][MAX_COLUMNS], const int columns);//1.13

//Main Diagonal
void showMatrix(int matrix[][MAX_COLUMNS], const int rows , const int columns);
int sumAboveMainDiagonal(const int matrix[][MAX_COLUMNS], const int rows, const int columns);//1.12
int sumBelowMainDiagonal(const int matrix[][MAX_COLUMNS], const int rows, const int columns);//1.12
int sumMainDiagonal(const int matrix[][MAX_COLUMNS], const int rows , const int columns);//1.13
bool isDiagonalMatrix(const int matrix[][MAX_COLUMNS], const int rows , const int columns);//1.14
bool isIdentityMatrix(const int matrix[][MAX_COLUMNS], const int rows , const int columns);//1.15
bool isSymmetricMatrix(const int matrix[][MAX_COLUMNS], const int columns);//1.16
void transposeMatrixInSitu(int matrix[][MAX_COLUMNS], const int columns);//1.17
void transposeMatrix(const int matrix1[][MAX_COLUMNS], int matrix2[][MAX_COLUMNS], const int columns);//1.18 
void multiplyMatrices(const int matrix1[4][3], const int rows1, const int columns1, const int matrix2[3][2], const int rows2, const int columns2, int matrixResult[4][2]);//1.19
bool validateScoreMatrix(const int matrix[][MAX_COLUMNS], const int rows, const int columns);//1.20 No entendi muy bien este punto

#endif // MATRICES_H_INCLUDED