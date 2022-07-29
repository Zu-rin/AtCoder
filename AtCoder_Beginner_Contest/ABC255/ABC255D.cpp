#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
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
template<typename T>
int Binary_search(T n, vector<T> &d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

int main(void) {
	int num, q, i;
	ll x;
	cin >> num >> q;
	vector<ll> a(num), d(num, 0);
	rep(i, num)
		cin >> a[i];
	sort(a.begin(), a.end());
	d[0] = a[0];
	rep(i, num - 1)
		d[i + 1] = d[i] + a[i + 1];
	rep(i, q) {
		cin >> x;
		ll k = Binary_search(x, a), ans = 0;
		if (k >= 0)
			ans += x * (k + 1) - d[k];
		if (k < num - 1)
			ans += d[num - 1] - (k >= 0 ? d[k] : 0) - x * (num - k - 1);
		cout << ans << "\n";
	}
	return 0;
}