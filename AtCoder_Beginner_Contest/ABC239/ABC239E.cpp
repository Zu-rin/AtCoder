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

void Search(vector<vector<int>> &d, vector<vector<int>> &ans, vector<int> &x, vector<int> &ok, int n = 1) {
	int i;
	vector<int> a = { x[n] };
	ok[n] = 0;
	for (int nx : d[n]) {
		if (ok[nx]) {
			Search(d, ans, x, ok, nx);
			a.insert(a.begin(), ans[nx].begin(), ans[nx].end());
		}
	}
	sort(a.begin(), a.end(), greater<int>());
	ans[n] = { a.begin(), a.begin() + min(20, (int)a.size()) };
	return;
}

int main(void) {
	int num, i, q, a, b;
	cin >> num >> q;
	vector<int> x(num + 1), ok(num + 1, 1);
	vector<vector<int>> d(num + 1), ans(num + 1);
	for (i = 1; i <= num; i++)
		scanf_s("%d", &x[i]);;
	rep(i, num - 1) {
		scanf_s("%d%d", &a, &b);
		d[a].push_back(b);
		d[b].push_back(a);
	}
	Search(d, ans, x, ok);
	rep(i, q) {
		scanf_s("%d%d", &a, &b);
		cout << ans[a][b - 1] << "\n";
	}
	return 0;
}