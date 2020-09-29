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

int Bitnum(const string& s) {
	int i, ans = 0;
	rep(i, s.size()) {
		if (s[i] == '1')
			ans++;
	}
	return ans;
}

int Bitnum(ll n) {
	int ans = 0;
	while (n) {
		if (n & 1)
			ans++;
		n >>= 1;
	}
	return ans;
}

int Search(vector<int>& d, int n) {
	if (d[n] || n == 0)
		return d[n];
	return d[n] = Search(d, n % Bitnum(n)) + 1;
}

int Init(string& s, int k) {
	if (k <= 0)
		return 0;
	int i, ans = 0;
	rep(i, s.size()) {
		ans <<= 1;
		if (s[i] == '1')
			ans++;
		ans %= k;
	}
	return ans;
}

ll Pow(ll n, ll k, const ll mod){
	if (mod <= 0)
		return 0;
	ll ans = 1, a = n % mod;
	while (k > 0) {
		if (k & 1) {
			ans *= a;
			ans %= mod;
		}
		a *= a;
		a %= mod;
		k >>= 1;
	}
	return ans;
}

int main(void) {
	int num, i, a, b, k, ans;
	string s;
	cin >> num >> s;
	vector<int> d(num + 1, 0);
	k = Bitnum(s);
	a = Init(s, k - 1);
	b = Init(s, k + 1);
	rep(i, num) {
		if (s[i] == '1') {
			if (k == 1) {
				printf("0\n");
				continue;
			}
			ll n = a - Pow(2, num - i - 1, k - 1);
			if (n < 0)
				n += k - 1;
			ans = Search(d, n) + 1;
		}
		else {
			ll n = b + Pow(2, num - i - 1, k + 1);
			n %= k + 1;
			ans = Search(d, n) + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}