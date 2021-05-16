#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;
typedef long long ll;

int num;

void dfs(int n, vector<vector<int>> &d, vector<int> &k, vector<int> &day) {
	if (k[n] == num - 1)
		return;
	int a = d[n][k[n]];
	if (k[a] == num - 1 || d[a][k[a]] != n)
		return;
	day[n] = max(day[n], day[a]) + 1;
	day[a] = day[n];
	k[n]++;
	k[a]++;
	dfs(n, d, k, day);
	dfs(a, d, k, day);
	return;
}


int main(void) {
	int i, j, ans = 0;
	cin >> num;
	vector<vector<int>> d(num, vector<int>(num - 1));
	vector<int> day(num, 0), k(num, 0);
	for (i = 0; i < num; i++) {
		for (j = 0; j < num - 1; j++) {
			scanf_s("%d", &d[i][j]);
			d[i][j]--;
		}
	}
	for (i = 0; i < num; i++)
		dfs(i, d, k, day);
	for (i = 0; i < num; i++) {
		if (k[i] < num - 1) {
			printf("-1\n");
			return 0;
		}
		ans = max(ans, day[i]);
	}
	cout << ans << "\n";
	return 0;
}