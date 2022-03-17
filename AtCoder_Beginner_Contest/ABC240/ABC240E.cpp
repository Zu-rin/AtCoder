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

struct section {
	int l, r;
};

int Search(vector<vector<int>>& d, vector<section> &ans, vector<char>& ok, int n = 1) {
	int lf = (n != 1 and d[n].size() == 1);
	ok[n] = 0;
	for (int nx : d[n]) {
		if (ok[nx]) {
			ok[nx] = 0;
			ans[nx].l = ans[n].l + lf;
			lf += Search(d, ans, ok, nx);
		}
	}
	ans[n].r = ans[n].l + max(0, lf - 1);
	return lf;
}

int main(void) {
	int num, i, a, b;
	cin >> num;
	vector<section> ans(num + 1);
	vector<char> ok(num + 1, 1);
	vector<vector<int>> d(num + 1);
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	ans[1].l = 1;
	Search(d, ans, ok);
	for (i = 1; i <= num; i++) {
		cout << ans[i].l << " ";
		cout << ans[i].r << "\n";
	}
	return 0;
}