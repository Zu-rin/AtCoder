#include <iostream>
#include <vector>
#include <algorithm>
#define T 1
#define F 2

using namespace std;

int mark[3][3] = { 0 }, yoko[3][2], tate[2][3];

int score(int now, int k) {
	int i, j, m = 0;
	if (k == 9) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 2; j++) {
				if (mark[i][j] == mark[i][j + 1])
					m += yoko[i][j];
			}
		}
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 3; j++) {
				if (mark[i][j] == mark[i + 1][j])
					m += tate[i][j];
			}
		}
		return m;
	}
	if (now == F)
		m = 2 << 20;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (mark[i][j] == 0) {
				mark[i][j] = now;
				if (now == T)
					m = max(m, score(now % 2 + 1, k + 1));
				else
					m = min(m, score(now % 2 + 1, k + 1));
				mark[i][j] = 0;
			}
		}
	}
	return m;
}

int main(void) {
	int now = T, i, ans, sum = 0;
	scanf_s("%d%d%d%d%d%d", &tate[0][0], &tate[0][1], &tate[0][2], &tate[1][0], &tate[1][1], &tate[1][2]);
	scanf_s("%d%d%d%d%d%d", &yoko[0][0], &yoko[0][1], &yoko[1][0], &yoko[1][1], &yoko[2][0], &yoko[2][1]);
	for (i = 0; i < 3; i++) {
		sum += yoko[i][0] + yoko[i][1];
		sum += tate[0][i] + tate[1][i];
	}
	ans = score(now, 0);
	cout << ans << "\n";
	cout << sum - ans << "\n";
	return 0;
}