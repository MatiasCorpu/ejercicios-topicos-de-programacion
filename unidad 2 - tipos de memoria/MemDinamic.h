#ifndef MEM_DINAMIC_H_INCLUDED
#define MEM_DINAMIC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALL_OK 0
#define ERR_MEM 1
#define DUPLICATE 2
#define SIN_MEM 3

#define INI_CAP 10

#define NAME 30
#define LASTNAME 30

typedef void (*ShowElementFunction)(const void *i);   // para la funcion generica que muesta el vector
typedef int (*Compare)(const void *a, const void *b); // para la funcion generica que compara elementos

typedef struct
{
    void *array;
    int elements;
    int capacity;
} Array;

typedef struct
{   
    int code;
    char name[NAME];
    char lastName[LASTNAME];
    float average; // promedio
} Student;

void showStudent(const void *i);
void showInt(const void *i);
void showChar(const void *i);
void advanceIndex(const void *array, const int numElements, size_t sizeElement, ShowElementFunction showElement);

bool arrayCreate(Array *array, size_t sizeElement);
void arrayDelete(Array *array);

int compareStudent(const void *a, const void *b);
int compareInt(const void *a, const void *b);
int compareChar(const void *a, const void *b);
int insertOrderedArray(Array *array, void *element, size_t sizeElement, Compare cmp);

#endif // MEM_DINAMIC_H_INCLUDED
