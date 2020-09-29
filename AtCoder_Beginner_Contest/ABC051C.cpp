#include <iostream>

using namespace std;

int main(void) {
	int sx, sy, gx, gy, i;
	scanf_s("%d%d%d%d", &sx, &sy, &gx, &gy);
	for (i = sy; i < gy; i++)
		printf("U");
	for (i = sx; i < gx; i++)
		printf("R");
	for (i = sy; i < gy; i++)
		printf("D");
	for (i = sx; i <= gx; i++)
		printf("L");
	for (i = sy; i <= gy; i++)
		printf("U");
	for (i = sx; i <= gx; i++)
		printf("R");
	printf("DR");
	for (i = sy; i <= gy; i++)
		printf("D");
	for (i = sx; i <= gx; i++)
		printf("L");
	printf("U\n");
	return 0;
}