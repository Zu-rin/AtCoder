#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int W;
int Search(int a, int w, vector<vector<int>> &d, const vector<int> &l, vector<int> &k, vector<vector<vector<vector<int>>>> &dp) {
	if (W < w)
		return 0;
	if (dp[k[0]][k[1]][k[2]][k[3]] > 0)
		return dp[k[0]][k[1]][k[2]][k[3]];
	int i, ans = 0;
	for (i = 0; i < 4; i++)
		ans += d[i][k[i]];
	for (i = 0; i < 4; i++) {
		if (l[i] > k[i]) {
			k[i]++;
			ans = max(ans, Search(a, w + a + i, d, l, k, dp));
			k[i]--;
		}
	}
	dp[k[0]][k[1]][k[2]][k[3]] = ans;
	return ans;
}

int main(void) {
	int num, w, i, j, v, a;
	cin >> num >> W >> a >> v;
	vector<vector<int>> d(4, vector<int>(num + 1));
	vector<int> l(4, 0), k(4, 0);
	d[0][l[0]++] = v;
	for (i = 0; i < num - 1; i++) {
		cin >> w >> v;
		d[w - a][l[w - a]++] = v;
	}
	for (i = 0; i < 4; i++) {
		sort(d[i].begin(), d[i].end(), greater<int>());
		for (j = 0; j < l[i] - 1; j++) {
			d[i][j + 1] += d[i][j];
		}
		for (j = l[i]; j > 0; j--)
			d[i][j] = d[i][j - 1];
		d[i][0] = 0;
	}
	vector<vector<vector<vector<int>>>> dp(l[0] + 1, vector<vector<vector<int>>>(l[1] + 1, vector<vector<int>>(l[2] + 1, vector<int>(l[3] + 1, 0))));
	a = Search(a, 0, d, l, k, dp);
	cout << a << "\n";
	return 0;
}