#include <stdio.h>
#include <stdlib.h>

#include "normalize.h"
#include "normalize.c"

#include "stringDeobfuscator.h"
#include "stringDeobfuscator.c"

#include "putStringsInMatrix.h"
#include "putStringsInMatrix.c"

#define MAX_STRING_LENGTH 100
#define MAX_ROWS 10


int main()
{
    /*
    //Ejercicio 1.9

    char stringToNormalize[] = "&++**¨*`çHoLa  ·ªqUe ¨$ TAl)(/0987>< @67Me)llaMo___matiaS";
    char normalizedString[MAX_STRING_LENGTH];
    normalize(stringToNormalize, normalizedString);
    printf("\n\nCADENA SIN NORMALIZAR: %s\n", stringToNormalize);
    printf("CADENA NORMALIZADA: %s\n\n", normalizedString);
    */
   
   /*
    //Ejercicio 1.10

    const char obfuscatedText[] = "Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj";
    const char shiftGroup[] = "abcdghijkoqtuv";
    char deobfuscatedText[MAX_STRING_LENGTH];
    printf("\nTEXTO ORIGINAL: %s\n", obfuscatedText);
    printf("TEXTO OBFUSCADO: %s\n\n", obfuscateString(obfuscatedText, shiftGroup, deobfuscatedText));
    */

   /*
    //Ejericio 1.11
    
    char matrtix[MAX_ROWS][MAX_STRING_LENGTH];
    char string1[MAX_STRING_LENGTH], string2[MAX_STRING_LENGTH];
    int rows = 0;

    puts("Inglese dos (2) cadenenas de texto (finaliza ingresando 2 cadenas iguales):");
    fgets(string1, sizeof(string1), stdin); removeNewLine(string1);
    fgets(string2, sizeof(string2), stdin); removeNewLine(string2);
    while (myStrcmp(string1, string2) != 0)
    {
        putStringsInMatrix(matrtix, &rows, MAX_STRING_LENGTH, string1, string2);
        printf("--------------------------------------------------------------------------------------\n");
        puts("Inglese nuevamente dos (2) cadenenas de texto (finaliza ingresando 2 cadenas iguales):");
        fgets(string1, sizeof(string1), stdin); removeNewLine(string1);
        fgets(string2, sizeof(string2), stdin); removeNewLine(string2);
    }
    showMatrixString(matrtix, &rows, MAX_STRING_LENGTH);
    */

    return 0; 
}
