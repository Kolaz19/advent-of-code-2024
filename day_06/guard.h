#ifndef GUARD
#define GUARD
#include <stdbool.h>

typedef enum Direction {
	L,
	U,
	R,
	D
}Direction;

typedef struct guard {
	char* pos;
	Direction dir;
}guard;

void setStartingPos(char *input, guard* guard);
bool willGuardLeaveMap(char *input, int filelen, int linelen, guard *guard);
bool updateGuard(guard *mainGuard, int linelen, guard* copyOfGuard, char* optionalObstacle);
char *getFuturePos(guard *guard, int linelen);

#endif
