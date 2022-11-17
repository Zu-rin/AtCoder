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
#define INF 1ll << 60

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	ll num, m, i, ans = -INF, a = 0;
	cin >> num >> m;
	vector<ll> d(num), s(num + 1);
	rep(i, num) {
		cin >> d[i];
		s[i + 1] += s[i] + d[i];
	}
	rep(i, m) {
		a += d[i] * (i + 1);
	}
	chmax(ans, a);
	rep(i,  num - m) {
		a -= s[i + m] - s[i];
		a += d[i + m] * m;
		chmax(ans, a);
	}
	cout << ans << "\n";
	return 0;
}