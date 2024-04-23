/*
Ejercicio 1.10
La siguiente línea “Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj” ha
sido ofuscada para impedir su lectura desplazando desplazado hacia atrás dentro del grupo
"abcdghijkoqtuv" tantos caracteres como posición tiene en la palabra.
Ejemplo, si la palabra es “hola”
● "h":un lugar atrás porque es la primera letra de la palabra, queda "g"
● "o":dos lugares atrás, queda "j"
● "l":No figura en grupo, no se modifica, queda "l"
● "a":cuatro lugares hacia atrás, queda "q", antes de la “a” está la “v”.
Quedando una vez ofuscada como “gjlq”.
● No considere ningún carácter que no figura dentro del grupo
● Una palabra es todo conjunto de uno o mas caracteres que responden a la función isalpha
● La frase desofuscada esta en Español
*/

#include <stdio.h>
#include <stdlib.h>

#include "stringDeobfuscator.h"
#include "normalize.h"

int numElementsString(const char *string)
{
    int numElements = 0;
    while (*string != '\0')
    {
        numElements++;
        string++;
    }
    return numElements;
}


int binarySearchString(const char *array, const int numElements, const char element)
{
    int left = 0;
    int right = numElements;
    int middle = 0;

    while (left <= right)
    {
        middle = (left + right) / 2;

        if (*(array + middle) == element)
            return middle;
        else if (*(array + middle) < element)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return CHAR_NOT_FOUND;
}

void decryptWord(Word *word, const char *shiftGroup, const int numElements)
{
    char *currentLetter = word->word;
    char *group = (char *)shiftGroup;

    int shiftRigth = 1;
    int position = 0;

    while (*currentLetter != '\0')
    {
        position = binarySearchString(group, numElements, *currentLetter);

        if (position != CHAR_NOT_FOUND)
        {
            if (numElements > position + shiftRigth)
                *currentLetter = *(group + (position + shiftRigth));
            else
                *currentLetter = *(group + (position + shiftRigth - numElements));
        }
        shiftRigth++;
        currentLetter++;
    }
}

char *obfuscateString(const char *obfuscatedText, const char *shiftGroup, char *deobfuscatedText)
{
    WordSequence readSeq;
    createWordSequence(&readSeq, (char *)obfuscatedText);

    WordSequence writeSeq;
    createWordSequence(&writeSeq, (char *)deobfuscatedText);

    int numElements = numElementsString(shiftGroup);

    Word word;

    readWord(&readSeq, &word);
    while (!endOfWordSequence(&readSeq))
    {
        decryptWord(&word, shiftGroup, numElements);
        writeWord(&writeSeq, &word);
        writeCharacter(&writeSeq, ' ');
        readWord(&readSeq, &word);
    }
    repositionCursor(&writeSeq, -1);
    closeWordSequence(&writeSeq);

    return deobfuscatedText;
}