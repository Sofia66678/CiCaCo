#include <stdio.h>

enum Cell { EMPTY, X, O};

void draw(enum Cell *ptr) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			int cell = *ptr;
			if (cell == 1) {
				printf("X");
			} else if (cell == 2) {
				printf("O");
			} else {
				printf(".");
			}
		ptr++;
		}
		printf("\n");
	}
}

int turnsLeft(enum Cell *ptr) {
	int count = 0;
	for (int i = 0; i < 9; i++) {
		int cell = *ptr;
		if (cell == EMPTY) {
			count++;
		}
		ptr++;
	}

	return count;
}

int checkWinner(enum Cell *ptr) {
	return 0;
}

int main () {
	enum Cell map[3][3] = { {EMPTY, EMPTY, EMPTY} , {EMPTY, EMPTY, EMPTY} , {EMPTY, EMPTY, EMPTY} };
	enum Cell *ptr = &map[0][0];
	draw(ptr);
	printf("\nTurns left:%d\nWho won:%d\n", turnsLeft(ptr), checkWinner(ptr));
	return 0;
}
