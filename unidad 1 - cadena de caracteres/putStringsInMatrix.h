#ifndef PUT_STRINGS_IN_MATRIX_H_INCLUDED
#define PUT_STRINGS_IN_MATRIX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100
#define MAX_ROWS 10

void removeNewLine(char *str);//para remover \n de fgets
int myStrcmp(const char *string1, const char *strin2);
int myStrcmpi(const char *string1, const char *strin2);
int myStrlen(const char *string);
void showMatrixString(char matrix[][MAX_STRING_LENGTH], int *rows, int columns);
void putsInMatrix(char matrix[][MAX_STRING_LENGTH], int *rows, const char *string1);
void putStringsInMatrix(char matrix[][MAX_STRING_LENGTH], int *rows, int columns, const char *string1, const char *string2);

#endif // PUT_STRINGS_IN_MATRIX_H_INCLUDED