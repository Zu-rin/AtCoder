#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <cmath>
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
typedef struct Item {
	ll v, w;
	friend bool operator<(const Item& l, const Item& r) {
		return l.w < r.w || (l.w == r.w && l.v < r.v);
	}
	friend Item operator+(const Item& l, const Item& r) {
		return { l.v + r.v, l.w + r.w };
	}
} item;

// nˆÈ‰º‚Ì—v‘f‚Ì’†‚ÅÅ‘å‚Ì“Y‚¦Žš‚ð•Ô‚·
// n < min(d) : -1
// max(d) < n : d.size() - 1
template<class T>
int Binary_search(T n, vector<T>& d) {
	auto tag = upper_bound(d.begin(), d.end(), n);
	return distance(d.begin(), tag) - 1;
}

ll num, lim;

void Brute(int s, int g, vector<item>& d, vector<item>& dp) {
	int i;
	dp.resize(1 << (g - s));
	for (i = 1; i < dp.size(); i++) {
		if (i - (i & -i)) {
			dp[i] = dp[i - (i & -i)] + dp[i & -i];
		}
		else {
			dp[i] = d[(int)log2(i & -i) + s];
		}
	}
}

ll Solve1(vector<item>& d) {
	int i, p;
	ll ans = 0;
	vector<item> d1, d2, buf = { {0,0} };
	Brute(0, num >> 1, d, d1);
	Brute(num >> 1, num, d, d2);
	sort(d1.begin(), d1.end());
	for (i = 1; i < d1.size(); i++) {
		if (buf[buf.size() - 1].v < d1[i].v)
			buf.push_back(d1[i]);
	}
	rep(i, d2.size()) {
		p = Binary_search({ INF, lim - d2[i].w }, buf);
		if (p < 0)
			continue;
		chmax(ans, buf[p].v + d2[i].v);
	}
	return ans;
}

ll Solve2(vector<item>& d) {
	int i, j, W = 200000;
	vector<ll> dp(W + 1, 0);
	rep(i, num) {
		for (j = W; j - d[i].w >= 0; j--) {
			chmax(dp[j], dp[j - d[i].w] + d[i].v);
		}
	}
	return dp[min(lim, (ll)W)];
}

ll Solve3(vector<item>& d) {
	int i, j, V = 200000;
	vector<ll> dp(V + 1, INF);
	dp[0] = 0;
	rep(i, num) {
		for (j = V; j - d[i].v >= 0; j--) {
			chmin(dp[j], dp[j - d[i].v] + d[i].w);
		}
	}
	for (i = V; i >= 0; i--) {
		if (dp[i] <= lim)
			break;
	}
	return i;
}

int main(void) {
	int i;
	ll ans, maxv = 0;
	cin >> num >> lim;
	vector<item> d(num);
	rep(i, num) {
		cin >> d[i].v >> d[i].w;
		chmax(maxv, d[i].v);
	}
	if (num <= 30) {
		ans = Solve1(d);
	}
	else if (maxv <= 1000) {
		ans = Solve3(d);
	}
	else {
		ans = Solve2(d);
	}
	cout << ans << "\n";
	return 0;
}