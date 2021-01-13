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
typedef pair<int, int> pp;

int main(void) {
	int num, m, i, x, y;
	ll ans = -INF;
	cin >> num >> m;
	vector<ll> a(num + 1, 0), b(num + 1, INF);
	vector<vector<int>> d(num + 1);
	for (i = 1; i <= num; i++)
		cin >> a[i];
	rep(i, m) {
		cin >> x >> y;
		d[x].push_back(y);
	}
	rep(i, num + 1) {
		chmax(ans, a[i] - b[i]);
		for (int n : d[i])
			chmin(b[n], min(a[i], b[i]));
	}
	cout << ans << "\n";
	return 0;
}