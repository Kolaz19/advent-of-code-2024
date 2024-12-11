#include "processLine.h"

static unsigned long long concatenate(unsigned long long x, unsigned long long y) {
    unsigned long long pow = 10;
    while (y >= pow)
        pow *= 10;
    return x * pow + y;
}

bool isLegit(operation op, long long sum, int *numInArray, int indxCounter, long long result) {
    if (op == PLUS) {
        sum += *numInArray;
    } else if (op == MULT) {
        sum *= *numInArray;
    } else if (op == CONCAT) {
        sum = concatenate(sum, *numInArray);
    }

    if (--indxCounter == 0) {
        return result == sum;
    } else if (sum > result) {
        return false;
    }

    numInArray++;
    return isLegit(PLUS, sum, numInArray, indxCounter, result) ||
           isLegit(MULT, sum, numInArray, indxCounter, result) ||
           isLegit(CONCAT, sum, numInArray, indxCounter, result);
}
