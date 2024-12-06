#include "guard.h"
#include <stdbool.h>
// clang-format off
#define turnRight(dir) if ((dir) == 3) { dir = 0; } else { dir++; }
// clang-format on

bool isGuard(char *cur);
char *getFuturePos(guard *guard, int linelen);

void setStartingPos(char *input, guard *guard) {
    char *curChar = input;
    do {
        if (isGuard(curChar)) {
            guard->pos = curChar;
            guard->dir = U;
        }
    } while (*(++curChar) != '\0');
}

bool isGuard(char *cur) {
    if (*cur == '^') {
        return true;
    }
    return false;
}

char *getFuturePos(guard *guard, int linelen) {
    char *pos = guard->pos;
    switch (guard->dir) {
    case L:
        return (pos - 1);
        break;
    case R:
        return (pos + 1);
        break;
    case U:
        return (pos - linelen);
        break;
    case D:
        return (pos + linelen);
        break;
    }
}

bool willGuardLeaveMap(char *input, int filelen, int linelen, guard *guard) {
    char *futurePos = getFuturePos(guard, linelen);
    if (futurePos < input || futurePos > input + filelen || *futurePos == '\n') {
        return true;
    } else {
        return false;
    }
}

void updateGuard(guard *guard, int linelen) {
    char *futurePos = getFuturePos(guard, linelen);
    if (*futurePos == '#') {
        turnRight(guard->dir);
    } else {
        guard->pos = futurePos;
    }
}
