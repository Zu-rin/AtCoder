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

ll Pat(ll a, ll n) {
	return min(max(0ll, a - 1), max(0ll, 2 * n - a + 1));
}

int main(void) {
	ll i, n, k, ans = 0;
	cin >> n >> k;
	for (i = 2; i <= 2 * n; i++) {
		ans += Pat(i, n) * Pat(i - k, n);
	}
	cout << ans << "\n";
	return 0;
}