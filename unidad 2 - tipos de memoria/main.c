#include <stdio.h>
#include <stdlib.h>

#include "MemDinamic.h"
#include "MemDinamic.c"

int main()
{
    /*
    //PARA ARRAY DE ENTEROS:

    Array arrayINT;
    int elem;

    if (!arrayCreate(&arrayINT, sizeof(int)))
        return ERR_MEM;

    printf("Ingrese un entero para introducirlo en el vector (fin = 0):");
    scanf("%d", &elem);

    while (elem != 0)
    {
        insertOrderedArray(&arrayINT, &elem, sizeof(int), compareInt);
        printf("Ingrese un entero para introducirlo en el vector (fin = 0):");
        scanf("%d", &elem);
    }

    advanceIndex(arrayINT.array, arrayINT.elements, sizeof(int), showInt);
    arrayDelete(&arrayINT);
    */

    /*
    //PARA ARRAY DE CARACTERES:

    Array arrayCHAR;
    char elem;

    if (!arrayCreate(&arrayCHAR, sizeof(int)))
        return ERR_MEM;

    printf("Ingrese un entero para introducirlo en el vector (fin = !):");
    scanf(" %c", &elem);

    while (elem != '!')
    {
        insertOrderedArray(&arrayCHAR, &elem, sizeof(char), compareChar);
        printf("Ingrese un entero para introducirlo en el vector (fin = !):");
        scanf(" %c", &elem);
    }

    advanceIndex(arrayCHAR.array, arrayCHAR.elements, sizeof(char), showChar);
    arrayDelete(&arrayCHAR);
    */

    // PARA UN ARRAY DE ESTUDIANTES:
    
    Array arrayStudent;
    Student std;
    int counter = 1;

    if (!arrayCreate(&arrayStudent, sizeof(Student)))
        return ERR_MEM;

    printf("ingrese nombre del alumno numero %d (fin = 'fin'): ", counter);
    scanf("%s", &std.name);

    while (strcmpi(std.name, "fin") != 0)
    {
        printf("ingrese apellido del alumno: ");
        scanf("%s", &std.lastName);
        printf("ingrese promedio del alumno: ");
        scanf("%f", &std.average);
        printf("ingrese codigo del alumno: ");
        scanf("%d", &std.code);
        insertOrderedArray(&arrayStudent, &std, sizeof(Student), compareStudent);
        puts("------------------------------------------------------------------");
        printf("ingrese nombre del alumno numero %d (fin = 'fin'): ", counter++);
        scanf("%s", &std.name);
    }

    printf("Cantidad de alumnos registrados = %d\n", arrayStudent.elements);
    advanceIndex(arrayStudent.array, arrayStudent.elements, sizeof(Student), showStudent);
    arrayDelete(&arrayStudent);

    return 0;
}