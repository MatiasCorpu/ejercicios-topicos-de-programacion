/*
Ejercicio 1.9
Desarrollar una función que normalice la cadena de texto que se le pasa como argumento. En este
caso, la cadena se encontrará normalizada cuando la primera letra de cada palabra sea mayúscula y
las siguientes minúsculas. La cadena normalizada no deberá contener espacios o tabulaciones al
inicio o al final. En el caso de que las palabras de la cadena se encuentren separadas por más de un
espacio o tabulación, se deberán eliminar los excedentes. Se debe modificar la cadena pasada como
argumento. No puede realizar una o más copias locales de la cadena original. Contemple las
condiciones de borde y haga un listado de éstas.
*/
#include <stdio.h>
#include <stdlib.h>

#include "normalize.h"

void createWordSequence(WordSequence *wordSeq, char *string)
{
    wordSeq->cursor = string;
    wordSeq->endSequence = false;
}

bool endOfWordSequence(const WordSequence *wordSeq)
{
    return wordSeq->endSequence;
}

bool isLetter(const char character)
{
    return ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'));
}

bool readWord(WordSequence *wordSeq, Word *word)
{
    while (*wordSeq->cursor != '\0' && !isLetter(*wordSeq->cursor)) // incrementa hasta que encuentra una letra
        wordSeq->cursor++;

    if (*wordSeq->cursor == '\0') // si la secuencia de palabras termina sale
    {
        wordSeq->endSequence = true;
        return false;
    }

    char *currentWord = word->word;

    while (*wordSeq->cursor != '\0' && isLetter(*wordSeq->cursor)) // leo la palabra de wordSeq en word
    {
        *currentWord = *wordSeq->cursor;
        currentWord++;
        wordSeq->cursor++;
    }

    *currentWord = '\0';
    return true;
}

void capitalizeWord(Word *word)
{
    char *currentWord = word->word;

    *currentWord = toupper(*currentWord);
    currentWord++;

    while (*currentWord != '\0')
    {
        *currentWord = tolower(*currentWord);
        currentWord++;
    }
}

void writeWord(WordSequence *wordSeq, const Word *word)
{
    const char *currentWord = word->word;

    while (*currentWord != '\0')
    {
        *wordSeq->cursor = *currentWord;
        wordSeq->cursor++;
        currentWord++;
    }
}

void writeCharacter(WordSequence *wordSeq, const char character)
{
    *wordSeq->cursor = character;
    wordSeq->cursor++;
}

void repositionCursor(WordSequence *wordSeq, int displacement)
{
    wordSeq->cursor += displacement;
}

void closeWordSequence(WordSequence *wordSeq)
{
    *wordSeq->cursor = '\0';
}

char *normalize(const char *stringToNormalize, char *normalizedString)
{
    WordSequence readSeq;
    createWordSequence(&readSeq, (char *)stringToNormalize);

    WordSequence writeSeq;
    createWordSequence(&writeSeq, (char *)normalizedString);

    Word word;

    readWord(&readSeq, &word);

    while (!endOfWordSequence(&readSeq))
    {
        capitalizeWord(&word);
        writeWord(&writeSeq, &word);
        writeCharacter(&writeSeq, ' ');
        readWord(&readSeq, &word);
    }

    repositionCursor(&writeSeq, -1);
    closeWordSequence(&writeSeq);

    return normalizedString;
}