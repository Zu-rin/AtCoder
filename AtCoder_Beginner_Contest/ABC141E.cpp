#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <set>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MODA 1000000007
#define MODB 1000000009
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pp;

ll Pow(ll n, ll k, ll MOD) {
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

ll Inverse(ll a, ll MOD) {
	return Pow(a, MOD - 2, MOD);
}

int main(void) {
	int num, i, j, ans;
	string s;
	cin >> num >> s;
	vector<vector<ll>> a(num, vector<ll>(num + 1, 0)), b(num, vector<ll>(num + 1, 0));
	rep(i, num) {
		for (j = i; j < num; j++) {
			a[i][j + 1] = a[i][j] * 26 + (s[j] - 'a');
			b[i][j + 1] = b[i][j] * 26 + (s[j] - 'a');
			a[i][j + 1] %= MODA;
			b[i][j + 1] %= MODB;
		}
	}
	for (ans = num >> 1; ans >= 1; ans--) {
		set<pp> st;
		rep(i, num - ans + 1) {
			pp key(a[i][i + ans], b[i][i + ans]);
			if (st.count(key)) {
				cout << ans << "\n";
				return 0;
			}
			st.insert(key);
		}
	}
	printf("0\n");
	return 0;
}