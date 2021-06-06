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
typedef pair<int, ll> pp;

int DFS(int n, vector<vector<pp>> &d, vector<int> &ok) {
	ok[n] = 0;
	ll sum = 1;
	for (pp& e : d[n]) {
		if (ok[e.first]) {
			e.second = DFS(e.first, d, ok);
			sum += e.second;
		}
	}
	return sum;
}

int main(void) {
	int num, i, a, b;
	ll ans = 0;
	cin >> num;
	vector<int> ok(num + 1, 1);
	vector<vector<pp>> d(num + 1);
	rep(i, num - 1) {
		cin >> a >> b;
		d[a].push_back(pp(b, 0));
		d[b].push_back(pp(a, 0));
	}
	DFS(1, d, ok);
	rep(i, num + 1) {
		for (pp& e : d[i]) {
			ans += e.second * (num - e.second);
		}
	}
	cout << ans << "\n";
	return 0;
}