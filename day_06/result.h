#ifndef RESULT
#define RESULT
#include <stdbool.h>


void addPosToList(char* curChar, char** result, int arrSize);
bool alreadyInList(char* curChar, char** list, int arrSize);
int getResult(char** result, int arrSize);


#endif
