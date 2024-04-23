/*
Ejercicio 1.11
Ingresar por teclado pares de cadenas de caracteres, finalizando el ingreso cuando ambas cadenas
sean iguales (las que no deben procesarse). Para cada par, cargar en un array bidimensional, ambas
cadenas, respetando cargar primero la más pequeña y luego la mayor, si las longitudes fueran
iguales, el orden lo dará la comparación lexicográfica haciendo caso omiso de mayúsculas y
minúsculas.
Escriba una función que determine la comparación solicitada invocando a versiones propias de las
funciones de biblioteca estándar strlen y strcmpi o strcasecmp (dado que esta no es una función
estándar en algunos compiladores tiene otro nombre).
*/

#include <stdio.h>
#include <stdlib.h>

#include "putStringsInMatrix.h"


void removeNewLine(char *str) {
    size_t len = myStrlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int myStrcmp(const char *string1, const char *strin2)
{
    while (*string1 != '\0' && *strin2 != '\0')
    {
        if (*string1 < *strin2)
            return 1;
        else if (*string1 > *strin2)
            return -1;

        string1++;
        strin2++;
        
    }
    return myStrlen(string1) - myStrlen(strin2);
}

char myTolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int myStrcmpi(const char *string1, const char *strin2)
{
    while (*string1 != '\0' && *strin2 != '\0')
    {
        if (myTolower(*string1) < myTolower(*strin2))
            return -1;
        else if (myTolower(*string1) > myTolower(*strin2))
            return 1;

        string1++;
        strin2++;
        
    }
    return myStrlen(string1) - myStrlen(strin2);
}

int myStrlen(const char *string)
{
    int count = 0;
    while (*string != '\0')
    {
        count++;
        string++;
    }
    return count;
}

void showMatrixString(char matrix[][MAX_STRING_LENGTH], int *rows, int columns)
{
    for (int i = 0; i < *rows; i++)
        printf("[%s]\n", matrix[i]);
}

void putInMatrix(char matrix[][MAX_STRING_LENGTH], int *rows, const char *string)
{   
    if(*rows ==  MAX_ROWS)
        return;
    
    int columns = myStrlen(string);
    int i = *rows;

    while (*rows == i)
    {
        for(int j = 0 ; j < columns + 1; j++)
        {
            //printf("myStrlen(string): %d\n", myStrlen(string));
            matrix[i][j] = *string;
            //printf("string1: %c\n", *string);
            string++;
        }
        (*rows)++;
    }  
}

void putStringsInMatrix(char matrix[][MAX_STRING_LENGTH], int *rows, int columns, const char *string1, const char *string2)
{
    int side = myStrcmpi(string1, string2);
    int dif = myStrlen(string1) - myStrlen(string2);

    if(dif < 0)
    {
        putInMatrix(matrix, rows, string1);
        putInMatrix(matrix, rows, string2);
    }
    else if(dif > 0)
        {
            putInMatrix(matrix, rows, string2);
            putInMatrix(matrix, rows, string1);
        } else
            {
                if(side < 0)
                {
                   putInMatrix(matrix, rows, string1);
                   putInMatrix(matrix, rows, string2);
                } else
                    {
                        putInMatrix(matrix ,rows ,string2);
                        putInMatrix(matrix, rows, string1);
                    }
            }
}