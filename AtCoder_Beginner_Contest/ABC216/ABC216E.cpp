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

ll sum(ll l, ll r, ll n, ll & k) {
	ll ans, s = k / n;
	if (r - l <= s) {
		k -= (r - l) * n;
		ans = (r - l) * (r + l + 1) / 2 * n;
	}
	else {
		ans = sum(r - s, r, n, k);
		ans += (r - s) * k;
		k = 0;
	}
	return ans;
}

int main(void) {
	int num, i, x;
	ll ans = 0, k;
	cin >> num >> k;
	vector<int> d(num);
	rep(i, num)
		cin >> d[i];
	d.push_back(0);
	sort(d.begin(), d.end(), greater<int>());
	rep(i, num) {
		if (k) {
			ans += sum(d[i + 1], d[i], i + 1, k);
		}
	}
	cout << ans << "\n";
	return 0;
}