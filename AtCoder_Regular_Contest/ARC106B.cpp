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

ll Search(int n, vector<ll> &x, vector<ll> &ok, vector<vector<int>> & d) {
	ll sum = x[n];
	ok[n] = 0;
	for (int i = 0; i < d[n].size(); i++) {
		if (ok[d[n][i]])
			sum += Search(d[n][i], x, ok, d);
	}
	return sum;
}

int main(void) {
	int num, m, i, a, b;
	cin >> num >> m;
	vector<ll> x(num + 1), ok(num + 1, 1);
	vector<vector<int>> d(num + 1);
	rep(i, num)
		cin >> x[i + 1];
	rep(i, num) {
		cin >> b;
		x[i + 1] -= b;
	}
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	ok[0] = 0;
	rep(i, num) {
		if (ok[i] && Search(i, x, ok, d)) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}