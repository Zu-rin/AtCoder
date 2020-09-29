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
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

ll nC2(ll n) {
	return (n * (n - 1)) >> 1;
}

ll Number(vector<ll>& a, vector<ll>& b, ll x) {
	int i, j = b.size() - 1;
	ll ans = 0;
	rep(i, a.size()) {
		while (j >= 0 && a[i] * b[j] >= x)
			j--;
		ans += j + 1;
	}
	return ans;
}

ll Judge(vector<ll>& a, vector<ll>& b, ll x, int p) {
	int i;
	ll ans = 0;
	if (p) {
		ans = Number(a, a, x);
		rep(i, a.size()) {
			if (a[i] * a[i] < x)
				ans--;
			else
				break;
		}
		ans += Number(b, b, x);
		rep(i, a.size()) {
			if (a[i] * a[i] < x)
				ans--;
			else
				break;
		}
		ans >>= 1;
	}
	else {
		ans = Number(a, b, x);
	}
	return ans;
}

ll Search(vector<ll>& a, vector<ll>& b, ll k, int pos, ll l = -INF, ll r = INF) {
	if (r - l <= 1) {
		return l;
	}
	ll p = (l + r) / 2;
	if (Judge(a, b, p, pos) < k) {
		return Search(a, b, k, pos, p, r);
	}
	return Search(a, b, k, pos, l, p);
}

int main(void) {
	int num, i, j, k;
	ll a, ans;
	vector<ll> neg, pos, zero;
	cin >> num >> k;
	rep(i, num) {
		cin >> a;
		if (a < 0)
			neg.push_back(a);
		else if(a > 0)
			pos.push_back(a);
		else
			zero.push_back(a);
	}
	if (k <= neg.size() * pos.size()) {
		sort(neg.begin(), neg.end());
		sort(pos.begin(), pos.end(), greater<ll>());
		ans = Search(neg, pos, k, 0);
	}
	else if (k > nC2(num) - nC2(pos.size()) - nC2(neg.size())) {
		k -= nC2(num) - nC2(pos.size()) - nC2(neg.size());
		sort(neg.begin(), neg.end(), greater<ll>());
		sort(pos.begin(), pos.end());
		ans = Search(neg, pos, k, 1, 0);
	}
	else
		ans = 0;
	cout << ans << "\n";
	return 0;
}