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

ll Pow(ll n, ll k) {
	ll ans = 1, a = n % MOD;
	while (k > 0) {
		if (k & 1) {
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		k >>= 1;
	}
	return ans;
}

void Fill(vector<string> &d, vector<vector<ll>>& x, vector<vector<ll>> &y) {
	int i, j;
	for (i = 1; i < d.size(); i++) {
		for (j = 1; j < d[i].size(); j++) {
			if (d[i][j] == '.')
				x[i][j] = x[i][j - 1] + 1;
		}
		ll a = 0;
		for (j = d[i].size() - 1; j > 0; j--) {
			if (d[i][j] == '.')
				x[i][j] = chmax(a, x[i][j]);
			else
				a = 0;
		}
	}
	for (j = 1; j < d[0].size(); j++) {
		for (i = 1; i < d.size(); i++) {
			if (d[i][j] == '.')
				y[i][j] = y[i - 1][j] + 1;
		}
		ll a = 0;
		for (i = d.size() - 1; i > 0; i--) {
			if (d[i][j] == '.')
				y[i][j] = chmax(a, y[i][j]);
			else
				a = 0;
		}
	}
}

int main(void) {
	int num, i, j, h, w, sum = 0;
	ll ans = 0, all;
	cin >> h >> w;
	vector<string> d(h + 2, string(w + 2, '#'));
	vector<vector<ll>> x(h + 2, vector<ll>(w + 2, 0)), y(h + 2, vector<ll>(w + 2, 0));
	for (i = 1; i <= h; i++) {
		cin >> d[i];
		rep(j, d[i].size()) {
			if (d[i][j] == '.')
				sum++;
		}
		d[i] = "#" + d[i] + "#";
	}
	Fill(d, x, y);
	all = Pow(2ll, sum);
	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++) {
			if (d[i][j] == '.') {
				ans += all - Pow(2ll, sum - x[i][j] - y[i][j] + 1);
				ans = (ans + MOD) % MOD;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}