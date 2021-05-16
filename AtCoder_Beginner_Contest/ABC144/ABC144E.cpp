#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007
#define INF 1ll << 60

using namespace std;
typedef long long ll;

ll Binary_search(const vector<ll>& d, const vector<ll> &a, ll l, ll r, const ll k) {
	if (l > r)
		return l;
	ll i, sum = 0, p = (r + l) >> 1;
	for (i = 0; i < d.size(); i++) {
		sum += max(0ll, d[i] - p / a[i]);
	}
	if (sum <= k) {
		return min(p, Binary_search(d, a, l, p - 1, k));
	}
	else
		return Binary_search(d, a, p + 1, r, k);
}

int main(void) {
	int num;
	ll i, k;
	cin >> num >> k;
	vector<ll> d(num), a(num);
	for (i = 0; i < num; i++)
		scanf_s("%lld", &d[i]);
	for (i = 0; i < num; i++)
		scanf_s("%lld", &a[i]);
	sort(d.begin(), d.end(), greater<ll>());
	sort(a.begin(), a.end());
	cout << Binary_search(d, a, 0, d[0] * a[num - 1], k) << "\n";
	return 0;
}