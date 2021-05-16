#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int num, i, j, sum, a, b;
	cin >> num;
	vector<int> ans(num * num + 1, 0);
	vector<vector<int>> d(num, vector<int>(num));
	for (i = 0; i < num; i++) {
		sum = 0;
		for (j = 0; j < num; j++) {
			scanf_s("%d", &a);
			sum += a;
			d[i][j] = sum;
		}
	}
	for (i = 1; i < num; i++) {
		for (j = 0; j < num; j++) {
			d[i][j] += d[i - 1][j];
		}
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			for (a = i; a < num; a++) {
				for (b = j; b < num; b++) {
					sum = d[a][b];
					if (i > 0)
						sum -= d[i - 1][b];
					if (j > 0)
						sum -= d[a][j - 1];
					if (i > 0 && j > 0)
						sum += d[i - 1][j - 1];
					ans[(a - i + 1)*(b - j + 1)] = max(ans[(a - i + 1)*(b - j + 1)], sum);
				}
			}
		}
	}
	for (sum = 0, i = 1; i <= num * num; i++) {
		if (sum > ans[i])
			ans[i] = sum;
		else
			sum = ans[i];
	}
	cin >> num;
	for (i = 0; i < num; i++) {
		scanf_s("%d", &a);
		printf("%d\n", ans[a]);
	}
	return 0;
}