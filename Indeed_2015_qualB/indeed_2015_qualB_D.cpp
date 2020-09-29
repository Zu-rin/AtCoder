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

ll Combi(ll n) {
	return n * (n - 1) / 2 + n;
}

int main(void) {
	int num, i, k, a;
	ll all;
	cin >> num >> k;
	vector<list<int>> d(k + 1);
	rep(i, num) {
		cin >> a;
		d[a].push_back(i);
	}
	all = Combi(num);
	for(i = 1; i <= k; i++) {
		ll ans = 0, p = -1;
		for (auto it = d[i].begin(); it != d[i].end(); it++) {
			ans += Combi(*it - p - 1);
			p = *it;
		}
		ans += Combi(num - p - 1);
		cout << all - ans << "\n";
	}
	return 0;
}