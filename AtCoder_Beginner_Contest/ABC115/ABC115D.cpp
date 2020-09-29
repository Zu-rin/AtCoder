#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll Search(int l, ll &x, vector<vector<ll>> &d) {
	if (x == 0)
		return 0;
	if (x >= d[l][1]) {
		x -= d[l][1];
		return d[l][0];
	}
	x--;
	ll ans = Search(l - 1, x, d);
	if (x > 0) {
		ans++;
		x--;
	}
	ans += Search(l - 1, x, d);
	return ans;
}

int main(void) {
	int n, i;
	ll x, ans;
	cin >> n >> x;
	vector<vector<ll>> d(n + 1, vector<ll>(2));
	d[0][0] = 1;
	d[0][1] = 1;
	for (i = 0; i < n; i++) {
		d[i + 1][0] = (d[i][0] << 1) + 1;
		d[i + 1][1] = (d[i][1] << 1) + 3;
	}
	ans = Search(n, x, d);
	cout << ans << "\n";
	return 0;
}