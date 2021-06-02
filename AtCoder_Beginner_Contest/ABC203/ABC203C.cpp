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
#define INF 1ll << 62

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pp;

int main(void) {
	int num, i;
	ll k, ans = 0;
	cin >> num >> k;
	vector<pp> d(num);
	rep(i, num)
		cin >> d[i].first >> d[i].second;
	sort(d.begin(), d.end());
	d.push_back(pp(INF, 0));
	for (pp& x : d) {
		if (k < x.first - ans) {
			ans += k;
			break;
		}
		k += x.second - x.first + ans;
		ans = x.first;
	}
	cout << ans << "\n";
	return 0;
}