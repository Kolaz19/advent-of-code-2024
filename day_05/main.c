#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_FILE "input.txt"
#define LEN_FILE 20000
#define LEN_MAP_NUMBERS 50
#define LEN_MAP_ROWS 100
#define LEN_MAP_LINE 5

int fillStringFromFile(char *values);
bool isAtSwitch(char *cur);
void collectNumbers(int *mappingForNumber, int num2);
char *processLine(int *mappingForNumber, char *cur, int *pageNumber);

int main() {
    char input[LEN_FILE];
    if (!(fillStringFromFile(input))) {
        exit(EXIT_FAILURE);
    }

    char *curChar = input;
    int sum, num1, num2 = 0;
    int pageNumber = 0;
    bool afterSwitch = false;

    int mappings[LEN_MAP_ROWS][LEN_MAP_NUMBERS] = {0};

    do {
        if (afterSwitch) {
            curChar = processLine(mappings[0], curChar, &pageNumber);
            sum += pageNumber;
        } else {
            if (sscanf(curChar, "%d|%d", &num1, &num2) != 2) {
                exit(EXIT_FAILURE);
            }
            curChar += LEN_MAP_LINE;
            collectNumbers(&(mappings[num1][0]), num2);
        }

        if (!afterSwitch && isAtSwitch(curChar)) {
            afterSwitch = true;
            curChar++;
        }

    } while (*(++curChar) != '\0');

    printf("Result: %d", sum);
}

char *processLine(int *mappingForNumber, char *cur, int *pageNumber) {
    char *tmp = cur;
    int size = 0;
    // Will stay at new line after that
    while (*(tmp++) != '\n')
        ;
    int amountNumbersInLine = (tmp - cur) / 3;
    int numbers[amountNumbersInLine];

    // Collect numbers into array
    for (int i = 0; i < amountNumbersInLine; i++) {
        if (sscanf(cur, "%d", &(numbers[i])) != 1) {
            exit(EXIT_FAILURE);
        }
        cur += 3;
    }

    bool wasFaulty = false;
    bool stillFaulty = true;
    // Loop through row / current line
    do {
        stillFaulty = false;
        for (int i = 0; i < amountNumbersInLine; i++) {
            int *numStart = mappingForNumber + (LEN_MAP_NUMBERS * numbers[i]);
            // Loop through mappings for number of left side
            for (int k = 0; k < LEN_MAP_NUMBERS; k++) {
                if (numStart[k] == 0) {
                    break;
                }
                // Check if mapped number on right appears before current number in row
                for (int v = 0; v < i; v++) {
                    if (numStart[k] == numbers[v]) {
                        wasFaulty = true;
                        stillFaulty = true;
                        int tmpNumber = numbers[v];
                        numbers[v] = numbers[i];
                        numbers[i] = tmpNumber;
                    }
                }
            }
        }
    } while (stillFaulty);

    if (wasFaulty) {
        *pageNumber = numbers[(amountNumbersInLine - 1) / 2];
    } else {
        *pageNumber = 0;
    }
    return tmp - 1;
}

void collectNumbers(int *mappingForNumber, int num2) {
    for (int i = 0; i < LEN_MAP_NUMBERS; i++) {
        if (mappingForNumber[i] == 0) {
            mappingForNumber[i] = num2;
            return;
        } else if (mappingForNumber[i] == num2) {
            return;
        }
    }
}

bool isAtSwitch(char *cur) {
    if (*cur == '\n' && *(cur + 1) == '\n') {
        return true;
    } else {
        return false;
    }
}

int fillStringFromFile(char *values) {
    char *curPos = values;
    FILE *file;
    file = fopen(NAME_FILE, "r");
    if (file == NULL) {
        return 0;
    }
    while ((*curPos = fgetc(file)) != EOF) {
        curPos++;
    }
    *curPos = '\0';
    fclose(file);
    return 1;
}
