#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define rep(i, n) for(i = 0; i < (n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define MOD 1000000007
#define INF 1 << 30

using namespace std;
typedef long long ll;
typedef pair<int, int> pp;

int main(void) {
	int num, i, j, a, b;
	ll ans = 0;
	cin >> num;
	vector<ll> d(100, 0);
	for (i = 1; i <= num; i++) {
		a = i;
		while (a >= 10)
			a /= 10;
		b = i % 10;
		d[a * 10 + b]++;
	}
	rep(i, 10) {
		rep(j, 10) {
			ans += d[10 * i + j] * d[10 * j + i];
		}
	}
	cout << ans << "\n";
	return 0;
}