#ifndef PROCESS
#define PROCESS
#include <stdbool.h>

typedef enum operation {
    PLUS,
    MULT
} operation;

bool isLegit(operation op, long long sum, int *numInArray, int indxCounter, long long result);

#endif
