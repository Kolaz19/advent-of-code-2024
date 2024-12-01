#include <stdbool.h>
#include <stdio.h>

#define NAME_FILE "input.txt"
#define LINE_LENGTH 50
#define AMOUNT_LINES 1000

void fillStringFromFile(char *values);
void sortList(int *list);
int getAmountInList(int num, int *list);

int main() {
    char input[LINE_LENGTH * AMOUNT_LINES];

    fillStringFromFile(input);

    int list1[AMOUNT_LINES];
    int list2[AMOUNT_LINES];

    int curIndex = 0;
    char *curLine = input;

    // Extract integers from string
    while (sscanf(curLine, "%d %d", &(list1[curIndex]), &(list2[curIndex])) == 2) {
        curLine = curLine + LINE_LENGTH;
        curIndex++;
    }

    int sum = 0;
    for (int i = 0; i < AMOUNT_LINES; i++) {
        sum += list1[i] * getAmountInList(list1[i], list2);
    }

    printf("%d\n", sum);
}

int getAmountInList(int num, int *list) {
    int amount = 0;
    for (int i = 0; i < AMOUNT_LINES; i++) {
        if (list[i] == num) {
            amount++;
        }
    }
    return amount;
}

// Bubble sort
void sortList(int *list) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < AMOUNT_LINES - 1; i++) {
            if (list[i] > list[i + 1]) {
                int tmp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = tmp;
                sorted = false;
            }
        }
    }
}

void fillStringFromFile(char *values) {
    int index = 0;
    char codeLine[LINE_LENGTH];
    FILE *fileCodes;
    fileCodes = fopen(NAME_FILE, "r");
    if (fileCodes) {
        while (fgets(values + (index * LINE_LENGTH), LINE_LENGTH, fileCodes)) {
            index++;
        }
    }
    fclose(fileCodes);
}
