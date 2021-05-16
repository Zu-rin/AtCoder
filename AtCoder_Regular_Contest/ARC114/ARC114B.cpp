#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 998244353
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

int DFS(int n, int k, vector<int>& d, vector<int>& v) {
	v[n] = k;
	if (v[d[n]] < 0)
		return DFS(d[n], k, d, v);
	else if (v[d[n]] == k)
		return 1;
	return 0;
}

int main(void) {
	int num, i, k = 0, x = 0;
	cin >> num;
	vector<int> d(num), v(num, -1);
	rep(i, num) {
		cin >> d[i];
		d[i]--;
	}
	rep(i, num) {
		if (v[i] < 0) {
			if (DFS(i, x, d, v))
				k++;
			x++;
		}
	}
	cout << Pow(2ll, k) - 1 << "\n";
	return 0;
}