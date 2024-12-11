#include "processLine.h"
#include "readFile.h"
#include <stdbool.h>
#include <stdio.h>

int main() {
    char input[LEN_FILE + 1];
    fillStringFromFile(input);

    char *curChar = input;
    long long result;
    int arr[30];
    int amountNumbers;
    long long sum = 0;

    do {
        curChar = getArrayFromString(curChar, &result, arr, &amountNumbers);
        if (isLegit(PLUS, 0, arr, amountNumbers, result)) {
            sum += result;
        }
    } while (*(++curChar) != '\0');

    printf("RESULT:\t%lld\n", sum);
}
