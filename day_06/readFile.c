#include <stdio.h>
#include "readFile.h"

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
