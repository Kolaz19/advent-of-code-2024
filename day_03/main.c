#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_FILE "input.txt"
#define FILE_LEN 20000

int fillStringFromFile(char *values);
bool isMultiplierExpression(char *start);
bool isEnableExpression(char *start);
bool isDisableExpression(char *start);

int main() {
    char input[FILE_LEN];
    if (!(fillStringFromFile(input))) {
        exit(EXIT_FAILURE);
    }

    char *curChar = input;

    int sum = 0;
    int firstNum = 0;
    int secondNum = 0;
	bool enabled = true;

    do {
        if (enabled && isMultiplierExpression(curChar)) {
            // Advance to first number and extract it from string
            curChar += 4;
            if (sscanf(curChar, "%d", &firstNum) != 1) {
                exit(EXIT_FAILURE);
            }
            // Advance to next comma
            while (isdigit(*curChar)) {
                curChar++;
            }
            // Skip comma
            curChar++;
            // Extract second number
            if (sscanf(curChar, "%d", &secondNum) != 1) {
                exit(EXIT_FAILURE);
            }
            sum += firstNum * secondNum;
        } else if (isEnableExpression(curChar)) {
			enabled = true;
        } else if (isDisableExpression(curChar)) {
			enabled = false;
        }
    } while (*(++curChar) != '\0');

    printf("Result:\t%d\n", sum);
}

bool isEnableExpression(char *start) {
    char *curPos = start;
    if (*(curPos++) != 'd' || *(curPos++) != 'o' || *(curPos++) != '(' || *(curPos++) != ')') {
        return false;
    }
    return true;
}

bool isDisableExpression(char *start) {
    char *curPos = start;
    if (*(curPos++) != 'd' || *(curPos++) != 'o' || *(curPos++) != 'n' || *(curPos++) != '\'') {
        return false;
    }
    if (*(curPos++) != 't' || *(curPos++) != '(' || *(curPos++) != ')') {
        return false;
    }
    return true;
}

bool isMultiplierExpression(char *start) {
    char *curPos = start;
    if (*(curPos++) != 'm' || *(curPos++) != 'u' || *(curPos++) != 'l' || *(curPos++) != '(' || !isdigit(*(curPos++))) {
        return false;
    }

    // Advance rest of digits
    char *checkPoint = curPos;
    while (isdigit(*curPos)) {
        curPos++;
    }
    // Not more then 3 digits
    if ((curPos - checkPoint) > 2) {
        return false;
    }

    if (*(curPos++) != ',' || !isdigit(*(curPos++))) {
        return false;
    }

    // Advance rest of digits
    checkPoint = curPos;
    while (isdigit(*curPos)) {
        curPos++;
    }
    // Not more then 3 digits
    if ((curPos - checkPoint) > 2) {
        return false;
    }

    if (*curPos != ')') {
        return false;
    }

    return true;
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
