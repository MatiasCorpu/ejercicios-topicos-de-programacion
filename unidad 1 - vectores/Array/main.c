#include <stdio.h>
#include <stdlib.h>
#include "Arrays.h"

#include "Arrays.h"

#include "Arrays_unidimencionales.c"

int main()
{
    int arrayMessy[8] = {3,2,1,4,8,7};
    int arraySorted[8] = {1,2,3,5,6,7};
    int arrayElementsRepeat[11] = {1,1,2,4,1,1,1,1,5,1};
    int sizeArray = 8;
    int numElements = 6;
    int numElements2 = 10;


    //NUMEROS ENTEROS

    //insertIntoArray(arrayMessy, &numElements, sizeArray, 5, 111111); showArray(arrayMessy, numElements);
    //insertIntoArraysorted(arraySorted, &numElements, sizeArray, 4); showArray(arraySorted, numElements);
    //removeIntegerFromArrayByPosition(arraySorted, &numElements, 4);showArray(arraySorted, numElements);
    //removeFirstIntegerFromArray(arraySorted, &numElements);showArray(arraySorted, numElements);
    //removeAllOccurrencesFromArray(arrayElementsRepeat, &numElements2, 1); showArray(arrayElementsRepeat, numElements2);

    
    //Ejercicios que dejaron en clases array de enteros
    
    //if(removeElementInArraySorted(arraySorted, &numElements, 4)) printf("Se elimino correctamente\n"); else printf("Elemento no encontrado\n");showArray(arraySorted, numElements);
    /*
    int vec[12] = {1,1,2,2,2,4,4,5,6,7,8,10};
    int ce = 12; 
    if(removeDuplicatesFromSortedArray(vec, &ce)) showArray(vec, ce);
    printf("ce = %d\n",ce);
    */
    //sortAscendingIntArray(arrayMessy, numElements); showArray(arrayMessy, numElements);


    //STRINGS
    //if(esPalindromo("Reconocer")){ printf("Es palindromo"); } else printf("No es palindromo");
    //printf("%d",stringToNumericValue("12345"));
    //printf("todas las ocurrencias de la palabra = %d",countOccurrencesOfWordInText("eeuueeuu holaeeuu eueaeeuu", "eeuu"));

    /*    
    int element = 4;
    insertIntoArrayGeneric(arraySorted, sizeof(int), &numElements, sizeArray, 4, &element); showArrayGeneric(arraySorted, sizeof(int), numElements, showInt);
    printf("\n\n");
    char arraySortedChar[8] = {'a','a','a','a','a','a'}; char letter = 'b';
    insertIntoArrayGeneric(arraySortedChar, sizeof(char), &numElements, sizeArray, 4, &letter); showArrayGeneric(arraySortedChar, sizeof(char), numElements, showChar);
    */

    return 0;
}
