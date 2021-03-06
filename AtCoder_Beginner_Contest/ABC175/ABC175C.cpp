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
	int num, i;
	ll x, k, d, ans;
	cin >> x >> k >> d;
	x = abs(x);
	if (x / d >= k)
		ans = x - k * d;
	else {
		k -= x / d;
		ans = x % d;
		if (k & 1)
			ans = abs(d - ans);
	}
	cout << ans << "\n";
	return 0;
}