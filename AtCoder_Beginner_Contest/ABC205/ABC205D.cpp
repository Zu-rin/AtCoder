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

// nˆÈ‰º‚Ì—v‘f‚Ì’†‚ÅÅ‘å‚Ì“Y‚¦š‚ğ•Ô‚·
// n < min(d) : -1
// max(d) < n : d.size() - 1
int Binary_search(ll n, vector<ll> &d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	int num, i, q, p;
	ll k;
	cin >> num >> q;
	vector<ll> d(num), a(num);
	rep(i, num) {
		cin >> a[i];
		d[i] = a[i] - i - 1;
	}
	rep(i, q) {
		cin >> k;
		p = Binary_search(k - 1, d);
		if (p >= 0)
			cout << k - d[p] + a[p]<< "\n";
		else
			cout << k << "\n";
	}
	return 0;
}