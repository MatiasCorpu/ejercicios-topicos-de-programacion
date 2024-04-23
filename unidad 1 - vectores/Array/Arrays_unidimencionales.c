#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "Arrays.h"




/*
<<<<<<EJERCICIOS DE ARRAYS DE LA GUIA - UNIDAD 1>>>>>>

        <<<NUMEROS ENTEROS>>>
1.1 Desarrollar una función que inserte un elemento en un arreglo de enteros dada la posición de inserción.
1.2 Desarrollar una función que inserte un elemento en un arreglo de enteros ordenado en forma ascendente, de forma de no alterar el orden
1.3 Desarrollar una función que elimine el elemento que ocupa una determinada posición de un arreglo de enteros
1.4 Desarrollar una función que elimine la primera aparición de un elemento determinado de un arreglo de enteros
1.5 Desarrollar una función que elimine todas las apariciones de un determinado elemento de un arreglo de enteros




Estos ejercicios lo dio el profesor en la clase 2°, no esta en la guia de ejercicios:
1.9 Desarrollar una función que elimine todos los elementos duplicados de un array de eneteros ordenado.
1.10 Desarrollar una función que elimine un elemento en un arreglo de enteros ordenado en forma ascendente, de forma de no alterar el orden
1.11 Desarrollar una funsión que ordene de forma ascendente un array de enteros.

1.12 Hacer todo pero con TDA (tipo de dato abstracto), le paso a las funciones las direcciones de memeria de las estructuras. Dichas estructuras tienen que tener:
typedef struct{
    int vec[8]; -> el tamaño máximo definido porque todavía no vimos memoria dinámica
    int ce; -> se define una variable que tiene la cantidad de elementos que hay en el vector.
}Vector




        <<<STRINGS>>>
1.6 Desarrollar una función que determine si una cadena de caracteres es un palíndromo.
1.7 Desarrollar una función que devuelva el valor numérico de una cadena de caracteres (asumiendo que los caracteres representan dígitos).
1.8 Desarrollar una función que cuente el número de apariciones de una palabra dentro de una cadena
de texto. Para ello la función recibe como parámetros dos punteros a char. El primero corresponde al
texto, el segundo corresponde a la cadena buscada. La función debe retornar el número de
ocurrencias. Contemple las condiciones de borde y haga un listado de éstas.


1.21 Haga una reingeniería de los ejercicios 1.1 a 1.5 para que puedan operar con cualquier tipo de dato (recuerde que los ejercicios originales estaban diseñados para operar con números enteros). Haga uso de memoria estática
*/

// NUMEROS ENTEROS:

void showArray(const int *array, const int numElements)
{
    for (const int *i = array; i < array + numElements; i++)
        printf("%d\t", *i);
}

int insertIntoArray(int *array, int *numElements, int sizeArray, int position, int element) // 1.1
{
    if (*numElements == sizeArray)
        return ERROR_SIZE_ARRAY;

    for (int *i = array + *numElements - 1; i >= array + position - 1; i--)
        *(i + 1) = *i;

    *(array + position - 1) = element;
    (*numElements)++;

    return ALL_OK;
}

int insertIntoArraySorted(int *array, int *numElements, const int sizeArray, int element) // 1.2
{
    if (*numElements == sizeArray)
        return ERROR_SIZE_ARRAY;

    int position = binarySearchInsertPosition(array, *numElements, element);

    for (int *i = array + (*numElements) - 1; i >= array + position; i--)
        *(i + 1) = *i;

    *(array + position) = element;
    (*numElements)++;

    return ALL_OK;
}

int binarySearchInsertPosition(const int *array, const int numElements, const int element) // busca el elemento utilizando búsqueda binaria y devuelve la posición donde debería estar si no se encuentra.
{
    int left = 0;
    int right = numElements - 1;

    bool found = false;

    int comp;
    int half;

    while (found == false && left <= right)
    {
        half = (right + left) / 2; // numElement es par, half = "mitad - 1"
        comp = element - *(array + half);

        if (comp == 0)
            found = true;
        else if (comp < 0)
            right = half - 1;
        else
            left = half + 1;
    }

    return found ? half : left;
}

int removeIntegerFromArrayByPosition(int *array, int *numElements, int position) // 1.3
{
    if (position < 0 || position >= *numElements)
        return ERROR_INDEX;

    for (int *i = array + position - 1; i <= array + (*numElements) - 1; i++)
        *i = *(i + 1);

    (*numElements)--;

    return ALL_OK;
}

