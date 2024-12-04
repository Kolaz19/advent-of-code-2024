#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_FILE "input.txt"
#define LEN_ROW 141
#define LEN_LINES 140
#define FILE_LEN LEN_ROW *LEN_LINES + 1

typedef enum offset {
    LEFT = -1,
    NO_OFFSET = 0,
    RIGHT = 1
} offset;

int fillStringFromFile(char *values);
int getNumberOfXmas(char *cur, char *start);
bool inSequence(char *cur, int indx);
bool isLeft(char *cur, char *start);
bool isRight(char *cur, char *start);
bool isUnder(char *cur, char *start, offset off);
bool isAbove(char *cur, char *start, offset off);

int main() {
    char input[FILE_LEN];
    if (!(fillStringFromFile(input))) {
        exit(EXIT_FAILURE);
    }

    char *curChar = input;
    int sum = 0;
    do {
        sum += getNumberOfXmas(curChar, input);
    } while (*(++curChar) != '\0');
    printf("Result: %d", sum);
}

bool isLeft(char *cur, char *start) {
    char *tmp = cur;

    for (int i = 0; i < 4; i++) {
        if (tmp < start) {
            return false;
        }
        if (!inSequence(tmp, i)) {
            return false;
        }
		tmp--;
    }

    return true;
}

bool isRight(char *cur, char *start) {
    char *tmp = cur;

    for (int i = 0; i < 4; i++) {
        if (tmp > start + FILE_LEN) {
            return false;
        }
        if (!inSequence(tmp, i)) {
            return false;
        }
		tmp++;
    }
    return true;
}

bool isAbove(char *cur, char *start, offset off) {
    char *tmp = cur;

    for (int i = 0; i < 4; i++) {
        if (tmp < start) {
            return false;
        }
        if (!inSequence(tmp, i)) {
            return false;
        }
        tmp -= LEN_ROW;
        tmp += off;
    }
    return true;
}

bool isUnder(char *cur, char *start, offset off) {
    char *tmp = cur;

    for (int i = 0; i < 4; i++) {
        if (tmp > start + FILE_LEN) {
            return false;
        }
        if (!inSequence(tmp, i)) {
            return false;
        }
        tmp += LEN_ROW;
        tmp += off;
    }
    return true;
}

bool inSequence(char *cur, int indx) {
    switch (indx) {
    case 0:
        return *cur == 'X';
    case 1:
        return *cur == 'M';
    case 2:
        return *cur == 'A';
    case 3:
        return *cur == 'S';
    }
    return false;
}

int getNumberOfXmas(char *cur, char *start) {
    int sum = 0;

	//Check if current char is 'X'
    if (!inSequence(cur, 0)) {
        return sum;
    }
	//Check left & right
    if (isLeft(cur, start)) {
        sum++;
    }
    if (isRight(cur, start)) {
        sum++;
    }
	//Check up & down
    if (isAbove(cur, start, NO_OFFSET)) {
        sum++;
    }
    if (isAbove(cur, start, LEFT)) {
        sum++;
    }
    if (isAbove(cur, start, RIGHT)) {
        sum++;
    }
    if (isUnder(cur, start, NO_OFFSET)) {
        sum++;
    }
    if (isUnder(cur, start, LEFT)) {
        sum++;
    }
    if (isUnder(cur, start, RIGHT)) {
        sum++;
    }

    return sum;
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
