#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cmath>
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
	ll n, i, ans = 0, r;
	cin >> n;
	vector<ll> d(1000002);
	for (i = 1; i * i <= n; i++)
		d[i] = n / i;
	d[i] = n / i;
	r = i - 1;
	for (i = 1; i <= r; i++)
		ans += i * (d[i] - d[i + 1]);
	for (i = 1; i <= n / (r + 1); i++)
		ans += n / i;
	cout << ans << "\n";
	return 0;
}