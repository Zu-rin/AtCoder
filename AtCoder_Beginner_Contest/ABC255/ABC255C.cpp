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
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i;
	ll x, a, d, n, ans;
	cin >> x >> a >> d >> n;
	if (d < 0) {
		x *= -1;
		a *= -1;
		d *= -1;
	}
	if (x <= a) {
		ans = abs(a - x);
	}
	else if (a + d * (n - 1) <= x) {
		ans = abs(a + d * (n - 1) - x);
	}
	else {
		x -= a;
		ans = min(x % d, d - x % d);
	}
	cout << ans << "\n";
	return 0;
}