#include <iostream>
#include <vector>
#include <algorithm>
#define INF -1 * (1 << 30)

using namespace std;

int num;

int Search(vector<int> &f, vector<vector<int>> &p, int x, int t) {
	if (t == 10) {
		if (x == 0)
			return INF;
		int n, d, ans = 0;
		for (int i = 0; i < num; i++) {
			d = 0;
			n = x & f[i];
			while (n > 0) {
				if (n & 1)
					d++;
				n >>= 1;
			}
			ans += p[i][d];
		}
		return ans;
	}
	int ans = Search(f, p, x << 1, t + 1);
	ans = max(ans, Search(f, p, (x << 1) + 1, t + 1));
	return ans;
}

int main(void) {
	int i = 0, j, buf, ans;
	cin >> num;
	vector<int> f(num, 0);
	vector<vector<int>> p(num, vector<int>(11));
	for (; i < num; i++) {
		for (j = 0; j < 10; j++) {
			scanf_s("%d", &buf);
			if (buf)
				f[i] += 1 << j;
		}
	}
	for (i = 0; i < num; i++)
		for (j = 0; j < 11; j++)
			scanf_s("%d", &p[i][j]);
	ans = Search(f, p, 0, 0);
	printf("%d\n", ans);
	return 0;
}