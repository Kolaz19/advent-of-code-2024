#include "readFile.h"
#include "guard.h"
#include "result.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[LEN_FILE+1];
    fillStringFromFile(input);

	char* result[LEN_FILE] = { NULL };

	guard guard;
	setStartingPos(input, &guard);
	addPosToResult(guard.pos, result, LEN_FILE);
	
	while (!willGuardLeaveMap(input, LEN_FILE, LEN_LINE, &guard)) {
		updateGuard(&guard, LEN_LINE);
		addPosToResult(guard.pos, result, LEN_FILE);
	}
	int sum = getResult(result, LEN_FILE);

    printf("Result: %d", sum);
}
