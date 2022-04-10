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
#define INF (1ll << 60)

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll k;
int Judge(ll p, vector<ll> &d) {
	ll s = 0;
	for (ll a : d)
		s += min(p, a);
	return s >= p * k;
}

int main(void) {
	int num, i;
	cin >> num >> k;
	ll l = 0, r = INF / k;
	vector<ll> d(num);
	rep(i, num)
		cin >> d[i];
	while (l + 1 < r) {
		ll p = (l + r) >> 1;
		if (Judge(p, d))
			l = p;
		else
			r = p;
	}
	cout << l << "\n";
	return 0;
}