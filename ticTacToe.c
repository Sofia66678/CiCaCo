#include <stdio.h>

enum Cell { EMPTY, X, O}; //remember, empty is 0, x is 1, o is 2.

void draw(enum Cell *ptr) {
	enum Cell *dupe_ptr = ptr;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (*dupe_ptr == X) {
				printf("X");
			} else if (*dupe_ptr == O) {
				printf("O");
			} else {
				printf(".");
			}
		dupe_ptr++;
		}
		printf("\n");
	}
}

int turnsLeft(enum Cell *ptr) {
	enum Cell *dupe_ptr = ptr;
	int count = 0;
	for (int i = 0; i < 9; i++) {
		if (*dupe_ptr == EMPTY) {
			count++;
		}
		dupe_ptr++;
	}

	return count;
}

enum Cell checkWinner(enum Cell *ptr) {
	enum Cell *dupe_ptr = ptr;
	dupe_ptr = dupe_ptr + 4;
	if ((*dupe_ptr != EMPTY) && (*(dupe_ptr - 4) == *dupe_ptr) && (*(dupe_ptr + 4) == *dupe_ptr) || (*(dupe_ptr - 2) == *dupe_ptr) && (*(dupe_ptr + 2) == *dupe_ptr)) {
		return *dupe_ptr;
	}

	dupe_ptr = ptr;
	for (int i = 0; i < 3; i++) {
		if ((*dupe_ptr != EMPTY) && (*(dupe_ptr + 1) == *dupe_ptr) && (*(dupe_ptr + 2) == *dupe_ptr)) {
			return *dupe_ptr;
		}
		dupe_ptr = dupe_ptr + 3;
	}

	dupe_ptr = ptr;
	for (int i = 0; i < 3; i++) {
                if ((*dupe_ptr != EMPTY) && (*(dupe_ptr + 3) == *dupe_ptr) && (*(dupe_ptr + 6) == *dupe_ptr)) {
                        return *dupe_ptr;
                }
                dupe_ptr = dupe_ptr + 1;
        }
// yeah yeah duplicate code, ill work on it later


	return EMPTY;
}

void playerInput(int *y, int *x, enum Cell turn_of) {
	if (turn_of == X) {
		printf("TURN OF: X, ");
	} else {
		printf("TURN OF: O, ");
	}

        printf("Input the Y cord (0-2): ", turn_of);
        scanf("%d", y);

        printf("Input the X cord (0-2): ");
	scanf("%d", x); //apparently you shouln't put the & when dealing with pointers for variables you want to change outside of the function.
}

int main () {
	enum Cell map[3][3] = { {EMPTY, EMPTY, EMPTY} , {EMPTY, EMPTY, EMPTY} , {EMPTY, EMPTY, EMPTY} }; // map[y][x], remember
	enum Cell *ptr = &map[0][0];

	while (turnsLeft(ptr) > 0 && checkWinner(ptr) == 0) {
		draw(ptr);
		enum Cell turn_of = EMPTY;

		if (turnsLeft(ptr) % 2 != 0) {
			turn_of = X;
		} else {
			turn_of = O;
		}

		int y;
		int x;

		playerInput(&y, &x, turn_of);

		while (map[y][x] != EMPTY) {
			printf("\nLOCATION NOT EMPTY! Type other valuves!\n");
			playerInput(&y, &x, turn_of);
		}

		map[y][x] = turn_of;
	}

	if (turnsLeft(ptr) <= 0) {
		printf("Draw, no turns left.\n");
	} else if (checkWinner(ptr) == X) {
		printf("X won!\n");
	} else {
		printf("O won!\n");
	}
	//printf("\nTurns left:%d\nWho won:%d\n", turnsLeft(ptr), checkWinner(ptr));
	return 0;
}
