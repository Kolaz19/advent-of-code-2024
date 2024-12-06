#ifndef READFILE
#define READFILE

/*
#define NAME_FILE "testInput.txt"
#define LEN_LINE 11
#define AMOUNT_LINES 10
#define LEN_FILE LEN_LINE * AMOUNT_LINES
*/

#define NAME_FILE "input.txt"
#define LEN_LINE 131
#define AMOUNT_LINES 130
#define LEN_FILE LEN_LINE * AMOUNT_LINES + 1

int fillStringFromFile(char *values);
#endif