int removeFirstIntegerFromArray(int *array, int *numElements) // 1.4
{
    if (*numElements <= 0)
        return ERROR_ARRAY_EMPTY;

    for (int *i = array; i < array + *numElements; i++)
        *i = *(i + 1);

    (*numElements)--;

    return ALL_OK;
}

int removeAllOccurrencesFromArray(int *array, int *numElements, int element) // 1.5 se puede hacer de una manera mas eficiente, recorriendo una vez al array y guardando las posiciones de memeria de los elementos del array que se repiten en otro array
{
    int *i = array;

    while (i < (array + *numElements))
    {
        printf("valor puntero = %d\telemento = %d\n", *i, element);

        if (*i == element)
        {
            removeFirstIntegerFromArray(i, numElements);
        }
        else
            i++;
    }

    return ALL_OK;
}

bool removeDuplicatesFromSortedArray(int *array, int *numElements) // 1.9
{
    int *i = array + 1;
    int *arr = array;
    int cont = 1;

    while (i <= (array + *numElements - 1))
    {
        if (*arr != *i)
        {
            arr++;
            *arr = *i;
            cont++;
        }
        i++;
    }
    *numElements = cont;
    return true;
}

int searchBinary(const int *array, const int numElements, const int element)
{
    int left = 0;
    int right = numElements;

    bool found = false;
    int half;
    int comp;

    while (!found && left <= right)
    {
        half = (right + left) / 2;
        comp = element - *(array + half);

        if (comp == 0)
            found = true;
        else if (comp < 0)
            right = half - 1;
        else
            left = half + 1;
    }
    return found ? half : -1;
}

bool removeElementInArraySorted(int *array, int *numElements, int element) // 1.10
{
    int position = searchBinary(array, *numElements, element);

    if (position < 0)
        return false;

    removeIntegerFromArrayByPosition(array, numElements, position + 1);

    return true;
}

void sortAscendingIntArray(int *array, int numElements)//1.11 (metodo de insersion)
{
    int toInsert;
    int *j;

    for(int *i = array + 1; i < array + numElements ; i++)
    {
        toInsert = *i;

        for(j = i - 1; j >= array && toInsert < *j; j--)
        {
            *(j + 1) = *j;
        }
        *(j + 1) = toInsert;
    }
}


// STRINGS:

bool esPalindromo(const char *string) // 1.6
{
    const char *left = string;
    const char *right = string;

    while (*right != '\0')
        right++;
    right--;

    while (left != right)
    {

        printf("%c = %c\n", *left, *right);

        if (tolower(*left) != tolower(*right))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int stringToNumericValue(const char *string) // 1.7
{
    int result = 0;

    while (*string != '\0')
    {
        result = (result * 10) + (*string - '0');
        string++;
    }

    return result;
}

int countOccurrencesOfWordInText(const char *text, const char *word) // 1.8
{
    if (*text == '\0' || *word == '\0')
        return ERROR_ARRAY_EMPTY;
    else if (strlen(text) < strlen(word))
        return ERROR_SIZE_ARRAY;

    const char *tx = text;
    const char *wrd = word;
    int cont = 0;

    while (*tx != '\0')
    {
        if (*wrd == *tx && *wrd != '\0')
        {
            tx++;
            wrd++;
        }
        else if (*wrd == '\0')
        {
            cont++;
            wrd = word;
        }
        else
            tx++;
    }

    if (*wrd == '\0')
        cont++;

    return cont;
}


//1.1 al 1.5 aceptando cualquier tipo de dato

void showInt(const void *element)
{
    printf("%d\t", *(const int *)element);
}

void showChar(const void *element)
{
    printf("%c\t", *(const char *)element);
}

void showArrayGeneric(const void* array, size_t sizeElment, const int numElements, ShowElementFunction showElement)
{
    for (const void *i = array; i < array + (numElements * sizeElment); i += sizeElment)
        showElement(i);
}

int insertIntoArrayGeneric(void *array, size_t sizeElment, int *numElements, int sizeArray, int position, void *element) // 1.1
{
    if(*numElements == sizeArray)
        return ERROR_SIZE_ARRAY;

    void *i;

    for(i = array + (sizeElment * (*numElements - 1)); i >= array + (sizeElment * (position - 1)); i -= sizeElment)
    {
        memcpy(i + sizeElment, i , sizeElment);
    }

    memcpy(array + (position - 1) * sizeElment, element , sizeElment);
    (*numElements)++;

    return ALL_OK;
}