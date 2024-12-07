#ifndef READFILE
#define READFILE

//#define TEST
#ifdef TEST
#define NAME_FILE "testInput.txt"
#define LEN_LINE 11
#define AMOUNT_LINES 10
#define LEN_FILE LEN_LINE * AMOUNT_LINES
#else

#define NAME_FILE "input.txt"
#define LEN_LINE 131
#define AMOUNT_LINES 130
#define LEN_FILE LEN_LINE * AMOUNT_LINES
#endif

int fillStringFromFile(char *values);
#endif
