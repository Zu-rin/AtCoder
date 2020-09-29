#include <iostream>
#include <vector>
#include <algorithm>
#define F false
#define T true

using namespace std;

int num;

int Search(vector<bool> &m, const vector<vector<bool>> &d, int p) {
	if (p == num) {
		int ans = 0;
		for (int i = 0; i < num; i++) {
			if (m[i] == F)
				continue;
			ans++;
			for (int j = i + 1; j < num; j++) {
				if (m[j] == F)
					continue;
				if (!d[i][j])
					return 0;
			}
		}
		return ans;
	}
	int a, b;
	m[p] = T;
	a = Search(m, d, p + 1);
	m[p] = F;
	b = Search(m, d, p + 1);
	return max(a, b);
}

int main(void) {
	int k, i = 0, a, b;
	cin >> num >> k;
	vector<bool> m(num, F);
	vector<vector<bool>> d(num, vector<bool>(num, F));
	for (; i < k; i++) {
		scanf_s("%d%d", &a, &b);
		d[--a][--b] = T;
		d[b][a] = T;
	}
	a = Search(m, d, 0);
	printf("%d\n", a);
	return 0;
}