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
	int num, i, a, m = 200000;
	ll ans = 0;
	cin >> num;
	vector<ll> d(200001, 0);
	rep(i, num) {
		cin >> a;
		d[a]++;
	}
	for (i = 1; i <= m; i++) {
		if (!d[i])
			continue;
		for (int j = 1; j <= m / i; j++) {
			if (!d[j])
				continue;
			ans += d[i] * d[j] * d[i * j];
		}
	}
	cout << ans << "\n";
	return 0;
}