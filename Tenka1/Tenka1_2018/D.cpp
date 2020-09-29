#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	int n, a, i, j, x = 1;
	cin >> n;
	a = (int)sqrt(8 * n + 1);
	if (a * a != 8 * n + 1) {
		printf("No\n");
		return 0;
	}
	a >>= 1;
	printf("Yes\n%d\n", a + 1);
	vector<vector<int>> d(a + 1, vector<int>(a));
	for (i = 0; i < a; i++) {
		for (j = i; j < a; j++) {
			d[i][j] = x;
			d[j + 1][i] = x++;
		}
	}
	for (i = 0; i <= a; i++) {
		printf("%d ", a);
		for (j = 0; j < a; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}