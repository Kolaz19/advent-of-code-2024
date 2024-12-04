#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_FILE "input.txt"
#define LEN_ROW 141
#define LEN_LINES 140
#define FILE_LEN LEN_ROW *LEN_LINES + 1

int fillStringFromFile(char *values);
bool isMas(char *cur, char *start);

int main() {
    char input[FILE_LEN];
    if (!(fillStringFromFile(input))) {
        exit(EXIT_FAILURE);
    }

    char *curChar = input;
    int sum = 0;
    do {
        if (isMas(curChar, input)) {
            sum++;
        }
    } while (*(++curChar) != '\0');
    printf("Result: %d", sum);
}

bool isMas(char *cur, char *start) {
    int sum = 0;

	//Check middle char 'A' and if this character is in first or last row
    if (*cur != 'A' || (cur - LEN_ROW) < start || (cur + LEN_ROW) > (start + FILE_LEN)) {
        return false;
    }

	//Collect surrounding characters
    char surrounding[4];
    // UP LEFT
    surrounding[0] = *(cur - (LEN_ROW + 1));
    // UP RIGHT
    surrounding[1] = *(cur - (LEN_ROW - 1));
    // DOWN LEFT
    surrounding[2] = *(cur + (LEN_ROW - 1));
    // DOWN RIGHT
    surrounding[3] = *(cur + (LEN_ROW + 1));

	for (int i = 0; i < 4; i++) {
		if (surrounding[i] != 'M' && surrounding[i] != 'S') {
			return false;
		}
	}

	//Opposing characters have to differ
	if (surrounding[0] == surrounding[3]) {
		return false;
	}
	if (surrounding[1] == surrounding[2]) {
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
