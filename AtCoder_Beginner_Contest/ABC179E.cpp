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
	ll i, j, num, x, m, ans, a = 0, b = 0, k = 0;
	cin >> num >> x >> m;
	if (m == 1) {
		printf("0\n");
		return 0;
	}
	vector<ll> d(m, 0), s(m, 0);
	rep(i, num) {
		k++;
		a += x;
		if (d[x]) {
			k -= s[x];
			b = a - d[x];
			a = d[x];
			int c = (num - s[x]) % k;
			k = (num - s[x]) / k;
			rep(j, c) {
				x *= x;
				x %= m;
				a += x;
			}
			break;
		}
		d[x] = a;
		s[x] = k;
		x *= x;
		x %= m;
	}
	if (i == num)
		ans = a;
	else
		ans = a + b * k;
	cout << ans << "\n";
	return 0;
}