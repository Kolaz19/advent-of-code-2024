#include "processLine.h"
#include "readFile.h"
#include <criterion/criterion.h>

Test(input, endofstring) {
    char input[LEN_LINE * AMOUNT_LINES + 1];
    fillStringFromFile(input);
    cr_assert_eq(input[LEN_LINE * AMOUNT_LINES], '\0');
}

Test(input, processString) {
    char *input = "300: 25 2 999\n"
                  "50: 4 55 22 88 999\n";

    int arr[3];
    long long result;
    int amount;
    input = getArrayFromString(input, &result, arr, &amount);
    cr_assert_eq(*input, '\n');
    cr_assert_eq(result, 300);
    cr_assert_eq(amount, 3);
}

Test(process, randomArray) {
    int arr[3] = {3, 10, 100};
    int arr2[3] = {10, 100, 3};
	int arr3[7] = {10, 10, 10, 10, 10, 10 , 3};
	int arr4[2] = {2, 3};
	int arr5[3] = {2, 3, 3};
    long long result = 1300;
    long long result2 = 30600;
    bool target;
    cr_assert(isLegit(PLUS, 0, arr, 3, result));
    cr_assert_not(isLegit(PLUS, 0, arr2, 3, result));
    cr_assert(isLegit(PLUS, 0, arr3, 7, result2));
    cr_assert(isLegit(PLUS, 0, arr4, 2, 6));
    cr_assert_not(isLegit(PLUS, 0, arr4, 3, 6));
}
