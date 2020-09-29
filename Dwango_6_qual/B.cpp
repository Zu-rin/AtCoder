#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define MOD 1000000007
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

void Inik(vector<ll> &k) {
	k[0] = 1;
	for (ll i = 1; i < k.size(); i++)
		k[i] = i * k[i - 1] % MOD;
	return;
}

void Inip(vector<ll>& p, vector<ll> &k) {
	ll i, num = p.size();
	for (i = 1; i < num - 1; i++) {
		p[i] = k[i - 1] * k[num - 1];
		p[i] %= MOD;
		p[i] *= Inverse(k[i + 1]);
		p[i] %= MOD;
	}
	p[num - 1] = k[num - 2];
	return;
}

int main(void) {
	int num, i, l, r;
	ll ans = 0;
	cin >> num;
	vector<ll> d(num), k(num + 5), p(num);
	Inik(k);
	Inip(p, k);
	rep(i, num)
		cin >> d[i];
	for (i = 1; i < num; i++) {
		l = 0;
		r = l + i;
		for (; r < num; r++, l++) {
			ans += (d[r] - d[l]) * p[i];
			ans %= MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}