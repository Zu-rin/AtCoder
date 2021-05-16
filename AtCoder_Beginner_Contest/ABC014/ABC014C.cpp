#include <stdio.h>
#include <iostream>

#define COLORS 1000001

using namespace std;

int main(void) {
	int num;
	cin >> num;
	int min, max, colors[COLORS+1] = { 0 }, ans = 0, sum = 0, i = 0;
	for (; i < num; i++) {
		cin >> min >> max;
		colors[min]++;
		colors[max + 1]--;
	}
	i = 0;
	while (colors[i] == 0)
		i++;
	for (; i < COLORS; i++) {
		sum += colors[i];
		if (ans < sum)
			ans = sum;
	}
	cout << ans << "\n";
	return 0;
}