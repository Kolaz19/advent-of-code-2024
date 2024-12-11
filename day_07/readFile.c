#include "readFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *getArrayFromString(char *line, long long *result, int *numbers, int *amountOfNumbers) {
    long long number = 0;
	*amountOfNumbers = 0;

    if (sscanf(line, "%lld", result) != 1) {
        exit(EXIT_FAILURE);
    }

    while (*(line++) != ':')
        ;

    while (*line != '\n') {
        if (sscanf(line, "%d", numbers + *amountOfNumbers) != 1) {
            exit(EXIT_FAILURE);
        }
        if (*(numbers + *amountOfNumbers) > 99) {
            line += 4;
        } else if (*(numbers + *amountOfNumbers) > 9) {
            line += 3;
        } else {
            line += 2;
        }

		(*amountOfNumbers)++;
    }
    return line;
}
