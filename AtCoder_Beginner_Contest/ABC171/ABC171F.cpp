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

ll Inverse(ll a) {
	return Pow(a, MOD - 2);
}

//nCa‚ğŒvZAa < 0 ‚Ì 0
ll Combi(ll n, ll a, vector<ll> & k) {
	a = min(a, n - a);
	if (a < 0)
		return 0;
	else if (a == 0)
		return 1;
	ll ans = k[n] * Inverse(k[a]) % MOD;
	return ans * Inverse(k[n - a]) % MOD;
}

// d[n] = n! ‚Ì”z—ñ‰Šú‰»
void Ini_fact(vector<ll> & d) {
	d[1] = 1;
	for (ll i = 2; i < d.size(); i++)
		d[i] = d[i - 1] * i % MOD;
	return;
}

int main(void) {
	ll num, i, k, ans = 0;
	char c = 'a';
	string s;
	vector<ll> kai(2000010);
	cin >> num >> s;
	Ini_fact(kai);
	rep(i, num + 1) {
		k = Pow(25, i) * Pow(26, num - i) % MOD;
		k *= Combi(s.size() + i - 1, i, kai);
		k %= MOD;
		ans += k;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}