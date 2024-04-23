#ifndef NORMALIZE_H_INCLUDED
#define NORMALIZE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define WORD_SIZE 50

typedef struct
{
    char *cursor;
    bool endSequence;
} WordSequence;

typedef struct
{
    char word[WORD_SIZE];
} Word;

void createWordSequence(WordSequence *wordSeq, char *string);
bool readWord(WordSequence *wordSeq, Word *word);
void writeWord(WordSequence *wordSeq, const Word *word);
void writeCharacter(WordSequence *wordSeq, const char character);
void capitalizeWord(Word *word);
bool endOfWordSequence(const WordSequence *wordSeq);
void repositionCursor(WordSequence *wordSeq, int displacement);
void closeWordSequence(WordSequence *wordSeq);
bool isLetter(const char character);

char *normalize(const char *stringToNormalize, char *normalizedString);

#endif // NORMALIZE_H_INCLUDED