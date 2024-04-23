#ifndef STRINGDEOBFUSCATOR_H_INCLUDED
#define STRINGDEOBFUSCATOR_H_INCLUDED

#define CHAR_NOT_FOUND -1

int numElementsString(const char *string);
int binarySearchString(const char *array, const int numElements, const char element);
void decryptWord(Word *word, const char *shiftGroup, const int numElements);
char *obfuscateString(const char* obfuscatedText, const char *shiftGroup, char *deobfuscatedText);

#endif // STRINGDEOBFUSCATOR_H_INCLUDED