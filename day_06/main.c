#include "guard.h"
#include "readFile.h"
#include "result.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool stuckInLoop(guard *copyOfGuard, char *input, char *newObstacle);
bool alreadyTraversed(guard *path, int curPathIndex, guard *guard);

int main() {
    char input[LEN_FILE + 1];
    fillStringFromFile(input);

    char *result[LEN_FILE] = {NULL};
    char *checkedPositions[LEN_FILE] = {NULL};
    char *newObstacle = NULL;

    guard mainGuard;
    guard copyOfGuard;
    setStartingPos(input, &mainGuard);
    addPosToList(mainGuard.pos, result, LEN_FILE);

    while (!willGuardLeaveMap(input, LEN_FILE, LEN_LINE, &mainGuard)) {

        newObstacle = getFuturePos(&mainGuard, LEN_LINE);
        // Return copy of mainGuard, but turned to the right
        if (updateGuard(&mainGuard, LEN_LINE, &copyOfGuard, NULL)) {
            // Only check previously not traversed positions
            if (!alreadyInList(newObstacle, checkedPositions, LEN_FILE) && stuckInLoop(&copyOfGuard, input, newObstacle)) {
                addPosToList(newObstacle, result, LEN_FILE);
            }
            addPosToList(newObstacle, checkedPositions, LEN_FILE);
        }
    }
    //-1 because first position should not count
    int sum = getResult(result, LEN_FILE) - 1;

    printf("Result: %d", sum);
}

// Check if from this point on guard traverses already traversed positions
bool stuckInLoop(guard *copyOfGuard, char *input, char *newObstacle) {
    int curPathIndex = 0;
    guard path[LEN_FILE];

    while (!willGuardLeaveMap(input, LEN_FILE, LEN_LINE, copyOfGuard)) {
        path[curPathIndex].pos = copyOfGuard->pos;
        path[curPathIndex].dir = copyOfGuard->dir;
        curPathIndex++;
        updateGuard(copyOfGuard, LEN_LINE, NULL, newObstacle);
        if (alreadyTraversed(path, curPathIndex, copyOfGuard)) {
            return true;
        }
    }
    return false;
}

bool alreadyTraversed(guard *path, int curPathIndex, guard *guard) {
    for (int i = 0; i < curPathIndex; i++) {
        if (guard->pos == path[i].pos && guard->dir == path[i].dir) {
            return true;
        }
    }
    return false;
}
