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

int main(void) {
	int num, i, j, q, a, b;
	ll x, ans = 0;
	vector<ll> d(100001, 0);
	cin >> num;
	rep(i, num) {
		cin >> a;
		d[a]++;
		ans += a;
	}
	cin >> q;
	rep(j, q) {
		cin >> a >> b;
		x = d[a];
		d[a] = 0;
		d[b] += x;
		ans += (ll)(b - a) * x;
		cout << ans << "\n";
	}
	return 0;
}