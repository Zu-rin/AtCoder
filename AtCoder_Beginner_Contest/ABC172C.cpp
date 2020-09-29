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
int Binary_search(ll n, vector<ll> & d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	int n, m, i, ans;
	ll k;
	cin >> n >> m >> k;
	vector<ll> a(n), b(m);
	rep(i, n)
		cin >> a[i];
	rep(i, m)
		cin >> b[i];
	rep(i, m - 1)
		b[i + 1] += b[i];
	ans = Binary_search(k, b);
	rep(i, n) {
		k -= a[i];
		if (k < 0)
			break;
		chmax(ans, i + 1 + Binary_search(k, b));
	}
	cout << ans + 1 << "\n";
	return 0;
}