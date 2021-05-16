#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
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

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

vector<ll> MakePrime(int n) {
	vector<ll> k(n, 1), ans;
	for (int i = 2; i < k.size(); i++) {
		if (k[i]) {
			ans.push_back(i);
			for (int j = i << 1; j < k.size(); j += i)
				k[j] = 0;
		}
	}
	return ans;
}

int main(void) {
	int num, i, j;
	ll ans = 0, buf;
	cin >> num;
	vector<ll> d(num), p;
	p = MakePrime(1001);
	vector<int> ma(p.size(), 0);
	vector<vector<int>> k(num, vector<int>(p.size(), 0));
	rep(i, num) {
		cin >> d[i];
		rep(j, p.size()) {
			while (d[i] % p[j] == 0) {
				d[i] /= p[j];
				k[i][j]++;
			}
			chmax(ma[j], k[i][j]);
		}
	}
	rep(i, num) {
		buf = 1;
		rep(j, p.size()) {
			buf *= Pow(p[j], ma[j] - k[i][j]);
			buf %= MOD;
		}
		ans += buf;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}