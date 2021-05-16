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

int Cycle(int n, vector<int> & d, vector<int> & c, int dep = 0) {
	if (c[n])
		return dep;
	c[n] = 1;
	return c[n] = Cycle(d[n], d, c, dep + 1);
}

void Solve(int n, int k, vector<int> &d, vector<int> &ans) {
	int i, a = n, b = n;
	rep(i, k)
		b = d[b];
	while (true) {
		ans[a] = b;
		a = d[a];
		b = d[b];
		if (a == n)
			break;
	}
	return;
}

void Input(int m, vector<int> &d) {
	int i, a, buf, num = d.size();
	vector<int> x(num);
	rep(i, num)
		x[i] = i;
	rep(i, m) {
		cin >> a;
		buf = x[a];
		x[a] = x[a - 1];
		x[a - 1] = buf;
	}
	rep(i, num)
		d[x[i]] = i;
	return;
}

int main(void) {
	int num, i, m, k, a, buf;
	cin >> num >> m >> k;
	vector<int> d(num), c(num, 0), ans(num, 0);
	Input(m, d);
	rep(i, num) {
		if (!c[i]) {
			Cycle(i, d, c);
		}
	}
	rep(i, num) {
		if (!ans[i]) {
			Solve(i, k % c[i], d, ans);
		}
	}
	rep(i, num)
		cout << ans[i] + 1 << "\n";
	return 0;
}