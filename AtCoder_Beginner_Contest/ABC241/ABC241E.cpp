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
	int i, n = 0;
	ll num, k, ans = 0;
	cin >> num >> k;
	vector<int> dpt(num, -1);
	vector<ll> d(num), s(num);
	rep(i, num)
		cin >> d[i];
	dpt[0] = 0;
	while (k) {
		ll nx = (ans + d[n]) % num;
		if (dpt[nx] >= 0) {
			int cir = dpt[n] - dpt[nx] + 1;
			ll cir_s = s[n] - s[nx] + d[n];
			ans += k / cir * cir_s;
			k %= cir;
			break;
		}
		dpt[nx] = dpt[n] + 1;
		s[nx] = (ans += d[n]);
		n = nx;
		k--;
	}
	while (k) {
		ll nx = (ans + d[n]) % num;
		ans += d[n];
		n = nx;
		k--;
	}
	cout << ans << "\n";
	return 0;
}