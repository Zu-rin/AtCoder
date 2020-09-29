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

int Judge(ll n, int k, const vector<ll> & d) {
	int i, s = 0;
	rep(i, d.size()) {
		if ((n & d[i]) == n)
			s++;
	}
	return s >= k;
}

int main(void) {
	int num, i, j, k;
	ll ans = 0;
	cin >> num >> k;
	vector<ll> a(num + 1), d;
	for (i = 1; i <= num; i++)
		cin >> a[i];
	rep(i, num)
		a[i + 1] += a[i];
	rep(i, num) {
		for (j = i + 1; j <= num; j++)
			d.push_back(a[j] - a[i]);
	}
	for (i = 40; i >= 0; i--) {
		if(Judge((1ll << i) + ans, k, d))
			ans += 1ll << i;
	}
	cout << ans << "\n";
	return 0;
}