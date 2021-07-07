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
	ll n, i, a, b, c, ans = INF;
	cin >> n;
	for (b = 0; (1ll << b) <= n; b++) {
		a = n / (1ll << b);
		c = n % (1ll << b);
		chmin(ans, a + b + c);
	}
	cout << ans << "\n";
	return 0;
}