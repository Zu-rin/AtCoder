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

int main(void) {
	int num, i;
	ll ans = 0, n = 0;
	cin >> num;
	vector<ll> d(num), ma(num + 1, -INF), sm(num + 1, 0);
	rep(i, num)
		cin >> d[i];
	rep(i, num) {
		sm[i + 1] = sm[i] + d[i];
		ma[i + 1] = max(ma[i], sm[i + 1]);
	}
	for (i = 1; i <= num; i++) {
		chmax(ans, n + sm[i]);
		chmax(ans, n + ma[i]);
		n += sm[i];
	}
	cout << ans << "\n";
	return 0;
}