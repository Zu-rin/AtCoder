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
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<ll, int> pp;

ll Search(vector<ll> &h, vector<vector<int>> &d, int n = 1) {
	ll ans = 0;
	vector<ll> a(h.size(), INF);
	priority_queue<pp, vector<pp>, greater<pp>> que;
	que.push(pp(0, 1));
	while (!que.empty()) {
		ll c = que.top().first;
		int n = que.top().second;
		que.pop();
		if (a[n] != INF)
			continue;
		a[n] = c;
		for (int nx : d[n]) {
			if (a[nx] != INF)
				continue;
			if (h[n] >= h[nx])
				que.push(pp(c, nx));
			else
				que.push(pp(c + h[nx] - h[n], nx));
		}
	}
	for (int i = 1; i < a.size(); i++)
		chmax(ans, h[1] - h[i] - a[i]);
	return ans;
}

int main(void) {
	int num, m, i, a, b;
	cin >> num >> m;
	vector<ll> h(num + 1);
	vector<vector<int>> d(num + 1);
	for (i = 1; i <= num; i++)
		cin >> h[i];
	rep(i, m) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	cout << Search(h, d) << "\n";
	return 0;
}