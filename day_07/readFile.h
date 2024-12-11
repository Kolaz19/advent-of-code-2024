#ifndef READFILE
#define READFILE

//#define TEST
#ifdef TEST
#define NAME_FILE "testInput.txt"
#define LEN_LINE 60
#define AMOUNT_LINES 424
#define LEN_FILE LEN_LINE * AMOUNT_LINES
#else

#define NAME_FILE "input.txt"
#define LEN_LINE 100
#define AMOUNT_LINES 850
#define LEN_FILE LEN_LINE * AMOUNT_LINES
#endif

int fillStringFromFile(char *values);
char* getArrayFromString(char *line, long long *result, int *numbers, int *amountOfNumbers);
#endif
