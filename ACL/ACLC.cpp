#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void DFS(int s, int k, vector<vector<int>> & d, vector<int> &ans) {
	ans[s] = k;
	int i;
	rep(i, d[s].size()) {
		if (ans[d[s][i]] == 0) {
			DFS(d[s][i], k, d, ans);
		}
	}
	return;
}

int main(void) {
	int num, m, i, a, b, k = 0;
	cin >> num >> m;
	vector<vector<int>> d(num + 1);
	vector<int> ans(num + 1, 0);
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	for (i = 1; i <= num; i++) {
		if (ans[i] == 0) {
			k++;
			DFS(i, k, d, ans);
		}
	}
	cout << k - 1 << "\n";
	return 0;
}