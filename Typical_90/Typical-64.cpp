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
	int num, i, q, l, r;
	ll v, ans = 0;
	cin >> num >> q;
	vector<ll> d(num), a(num - 1);
	rep(i, num)
		cin >> d[i];
	rep(i, num - 1) {
		a[i] = d[i + 1] - d[i];
		ans += abs(a[i]);
	}
	rep(i, q) {
		cin >> l >> r >> v;
		if (1 < l) {
			ans += abs(a[l - 2] + v) - abs(a[l - 2]);
			a[l - 2] += v;
		}
		if (r < num) {
			ans += abs(a[r - 1] - v) - abs(a[r - 1]);
			a[r - 1] -= v;
		}
		cout << ans << "\n";
	}
	return 0;
}