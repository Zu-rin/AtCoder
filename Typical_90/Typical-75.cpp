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
	ll num, i, d = 0, n, ans = 0;
	cin >> n;
	while (!(n & 1)) {
		d++;
		n >>= 1;
	}
	for (i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			d++;
			n /= i;
		}
	}
	if (n == 1)
		d--;
	while (d) {
		ans++;
		d >>= 1;
	}
	cout << ans << "\n";
	return 0;
}