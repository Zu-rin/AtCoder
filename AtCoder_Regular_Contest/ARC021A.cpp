#include <iostream>

using namespace std;

int main(void) {
	int d[4][4], i, j;
	bool con = false;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			scanf_s("%d", &d[i][j]);
		}
	}
	for (i = 0; i < 4; i++) {
		j = 0;
		while (!con && j < 3) {
			if (d[i][j] == d[i][j + 1]) {
				con = true;
				break;
			}
			j++;
		}
	}
	for (j = 0; j < 4; j++) {
		i = 0;
		while (!con && i < 3) {
			if (d[i][j] == d[i + 1][j]) {
				con = true;
				break;
			}
			i++;
		}
	}
	if (con)
		printf("CONTINUE\n");
	else
		printf("GAMEOVER\n");
	return 0;
}