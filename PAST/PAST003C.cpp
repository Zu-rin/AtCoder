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
#define INF 1ll << 40

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll Pow(ll n, ll k) {
	ll ans = 1, a = n, lim = 1000000000, out = false;
	while (k > 0) {
		if (k & 1) {
			ans *= a;
			if (out)
				return INF;
		}
		a *= a;
		k >>= 1;
		if (ans > lim)
			return INF;
		if (a > lim)
			out = true;
	}
	return ans;
}

int main(void) {
	int num, i;
	ll a, r, n, ans;
	cin >> a >> r >> n;
	ans = Pow(r, n - 1);
	if (ans == INF || ans * a > 1000000000)
		printf("large\n");
	else
		cout << ans * a << "\n";
	return 0;
}