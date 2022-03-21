#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 998244353
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	ll num, i, ans = 0;
	cin >> num;
	for (ll a = 1; a * a <= num; a++) {
		ans += max(0ll, num / a - a + 2) >> 1;
		if (ans >= MOD)
			ans -= MOD;
	}
	cout << ans << "\n";
	return 0;
}