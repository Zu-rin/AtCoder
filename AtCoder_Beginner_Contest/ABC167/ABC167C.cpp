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

int AllCost(int v, vector<int> & c) {
	int i, ans = 0;
	rep(i, c.size()) {
		if (v & (1 << i)) {
			ans += c[i];
		}
	}
	return ans;
}

int Judge(int k, int v, vector<vector<int>>& d) {
	int i, j;
	vector<int> s(d[0].size(), 0);
	rep(i, d.size()) {
		if (v & (1 << i)) {
			rep(j, d[i].size()) {
				s[j] += d[i][j];
			}
		}
	}
	rep(i, s.size()) {
		if (s[i] < k) {
			return false;
		}
	}
	return true;
}

int Search(int n, int k, int v, vector<int> &c, vector<vector<int>> & d) {
	if (n == c.size()) {
		if (Judge(k, v, d))
			return AllCost(v, c);
		else
			return INF;
	}
	int ans = Search(n + 1, k, v << 1, c, d);
	chmin(ans, Search(n + 1, k, (v << 1) + 1, c, d));
	return ans;
}


int main(void) {
	int num, i, j, m, k, ans;
	cin >> num >> m >> k;
	vector<int> c(num);
	vector<vector<int>> d(num, vector<int>(m));
	rep(i, num) {
		cin >> c[i];
		rep(j, m)
			cin >> d[i][j];
	}
	ans = Search(0, k, 0, c, d);
	if (ans == INF)
		printf("-1\n");
	else
		cout << ans << "\n";
	return 0;
}