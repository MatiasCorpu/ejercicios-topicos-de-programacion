#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

#define ALL_OK 0
#define ERROR_SIZE_ARRAY -1
#define ERROR_INDEX -2
#define ERROR_ARRAY_EMPTY -3


typedef void (*ShowElementFunction)(const void *array);

//NUMEROS ENTEROS
void showArray(const int* array, const int numElements);
int binarySearchInsertPosition(const int* array, const int numElements, const int element);
int searchBinary(const int* array, const int numElements, const int element);
int insertIntoArray(int* array, int* numElements, const int sizeArray, int position, int element);
int insertIntoArraySorted(int* array, int* numElements, const int sizeArray, int element);
int removeIntegerFromArrayByPosition(int *array, int* numElements, int position);
int removeFirstIntegerFromArray(int *array, int* numElements);
int removeAllOccurrencesFromArray(int *array, int* numElements, int element);
bool removeElementInArraySorted(int* array, int* numElements, int element);
bool removeDuplicatesFromSortedArray(int *array, int *numElements);
void sortAscendingIntArray(int *array, int numElements);

//STRINGS
bool esPalindromo(const char* string); //ignora mayusculas/minusculas
int stringToNumericValue(const char* string);
int countOccurrencesOfWordInText(const char* text, const char* word);

//funciones del 1.1 al 1.5 aceptando cualquier tipo de parametro
void showInt(const void *element);
void showChar(const void *element);
void showArrayGeneric(const void* array, size_t sizeElment, const int numElements, ShowElementFunction showElement);
int insertIntoArrayGeneric(void *array, size_t sizeElment, int *numElements, int sizeArray, int position, void *element); // 1.1

#endif // ARRAYS_H_INCLUDED
