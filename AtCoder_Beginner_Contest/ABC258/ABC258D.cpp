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
#define INF 1ll << 62

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i;
	ll ans = INF, s = 0, x, a, b;
	cin >> num >> x;
	rep(i, num) {
		cin >> a >> b;
		x = max(0ll, x - 1);
		s += a + b;
		chmin(ans, s + b * x);
	}
	cout << ans << "\n";
	return 0;
}