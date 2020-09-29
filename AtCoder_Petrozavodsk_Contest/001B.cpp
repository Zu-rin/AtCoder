#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(void) {
	int num, i, j;
	ll a = 0, b = 0;
	cin >> num;
	vector<vector<int>> d(2, vector<int>(num));
	for (i = 0; i < 2; i++) {
		for (j = 0; j < num; j++)
			scanf_s("%d", &d[i][j]);
	}
	for (i = 0; i < num; i++) {
		if (d[0][i] < d[1][i])
			a += (d[1][i] - d[0][i]) >> 1;
		else if (d[0][i] > d[1][i])
			b += d[0][i] - d[1][i];
	}
	if (a >= b)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}