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

int main(void) {
	ll l, num, i, a, w = INF, ans = 0;
	cin >> l >> num;
	vector<ll> d = { 0 };
	rep(i, num) {
		cin >> a;
		d.push_back(a);
	}
	d.push_back(l + 1);
	sort(d.begin(), d.end());
	rep(i, d.size() - 1) {
		a = d[i + 1] - d[i] - 1;
		if (a)
			chmin(w, a);
	}
	rep(i, d.size() - 1) {
		a = d[i + 1] - d[i] - 1;
		ans += a / w + (a % w ? 1 : 0);
	}
	cout << ans << "\n";
	return 0;
}