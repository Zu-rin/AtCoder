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

ll judge(vector<int> & d, vector<int> & c, ll k, int s) {
	int i, p = d[s];
	ll sum = c[p], ans = c[p];
	vector<ll> b = { c[p] };
	for(i = 0; i < k && p != s; i++) {
		p = d[p];
		sum += c[p];
		chmax(ans, sum);
		b.push_back(ans);
	}
	if (i == k)
		return b[k - 1];
	ll a = k / b.size() * sum;
	if (k % b.size())
		a += max(0ll, b[k % b.size() - 1]);
	else
		chmax(a, a - sum + ans);
	return max(a, ans);
}

int main(void) {
	int num, i, k;
	ll ans = -INF;
	cin >> num >> k;
	vector<int> d(num), c(num);
	rep(i, num) {
		cin >> d[i];
		d[i]--;
	}
	rep(i, num)
		cin >> c[i];
	rep(i, num) {
		chmax(ans, judge(d, c, k, i));
	}
	cout << ans << "\n";
	return 0;
}