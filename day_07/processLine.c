#include "processLine.h"

bool isLegit(operation op, long long sum, int *numInArray, int indxCounter, long long result) {
    if (op == PLUS) {
        sum += *numInArray;
    } else if (op == MULT) {
        sum *= *numInArray;
    }

    if (--indxCounter == 0) {
        return result == sum;
    } else if (sum > result) {
        return false;
    }

    numInArray++;
    return isLegit(PLUS, sum, numInArray, indxCounter, result) ||
           isLegit(MULT, sum, numInArray, indxCounter, result);
}
