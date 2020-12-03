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

ll lim;

// nˆÈ‰º‚Ì—v‘f‚Ì’†‚ÅÅ‘å‚Ì“Y‚¦š‚ğ•Ô‚·
// n < min(d) : -1
// max(d) < n : d.size() - 1
int Binary_search(ll n, vector<ll> & d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

void Brute(const vector<ll> &d, vector<ll> &x) {
	int num, i, j;
	x.push_back(0);
	rep(i, d.size()) {
		num = x.size();
		rep(j, num) {
			if (x[j] + d[i] <= lim)
				x.push_back(x[j] + d[i]);
		}
	}
	return;
}

int main(void) {
	int num, i;
	ll a, ans = 0;
	cin >> num >> lim;
	vector<ll> d(num), d1, d2;
	rep(i, num)
		cin >> d[i];
	Brute(vector<ll>(d.begin(), d.begin() + (d.size() >> 1)), d1);
	Brute(vector<ll>(d.begin() + (d.size() >> 1), d.end()), d2);
	sort(d2.begin(), d2.end());
	for(ll a : d1) {
		chmax(ans, d2[Binary_search(lim - a, d2)] + a);
	}
	cout << ans << "\n";
	return 0;
}