#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int startX, startY, endX, endY, time, speed, num, i = 0;
	double dist;
	cin >> startX >> startY >> endX >> endY >> time >> speed >> num;
	int posX, posY;
	for (; i < num; i++) {
		cin >> posX >> posY;
		dist = sqrt(pow(abs(startX - posX), 2) + pow(abs(startY - posY), 2));
		dist += sqrt(pow(abs(endX - posX), 2) + pow(abs(endY - posY), 2));
		if (dist / speed > time)
			continue;
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}