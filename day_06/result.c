#include "result.h"
#include <stdlib.h>

void addPosToResult(char* curChar, char** result, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		if (result[i] == curChar) {
			return;
		} else if (result[i] == NULL) {
			result[i] = curChar;
			return;
		}
	}
}

int getResult(char** result, int arrSize) {
	int sum = 0;
	for (int i = 0; i < arrSize; i++) {
		if (result[i] == NULL) {
			break;
		}
		sum++;
	}
	return sum;
}
