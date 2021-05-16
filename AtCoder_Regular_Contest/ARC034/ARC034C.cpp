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
#define MOD 1000000007
#define PI 3.14159265358979323846
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

void Div(ll n, map<ll, int> & d) {
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			d[i]++;
			n /= i;
		}
	}
	if (n > 1)
		d[n]++;
	return;
}

int main(void) {
	int num, i;
	ll a, b, ans = 1;
	map<ll, int> d;
	cin >> a >> b;
	while (a > b) {
		Div(a, d);
		a--;
	}
	for (auto it = d.begin(); it != d.end(); it++) {
		ans *= (*it).second + 1;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}