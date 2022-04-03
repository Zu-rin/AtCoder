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
#define INF 1ll << 61

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll f(ll a, ll b) {
	return (a + b) * (a * a + b * b);
}

int main(void) {
	ll n, i, j = 1000000, ans = INF;
	cin >> n;
	rep(i, j + 1) {
		while (true) {
			ll x = f(i, j);
			if (x < n or j < 0)
				break;
			chmin(ans, x);
			j--;
		}
	}
	cout << ans << "\n";
	return 0;
}