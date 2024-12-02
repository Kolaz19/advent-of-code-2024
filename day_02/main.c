#include <stdbool.h>
#include <stdio.h>

#define NAME_FILE "input.txt"
#define LINE_LENGTH 50
#define AMOUNT_LINES 1000

void fillStringFromFile(char *values);
bool isSafe(int maxIndex, int *arr);


int main() {
    char input[LINE_LENGTH * AMOUNT_LINES];

    fillStringFromFile(input);

    char *curChar = input;
    int amountNumbersInLine = 0;
    int numbersLine[20];
    int sum = 0;

    while (true) {
        // Skip space
        if (*curChar == ' ') {
            curChar++;
        } else if (*curChar == '\0') {
            if (*(curChar - 1) == '\n') {
                // Jump to next line
                curChar = input + ((curChar - input) / LINE_LENGTH + 1) * LINE_LENGTH;
            } else {
                break;
            }

            // Check safety of line at end of line
            if (isSafe(amountNumbersInLine-1, numbersLine)) {
                sum++;
            }
            amountNumbersInLine = 0;

        } else if (*curChar == '\n') {
            curChar++;
        } else if (sscanf(curChar, "%d", &(numbersLine[amountNumbersInLine])) == 1) {
            // Collect numbers
            if (numbersLine[amountNumbersInLine] < 10) {
                curChar++;
            } else {
                curChar += 2;
            }
			amountNumbersInLine++;
        }
    }

    printf("Result:\t%d\n", sum);
}

bool isSafe(int maxIndex, int *arr) {
    bool isIncreasing = arr[0] < arr[1];
    int diff = 0;
    for (int i = 0; i < maxIndex; i++) {
        if (!(arr[i] < arr[i + 1] == isIncreasing)) {
            return false;
        }
        if (isIncreasing) {
            diff = arr[i + 1] - arr[i];
        } else {
            diff = arr[i] - arr[i + 1];
        }
        if (!(diff > 0 && diff < 4)) {
            return false;
        }
    }
    return true;
}

void fillStringFromFile(char *values) {
    int index = 0;
    FILE *fileCodes;
    fileCodes = fopen(NAME_FILE, "r");
    if (fileCodes) {
        while (fgets(values + (index * LINE_LENGTH), LINE_LENGTH, fileCodes)) {
            index++;
        }
    }
    fclose(fileCodes);
}
