/*
2.1 Desarrolle un programa que reserve memoria para almacenar 10 enteros. Luego asigne valores a dichos elementos. Asegúrese de devolver la memoria reservada.

2.2 Modifique el programa del punto 2.1 para que la cantidad de elementos sea ingresada por teclado.

2.3 Desarrolle un programa que reserve memoria para almacenar 5 elementos de un tipo de dato creado por Usted. Dicho tipo de dato debe contener al menos un array de char, un entero, un flotante y un char. Luego asigne valores a dichos elementos. Asegúrese de devolver la memoria reservada.

*/

#include "MemDinamic.h"

void showInt(const void *i)
{
    printf("%d ", *(const char *)i);
}

void showChar(const void *i)
{
    printf("%c ", *(const char *)i);
}

void advanceIndex(const void *array, const int numElements, size_t sizeElement, ShowElementFunction showElement)
{
    for (const void *i = array; i < array + (numElements * sizeElement); i += sizeElement)
    {
        showElement(i);
    }
}

//-------------------------------------------------------------------------------------------------

bool arrayCreate(Array *array, size_t sizeElement)
{
    array->array = malloc(INI_CAP * sizeElement);

    if (array->array == NULL)
        return false;

    array->capacity = INI_CAP;
    array->elements = 0;

    return true;
}

void arrayDelete(Array *array)
{
    free(array->array);
    array->array = NULL;
    array->capacity = 0;
    array->elements = 0;
}

//-------------------------------------------------------------------------------------------------

int compareInt(const void *a, const void *b)
{
    const int *A = a;
    const int *B = b;

    return (*A < *B) ? -1 : ((*A > *B) ? 1 : 0);
}

int compareChar(const void *a, const void *b)
{
    const char *A = a;
    const char *B = b;

    return (*A < *B) ? -1 : ((*A > *B) ? 1 : 0);
}

int insertOrderedArray(Array *array, void *element, size_t sizeElement, Compare cmp)
{   
    if (array->capacity == array->elements)
    {   
        int newCap = array->capacity * 1.5;
        void *newArray = realloc(array->array, newCap * sizeElement);

        if (newArray == NULL)
            return SIN_MEM;

        array->array = newArray;
        array->capacity = newCap;
    }

    void *first = array->array;
    void *last = array->array + (array->elements * sizeElement) - sizeElement;

    while (first <= last && cmp(first, element) < 0)
        first += sizeElement;

    if (first <= last && cmp(first, element) == 0)
        return DUPLICATE;
    
    for (void *i = last; i >= first; i -= sizeElement)
        memcpy(i + sizeElement, i, sizeElement);
    
    memcpy(first, element, sizeElement);
    array->elements += 1;

    return ALL_OK;
}

//-------------------------------------------------------------------------------------------------

void showStudent(const void *i)
{   
    const Student std = *(Student *)i;
    printf("%d %s %s %.2f\n",std.code, std.name, std.lastName, std.average);
}

int compareStudent(const void *a, const void *b)
{
    const Student A = *(Student *)a;
    const Student B = *(Student *)b;

    return (A.code < B.code) ? -1 : ((A.code > B.code) ? 1 : 0);
}