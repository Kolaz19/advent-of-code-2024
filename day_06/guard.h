#ifndef GUARD
#define GUARD
#include <stdbool.h>

typedef enum DIRECTION {
	L,
	U,
	R,
	D
}DIRECTION;

typedef struct guard {
	char* pos;
	DIRECTION dir;
}guard;

void setStartingPos(char *input, guard* guard);
bool willGuardLeaveMap(char *input, int filelen, int linelen, guard *guard);
void updateGuard(guard *guard, int linelen);

#endif
