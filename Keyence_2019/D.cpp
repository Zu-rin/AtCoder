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
	int n, m, i, x;
	ll ans = 1;
	cin >> n >> m;
	vector<ll> a(n * m + 2, 0), b(n * m + 2, 0);
	rep(i, n) {
		cin >> x;
		a[x]++;
	}
	rep(i, m) {
		cin >> x;
		b[x]++;
	}
	for(i = n * m; i > 0; i--) {
		if (a[i] > 1 || b[i] > 1)
			ans = 0;
		a[i] += a[i + 1];
		b[i] += b[i + 1];
	}
	for (i = n * m; i; i--) {
		if (a[i + 1] + 1 == a[i]) {
			if (b[i + 1] == b[i]) {
				ans *= b[i];
			}
		}
		else if (b[i + 1] + 1 == b[i]) {
			ans *= a[i];
		}
		else
			ans *= max(0ll, (a[i] * b[i] - n * m + i)) % MOD;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}