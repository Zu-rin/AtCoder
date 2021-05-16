#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 2019
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, ll> pp;

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

int main(void) {
	int num, i, j, a;
	ll x, ans = 0;
	string s;
	cin >> s;
	vector<int> d(s.size() + 1, 0);
	map<int, ll> mp;
	mp[0] = 1;
	for (i = s.size() - 1; i >= 0; i--) {
		a = s[i] - '0';
		d[i] = (d[i + 1] +  a * Pow(10, s.size() - i - 1)) % 2019;
		mp[d[i]]++;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		x = (*it).second;
		ans += x * (x - 1) / 2;
	}
	cout << ans << "\n";
	return 0;
}