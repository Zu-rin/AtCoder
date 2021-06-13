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

int Binary_search(ll n, vector<ll> &d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag);
}

void make_set(int num, vector<vector<ll>> &d) {
	int i;
	vector<ll> a(num);
	rep(i, num)
		cin >> a[i];
	for (i = 1; i < (1 << num); i++) {
		ll k = 0, sum = 0;
		for (int j = 0; (1 << j) <= i; j++) {
			if (i & (1 << j)) {
				sum += a[j];
				k++;
			}
		}
		d[k].push_back(sum);
	}
}

int main(void) {
	int num, k, i;
	ll p, ans = 0;
	cin >> num >> k >> p;
	vector<vector<ll>> a(num + 1), b(num + 1);
	make_set(num / 2, a);
	make_set(num / 2 + (num & 1), b);
	a[0].push_back(0);
	b[0].push_back(0);
	rep(i, k + 1)
		sort(b[i].begin(), b[i].end());
	rep(i, k + 1) {
		vector<ll>& tag = b[k - i];
		for (ll& x : a[i]) {
			if (x <= p)
				ans += Binary_search(p - x, tag);
		}
	}
	cout << ans << "\n";
	return 0;
}