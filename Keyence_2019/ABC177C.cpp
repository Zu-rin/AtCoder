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
	int num, i;
	ll ans = 0;
	cin >> num;
	vector<ll> d(num), a(num, 0);
	rep(i, num) {
		cin >> d[i];
		a[i] = d[i];
	}
	rep(i, num - 1) {
		a[i + 1] += a[i];
	}
	rep(i, num) {
		ans += d[i] * ((a[num - 1] - a[i]) % MOD) % MOD;
	}
	ans %= MOD;
	cout << ans << "\n";
	return 0;
}