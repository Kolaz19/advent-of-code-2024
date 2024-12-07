#include "guard.h"
#include "readFile.h"
#include <criterion/criterion.h>

Test(input, endofstring) {
    char input[LEN_LINE * AMOUNT_LINES + 1];
    fillStringFromFile(input);
    cr_assert_eq(input[LEN_LINE * AMOUNT_LINES], '\0');
    cr_assert_eq(input[LEN_LINE * AMOUNT_LINES - 1], '\n');
}

Test(guard, directionTurn) {
    char *testString = ".#.\n"
                       ".^#\n"
                       ".#.\n";
    guard guard;
    setStartingPos(testString, &guard);

    int amountMoves = 0;
    while (!willGuardLeaveMap(testString, strlen(testString), 4, &guard)) {
        updateGuard(&guard, 4, NULL, NULL);
        amountMoves++;
    }
    cr_assert_eq(amountMoves, 4);
    // Check end position
    cr_assert_eq(testString + 4, guard.pos);
}

Test(guard, leaveMap) {
    char *testString = "...\n"
                       "...\n"
                       "...\n";
    // TOP LEFT FACING UP
    guard guard;
    guard.pos = testString;
    guard.dir = U;
    cr_assert(willGuardLeaveMap(testString, strlen(testString), 4, &guard));

    // TOP LEFT FACING LEFT
    guard.pos = testString;
    guard.dir = L;
    cr_assert(willGuardLeaveMap(testString, strlen(testString), 4, &guard));

    // DOWN RIGHT FACING RIGHT
    guard.pos = testString + 10;
    guard.dir = R;
    cr_assert(willGuardLeaveMap(testString, strlen(testString), 4, &guard));

    // DOWN RIGHT FACING DOWN
    guard.pos = testString + 10;
    guard.dir = D;
    cr_assert(willGuardLeaveMap(testString, strlen(testString), 4, &guard));

    // MIDDLE LEFT TURNING LEFT
    guard.pos = testString + 4;
    guard.dir = L;
    cr_assert(willGuardLeaveMap(testString, strlen(testString), 4, &guard));

    // MIDDLE LEFT TURNING RIGHT
    guard.pos = testString + 6;
    guard.dir = R;
    cr_assert(willGuardLeaveMap(testString, strlen(testString), 4, &guard));
}

Test(guard, notLeaveMap) {
    char *testString = "...\n"
                       "...\n"
                       "...\n";
    guard guard;
	//Stand in middle
    guard.pos = testString + 5;

	//Check each direction
    for (int i = 0; i < 4; i++) {
        guard.dir = i;
        cr_assert_not(willGuardLeaveMap(testString, strlen(testString), 4, &guard));
    }
}
