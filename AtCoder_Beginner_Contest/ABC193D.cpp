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

ll nP2(ll n) {
	return n * (n - 1);
}

ll score(string& s, ll k) {
	vector<int> d(10, 0);
	int i;
	ll ans = 0;
	rep(i, 5)
		d[s[i] - '0']++;
	rep(i, 10) {
		ll a = i;
		for (int j = 0; j < d[i]; j++)
			a *= 10;
		ans += a;
	}
	return ans;
}

ll win(string& s, string& t, vector<ll>& d, ll k) {
	ll ans = 0;
	for (s[4] = '1'; s[4] <= '9'; s[4]++) {
		if (!d[s[4] - '0'])
			continue;
		ll a = d[s[4] - '0'];
		d[s[4] - '0']--;
		for (t[4] = '1'; t[4] <= '9'; t[4]++) {
			if (!d[t[4] - '0'])
				continue;
			if (score(s, k) > score(t, k))
				ans += a * d[t[4] - '0'];
		}
		d[s[4] - '0']++;
	}
	return ans;
}

int main(void) {
	int i;
	ll k, a, sum = 0;
	string s, t;
	cin >> k >> s >> t;
	vector<ll> d(10, k);
	rep(i, 4) {
		d[s[i] - '0']--;
		d[t[i] - '0']--;
	}
	sum = nP2(k * 9 - 8);
	a = win(s, t, d, k);
	double ans = (double)a / (double)sum;
	printf("%.10lf\n", ans);
	return 0;
}