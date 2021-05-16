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

ll Pow(ll n, ll k, ll mod) {
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
	int i;
	vector<vector<int>> d;
	ll a, b, c;
	d.emplace_back(vector<int>{ 0 });
	d.emplace_back(vector<int>{ 1 });
	d.emplace_back(vector<int>{ 2, 4, 8, 6 });
	d.emplace_back(vector<int>{ 3, 9, 7, 1 });
	d.emplace_back(vector<int>{ 4, 6 });
	d.emplace_back(vector<int>{ 5 });
	d.emplace_back(vector<int>{ 6 });
	d.emplace_back(vector<int>{ 7, 9, 3, 1 });
	d.emplace_back(vector<int>{ 8, 4, 2, 6 });
	d.emplace_back(vector<int>{ 9, 1 });
	cin >> a >> b >> c;
	a %= 10;
	ll p = (Pow(b, c, d[a].size()) - 1) % d[a].size();
	if (p < 0)
		p += d[a].size();
	cout << d[a][p] << "\n";
	return 0;
}