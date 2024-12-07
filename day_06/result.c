#include <stdbool.h>
#include <stdlib.h>

void addPosToList(char* curChar, char** result, int arrSize) {
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

bool alreadyInList(char* curChar, char** list, int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		if (list[i] == NULL) {
			return false;
		} else if (list[i] == curChar) {
			return true;
		}
	}
	return false;
}
